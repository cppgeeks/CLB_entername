#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

typedef struct {
    int         x;
    int         y;
    int         z;
    int         t;
} pos_project;///position of text;


class Work{

    public :

                            Work();
            virtual         ~Work();
    private :

            void            DrawText(SDL_Renderer* renderer, TTF_Font* font, std::string str, pos_project pos );
                                   



} 