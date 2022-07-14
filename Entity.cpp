#include "Entity.hpp"

Entity::Entity(std::string file)
{
AddScript(file);

}

void Entity::Update()
{
//runs the OnUpdate function of all scripts, scripts MUST have this function 
if(!Scripts.empty())
{
 for( ; ScriptIndex < Scripts.size(); ScriptIndex++)
    {
    luabridge::LuaRef OnUpdate = luabridge::getGlobal(Scripts[ScriptIndex], "OnUpdate");
    OnUpdate();
    }
    ScriptIndex = 0;
}
}

std::string Entity::GetAsset()
{
return Asset;
}
void Entity::SetAsset(std::string _Asset)
{
Asset = _Asset;
}

DrawTypes Entity::GetDrawType()
{
return _DrawType;
}

Vector3 Entity::GetPosition3D()
{
luabridge::LuaRef Position = luabridge::getGlobal(Scripts[0], "Position");
Position3D = (Vector3)
{
Position["x"],
Position["y"],
Position["z"]
};
return Position3D;
}

Vector2 Entity::GetPosition2D()
{
return Position2D;
}

void Entity::AddScript(std::string file)
{
    Scripts.emplace_back();
    Scripts.back() = luaL_newstate(); 
    luaL_openlibs(Scripts.back());
    
    
    luabridge::getGlobalNamespace(Scripts.back())
            .addFunction("IsKeyPressed", IsKeyPressed)
            .addFunction("SetAsset", _setAsset)
            .addFunction("RegisterListener", _RegisterListener)
            .addFunction("DeregisterListener", _DeregisterListener)
            .addFunction("CallEvent", _CallEvent);

    luaL_dofile(Scripts.back(), file.data());
}

void Entity::AddScript(lua_State* Script)
{
luaL_openlibs(Script);
Scripts.push_back(Script);
}

//event sytem functions
void Entity::RegisterListener(std::string Event)
{
    Events::RegisterListener(Event, Scripts[ScriptIndex]);
}

void Entity::DeregisterListener(std::string Event)
{
    Events::DeregisterListener(Event, Scripts[ScriptIndex]);
}

void Entity::CallEvent(std::string Event)
{
    Events::CallEvent(Event);
}
