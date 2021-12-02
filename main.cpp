//#include "player.h"
//#include <iostream>
#include "level.h"


int main()
{
  /*Window init should be first! */
	const int screenWidth=1080;
	const int screenHeight=720;
	InitWindow(screenWidth,screenHeight, "Animations and textures");
	SetTargetFPS(60);

	/* Objects */
	std::vector<GameObject*> objects1;
	Player player(&objects1, 10, 500);

	//Texture2D background = LoadTexture("./Sprites/background.png");
	
	/* Level Init*/

	Level level1(&objects1, "./Sprites/background.png");
	level1.Init();
	
	//while(!WindowShouldClose())
	//{
	//ClearBackground(Color{41,135,1});
	level1.Loop();
	  /*
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
	  */
	  //}

	CloseWindow();
}
