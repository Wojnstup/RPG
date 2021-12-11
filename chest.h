#ifndef _INTERACTABLE_H
#include "Engine/interactable.h"
#endif

class Chest : public Interactable {
 public:
  Chest(std::vector<GameObject*> * objects, int x, int y);
  void OnInteract();
  void Update();
  
  Texture2D sprite;
  struct Rectangle collider;
  struct Rectangle destination;
  //  std::vector<Vector2> points;

  bool isOpen = false;
};
