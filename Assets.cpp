#include "Assets.hpp"

void Assets::RegisterModel(std::string Name, const char* file, std::string TextureName)
{
Models[Name] = LoadModel(file);
if(TextureName != "null")
SetMaterialTexture(&Models[Name].materials[0], MATERIAL_MAP_DIFFUSE, Textures[TextureName]);
}

void Assets::RegisterTexture(std::string Name, const char* file)
{
Textures[Name] = LoadTexture(file);
}
