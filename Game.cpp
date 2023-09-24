#include "Game.h"




void Game::updatewave()
{
	this->elapsed_wave += ElapsedTime;
}

bool Game::is_wave()
{
	return this->waveTime >= this->elapsed_wave;
}

void Game::initwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200,900), "Korra", sf::Style::Close | sf::Style::Titlebar);   //1000 750 def
	this->window->setPosition(sf::Vector2i(400, 50));
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

void Game::initGUI()
{
	//load font
	if (!this->font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		std::cout << "Fonts cannot be loaded" << std::endl;
	}

	//init pointtext
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(40);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setOutlineThickness(2);
	this->pointText.setString("test");
	this->pointText.setPosition(sf::Vector2f(this->window->getSize().x - 350, 0));
	
	//init game over trxt
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setOutlineThickness(5);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(sf::Vector2f(this->window->getSize().x/2.f-this->gameOverText.getGlobalBounds().width/2.f, this->window->getSize().y/2.f- this->gameOverText.getGlobalBounds().height / 2.f));
	//init wintext
	this->winText.setFont(this->font);
	this->winText.setCharacterSize(100);
	this->winText.setFillColor(sf::Color::Green);
	this->winText.setOutlineThickness(5);
	this->winText.setString("YOU WIN!");
	this->winText.setPosition(sf::Vector2f(this->window->getSize().x / 2.f - this->winText.getGlobalBounds().width / 2.f, this->window->getSize().y / 2.f - this->winText.getGlobalBounds().height / 2.f));

	// init player GUI

	this->playerHpBar.setSize(sf::Vector2f(300.f, 20.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::initWorld()
{
	this->worldBackgroundTex.loadFromFile("background.png");
	this->WorldBackground.setTexture(this->worldBackgroundTex);
	this->WorldBackground.setColor(sf::Color::Cyan);
}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player(this->window->getSize().x/2,this->window->getSize().y/2);      //spawn on the middle of window *left, top edge of sprite*
}

void Game::initEnemies()
{
	this->Check_vector = 5;             //check actual amount of enemies vector after 4s
	this->mobsNumberMax = 20;           // max amount of mobs on the map
	this->mobsNumberMin = 8;             // minimal amount of mobs on the map
	this->elaped_check = Check_vector;    
	this->Change_number = 20;             //time after amount of enemies will be changed
	this->elapsed_number = 0;
	this->mobsNumberActual = this->mobsNumberMin-2;
	//wave stuff
	this->waveTime = 90;                               //change here
	this->elapsed_wave = 0;
	this->spawn_boss = true;
	this->Boss_isAlive = true;

}

void Game::initCrates()
{
	this->lootTime = 15;
	this->elapsed_loot = this->lootTime;
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

void Game::spawnCrate()
{
	if (this->elapsed_loot >= this->lootTime) {
		std::cout << "looot nadchodzi" << "/n";
		int x;
		int y;
		do {
			x = rand() % this->window->getSize().x + 1;
			y = rand() % this->window->getSize().y + 1;
		} while (abs(x - player->getPos().x) < 200 && abs(y - player->getPos().y) < 200);        //rand position at least 200 pixels from player

		crates.emplace_back(new Crate(x, y));

		this->elapsed_loot = 0;
	}
	else {
		this->elapsed_loot += this->ElapsedTime;
	}
}

Game::Game()
{
	this->initwindow();
	this->initTexture();
	this->initWorld();
	this->initGUI();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
	this->initCrates();
}

Game::~Game()
{ 
	delete this->window;
	delete this->player;
	

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}
	//delete projectiles
	for (auto* i : this->projectiles) {
		delete i;
	}
	//delete enemies
	for (auto* i : this->enemies) {
		delete i;
	}
	//delete crates
	for (auto* i : this->crates) {
		delete i;
	}
}

const int Game::getPoints() const
{
	return this->points;
}


void Game::run()
{
	sf::Clock clock;
	while (this->window->isOpen()) {
		this->ElapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		this->updatePollEvents();

		if (this->player->isAlive()&&this->Boss_isAlive) {
			this->update();
		}
		
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

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points : " << this->points;
	this->pointText.setString(ss.str());

	//update player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f * player->getHp() / player->getHpMax(), this->playerHpBar.getSize().y));
	//this->player->LoseHp(0.1f); testing
}

void Game::updateWorld()
{
	//may be used in the future 
}

void Game::updateCollision()
{
	for (int i = 0; i < enemies.size(); ++i) {
		
		if (this->enemies[i]->getBounds().intersects(this->player->getBounds())) {

			if (SpeedsterEnemy* speedster = dynamic_cast<SpeedsterEnemy*>(enemies[i])) {
				this->player->LoseHp(enemies[i]->getDmg());
				enemies[i]->LoseHp(enemies[i]->getMaxHp());
			}
			else {
				this->player->LoseHp(enemies[i]->getDmg());
			}
		}
	}
	//crate loots effects
	for (int i = 0; i < crates.size(); ++i) {
		if (this->crates[i]->getBounds().intersects(this->player->getBounds())) {
			if (dynamic_cast<Heart*>(crates[i])) {                                         ///add hp
				this->player->addHp(150.f);
				delete this->crates[i];
				this->crates.erase(this->crates.begin() + i);
			}
			else if (dynamic_cast<Bomb*>(crates[i])) {
				if (is_wave()) {
					this->enemies.clear();
				}													 //clear map out of enemies(but not boss)  until next vector checking (4s)                                              
				delete this->crates[i];
				this->crates.erase(this->crates.begin() + i);
			}
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

		//destroying crate
		for (int k = 0; k < crates.size();k++) {
			if (projectile->getBounds().intersects(crates[k]->getBounds())) {
				if (dynamic_cast<Crate*>(crates[k])) {
					int l = rand() % 2;
					if (l == 0) {
						crates.emplace_back(new Heart(crates[k]->getPos().x, crates[k]->getPos().y));
					}
					else
					{
						crates.emplace_back(new Bomb(crates[k]->getPos().x, crates[k]->getPos().y));
					}
					delete this->crates[k];
					this->crates.erase(this->crates.begin() + k);

				}
			}
		}
	}
}

void Game::updateEnemies()
{
	//spawn mobs to keep actual number of mobs during wave
	if (this->is_wave()) {
		if (this->elaped_check >= this->Check_vector) {
			this->spawnAsset();
			elaped_check = 0;
		}
		else {
			elaped_check += ElapsedTime;
		}
	}
	else if (this->spawn_boss) {
		this->spawn_boss = false;
		this->enemies.clear();
		this->enemies.emplace_back(new BossEnemy(this->textures["BOSS"], this->window->getSize().x / 2, this->window->getSize().y / 2, this->player->getPos().x, this->player->getPos().y));
	}

	//changing actual number of mobs
	if (this->elapsed_number >= this->Change_number) {
		mobsNumberActual = rand() % (this->mobsNumberMax - this->mobsNumberMin + 1) + this->mobsNumberMin;
		elapsed_number = 0;
	}
	else {
		elapsed_number += ElapsedTime;
	}

	// removing enemy being out of screen size +100  and enemies with <=0 hp

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
			if (BossEnemy* boss = dynamic_cast<BossEnemy*>(enemy)) {
				this->Boss_isAlive = false;
			}
			this->points += enemy->getPoints();    //if enemy is killed by our projectile player get points(enemy being put of screen don't give us points!)
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
			
		}

		++counter;
	}
}

void Game::updateCrates()
{
	this->spawnCrate();
}

void Game::updateCombat()
{
	for (int i = 0; i < enemies.size(); ++i) {
		//collision with players
		if (this->enemies[i]->getBounds().intersects(this->player->getBounds())) {
			this->enemies[i]->LoseHp(this->player->getDamage());
		}
		//collision with projectiles
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
					if (BossEnemy* boss = dynamic_cast<BossEnemy*>(enemies[i])) {         //Boss dont get many knockbacks - only 1 
						this->enemies[i]->is_knockback();
						delete this->projectiles[k];
						this->projectiles.erase(this->projectiles.begin() + k);
					}

					else {
						this->enemies[i]->is_knockback();
					}
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
	this->updateInput();
	this->player->update();
	this->updateProjectiles();
	this->updateEnemies();
	this->updateCrates();
	this->updateCombat();
	this->updateCollision();
	this->updateGUI();
	this->updateWorld();
	this->updatewave();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

}

void Game::renderWorld()
{
	this->window->draw(WorldBackground);
}

void Game::render()
{
	this->window->clear();

	//draw world
	this->renderWorld();

	//draw all all stuffs
	this->player->render(*this->window);

	for (auto* projectile : this->projectiles) {
		projectile->render(this->window);
	}

	for (auto *enemy : this->enemies) {
		enemy->render(this->window);
	}

	for (auto* crate : this->crates) {
		crate->render(this->window);
	}

	this->renderGUI();

	if (!player->isAlive()) {
		this->window->draw(this->gameOverText);
	}

	if (!Boss_isAlive) {
		this->window->draw(this->winText);
	}

	this->window->display();
}


