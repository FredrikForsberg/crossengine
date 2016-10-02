#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer);
	
	SDL_Surface *img = IMG_Load("res/pngtest/fan.png");
	if (!img) {
		printf("IMG_GetError: %s\n", IMG_GetError());
		return -1;
	}
	SDL_Rect dest    = {.x = 100, .y = 100, .w = 320, .h = 320};
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, img);
	SDL_RenderCopy (renderer, tex, NULL, &dest);
	SDL_DestroyTexture (tex);
	SDL_FreeSurface (img);
		
	SDL_RenderPresent(renderer);
	printf("you should see an fan.\n");
	return 0;
}

