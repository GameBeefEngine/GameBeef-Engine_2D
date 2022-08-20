#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#pragma once
class TextureLoader
{
public:
	SDL_Texture * loadTexture(std::string path, SDL_Renderer * gRenderer);
};

