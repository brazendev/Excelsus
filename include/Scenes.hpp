#pragma once

#include <vector>
#include <map>
#include <functional>
#include <string>
#include <iostream>
#include "Entity.hpp"
#include "lib/raylib.h"
#include "Assets.hpp"

//states are scenes, like levels
class SceneManagement
{
public:
SceneManagement();

void Draw3D();
void DrawUI();
void Draw2D();

void Update();
void ChangeState();

//Developer Functions
void CreateState();

void CreateEntity(std::string file);

bool DevMode{true};

static inline int state{};
private:
Assets egg{};



std::vector<std::vector<Entity>> SceneEntitys;
};