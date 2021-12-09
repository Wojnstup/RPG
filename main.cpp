#include "Engine/level.h"
#include "player.h"

int main()
{
  /*Window init should be first! */
	const int screenWidth=1080;
	const int screenHeight=720;
	InitWindow(screenWidth,screenHeight, "Animations and textures");
	SetTargetFPS(60);

	/* Objects */
	std::vector<GameObject*> objects1;

	std::vector<std::vector<Vector2>> colliders;
  
	std::vector<Vector2> polygon= {
	  Vector2{200,200},
	  Vector2{200,300},
	  Vector2{300,300},
	  Vector2{300,200}
	};
	
	std::vector<Vector2> treeLine = {
	  Vector2{0,240},
	  Vector2{1080,240}
	};
	
  
	colliders.push_back(treeLine);
	colliders.push_back(polygon);
	
	Player player(&objects1, &colliders, 10, 500);
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
