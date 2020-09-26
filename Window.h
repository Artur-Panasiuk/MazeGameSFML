#pragma once
#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Window
{
	void Open();
	void Close();

	bool mIsDone;
	bool mIsFullscreen;
	sf::RenderWindow mWindow;
	EventManager mEventManager;
public:
	Window();
	~Window();

	bool IsDone();

	void Draw(const sf::Drawable &lSprite);
	void BeginDrawing();
	void EndDrawing();
	void ToggleFullscreen();
	void EndProgram();

	void Update();

	EventManager* GetEventManager();
};