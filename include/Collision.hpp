#include <map>
#include <string>
#include <vector>
#include "lib/raylib.h"

class Collision{
public:
bool BoundingBoxCollision(BoundingBox Box, std::string Group);
bool RectangleCollision(Rectangle Rectangle, std::string Group);

void RegisterBoundingBox(BoundingBox& Box, std::string Group);
void RegisterRectangle(Rectangle& Rectangle, std::string Group);

private:
std::map<std::string, std::map<int, std::vector<BoundingBox>>> BoundingBoxCollisionGroups{};
std::map<std::string, std::map<int, std::vector<Rectangle>>> RectangleCollisionGroups{};

};