#include "Print.h"


Print::Print(){

        m_Window        =        nullptr;

        m_StartScreen   =        nullptr;

       

        m_Font          =        nullptr;

        m_Renderer      =        nullptr;
  
}

///////////////Init all


void   Print::DrawWindow(){
    
    m_Window         =       nullptr;

    m_Renderer       =       nullptr;

	m_Font           =       nullptr;

	m_Surface        =       nullptr;

	m_Texture        =       nullptr;
 
	//initializes  the subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return;
	}
 
	//Initialize the truetype font API.
	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return;
	}
 
	//Create window
	m_Window = SDL_CreateWindow("What your name ?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN);
	if (m_Window == nullptr)
	{
		printf("Could not create window %s", SDL_GetError());
		return;
	}
 
	//create a renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (m_Renderer == nullptr)
	{
		printf("Could not create render %s", SDL_GetError());
		return;
	}

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}

void Print::DrawText(std::string name, pos_project pos){
    SDL_Color fg = { 243, 156, 18 };
	
	auto surface_text = TTF_RenderText_Solid(m_Font, str.c_str(), fg);
	auto texture_text = SDL_CreateTextureFromSurface(m_Renderer, surface_text);


	auto surface_name = TTF_RenderText_Solid(m_Font, name.c_str(), fg);
	auto texture_name = SDL_CreateTextureFromSurface(m_Renderer, surface_name);

	SDL_FreeSurface(surface_text);
	SDL_FreeSurface(surface_name);
 
	SDL_Rect srcRest_text,srcRest_name;
	SDL_Rect desRect_text;
	SDL_Rect desRect_name;
	TTF_SizeText(m_Font, str.c_str(), &srcRest_text.w, &srcRest_text.h);
	
	srcRest_text.x = 0;
	srcRest_text.y =  0;
 
	desRect_text.x = pos_Text.x;
	desRect_text.y = pos_Text.y;
 
	desRect_text.w = srcRest_text.w;
	desRect_text.h = srcRest_text.h;
//////////////////////
	TTF_SizeText(m_Font, name.c_str(), &srcRest_name.w, &srcRest_name.h);
	srcRest_name.x = 0;
	srcRest_name.y = 0;
	
	desRect_name.x = pos_Name.x;
	desRect_name.y = pos_Name.y;

	desRect_name.w = srcRest_name.w;
	desRect_name.h = srcRest_name.h;
 
	//set background color
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);


    // clear the window to black
    SDL_RenderClear(m_Renderer);
	//Copy a portion of the texture to the current rendering target.
	SDL_RenderCopy(m_Renderer, texture_text, &srcRest_text, &desRect_text);
	SDL_RenderCopy(m_Renderer, texture_name, &srcRest_name, &desRect_name);
	//draw to screen
	SDL_RenderPresent(m_Renderer);
    
}



void Print::Run(){

    DrawWindow();
    
	m_Font = TTF_OpenFont("Font//arial.ttf", 30);
    SDL_StartTextInput();//start text input

	//main loop
	while (isRunning)
	{
		bool renderText = false;
		//main event
		while( SDL_PollEvent( &mainEvent ) != 0 )
				{
					//User requests quit
					if( mainEvent.type == SDL_QUIT )
					{
						return;
					}
					//Special key input
					else if( mainEvent.type == SDL_KEYDOWN )
					{
						//Handle backspace
						if( mainEvent.key.keysym.sym == SDLK_BACKSPACE && m_Name.length() > 0 )
						{
							//lop off character
							m_Name.pop_back();
							renderText = true;
						}
						//Handle copy
						else if( mainEvent.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
						{
							SDL_SetClipboardText( m_Name.c_str() );
						}
						//Handle paste
						else if( mainEvent.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
						{
							m_Name = SDL_GetClipboardText();
							renderText = true;
						}
					}
					//Special text input event
					else if( mainEvent.type == SDL_TEXTINPUT )
					{
						//Not copy or pasting
						if( !( ( mainEvent.text.text[ 0 ] == 'c' || mainEvent.text.text[ 0 ] == 'C' ) && ( mainEvent.text.text[ 0 ] == 'v' || mainEvent.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
						{
							//Append character
							m_Name += mainEvent.text.text;
							renderText = true;
						}
					}
				}
		
		DrawText(m_Name,pos_Name);
		
	}  


}

void Print::Quit(){
    //Destroy a window.
	SDL_DestroyWindow(m_Window);
	//Destroy a renderer
	SDL_DestroyRenderer(m_Renderer);
	//Shutdown and cleanup the truetype font API.
	TTF_Quit();
	//cleans up all initialized subsystems
	SDL_Quit();
	return;
}
///destroy obj
Print::~Print(){  
}
