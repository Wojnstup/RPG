#include "raylib.h"
#include "gameObject.h"


class Interactable : public GameObject {
 public:
  void OnInteract();
  std::vector<Vector2> collider;
};
