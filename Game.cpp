#include "Game.h"




void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1000,750), "Korra", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTexture()
{
	this->textures["WATER"] = new sf::Texture();
	this->textures["WATER"]->loadFromFile("Water.png");
	

	this->textures["EARTH"] = new sf::Texture();
	this->textures["EARTH"]->loadFromFile("Stone.png");

	this->textures["FIRE"] = new sf::Texture();
	this->textures["FIRE"]->loadFromFile("Fire.png");

	this->textures["AIR"] = new sf::Texture();
	if (!this->textures["AIR"]->loadFromFile("Air.png")) {
		std::cout << "errrrorreroe!!" << std::endl;
	}

	this->textures["COMMONENEMY"] = new sf::Texture();
	this->textures["COMMONENEMY"]->loadFromFile("commonenemy.png");

	this->textures["FASTENEMY"] = new sf::Texture();
	this->textures["FASTENEMY"]->loadFromFile("fastenemy.png");

	this->textures["SPEEDSTER"] = new sf::Texture();
	this->textures["SPEEDSTER"]->loadFromFile("speedster.png");

	this->textures["BOSS"] = new sf::Texture();
	this->textures["BOSS"]->loadFromFile("boss.png");

	this->textures["CRATE"] = new sf::Texture();
	this->textures["CRATE"]->loadFromFile("crate.png");

	this->textures["HEART"] = new sf::Texture();
	this->textures["HEART"]->loadFromFile("heart.png");

}

void Game::initPlayer()
{
	this->player = new Player(this->window->getSize().x/2,this->window->getSize().y/2);      //spawn on the middle of window *left, top edge of sprite*
}

void Game::initEnemies()
{
	this->Check_vector = 5;             //check actual amount of enemies vector after 4s
	this->mobsNumberMax = 30;           // max amount of mobs on the map
	this->mobsNumberMin = 10;             // minimal amount of mobs on the map
	this->elaped_check = Check_vector;    
	this->Change_number = 20;             //time after amount of enemies will be changed
	this->elapsed_number = 0;
	this->mobsNumberActual = this->mobsNumberMin;
}

void Game::spawnAsset()
{
	

	while (enemies.size() < mobsNumberActual) {
		int type;
		int x;
		int y;
		do {
			x = rand() % this->window->getSize().x + 1;
			y = rand() % this->window->getSize().y + 1;
		} 
		while (abs(x-player->getPos().x)<300 && abs(y - player->getPos().y) < 300);           //rand position at least 300 pixels from player
		type = rand() % 100+1;          //rand type of enemy
		if (type < 70) {
			enemies.emplace_back(new CommonEnemy(this->textures["COMMONENEMY"],x,y,this->player->getPos().x, this->player->getPos().y));
		}
		else if (type >= 70 && type < 90) {
			enemies.emplace_back(new FastEnemy(this->textures["FASTENEMY"], x, y,this->player->getPos().x, this->player->getPos().y));
		}
		else if (type >= 90) {
			enemies.emplace_back(new SpeedsterEnemy(this->textures["SPEEDSTER"], x, y,this->player->getPos().x, this->player->getPos().y));
		}
	}

}

Game::Game()
{
	this->initwindow();
	this->initTexture();
	this->initPlayer();
	this->initEnemies();

}

Game::~Game()
{ 
	delete this->window;
	delete this->player;

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}
	for (auto* i : this->projectiles) {
		delete i;
	}

	for (auto* i : this->enemies) {
		delete i;
	}
}


void Game::run()
{
	sf::Clock clock;
	while (this->window->isOpen()) {
		this->ElapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();
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

	// player elapsed time

	player->timeChecking();

	//Move player and animation          

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (player->getBounds().left > 0) {
			this->player->move(-1.f, 0.f);
		}
		this->player->animationLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (player->getBounds().left + player->getBounds().width < this->window->getSize().x) {
			this->player->move(1.f, 0.f);
		}
		this->player->animationRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if (player->getBounds().top > 0) {
			this->player->move(0.f, -1.f);
		}
		this->player->animationUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (player->getBounds().top + player->getBounds().height < this->window->getSize().y) {
			this->player->move(0.f, 1.f);
		}
		this->player->animationDown();
	}

	//selecting type of projectiles
	//water
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
		this->currentProjectile = ProjectileType::Water;
	}
	//earth
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
		this->currentProjectile = ProjectileType::Earth;
	}
	//fire
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
		this->currentProjectile = ProjectileType::Fire;
	}
	//air
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
		this->currentProjectile = ProjectileType::Air;
	}

	//Projetiles
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);       // using for dirX and dirY arguments
		float mouseX = static_cast<float>(mousePosition.x);
		float mouseY = static_cast<float>(mousePosition.y);

		switch (currentProjectile)
		{
		case ProjectileType::Water:
			if (mouseX != player->getPos().x && mouseY != this->player->getPos().y) {                     // 3rd case posx and posy are the same as a direction
				if (player->getWater()) {
					projectiles.emplace_back(new Water(this->textures["WATER"], this->player->getPos().x, this->player->getPos().y, mouseX, mouseY));
					player->isLoadedW();
				}	
			}
			break;

		case ProjectileType::Earth:
			if (mouseX != player->getPos().x && mouseY != this->player->getPos().y) {
				if (player->getEarth()) {
					projectiles.emplace_back(new Earth(this->textures["EARTH"], this->player->getPos().x, this->player->getPos().y, mouseX, mouseY));
					player->isLoadedE();
				}
			}	
			break;

		case ProjectileType::Fire:
			if (mouseX != player->getPos().x && mouseY != this->player->getPos().y) {
				if (player->getFire()) {
					projectiles.emplace_back(new Fire(this->textures["FIRE"], this->player->getPos().x, this->player->getPos().y, mouseX, mouseY));
					player->isLoadedF();
				}
			}
			break;

		case ProjectileType::Air:
			if (mouseX != player->getPos().x && mouseY != this->player->getPos().y) {
				if (player->getAir()) {
					projectiles.emplace_back(new Air(this->textures["AIR"], this->player->getPos().x, this->player->getPos().y, mouseX, mouseY));
					player->isLoadedA();
				}		
			}
			break;

		default:
			break;
		} 
		
	}

}

