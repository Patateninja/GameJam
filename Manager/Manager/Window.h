#pragma once
#include "tools.h"

class View;

class View;

class Window
{
	private:
		sf::RenderWindow* m_window;
		std::optional<View*> m_view;
		inline static sf::Sprite m_sprite;
		std::string m_title;
		sf::Event m_event;
		sf::Vector2i m_size;
		bool m_isFullscreen;
		bool m_isVSync;
		bool m_isFocused;
		bool m_isAntialiasing;
	public:
		Window(std::string _title, sf::Vector2i _size, bool _isFullscreen = false, bool _isVSync = false, bool _isAntialiasing = false);
		Window(const char* _title, sf::Vector2i _size, bool _isFullscreen = false, bool _isVSync = false, bool _isAntialiasing = false);
		~Window();

		void Update();
		void Clear();
		void Draw(sf::Drawable& _drawable);
		void Draw(sf::Drawable& _drawable, sf::RenderStates _states);
		void Draw(sf::Drawable& _drawable, sf::Shader& _shader);
		void Draw(sf::Drawable& _drawable, sf::Texture& _texture);
		void Display();
		void Close();

		inline bool isOpen() { return m_window->isOpen(); }
		inline bool isFocused() { return m_isFocused; }
		inline bool isFullscreen() { return m_isFullscreen; }
		inline bool isVSync() { return m_isVSync; }
		inline bool isAntialiasing() { return m_isAntialiasing; }
		inline bool hasView() { return m_view.has_value(); }
	
		inline View* getView() { return m_view.value(); }
		inline void setView(View* _view) { m_view = _view; }
		inline void resetView() { m_view.reset(); }

		inline sf::Vector2i getSize() { return m_size; }
		inline sf::Vector2f getPointWindowPos(sf::Vector2i _point);
		inline sf::RenderWindow* getWindow() { return m_window; }

		inline void setFullscreen(bool _isFullscreen) { m_isFullscreen = _isFullscreen; }
		inline void setVSync(bool _isVSync);
		inline void setAntialiasing(bool _isAntialiasing);
		inline void setSize(sf::Vector2i _size);
		inline void setIcon(std::string _iconPath);
};

