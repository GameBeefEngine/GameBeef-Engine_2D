# GameBeef Engine 2D
### by MonoGames Studio and Hallette Games


## Building:
Open solution with VS2017 and press build, repository containes example ( main.cpp ),

## Creating first game

Create main.cpp file in engine solution,
and include ```engine.h``` file

```cpp
#include "engine.h"
```
After, create main method, where we create window, and draw cube, that can walk, using arrow keys
```cpp

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("Engine Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
		,512,512,
		SDL_WINDOW_OPENGL);

	while (true)
	{
		// Get the next event
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				// Break out of the loop on quit
				break;
			}
		}
	}
}

```