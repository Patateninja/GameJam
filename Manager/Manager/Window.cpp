#include "Window.h"

Window::Window(std::string _title, sf::Vector2i _size, bool _isFullscreen, bool _isVSync, bool _isAntialiasing)
{
	m_title = _title;
	m_size = _size;
	m_isFullscreen = _isFullscreen;
	m_isVSync = _isVSync;
	m_isAntialiasing = _isAntialiasing;
	m_isFocused = false;
	m_event = sf::Event();
	
	sf::ContextSettings settings;

	if (m_isAntialiasing)
	{
		settings.antialiasingLevel = 8;
	}
	else
	{
		settings.antialiasingLevel = 0;
	}

	if (m_isFullscreen)
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Fullscreen, settings);
	}
	else
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Default, settings);
	}

	m_window->setVerticalSyncEnabled(m_isVSync);

	m_renderTexture = new sf::RenderTexture();
	m_renderTexture->create(m_size.x, m_size.y);
}

Window::~Window()
{
	delete m_window;
	delete m_renderTexture;
}

void Window::Update()
{
	if (m_view.has_value())
	{
		m_window->setView(m_view.value()->getView());
	}
	else
	{
		m_window->setView(m_window->getDefaultView());
	}

	while (m_window->pollEvent(m_event))
	{

#ifdef USING_IMGUI
		ImGui::SFML::ProcessEvent(m_event);
#endif
		if (m_event.type == sf::Event::Closed)
		{
			m_window->close();
		}

		if (m_event.type == sf::Event::Resized)
		{
			m_size = sf::Vector2i(m_event.size.width, m_event.size.height);
		}

		if (m_event.type == sf::Event::GainedFocus)
		{
			m_isFocused = true;
		}

		if (m_event.type == sf::Event::LostFocus)
		{
			m_isFocused = false;
		}

		if (m_event.type == sf::Event::KeyPressed)
		{
			if (m_event.key.code == sf::Keyboard::F11)
			{
				m_isFullscreen = !m_isFullscreen;

				if (m_isFullscreen)
				{
					m_window->create(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Fullscreen);
				}
				else
				{
					m_window->create(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Default);
				}
			}
		}
	}
}

void Window::Clear()
{
	m_window->clear();
	m_renderTexture->clear();
}

void Window::Draw(sf::Drawable& _drawable)
{
	m_renderTexture->draw(_drawable);
}

void Window::Draw(sf::Drawable& _drawable, sf::RenderStates _states)
{
	m_renderTexture->draw(_drawable, _states);
}

void Window::Draw(sf::Drawable& _drawable, sf::Shader& _shader)
{
	m_renderTexture->draw(_drawable, sf::RenderStates(&_shader));
}

void Window::Draw(sf::Drawable& _drawable, sf::Texture& _texture)
{
	m_renderTexture->draw(_drawable, sf::RenderStates(&_texture));
}

void Window::Display()
{
	Window::m_sprite.setTexture(m_renderTexture->getTexture());
	Window::m_sprite.setPosition(0.f, (float)getSize().y);
	Window::m_sprite.setScale(1.f, -1.f);
	m_window->draw(Window::m_sprite);
	m_window->display();
}

void Window::Close()
{
	m_window->close();
}

sf::Vector2f Window::getPointWindowPos(sf::Vector2i _point)
{
	return m_window->mapPixelToCoords(_point);
}

void Window::setVSync(bool _isVSync)
{
	m_isVSync = _isVSync;
	m_window->setVerticalSyncEnabled(m_isVSync);
}

void Window::setAntialiasing(bool _isAntialiasing)
{
	sf::ContextSettings settings;

	if (m_isAntialiasing)
	{
		settings.antialiasingLevel = 8;
	}
	else
	{
		settings.antialiasingLevel = 0;
	}

	if (m_isFullscreen)
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Fullscreen, settings);
	}
	else
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_size.x, m_size.y), m_title, sf::Style::Default, settings);
	}
}

void Window::setSize(sf::Vector2i _size)
{
	m_size = _size;
	m_window->setSize(sf::Vector2u(m_size.x, m_size.y));
}

void Window::setIcon(std::string _iconPath)
{
	sf::Image icon;
	icon.loadFromFile(_iconPath);
	m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
