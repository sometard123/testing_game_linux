#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <list>
#include <bullet.h>
#include <bomb.h>
using namespace std;
class reimu {
  public:
    //constructor/deconstructor

    reimu();
    ~reimu();
    //init

    void initBullets(Mix_Chunk *damage);
    void initBomb();
    void destroyBomb();
    //clear

    void clearBullet(); 
    //setters

    void setIsAlive(bool alive);
    //getters

    bool getIsAlive();
    double getX();
    double getY();
    double getHitboxX();
    double getHitboxY();
    bomb *getBomb();
    //misc
    void update();
    void draw(SDL_Renderer *renderer, SDL_Texture *texture);
    void collisionDetection();
    friend class collisionDetection;
    class reimuBullet: public bullet {
      public: 
        ~reimuBullet();
        virtual void updatePosition();
        virtual void draw(SDL_Renderer *renderer);
    };
    class reimuBomb: public bomb {
      public:
        reimuBomb(reimu *robj);
        virtual ~reimuBomb();
        virtual void updatePosition();
        virtual void draw(SDL_Renderer *renderer);
      private:
        bool onScreen;
        reimu *current;
    };
  private:
    typedef struct
    {
      double x;
      double y;
    }Hitbox;
    Hitbox h;
    const Uint8* state;
    double x;
    double y;
    double velocity;
    double diagonalVelocity;
    bool isAlive;
    list <reimu::reimuBullet*> bulletList[4];
    list <reimu::reimuBullet *>::iterator it;
    reimu::reimuBullet *bulletObject;
    bomb *bobj;
};
