#pragma once


#include<iostream>
#include <vector>
#include <string>
#include <map>

#include "lib/raylib.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#include "Events.hpp"


enum DrawTypes
{
    _MODEL,
    _MODELEX,
    _TEXTURE,
};

class Entity
{
private:
std::vector<lua_State*> Scripts;

DrawTypes _DrawType{_MODEL};

Vector3 Position3D {0, 0, 0};
Vector2 Position2D {0, 0};
    
std::string Asset{"test"};

//used during the update function to pass the lua state to extenal functions if needed
long long unsigned ScriptIndex{};

public:
void Update();
void AddScript(std::string file);
void AddScript(lua_State* state);
lua_State* GetScript(int index){return Scripts[index];}

std::string GetAsset();
void SetAsset(std::string _Asset);

std::function<void(std::string)> _setAsset = std::bind(&Entity::SetAsset, this, std::placeholders::_1);

Vector3 GetPosition3D();
Vector3 SetPosition3D();

Vector2 GetPosition2D();
Vector2 SetPosition2D();

DrawTypes GetDrawType();
DrawTypes SetDrawType();

Entity(std::string file = "entity.lua");


//event functions
void RegisterListener(std::string Event);
void DeregisterListener(std::string Event);

void CallEvent(std::string Event);

std::function<void(std::string)> _RegisterListener = std::bind(&Entity::RegisterListener, this, std::placeholders::_1);
std::function<void(std::string)> _DeregisterListener = std::bind(&Entity::DeregisterListener, this, std::placeholders::_1);

std::function<void(std::string)> _CallEvent = std::bind(&Entity::CallEvent, this, std::placeholders::_1);

};