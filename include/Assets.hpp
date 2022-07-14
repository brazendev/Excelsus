#pragma once

#include <map>
#include <string>
#include "lib/raylib.h"

class Assets{
    public:
    void RegisterModel(std::string Name, const char* file, std::string TextureName);
    void RegisterTexture(std::string Name, const char* file);
    
    Model GetModel(std::string Name){return Models[Name];}
    Texture GetTexture(std::string Name){return Textures[Name];}
    
    private:
    std::map<std::string, Model> Models;
    std::map<std::string, Texture> Textures;
};