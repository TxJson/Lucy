#ifndef GAME_H
#define GAME_H

#include "GameStates.h"
#include "Player.h"
#include "World.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();
	void MainMenu();

	Player myPlayer;
	GameState myGState;
	World myWorld;

	int myCho;

	//Accessors
	inline bool GetIsRunning() const { return this->myIsRunning; }

private:
	bool myIsRunning; //'TRUE' if game is running.
};

#endif