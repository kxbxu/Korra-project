#include "Menu.h"

Menu::Menu()
{
	this->okno();
	this->startgame = false;
	this->Text();

}

void Menu::pullevents()
{

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (ev.key.code == sf::Keyboard::Enter)
				this->startgame = true;
		}

	}
}

void Menu::StartGame()
{
	if (startgame)
	{
		Game game;
		game.run();
		points = game.getPoints();
	}
	startgame = false;
}

void Menu::Text()
{

	font.loadFromFile("Fonts/AlexandriaFLF.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setString("Press Enter to start the game");
	text.setPosition(this->window->getSize().x / 2.f - this->text.getGlobalBounds().width / 2.f, 70);


	font.loadFromFile("Fonts/AlexandriaFLF.ttf");
	text1.setFont(font);
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::Green);
	text1.setString("Score: 0");
	text1.setPosition(this->window->getSize().x / 2.f - this->text1.getGlobalBounds().width / 2.f, 500);
	text1.setOutlineThickness(1);


	font.loadFromFile("Fonts/AlexandriaFLF.ttf");
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setFillColor(sf::Color::Green);
	text2.setString("Press Escape to exit the window");
	text2.setPosition(this->window->getSize().x / 2.f - this->text2.getGlobalBounds().width / 2.f, this->window->getSize().y-50);
	//text2.setOutlineThickness(1);

	font.loadFromFile("Fonts/AlexandriaFLF.ttf");
	text3.setFont(font);
	text3.setCharacterSize(24);
	text3.setFillColor(sf::Color::Black);
	text3.setString("W - move up \nS - move down \nA - move left \nD - move right\nleft mouse button - attack \n1 - Water attack \n2 - Earth attack \n3 - Fire attack \n4 - Air attack");
	text3.setPosition(this->window->getSize().x / 2.f , 140);
	text3.setOutlineThickness(0.5);

	backgroundTex.loadFromFile("background_m.png");
	background.setTexture(backgroundTex);
}



void Menu::Update()
{
	this->pullevents();
	this->StartGame();
	this->PrintPoints();
	
}

void Menu::Render()
{
	this->window->clear(sf::Color::Black);
	this->window->draw(background);
	this->window->draw(text);
	this->window->draw(text1);
	this->window->draw(text2);
	this->window->draw(text3);
	this->window->display();
}

void Menu::PrintPoints()
{
	text1.setString("Score: " + std::to_string(points));
}

void Menu::okno()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Menu", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

const bool Menu::getWindowIsOpen() const
{
	return this->window->isOpen();
}

