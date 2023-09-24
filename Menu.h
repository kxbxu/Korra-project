#pragma once
#include "game.h"

class Menu
{
private:

	sf::RenderWindow* window;
	sf::VideoMode vm;
	sf::Event ev;

	sf::Sprite background;
	sf::Texture backgroundTex;

	sf::Font font;
	sf::Text text;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;

	int points;
	bool startgame;

	void okno();
	void pullevents();
	void StartGame();
	void Text();

public:

	Menu();

	const bool getWindowIsOpen() const;

	void Update();

	void Render();

	void PrintPoints();




};