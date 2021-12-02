#include "player.h"
#include <string>

class Level
{
 public:
  /* Constructors */
  //Level();
  Level(std::vector<GameObject*> * _objects , const char* _background_path);

  /* Variables */ 
  Texture2D background;
  bool isActive;
  std::vector<GameObject*> * objects;

  /* Functions */
  
  
  void Init();
  void Loop();


  
};

