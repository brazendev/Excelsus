#pragma once

#include <map>
#include <string>

#include "lib/raylib.h"

class Audio
{
public:

void _PlaySound(std::string name);
void RegisterSound(std::string name, const char* file);

void PlayMusic(std::string name);
void RegisterMusic(std::string name, const char* file);

private:
std::map<std::string, Sound> SoundMap;
std::map<std::string, Music> MusicMap;
};