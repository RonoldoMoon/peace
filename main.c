/*
	space invaders clone written with SDL1.2 in C
	* nov 28 2025
	* Marlow Rekers
	* Dec -  2025
	* Moon
*/

#include "game.h"

/***
DONT USE THE FRENCH VERSION OF COLOR XD
***/



int main(){
	   
    int quit    = 0;  
    int xvel, yvel, color;
    int shoot   = 0;
    int envel   = 0;    
    int atk     = 0;    
    int tvalive = 1;   
    int tvel    = 1;
     
    SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetCaption("Ailen Attack", "Ailen Attack");
	
	SDL_Surface* screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE);
	
    /*
     * color mask doesn't work yet :'(
    Uint32 colorkey = SDL_MapRGB(screen->format, 0, 0xFF, 0xFF); // Map a turquoise color
    SDL_SetColorKey(screen, SDL_SRCCOLORKEY, colorkey); 
    */
    
    //define images
    SDL_Surface* bgimage = SDL_LoadBMP("image/bg.bmp");
    SDL_Surface* player  = SDL_LoadBMP("image/jointship.bmp");
    SDL_Surface* tv      = SDL_LoadBMP("image/tv.bmp");
    
    //define position / hitbox of said images
    
    SDL_Rect rect, bg, enemy, bullet, shot;
    

    setRect(&rect,  10, 208,  32,  32);
    setRect(&bg,     0,   0, 320, 240);
    setRect(&enemy, 50,  10,  32,  32);
    setRect(&bullet, 0, 320,   4,   8);
    setRect(&shot,   0,   0,   4,   8);
    
    xvel = 0;
    yvel = 0;
    
    color = 0;
    
    SDL_Event event;
    /* Main game loop */
    /* Check for events */
    while(!quit)  {
    
    while( SDL_PollEvent( &event ))  {
    
        switch( event.type )  {
	
            case SDL_KEYDOWN:
	    
                switch( event.key.keysym.sym )  {
		
                    case SDLK_LEFT:   xvel = -4; break;
                    case SDLK_RIGHT:  xvel = 4;  break;
                    case SDLK_SPACE:  if(shoot == 0){
							shoot = 1;
							bullet.x = (rect.x + (rect.w /2));
							bullet.y = rect.y;
                                                    }   break;
                    case SDLK_a:      if(shoot == 0){
							shoot = 1;
							bullet.x = (rect.x + (rect.w /2));
							bullet.y = rect.y;
                                                    }   break;
                    case SDLK_RETURN: quit = 1;  break;
                    default:  break;
            }
            break;
	    
            case SDL_KEYUP:
	    
                switch( event.key.keysym.sym )  {
		
                    case SDLK_LEFT:  if( xvel < 0)  xvel = 0; break;  //not realy sure why are checking this value. ZIM
                    case SDLK_RIGHT: if( xvel > 0 ) xvel = 0; break;
                    case SDLK_UP:  /* if( yvel < 0 ) yvel = 0;  */ break;
                    case SDLK_DOWN: /* if( yvel > 0 )  yvel = 0; */break;
                    default: break;
                }   break;
            
            default: break;
        }
    }
    
/***
END EVENT HANDLING
***/


                /* accumulating movment vector to position */	
		if(rect.x < (320 - rect.w)){
			rect.x += xvel;
		}
		else{
			rect.x -= 4;
		}
		
		//draw the background
		SDL_BlitSurface(bgimage, NULL, screen, &bg);

                
		if(CheckCollision(enemy, bullet)){
			tv = SDL_LoadBMP("tvc.bmp");
			tvalive = 0;
			//printf(": %d", tvalive);
		}
		
		//draw the enemy
		if(tvalive && tvalive != 3){
			if(Timeout()){
				int xdir = (rand()%50);
				int pol = (rand()%4);
				if(pol < 1)
					pol = 1;
				if(pol > 1)
					pol = -1;
				
				if(enemy.x < (320 - enemy.w)){
					enemy.x += (xdir * pol);
				}
			}
			
			SDL_BlitSurface(tv, NULL, screen, &enemy);
		}
		
		if(Timeout()){
			if(atk == 0 && tvalive != 3)
				atk = 1;
		}
		
		if(atk == 1){
			shot.x = (enemy.x + 16);
			shot.y = (enemy.y + 16);
			SDL_FillRect(screen, &shot, SDL_MapRGB(screen->format, 20, 210, 200));
			atk = 2;
		}
		if(atk == 2){
			if(shot.y < 232){
				shot.y += 2;
				if(CheckCollision(rect, shot))
					player = SDL_LoadBMP("tvc.bmp");
				SDL_FillRect(screen, &shot, SDL_MapRGB(screen->format, 20, 210, 200));
			}
			else{
				atk = 0;
			}
				
		}
		
		//draw the player
		SDL_BlitSurface(player, NULL, screen, &rect);
		
		if(tvalive == 0)
		{
			SDL_BlitSurface(tv, NULL, screen, &enemy);
			enemy.y += envel;
			if(Timeout()){
				tvalive = 3;
			}
			/*
			if(enemy.y < 240){
				envel += 2;
			}else{
				tvalive = 2;
			}
			*/
		}
		
		if(shoot){
			if(bullet.y > 0){	
				bullet.y -= 4;
				SDL_FillRect(screen, &bullet, SDL_MapRGB(screen->format, 20, 210, 200));
			}
			else{
				shoot = 0;
			}
		}
		
		
		
		
		SDL_UpdateRect(screen, 0, 0, 0, 0);
		//SDL_Flip(screen);  // for double buffer.
		SDL_Delay(1000/60);

	}
    
    SDL_FreeSurface(player);
    SDL_Quit();
    
	return 0;
 }
 
