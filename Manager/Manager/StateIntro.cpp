#include "StateIntro.h"
#include "StateMachine.hpp"

namespace StateIntro
{
    sf::Sprite spriteIntro;
    sf::Sprite spriteIntroAnim;
    sf::Texture textureIntro;
    sf::Texture textureIntroAnim;
    sf::IntRect rectIntro(0, 0, 912, 1080);

    bool canDrawNoAnimIntro = true;
}

void StateIntro::Init()
{
	textureIntro.loadFromFile("../Ressources/Textures/logo_ga.png");
	textureIntroAnim.loadFromFile("../Ressources/Textures/logo_ga_anim.png");
	spriteIntro.setTexture(textureIntro);
	spriteIntroAnim.setTexture(textureIntroAnim);
	spriteIntroAnim.setTextureRect(rectIntro);
}

void StateIntro::Update()
{
    static float timerAnim = 0.f;
    static int frame = 0;
    static float fadeTimer = 0.f;  
    static bool fadingIn = true;   
    static bool fadingOut = false; 
    static float timeBetweenFades = 4.5f; 
    static float fadeDelay = 0.f;

    static float timerIntroToMenu = 0.f;

    timerAnim += getDeltaTime();
    fadeTimer += getDeltaTime();
    fadeDelay += getDeltaTime();
    timerIntroToMenu += getDeltaTime();



    if (fadingIn)
    {
        if (fadeTimer < 2.f)
        {
            float alpha = fadeTimer * 127.5f;
            spriteIntroAnim.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
        }
        else
        {
            if (fadeDelay > 2.f && fadeDelay < 3.8f)
            {
                canDrawNoAnimIntro = false;
                if (timerAnim > 0.2f)
                {
                    frame++;
                    frame = frame % 4;
                    rectIntro.left = rectIntro.width * frame;
                    spriteIntroAnim.setTextureRect(rectIntro);
                    timerAnim = 0;
                }

                if (fadeDelay > 3.38f)
                    canDrawNoAnimIntro = true;
            }
            if (fadeDelay >= timeBetweenFades)
            {
                fadingIn = false;
                fadingOut = true; 
                fadeTimer = 0.f;  
                fadeDelay = 0.f;  
            }
        }
    }

    if (fadingOut)
    {
        if (fadeTimer < 2.f) 
        {
            float alpha = 255 - (fadeTimer * 127.5f);
            spriteIntroAnim.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
        }
        else
        {
            fadeTimer = 0.f;
            fadingIn = true;
            fadingOut = false; 
            StateMachine::ChangeState(MENU);
        }
    }
}



void StateIntro::Display(sf::RenderWindow& _window)
{
    _window.draw(spriteIntro);

    if (!canDrawNoAnimIntro)
    {
        spriteIntroAnim.setPosition(_window.getSize().x / 2 - 456, _window.getSize().y / 2 - 540);
        _window.draw(spriteIntroAnim);
    }
    else
    {
        _window.draw(spriteIntro);
    }
        
}

void StateIntro::DeInit()
{
}

