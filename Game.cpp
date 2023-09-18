#include "Game.h"




void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Korra", sf::Style::Close | sf::Style::Titlebar);
	//this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTexture()
{

}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initwindow();
	this->initTexture();
	this->initPlayer();

}

Game::~Game()
{ 
	delete this->window;
	delete this->player;

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}
}


void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
		
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed) {
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {  //close the window by pressing "escape"
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	//Mvve player and animation

	sf::Clock clock;

	float deltaTime = clock.restart().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->player->move(-1.f, 0.f, deltaTime);
		this->player->animationLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->player->move(1.f, 0.f, deltaTime);
		this->player->animationRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->player->move(0.f, -1.f, deltaTime);
		this->player->animationUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->player->move(0.f, 1.f, deltaTime);
		this->player->animationDown();
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
}

void Game::render()
{
	this->window->clear();

	//draw all all stuffs
	this->player->render(*this->window);


	this->window->display();
}


