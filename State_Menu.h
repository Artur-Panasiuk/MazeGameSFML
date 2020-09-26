#pragma once
#include "BaseState.h"

class State_Menu : public BaseState
{
public:
	State_Menu(StateManager* lStateManager);
	~State_Menu();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Draw();
	void Update(const sf::Time& lTime);
private:
	sf::Texture TMainMenuBackground;
	sf::Sprite SMainMenuBackground;

	sf::Font MainFont;

	sf::Text play;
	sf::Text credits;
	sf::Text exit;
};