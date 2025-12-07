#pragma once

#include <string>
#include <raylib.h>

class Vector2I
{
    public:
        int x;
        int y;
};

enum choice
{
    Circle,
    Pyramid,
    Cube
};

class Data
{
    public:
        Vector2I startposition = {0,0};
        Vector2I WidthHeight = {1,1};

        Texture texture = {};

        bool fill = true;
        bool center = true;
        
        choice choice;

        std::string configpath = "";

        void ExecuteConfig();

        void Execute();
};