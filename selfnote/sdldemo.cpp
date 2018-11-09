#include <SDL2/SDL.h>
/**
 * @brief main
 *sdl的示例程序，展示sdl库的基本用法
 * @return
 */
int main()
{
    SDL_Window* window =0;
    SDL_Renderer* render=0;
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("hello",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
    render=SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(render,0,255,0,255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    return 0;
}
