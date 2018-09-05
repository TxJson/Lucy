#ifndef GAME_H
#define GAME_H

#include "GameStates.h"
#include "Player.h"
#include "Menu.h"

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Update();

	GameState myGState;
	Player myPlayer;
	Menu myMenu;

	//Accessors
	inline bool GetIsRunning() const { return this->myIsRunning; }

private:
	bool myIsRunning; //'TRUE' if game is running.
};

#endif
