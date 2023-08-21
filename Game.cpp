#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
}

void Game::initvindow()
{
	this->videomode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videomode, "Korra", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initVariables();
	this->initvindow();
}

Game::~Game()
{ 
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {

	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();



	this->window->display();
}


