#include "lib/raylib.h"
#include "Scenes.hpp"
#include "LuaBridge/LuaBridge.h"

#include <iostream>
#include <fstream>
   
int main()
{
    InitWindow(1280, 720, "EXCELSUS");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    SceneManagement Scene;
    
    //Entity Dev("Dev.lua");
 
    Camera3D camera;

    camera.position = (Vector3) { 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };      
    camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 45.0f;                               
    camera.projection = CAMERA_PERSPECTIVE;                  
    
    while (!WindowShouldClose())
    {
    if(Scene.DevMode)
    {
    //Dev.Update();
    }else{}
    Scene.Update();
    
    BeginDrawing();
    DrawFPS(10, 10);
    
    ClearBackground(RAYWHITE);
    Scene.DrawUI();
    BeginMode3D(camera);
    Scene.Draw3D();
    
    EndMode3D();
    
    EndDrawing();
    }
    CloseWindow();
    return 0;
}

    
    
   
    
    
    
    