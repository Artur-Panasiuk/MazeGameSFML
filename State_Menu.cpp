#include "State_Menu.h"
#include "StateManager.h"

State_Menu::State_Menu(StateManager * lStateManager)
	:BaseState(lStateManager)
{
}

State_Menu::~State_Menu()
{
}

void State_Menu::OnCreate(){
	if (!TMainMenuBackground.loadFromFile("img/MainMenuPlaceHolder.png")) {
		std::cout << "Could not find img/MainMenu.png\n";
	}
	else {
		SMainMenuBackground.setTexture(TMainMenuBackground);
	}

	if (!MainFont.loadFromFile("fonts/bahnschrift.ttf")) {
		std::cout << "Could not find fonts/bahnschrift.ttf\n";
	}
	else {
		//This is catastrophicaly bad, but it will do for now
		play.setFont(MainFont);
		play.setString(">PLAY<");
		play.setCharacterSize(30);
		play.setPosition(sf::Vector2f(120.0, 170.0));

		credits.setFont(MainFont);
		credits.setString(">CREDITS<");
		credits.setCharacterSize(30);
		credits.setPosition(sf::Vector2f(100.0, 220.0));

		exit.setFont(MainFont);
		exit.setString(">EXIT<");
		exit.setCharacterSize(30);
		exit.setPosition(sf::Vector2f(126.0, 320.0));

	}
}

void State_Menu::OnDestroy()
{
}

void State_Menu::Activate()
{
}

void State_Menu::Deactivate()
{
}

void State_Menu::Draw(){
	mStateManager->GetContext()->mWindow->Draw(SMainMenuBackground);
	mStateManager->GetContext()->mWindow->Draw(play);
	mStateManager->GetContext()->mWindow->Draw(credits);
	mStateManager->GetContext()->mWindow->Draw(exit);
}

void State_Menu::Update(const sf::Time & lTime)
{
}
