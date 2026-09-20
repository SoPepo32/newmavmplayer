#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <iostream>

#include <vector>
#include <utility>

#include <thread>
#include <chrono>

#include <fstream>

#include "tools/tools.h"


using namespace std;

void drawF(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+4*s, x+4*s, y+4*s);
}

void drawI(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
}

void drawL(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+3*s, y+10*s);
}

void drawE(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+6*s, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+5*s, x+4*s, y+5*s);
    SDL_RenderDrawLine(renderer, x, y, x+6*s, y);
}

void drawS(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x+5*s, y, x, y);
    SDL_RenderDrawLine(renderer, x, y, x, y+5*s);
    SDL_RenderDrawLine(renderer, x, y+5*s, x+5*s, y+5*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+5*s, x+5*s, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+5*s, y+10*s);
}

void drawO(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+5*s, y+10*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+10*s, x+5*s, y);
}

void drawU(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+5*s, y+10*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+10*s, x+5*s, y);
}

void drawP(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+4*s, x+5*s, y+4*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+4*s, x+5*s, y);
}

void drawN(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x+5*s, y, x+5*s, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y+10*s);
}

void drawM(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+3*s, y+4*s);
    SDL_RenderDrawLine(renderer, x+3*s, y+4*s, x+6*s, y);
    SDL_RenderDrawLine(renderer, x+6*s, y, x+6*s, y+10*s);
}

void drawA(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x+6*s, y+5*s, x+6*s, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+5*s, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+5*s, x+6*s, y+5*s);
    SDL_RenderDrawLine(renderer, x, y+5*s, x+3*s, y);
    SDL_RenderDrawLine(renderer, x+6*s, y+5*s, x+3*s, y);
}

void drawV(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x+6*s, y, x+6*s, y+5*s);
    SDL_RenderDrawLine(renderer, x, y, x, y+5*s);
    SDL_RenderDrawLine(renderer, x+3*s, y+10*s, x, y+5*s);
    SDL_RenderDrawLine(renderer, x+3*s, y+10*s*s, x+6*s, y+5*s);
}

void draw_forward_slash(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x+3*s, y, x, y+10*s);
}

void drawY(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x+3*s, y+4*s);
    SDL_RenderDrawLine(renderer, x+6*s, y, x+3*s, y+4*s);
    SDL_RenderDrawLine(renderer, x+3*s, y+4*s*s, x+3*s, y+10*s);
}

void drawC(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x+6*s, y);
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+6*s, y+10*s);
}

void drawG(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+10*s, x+5*s, y+10*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+3*s, x+5*s, y);
    SDL_RenderDrawLine(renderer, x+5*s, y+10*s, x+5*s, y+7*s);
    SDL_RenderDrawLine(renderer, x+3*s, y+7*s, x+5*s, y+7*s);
}

void drawR(SDL_Renderer* renderer, int x, int y, int s) {
    SDL_RenderDrawLine(renderer, x, y, x, y+10*s);
    SDL_RenderDrawLine(renderer, x, y, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+4*s, x+5*s, y+4*s);
    SDL_RenderDrawLine(renderer, x+5*s, y+4*s, x+5*s, y);
    SDL_RenderDrawLine(renderer, x, y+4*s, x+5*s, y+10*s);
}

class menu_up {
    private:
        int s;
    
    public:
        menu_up(int scale) {
            s = scale;
        }

        void drawConfig(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // C
            drawC(renderer,x*s,y,s);
            // O
            drawO(renderer,x+10*s,y,s);
            // N
            drawN(renderer,x+19*s,y,s);
            // F
            drawF(renderer,x+28*s,y,s);
            // I
            drawI(renderer,x+37*s,y,s);
            // G
            drawG(renderer,x+42*s,y,s);
        
            SDL_RenderDrawLine(renderer, std::round(83*s+20),0,std::round(83*s+20),std::round(19*s/2+10));
        }

        void drawColor(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // C
            drawC(renderer,x*s,y,s);
            // O
            drawO(renderer,x+10*s,y,s);
            // L
            drawL(renderer,x+19*s,y,s);
            // O
            drawO(renderer,x+26*s,y,s);
            // R
            drawR(renderer,x+35*s,y,s);
        
            SDL_RenderDrawLine(renderer, std::round(83*s+20),0,std::round(83*s+20),std::round(19*s/2+10));
        }

