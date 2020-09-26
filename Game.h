#pragma once
#include "Window.h"
#include "SharedContext.h"
#include "StateManager.h"

class Game
{
public:
	Game();
	~Game();

	bool IsDone();

	void Draw();
	void Update();
	void LateUpdate();

	sf::Time GetElapsed();

	Window* GetWindow();
private:
	void RestartClock();

	sf::Clock mClock;
	sf::Time mElapsed;
	Window mWindow;
	StateManager mStateManager;
	SharedContext mContext;
};