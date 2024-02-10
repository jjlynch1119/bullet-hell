#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

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

    player = new GameObject("assets/Ships/ship_0010.png", 0, 0);
    enemy = new GameObject("assets/Ships/ship_0009.png", 10, 10);
    map = new Map();

    newPlayer.addComponent<PositionComponent>();
    newPlayer.getComponent<PositionComponent>().setPos(500, 500);
    
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
    player->update();
    enemy->update();
    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().x() << ", ";
    std::cout << newPlayer.getComponent<PositionComponent>().y() << "\n";
}

void Game::render()
{
    SDL_RenderClear(renderer);

    //this is where we would add stuff to render
    map->drawMap();
    player->render();
    enemy->render();

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