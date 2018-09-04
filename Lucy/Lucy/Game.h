#ifndef GAME_H
#define GAME_H

#include "GameStates.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();
	int myCho; //My Choice
	GameState myGState;
	Player myPlayer;

	//Accessors
	inline bool GetIsRunning() const { return this->myIsRunning; }

private:
	bool myIsRunning; //'TRUE' if game is running.
};

#endif
