#include "stdafx.h"
#include <SDL.h>
#include "WarMongerGame.h"

int main(int argc, char* argv[])
{
	WarMongerGame game;

	game.run_no_pipeline();

	return 0;
}