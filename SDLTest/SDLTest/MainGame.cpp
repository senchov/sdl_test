//
//  MainGame.cpp
//  SDLTest
//
//  Created by Андрей Сеньчов on 3/2/17.
//  Copyright © 2017 Андрей Сеньчов. All rights reserved.
//

#include "MainGame.hpp"
#include <iostream>
#include <string>

void fatalError (std::string errorString)
{
    std::cout << errorString << std::endl;
    std::cout << "`enter any key to quit..." << std::endl;
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
}

MainGame::MainGame ()
{
    _window = nullptr;
    _screenWidth = 512;
    _screenHeight = 512;
    _gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run ()
{
    initSystem();
    
    gameLoop();
}

void MainGame::initSystem()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    _window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    if (_window == nullptr)
    {
        fatalError("SDC window could not be created");
    }
    
    SDL_GLContext glContex = SDL_GL_CreateContext(_window);
    if (glContex == nullptr)
    {
        fatalError("SDL_GL contex could not be created");
    }
    
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        fatalError("Could not itialize glew");
    }
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    glClearColor(0.0f, 0, 1.0f, 1.0f);
}

void MainGame::gameLoop()
{
    while (_gameState != GameState::EXIT) {
        processInput();
        drawGame();
    }
}

void MainGame::processInput()
{
    SDL_Event evnt;
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                break;
                
            default:
                break;
        }
    }
    
}

void MainGame::drawGame()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnableClientState(GL_COLOR_ARRAY);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(0,0);
    glVertex2f(0, 250);
    glVertex2f(250, 250);
    glEnd();
    
    
    SDL_GL_SwapWindow(_window);
}