        void drawGeneral(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // G
            drawG(renderer,x*s,y,s);
            // E
            drawE(renderer,x+9*s,y,s);
            // N
            drawN(renderer,x+19*s,y,s);
            // E
            drawE(renderer,x+29*s,y,s);
            // R
            drawR(renderer,x+38*s,y,s);
            // A
            drawA(renderer,x+47*s,y,s);
            // L
            drawL(renderer,x+57*s,y,s);
        
            SDL_RenderDrawLine(renderer, std::round(83*s+20),0,std::round(83*s+20),std::round(19*s/2+10));
        }

        void menu_config(SDL_Renderer* renderer){
            SDL_Rect rect = {36*s+10, 10*s + 10, 60*s + 10, 10*s + 10 + s*20};
            SDL_Rect rect_a = {36*s+10, 10*s + 10, 60*s + 10, 10*s + 10};
            SDL_Rect rect_b = {36*s+10, 20*s + 20, 60*s + 10, 10*s + 10};
            SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect_a);
            SDL_RenderDrawRect(renderer, &rect_b);
            drawColor(renderer, rect.x+5,rect.y+5);
            drawGeneral(renderer, rect.x+5,rect.y+25);
        }

        void drawFiles(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // F
            drawF(renderer,x,y,s);
            // I
            drawI(renderer,x+8*s,y,s);
            // L
            drawL(renderer,x+12*s,y,s);
            // E
            drawE(renderer,x+20*s,y,s);
            // S
            drawS(renderer,x+31*s,y,s);

            SDL_RenderDrawLine(renderer, std::round(36*s+10),0,std::round(36*s+10),std::round(19*s/2+10));
        }

        void menu_files(SDL_Renderer* renderer){
            SDL_Rect rect = {0, 10*s + 10, 92*s + 10, 10*s + 10 + s*20};
            SDL_Rect rect_a = {0, 10*s + 10, 92*s + 10, 10*s + 10};
            SDL_Rect rect_b = {0, 20*s + 20, 92*s + 10, 10*s + 10};
            SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect_a);
            SDL_RenderDrawRect(renderer, &rect_b);
            drawOpen(renderer, 5,rect.y+5);
            drawSave_Configuration(renderer, 5,rect.y+25);
        }

        void drawOpen(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // O
            drawO(renderer,x,y,s);
            // P
            drawP(renderer,x+9*s,y,s);
            // E
            drawE(renderer,x+18*s,y,s);
            // N
            drawN(renderer,x+28*s,y,s);
        }

        void drawSave_Configuration(SDL_Renderer* renderer, int x, int y) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // S
            drawS(renderer,x,y,s);
            // A
            drawA(renderer,x+9*s,y,s);
            // V
            drawV(renderer,x+19*s,y,s);
            // E
            drawE(renderer,x+29*s,y,s);
            // Space
            // C
            drawC(renderer,x+45*s,y,s);
            // O
            drawO(renderer,x+55*s,y,s);
            // N
            drawN(renderer,x+64*s,y,s);
            // F
            drawF(renderer,x+73*s,y,s);
            // I
            drawI(renderer,x+82*s,y,s);
            // G
            drawG(renderer,x+87*s,y,s);
        }
};

class menu_below {
    private:
        int s;
    
    public:
        menu_below(int scale) {
            s = scale;
        }

        void drawLoop(SDL_Renderer* renderer, int x, int y, bool Y_N) {
            SDL_Rect rect_a = {x-5*s, y-7*s, 58*s, 24*s};
            SDL_RenderDrawRect(renderer, &rect_a);
            // L
            drawL(renderer,x,y,s);
            // O
            drawO(renderer,x+7*s,y,s);
            // O
            drawO(renderer,x+16*s,y,s);
            // P
            drawP(renderer,x+25*s,y,s);

            // Check
            SDL_Rect rect_b = {x+34*s, y-2*s, 14*s, 14*s};
            if (Y_N) {
                SDL_RenderFillRect(renderer, &rect_b);
            } else {
                SDL_RenderDrawRect(renderer, &rect_b);
            }
        }

