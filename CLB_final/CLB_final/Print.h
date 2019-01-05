#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

typedef struct {
    int         x;
    int         y;    
} pos_project;///position of text;


class Print{
    
    
    public:

            Print();

            virtual         ~Print();

            void            Run(); 

            void            Quit();

    private:

            bool            Init();

            bool            Loadmedia();

            void            DrawWindow();

            void            DrawText(std::string str, pos_project pos);    

            bool            m_Init;

            SDL_Window*     m_Window;

            SDL_Texture*    m_StartScreen;

            SDL_Event       m_Event;

            SDL_Renderer*   m_Renderer;

            TTF_Font*       m_Font;

            std::string     m_Name = "";  

            std::string     str="What your name ?";
            
            SDL_Surface*    m_Surface;

            pos_project     pos_Text = {200,200};

            pos_project     pos_Name = {200,300};

            bool            isRunning      =       true;

            SDL_Event       mainEvent;
            SDL_Texture*    m_Texture;
            
};