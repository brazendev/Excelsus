#include "Events.hpp"

Events::Events()
{
    
}

void Events::RegisterListener(std::string Event, lua_State*& Listener)
{
EventListeners[Event].push_back(Listener);
}

void Events::DeregisterListener(std::string Event, lua_State*& Listener)
{
for(long long unsigned int i{}; i < EventListeners[Event].size(); i++)
{
if(EventListeners[Event][i] == Listener)
{
    EventListeners[Event].erase(EventListeners[Event].begin()+i);
}
}
}

void Events::CallEvent(std::string Event)
{
    if(EventListeners[Event].empty()){return;}
    
    for(long long unsigned int i{}; i < EventListeners[Event].size(); i++)
    {
        luabridge::LuaRef event = luabridge::getGlobal(EventListeners[Event][i], Event.data());
        event();
    }
    

}
