#include "Scenes.hpp"
#include <iostream>

SceneManagement::SceneManagement()
{
    CreateState();
    egg.RegisterModel("test", "assets/test2.obj", "null");
    CreateEntity("entity3D.lua");
}

void SceneManagement::Update()
{
for(long long unsigned int i{}; i < SceneEntitys[state].size(); i++)
{
SceneEntitys[state][i].Update();
}
}

void SceneManagement::Draw3D()
{
for(long long unsigned int i{}; i < SceneEntitys[state].size(); i++)
{
   switch (SceneEntitys[state][i].GetDrawType())
   {
   case _MODEL:
    DrawModel(egg.GetModel(SceneEntitys[state][i].GetAsset()), SceneEntitys[state][i].GetPosition3D(), 1, WHITE);
    break;
   case _MODELEX:
    DrawModelEx(egg.GetModel(SceneEntitys[state][i].GetAsset()), SceneEntitys[state][i].GetPosition3D(), (Vector3){0, 0, 0}, 0, (Vector3){1, 1, 1}, WHITE);
    break;
   default:
    break;
   }
}
}
void SceneManagement::DrawUI()
{

}
void SceneManagement::Draw2D()
{

}
    
//
//DEV FUNCTIONS
//

void SceneManagement::CreateState()
{
SceneEntitys.emplace_back();
}

void SceneManagement::CreateEntity(std::string file = "entity3D.lua")
{
SceneEntitys[state].emplace_back(file);
}