        void drawVolume(SDL_Renderer* renderer, int x, int y, int volume) {
            SDL_Rect rect_c = {x-5*s, y-10*s, 65*s, 45*s};
            SDL_RenderDrawRect(renderer, &rect_c);

            // V
            drawV(renderer,x,y,s);
            // O
            drawO(renderer,x+10*s,y,s);
            // L
            drawL(renderer,x+19*s,y,s);
            // U
            drawU(renderer,x+26*s,y,s);
            // M
            drawM(renderer,x+35*s,y,s);
            // E
            drawE(renderer,x+45*s,y,s);

            SDL_Rect rect_a = {x, y+15*s, 52*s, 10*s};
            SDL_RenderDrawRect(renderer, &rect_a);
            SDL_Rect rect_b = {x, y+15*s, volume*s, 10*s};
            SDL_RenderFillRect(renderer, &rect_b);
        }

        void drawPlayPause(SDL_Renderer* renderer, int x, int y) {
            SDL_Rect rect = {x-5*s, y-5*s, 99*s, 20*s};
            SDL_RenderDrawRect(renderer, &rect);

            // P
            drawP(renderer,x,y,s);
            // L
            drawL(renderer,x+9*s,y,s);
            // A
            drawA(renderer,x+18*s,y,s);
            // Y
            drawY(renderer,x+28*s,y,s);
            // /
            draw_forward_slash(renderer,x+38*s,y,s);
            // P
            drawP(renderer,x+45,y,s);
            // A
            drawA(renderer,x+54*s,y,s);
            // U
            drawU(renderer,x+64*s,y,s);
            // S
            drawS(renderer,x+73*s,y,s);
            // E
            drawE(renderer,x+83*s,y,s);
        }

        void draw_advance(SDL_Renderer* renderer, int x, int y) {
            SDL_Rect rect = {x-5*s, y-5*s, 20*s, 20*s};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_RenderDrawLine(renderer, x, y+5*s, x+10*s, y+5*s);
            SDL_RenderDrawLine(renderer, x+7*s, y, x+10*s, y+5*s);
            SDL_RenderDrawLine(renderer, x+7*s, y+10*s, x+10*s, y+5*s);
        }

        void draw_back(SDL_Renderer* renderer, int x, int y) {
            SDL_Rect rect = {x-5*s, y-5*s, 20*s, 20*s};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_RenderDrawLine(renderer, x, y+5*s, x+10*s, y+5*s);
            SDL_RenderDrawLine(renderer, x, y+5*s, x+3*s, y);
            SDL_RenderDrawLine(renderer, x, y+5*s, x+3*s, y+10*s);
        }

        void draw_after(SDL_Renderer* renderer, int x, int y) {
            SDL_Rect rect = {x-5*s, y-5*s, 80*s, 20*s};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_RenderDrawLine(renderer, x, y+5*s, x+70*s, y+5*s);
            SDL_RenderDrawLine(renderer, x+67*s, y, x+70*s, y+5*s);
            SDL_RenderDrawLine(renderer, x+67*s, y+10*s, x+70*s, y+5*s);
        }

        void draw_before(SDL_Renderer* renderer, int x, int y) {
            SDL_Rect rect = {x-5*s, y-5*s, 80*s, 20*s};
            SDL_RenderDrawRect(renderer, &rect);

            SDL_RenderDrawLine(renderer, x, y+5*s, x+70*s, y+5*s);
            SDL_RenderDrawLine(renderer, x, y+5*s, x+3*s, y);
            SDL_RenderDrawLine(renderer, x, y+5*s, x+3*s, y+10*s);
        }
};

