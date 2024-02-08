#include "Game.hpp"

int cnt;
SDL_Texture* playerTex;
SDL_Rect srcR, destR;

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

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized!...\n";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!\n";
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    SDL_Surface* tmpSurface = IMG_Load("assets/Ships/ship_0010.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update()
{
    cnt++;

    destR.h = 64;
    destR.w = 64;
    destR.x = cnt;

    std::cout << cnt << "\n";
}

void Game::render()
{
    SDL_RenderClear(renderer);

    //this is where we would add stuff to render
    SDL_RenderCopy(renderer, playerTex, nullptr, &destR);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned\n";
}

bool Game::running()
{
    return isRunning;
}