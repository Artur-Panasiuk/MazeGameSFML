#pragma once
#include "BaseState.h"

class State_Maze : public BaseState
{
public:
	State_Maze(StateManager* lStateManager);
	~State_Maze();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Draw();
	void Update(const sf::Time& lTime);
private:
};