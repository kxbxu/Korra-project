#ifndef GAME_H
#define GAME_H


#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "Air.h"
#include "CommonEnemy.h"
#include "FastEnemy.h"
#include "SpeedsterEnemy.h"
#include "BossEnemy.h"
#include "Heart.h"
#include "Bomb.h"
#include "Crate.h"

class Game
{
private:

	//Window
	sf::RenderWindow* window; 

	// enum class
	ProjectileType currentProjectile = ProjectileType::None;

	// projectiles container
	std::vector<Projectiles*> projectiles;

	//Resources
	std::map<std::string,sf::Texture*> textures;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameOverText;
	sf::Text winText;

	//World
	sf::Sprite WorldBackground;
	sf::Texture worldBackgroundTex;	

	//system
	unsigned points;


	//Crate
	std::vector<Loot*> crates;
	float lootTime;
	float elapsed_loot;

	//Player
	Player* player;	 

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	//global time
	float ElapsedTime;


	//Enemies
	 int mobsNumberMax;
	 int mobsNumberMin;
	 int mobsNumberActual;
	 float Check_vector ;
	 float elaped_check;   
	 float Change_number;
	 float elapsed_number;
	std::vector<Enemy*> enemies;

	//Enemies wave 
	float waveTime;           //initialization in Initenemies()
	float elapsed_wave;
	bool spawn_boss;
	//checking win
	bool Boss_isAlive;

	
	//private functions->wave
	void updatewave();
	bool is_wave();



	//Private functions
	void initwindow();
	void initTexture();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();
	void initCrates();

	void spawnAsset();
	void spawnCrate();

public:
	//constructor and destructor
	Game(); 
	virtual ~Game();

	//Acessor
	const int getPoints() const;

	//functions

	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateProjectiles();
	void updateEnemies();
	void updateCrates();
	void updateCombat();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
};

#endif // !GAME_H