void Game::updateProjectiles()
{
	unsigned counter=0;
	for (auto* projectile : this->projectiles) {
		projectile->update(this->ElapsedTime);

		//projectile culling 
		if (projectile->getBounds().top + projectile->getBounds().height < 0.f) {

			//delete projectiles by using erase method and iterator-counter
			delete this->projectiles.at(counter);
			this->projectiles.erase(this->projectiles.begin()+counter);
			--counter;
		}

		else if (projectile->getBounds().left + projectile->getBounds().width < 0.f) {
			delete this->projectiles.at(counter);
			this->projectiles.erase(this->projectiles.begin() + counter);
			--counter;
		}

		else if (projectile->getBounds().top > this->window->getSize().y) {
			delete this->projectiles.at(counter);
			this->projectiles.erase(this->projectiles.begin() + counter);
			--counter;
		}

		else if (projectile->getBounds().left> this->window->getSize().x) {
			delete this->projectiles.at(counter);
			this->projectiles.erase(this->projectiles.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateEnemies()
{
	//spawn mobs to keep actual number of mobs
	if (this->elaped_check >= this->Check_vector) {
		this->spawnAsset();
		elaped_check = 0;
	}
	else {
		elaped_check += ElapsedTime;
	}

	//changing actual number of mobs
	if (this->elapsed_number >= this->Change_number) {
		mobsNumberActual = rand() % (this->mobsNumberMax - this->mobsNumberMin + 1) + this->mobsNumberMin;
		elapsed_number = 0;
	}
	else {
		elapsed_number += ElapsedTime;
	}

	// removing enemy being out of screen size +100

	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update(ElapsedTime, this->player->getPos().x, this->player->getPos().y);

		//enemy culling 
		if (enemy->getBounds().top + enemy->getBounds().height < -100.f) {

			//delete projectiles by using erase method and iterator-counter
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		else if (enemy->getBounds().left + enemy->getBounds().width < -100.f) {
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		else if (enemy->getBounds().top > this->window->getSize().y + 100) {
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		else if (enemy->getBounds().left > this->window->getSize().x + 100) {
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		//checking hp

		else if (!enemy->isAlive()) {
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < enemies.size(); ++i) {
		for (size_t k = 0; k < this->projectiles.size(); k++) {
			if (this->enemies[i]->getBounds().intersects(this->projectiles[k]->getBounds())) {
				//mob losing hp
				this->enemies[i]->LoseHp(this->projectiles[k]->getDamage());

				//mobs getting efects and most of projectile is going to be destroyed
				if (Fire* fire = dynamic_cast<Fire*>(projectiles[k])) {
					this->enemies[i]->is_burn();
					delete this->projectiles[k];
					this->projectiles.erase(this->projectiles.begin() + k);
				}

				else if (Earth* earth = dynamic_cast<Earth*>(projectiles[k])) {
					this->enemies[i]->is_slowness();
				}

				else if (Air* air = dynamic_cast<Air*>(projectiles[k])) {
					this->enemies[i]->is_knockback();
					//delete this->projectiles[k];
					//this->projectiles.erase(this->projectiles.begin() + k);
				}

				else if (Water* water = dynamic_cast<Water*>(projectiles[k])) {
					delete this->projectiles[k];
					this->projectiles.erase(this->projectiles.begin() + k);
				}

			}
		}
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateProjectiles();
	this->updateEnemies();
	this->updateCombat();
}

void Game::render()
{
	this->window->clear();

	//draw all all stuffs
	this->player->render(*this->window);

	for (auto* projectile : this->projectiles) {
		projectile->render(this->window);
	}

	for (auto *enemy : this->enemies) {
		enemy->render(this->window);
	}

	this->window->display();
}


