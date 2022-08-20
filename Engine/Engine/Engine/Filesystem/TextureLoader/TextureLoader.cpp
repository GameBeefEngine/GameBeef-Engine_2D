#include "TextureLoader.h"

SDL_Texture * TextureLoader::loadTexture(std::string path, SDL_Renderer *gRenderer)
{
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		const SDL_MessageBoxButtonData buttons[] = {
				{ /* .flags, .buttonid, .text */        0, 0, "OK" },
		};
		const SDL_MessageBoxData messageboxdata = {
			SDL_MESSAGEBOX_INFORMATION, /* .flags */
			NULL, /* .window */
			"Engine error", /* .title */
			("Can\'t load texture %s! Error: ", path.c_str(), SDL_GetError(), "\n Press \"OK\" to close application"), /* .message */
			SDL_arraysize(buttons), /* .numbuttons */
			buttons, /* .buttons */
			NULL /* .colorScheme */
		};
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			const SDL_MessageBoxButtonData buttons[] = {
				{ /* .flags, .buttonid, .text */        0, 0, "OK" },
			};
			const SDL_MessageBoxData messageboxdata = {
				SDL_MESSAGEBOX_INFORMATION, /* .flags */
				NULL, /* .window */
				"Engine error", /* .title */
				("Can\'t create texture from %s! Error: ", path.c_str(), SDL_GetError(), "\n Press \"OK\" to close application"), /* .message */
				SDL_arraysize(buttons), /* .numbuttons */
				buttons, /* .buttons */
				NULL /* .colorScheme */
			};
			}

				//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
