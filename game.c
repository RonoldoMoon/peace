#include "game.h"

void setRect(SDL_Rect* p, int x, int y, int w, int h)  {

  p->x = x;
  p->y = y;
  p->w = w;
  p->h = h;
}

/* AI is for poopsters */
int CheckCollision(SDL_Rect* a, SDL_Rect* b)  {  //but helps you learn if you so choose. ;)

    // If any of the sides from a are outside of b
    if ( (a->y + a->h)   <= (b->y)        )  return 0; 
    if ( (a->y)          >= (b->y + b->h) )  return 0; 
    if ( (a->x + a->w)   <= (b->x)        )  return 0; 
    if ( (a->x)          >= (b->x + b->w) )  return 0; 

    // If none of the sides from a are outside b
    return 1;
}


void characterInit(character_t *p, int x, int y, int w, int h, int dx, int dy, char* spritepath)  {

  //p->id = (int)time();
  p->spritepath = spritepath;
  p->x  = x;  //maybe dont need these x and y.
  p->y  = y;
  p->dx = dx;
  p->dy = dy;
  p->rect = malloc(sizeof(SDL_Rect));  //some handling here too I guess.
  p->rect->x = x;                    //could have used setRect() ;P
  p->rect->y = y;
  p->rect->w = w;
  p->rect->h = h;
  p->surf = SDL_LoadBMP(spritepath);  //add some error handling here.
  p->loop = 0;                        //for now. to ba a function pointer.
  p->next = 0;                        //initial and for last in the list.
}

void characterDestroy(character_t *p)  {

  free(p->rect);
  SDL_FreeSurface(p->surf);
  free(p);
}

void* findLast(character_t *p)  {

  void* ref;

  while((ref = p->next)) if(ref) p = ref;  //find last in the list
  
  return p;
}

void characterAdd(character_t *p, int x, int y, int w, int h, int dx, int dy, char* spritepath)  {

  character_t* q = findLast(p);
  
  q->next = malloc(sizeof(character_t));
  
  characterInit(q->next, x, y, w, h, dx, dy, spritepath);
}

void characterDump(character_t *p)  {

  printf("path: %s\n", p->spritepath);
  printf("x: %d\n"   , p->x   );
  printf("y: %d\n"   , p->y   );
  printf("dx: %d\n"  , p->dx  );
  printf("dy: %d\n"  , p->dy  );
  putchar(10);
}

void dumpList(character_t *p)  {  //first element in t he list

  //could add find first here later. dont exist yet.
  
  void* ref;

  while((ref = p->next))  {
  
    characterDump(p);
    if(ref) p = ref; 
  }
}
  
