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

bool CheckCollisionPolyLine(Vector2 lineStart, Vector2 lineEnd, std::vector<Vector2> pol)
{
	struct Vector2 collisionPoint;
	for (int i=0; i<pol.size(); i++)
	  {
		if(
		   CheckCollisionLines(
							   lineStart,
							   lineEnd,
							   pol[i],
							   pol[(i+1)%pol.size()],
							   &collisionPoint
                               )
		)
		{
			return true;
		}
	  }
	return false;
  
}

bool CheckCollisionRecPoly(struct Rectangle rec, std::vector<Vector2> pol, int &lineIndex)
{
  for(int i=0; i < pol.size() - 1; i++)
	{
	  if(CheckCollisionRecLine(rec,pol[i],pol[i+1]))
		{
		  lineIndex=1;
		  return true;
		}
	}
  
  if(CheckCollisionRecLine(rec,pol[pol.size()-1],pol[0]))
	{
	  lineIndex = pol.size();
	  return true;
	}

  return false;
}


void CheckCollisionRecColliders(struct Rectangle &rec, struct Vector2 speed, std::vector<std::vector<Vector2>> colliders)
{
  int lineIndex;
  for(std::vector<Vector2> collider : colliders)
	{
	  if( CheckCollisionRecPoly(rec, collider, lineIndex ))
		rec.x = rec.x - speed.x;
	  
	  if( CheckCollisionRecPoly(rec, collider, lineIndex ))
		{
		  rec.x = rec.x + speed.x;
		  rec.y = rec.y - speed.y;
		}
	  
	  if( CheckCollisionRecPoly(rec, collider, lineIndex ))
		rec.x = rec.x - speed.x;

	  
	}

}

std::vector<Vector2> RecToPoints(struct Rectangle rec){
  std::vector<Vector2> points= {
	Vector2{rec.x,             rec.y},
	Vector2{rec.x,             rec.y + rec.height},
	Vector2{rec.x + rec.width, rec.y + rec.height},
	Vector2{rec.x + rec.width, rec.y}
  };
  return points;
}
