#include "player.h"
#include <iostream>

int main()
{
  /*Window init should be first! */
	const int screenWidth=1080;
	const int screenHeight=720;
	InitWindow(screenWidth,screenHeight, "Animations and textures");
	SetTargetFPS(60);

	std::vector<GameObject*> objects;
	Player player(&objects, 10, 500);
	//Player player2(&objects, 100, 100);

	Texture2D background = LoadTexture("./Sprites/background.png");
	
	while(!WindowShouldClose())
	{
	  BeginDrawing();
	     ClearBackground(Color{41,135,1});

		 DrawTextureTiled(
						  background,
						  Rectangle{
							0,0,540,360
						  },
						  Rectangle{
							0,0,1080,720
						  },
						  Vector2{0,0},
						  0.0f,
						  2.0f,
						  WHITE
						  );
		 
		 for( GameObject * object : objects )
		 {
			 object->Update();
		 }

	  EndDrawing();
	}

	CloseWindow();
}
