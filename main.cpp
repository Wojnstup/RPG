#include "player.h"

int main()
{
  /*Window init should be first!*/
	const int screenWidth=1080;
	const int screenHeight=720;
	InitWindow(screenWidth,screenHeight, "Animations and textures");
	SetTargetFPS(60);
	
	Player player;

	while(!WindowShouldClose())
	{
	  BeginDrawing();
	     ClearBackground(Color{94,3,119});
	     //player.DrawSprite(playerX/*+=5*/,100);
		 player.Move();
		 
		 
	  EndDrawing();
	}

	CloseWindow();
}
