#include "Collision.hpp"
#include "lib/raymath.h"

#include "Scenes.hpp"


bool Collision::BoundingBoxCollision(BoundingBox Box, std::string Group)
{
for(long long unsigned int i{}; i < BoundingBoxCollisionGroups[Group][SceneManagement::state].size(); i++)
{
if(&Box == &BoundingBoxCollisionGroups[Group][SceneManagement::state][i])
{
continue;
}
if(CheckCollisionBoxes(Box, BoundingBoxCollisionGroups[Group][SceneManagement::state][i]))
{
return true;
}   
}
return false;
}

bool Collision::RectangleCollision(Rectangle Rectangle, std::string Group)
{

for(long long unsigned int i{}; i < RectangleCollisionGroups[Group][SceneManagement::state].size(); i++)
{
if(&Rectangle == &RectangleCollisionGroups[Group][SceneManagement::state][i])
{
continue;
}

if(CheckCollisionRecs(Rectangle, RectangleCollisionGroups[Group][SceneManagement::state][i]))
{
return true;
}   
}
return false;

}

void Collision::RegisterBoundingBox(BoundingBox& Box, std::string Group)
{
BoundingBoxCollisionGroups[Group][SceneManagement::state].push_back(Box);
}
void Collision::RegisterRectangle(Rectangle& Rectangle, std::string Group)
{
RectangleCollisionGroups[Group][SceneManagement::state].push_back(Rectangle);
}