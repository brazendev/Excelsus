#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "lua.hpp"

#include "LuaBridge/LuaBridge.h"

class Events{
public:
static void RegisterListener(std::string Event, lua_State*& Listener);
static void DeregisterListener(std::string Event, lua_State*& Listener);

static void CallEvent(std::string Event);

Events();

private:
static inline std::map<std::string, std::vector<lua_State*>> EventListeners{};

};