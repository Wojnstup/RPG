#include "gameObject.h"
#include <string>


class Level
{
 public:
  /* Constructors */
  //Level();
  Level(
		std::vector<GameObject*> * _objects,
		const char* _background_path,
		Camera2D * _camera
		);

  /* Variables */ 
  Texture2D background;
  bool isActive;
  std::vector<GameObject*> * objects;
  Camera2D * camera;

  /* Functions */
  
  
  void Init();
  void Loop();


  
};