bool pointInPolygon(int x, int y, const std::vector<std::pair<int,int>>& vertices) {
    bool dentro = false;
    int n = vertices.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        int xi = vertices[i].first, yi = vertices[i].second;
        int xj = vertices[j].first, yj = vertices[j].second;

        bool intersecta = ((yi > y) != (yj > y)) &&
                          (x < (xj - xi) * (y - yi) / (double)(yj - yi) + xi);
        if (intersecta) dentro = !dentro;
    }
    return dentro;
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* ventana = SDL_CreateWindow("NewMaVMPlayer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_Event evento;
    bool corriendo = true;

    int scale = 1;
    //int i = 0;

    int volume = 19; // range 0->52

    bool mfiles = false;
    bool mconfig = false;
    bool Loop_Y_N = false;
    bool PlayPause_Y_N = true;

    menu_up MenuUp(scale);
    menu_below MenuBelow(scale);


    SDL_Rect rect_up = {0, 0, 640, 10*scale+10};
    SDL_Rect rect_files = {0, 0, 35*scale+10, 10*scale+10};
    SDL_Rect rect_loop = {0, 455-7*scale, 58*scale, 24*scale};
    SDL_Rect rect_down = {0, 480-(20*scale+20), 640, 20*scale+20};
    SDL_Rect rect_volume = {584, 450+15*scale, 52*scale, 10*scale};
    SDL_Rect rect_config = {35*scale+10, 0, 35*scale+10, 10*scale+10};
    SDL_Rect rect_pp = {252-5*scale, 445-10*scale, 65*scale, 45*scale};

    while (corriendo) {
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_QUIT) corriendo = false;

            if (evento.type == SDL_MOUSEBUTTONDOWN) {
                std::cout << "Click presionado en ("
                          << evento.button.x << ", "
                          << evento.button.y << ")" << std::endl;
                
                int x = evento.button.x;
                int y = evento.button.y;

                if (x >= rect_up.x && x <= rect_up.x + rect_up.w &&
                    y >= rect_up.y && y <= rect_up.y + rect_up.h) {
                    std::cout << "Click dentro del rectángulo B" << std::endl;
                }

                if (x >= rect_down.x && x <= rect_down.x + rect_down.w &&
                    y >= rect_down.y && y <= rect_down.y + rect_down.h) {
                    std::cout << "Click dentro del rectángulo A" << std::endl;
                }

                if (x >= rect_files.x && x <= rect_files.x + rect_files.w &&
                    y >= rect_files.y && y <= rect_files.y + rect_files.h) {
                    std::cout << "Click dentro de files" << std::endl;
                    mfiles = !mfiles;
                } else if (mfiles) {
                    mfiles = false;
                }

                if (x >= rect_config.x && x <= rect_config.x + rect_config.w &&
                    y >= rect_config.y && y <= rect_config.y + rect_config.h) {
                    std::cout << "Click dentro de config" << std::endl;
                    mconfig = !mconfig;
                } else if (mconfig) {
                    mconfig = false;
                }

                if (x >= rect_loop.x && x <= rect_loop.x + rect_loop.w &&
                    y >= rect_loop.y && y <= rect_loop.y + rect_loop.h) {
                    std::cout << "Click dentro de loop" << std::endl;
                    Loop_Y_N = !Loop_Y_N;
                }

                if (x >= rect_pp.x && x <= rect_pp.x + rect_pp.w &&
                    y >= rect_pp.y && y <= rect_pp.y + rect_pp.h) {
                    std::cout << "Click dentro de play/pause" << std::endl;
                    PlayPause_Y_N = !PlayPause_Y_N;
                }

                if (x >= rect_volume.x && x <= rect_volume.x + rect_volume.w &&
                    y >= rect_volume.y && y <= rect_volume.y + rect_volume.h) {
                    std::cout << "Click dentro de volume" << std::endl;
                    volume = x - rect_volume.x;
                    std::cout << "nuevo volumen: " << volume << std::endl;
                }
            }

            if (evento.type == SDL_MOUSEBUTTONUP) {
                std::cout << "Click liberado en ("
                          << evento.button.x << ", "
                          << evento.button.y << ")" << std::endl;
            }
        }
        // Fondo negro
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // amarillo
        SDL_RenderFillRect(renderer, &rect_down); // rectángulo relleno

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect_down);
        
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // amarillo
        SDL_RenderFillRect(renderer, &rect_up); // rectángulo relleno

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect_up);

        MenuUp.drawFiles(renderer, 5,5);
        MenuUp.drawConfig(renderer, 5+std::round(36*scale+10),5);
        
        MenuBelow.drawLoop(renderer, 5, 455, Loop_Y_N);
        MenuBelow.drawVolume(renderer, 584, 450, volume);
        MenuBelow.drawPlayPause(renderer, 252, 445);
        MenuBelow.draw_advance(renderer, 361, 445);
        MenuBelow.draw_back(renderer, 222, 445);
        MenuBelow.draw_after(renderer, 301, 465);
        MenuBelow.draw_before(renderer, 222, 465);

        if (mfiles) {
            MenuUp.menu_files(renderer);
        }

        if (mconfig) {
            MenuUp.menu_config(renderer);
        }

        SDL_RenderPresent(renderer);
        // this_thread::sleep_for(chrono::milliseconds(10));
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}