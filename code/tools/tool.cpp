#include "tools.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> tools::split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(s.substr(start));

    return tokens;
}


std::vector<std::pair<std::string, bool>> tools::folder_contents(const std::string& folder) {
    std::vector<std::pair<std::string, bool>> content;

    try {
        for (const auto& entry : fs::directory_iterator(folder)) {
            std::string nombre = entry.path().filename().string();
            bool IsItAFolder = entry.is_directory();
            content.push_back({nombre, IsItAFolder});
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return content;
}

void tools::file_search_engine(const std::string& folder) {
    std::vector<std::pair<std::string, bool>> content = tools::folder_contents(folder);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error SDL: " << SDL_GetError() << std::endl;
    } else {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window* ventana_files = SDL_CreateWindow("NewMaVMPlayer",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            640, 480, SDL_WINDOW_SHOWN);

        SDL_Renderer* renderer_files = SDL_CreateRenderer(ventana_files, -1, SDL_RENDERER_ACCELERATED);
        
        SDL_Event evento;
        bool corriendo = true;

        int scale = 1;
        
        while (corriendo) {
            SDL_Rect rect_down = {0, 480-(20*scale+10), 640, 20*scale+10};
            SDL_Rect rect_up = {0, 0, 640, 10*scale+10};
            SDL_Rect rect_files = {0, 0, 35*scale+10, 10*scale+10};
            SDL_Rect rect_config = {35*scale+10, 0, 35*scale+10, 10*scale+10};
            
            while (SDL_PollEvent(&evento)) {
                if (evento.type == SDL_QUIT) corriendo = false;

                if (evento.type == SDL_MOUSEBUTTONDOWN) {
                    std::cout << "Click presionado en ("
                            << evento.button.x << ", "
                            << evento.button.y << ")" << std::endl;
                }

                if (evento.type == SDL_MOUSEBUTTONUP) {
                    std::cout << "Click liberado en ("
                            << evento.button.x << ", "
                            << evento.button.y << ")" << std::endl;
                }

                if (evento.type == SDL_MOUSEBUTTONDOWN) {
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
                }
            }
            // Fondo negro
            SDL_SetRenderDrawColor(renderer_files, 0, 0, 0, 255);
            SDL_RenderClear(renderer_files);

            SDL_SetRenderDrawColor(renderer_files, 50, 50, 50, 255); // amarillo
            SDL_RenderFillRect(renderer_files, &rect_down); // rectángulo relleno

            SDL_SetRenderDrawColor(renderer_files, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer_files, &rect_down);
            
            SDL_SetRenderDrawColor(renderer_files, 50, 50, 50, 255); // amarillo
            SDL_RenderFillRect(renderer_files, &rect_up); // rectángulo relleno

            SDL_SetRenderDrawColor(renderer_files, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer_files, &rect_up);

            SDL_RenderPresent(renderer_files);
            // this_thread::sleep_for(chrono::milliseconds(10));
        }

        SDL_DestroyRenderer(renderer_files);
        SDL_DestroyWindow(ventana_files);
        SDL_Quit();
    }
}