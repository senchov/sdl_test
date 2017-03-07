//
//  main.cpp
//  SDLTest
//
//  Created by Андрей Сеньчов on 1/23/17.
//  Copyright © 2017 Андрей Сеньчов. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "MainGame.hpp"


int main(int argc, const char * argv[]) {
    //SDL_Init(SDL_INIT_EVERYTHING);
    MainGame mainGame;
    mainGame.run();
    
}
