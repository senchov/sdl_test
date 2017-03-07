//
//  MainGame.hpp
//  SDLTest
//
//  Created by Андрей Сеньчов on 3/2/17.
//  Copyright © 2017 Андрей Сеньчов. All rights reserved.
//

#pragma once
#ifndef MainGame_hpp
#define MainGame_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

enum class GameState {PLAY,EXIT};

class MainGame
{
public:
    MainGame();
    ~MainGame ();
    
    void run ();
    
    
private:
    void initSystem();
    void processInput();
    void gameLoop();
    void drawGame();
    
    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;
};

#endif /* MainGame_hpp */
