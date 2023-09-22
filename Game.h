#ifndef GAME_H
#define GAME_H


#include <map>
#include "Player.h"
#include "Water.h"
#include "Earth.h"
#include "Fire.h"
#include "Air.h"
#include "CommonEnemy.h"
#include "FastEnemy.h"
#include "SpeedsterEnemy.h"
#include "BossEnemy.h"

class Game
{
private:

	//Window
	sf::RenderWindow* window; 

	// enum class
	ProjectileType currentProjectile = ProjectileType::None;

	// projectiles cotainer
	std::vector<Projectiles*> projectiles;

	//Resources
	std::map<std::string,sf::Texture*> textures;

	//Player
	Player* player;	 

	
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


	//Private functions
	void initwindow();
	void initTexture();

	void initPlayer();
	void initEnemies();

	void spawnAsset();

public:
	//constructor and destructor
	Game(); 
	virtual ~Game();

	//functions

	void run();

	void updatePollEvents();
	void updateInput();
	void updateProjectiles();
	void updateEnemies();
	void updateCombat();
	void update();
	void render();
};

#endif // !GAME_H