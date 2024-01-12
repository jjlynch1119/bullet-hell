#include "Game.hpp"

Game::Game()
{
    
}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING == 0))
    {
        std::cout <<"Subsystems Initialized...\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "Renderer created!\n";
        }

        isRunning = true;
    }  
    else
    {
        isRunning = false;
    }
}

void Game::handleEvents()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::clean()
{
    
}

bool Game::running()
{
    return isRunning;
}