#include "raylib.h"
#define _COLLISIONS_H


bool CheckCollisionRecLine(struct Rectangle rec, struct Vector2 lineStart, struct Vector2 lineEnd)
{
  struct Vector2 points[] =
	{
	  Vector2{rec.x,             rec.y},
	  Vector2{rec.x,             rec.y + rec.height},
	  Vector2{rec.x + rec.width, rec.y + rec.height},
	  Vector2{rec.x + rec.width, rec.y}
	};

	struct Vector2 collisionPoint;

	for (int i=0; i<4; i++)
	  {
		if(
		   CheckCollisionLines(
							   lineStart,
							   lineEnd,
							   points[i],
							   points[(i+1)%4],
							   &collisionPoint
                               )
		)
		{
			return true;
		}
	  }
	return false;
}

