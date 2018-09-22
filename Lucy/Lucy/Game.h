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

	static Player& GPlayer;
	static World& GWorld;

	int myCho;

	//Accessors
	inline bool GetIsRunning() const { return this->myExecutionFlag; }

private:
	GameState myGState;
	bool myExecutionFlag; //'TRUE' if game is running.
};

#endif