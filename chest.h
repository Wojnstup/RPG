#ifndef _INTERACTABLE_H
#include "Engine/interactable.h"
#endif

#ifndef _TEXTBOX_H
#include "textbox.h"
#endif

class Chest : public Interactable {
 public:
  Chest(std::vector<GameObject*> * objects, int x, int y, TextBox * _textBox);
  void OnInteract();
  void Update();
  Texture2D sprite;
  struct Rectangle collider;
  struct Rectangle destination;


  TextBox * textBox;
  bool messege = false;
  bool isOpen = false;
};
