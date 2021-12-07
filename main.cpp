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
	Camera2D camera = {0};
	camera.target = player.position;
	camera.offset = Vector2{screenWidth/2,screenHeight/2};
	camera.rotation = 0.0f;
	camera.zoom=1.0f;
	

	
	/* Level Init*/

	Level level1(&objects1, "./Sprites/background.png", &camera);
	level1.Init();
	
	level1.Loop();

	CloseWindow();
}
