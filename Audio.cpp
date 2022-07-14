#include "Audio.hpp"

void Audio::_PlaySound(std::string name)
{
PlaySound(SoundMap[name]);
}
void Audio::PlayMusic(std::string name)
{
PlayMusicStream(MusicMap[name]);
}


void Audio::RegisterSound(std::string name, const char* file)
{
SoundMap[name] = LoadSound(file);
}
void Audio::RegisterMusic(std::string name, const char* file)
{
MusicMap[name] = LoadMusicStream(file);
}