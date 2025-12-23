#include <SDL/SDL.h>
#include <time.h>

/***
Defines
***/

#define YOURE_GAY


/***
Typedefs
***/

typedef struct character_s  {

  char*        spritepath;  //maybe
  int          x;
  int          y;
  int          dx;
  int          dy;
  SDL_Rect    *rect;
  SDL_Surface *surf;
  void*        loop; //loop delta handler thing.
  void*        next; //next character in the 'linked list'
}  character_t;
  

/***
Prototypes
***/

void setRect(SDL_Rect* p, int x, int y, int w, int h);
int  CheckCollision(SDL_Rect* a, SDL_Rect* b);
void characterInit(character_t *p, int x, int y, int w, int h, int dx, int dy, char* spritepath); 
void characterDestroy(character_t *p);
void* findLast(character_t *p);
void characterAdd(character_t *p, int x, int y, int w, int h, int dx, int dy, char* spritepath);
void characterDump(character_t *p);
void dumpList(character_t *first);
