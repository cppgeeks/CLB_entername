#include "Work.h"

Work::Work(){   

}


////draw text input
Work::DrawText(SDL_Renderer* renderer, TTF_Font* font, std::string str, pos_project pos ){

     SDL_Color white = {255,255,255};
    
    auto surfaceMessage = TTF_RenderText_Solid(font, str.c_str(), white);

    auto Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect;

    Message_rect.x      =           pos.x;
    Message_rect.y      =           pos.y;
    Message_rect.w      =           pos.z;
    Message_rect.h      =           pos.t;

    SDL_RenderCopy(renderer, Message, nullptr, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}



Work::~Work(){

}