#include <iostream>
#include <vector>

#include "SDL2/SDL.h"
// #include "tiny_obj_loader.h"

// #define WIDTH 1080
// #define HEIGHT 720
//
// using Vec3 = float[3];
// using Tri = Vec3[3];

int main(int argc, char *argv[])
{

    try
    {

        std::string objFilePath = "path/to/your/file.obj";

        // Load the OBJ file using TinyObjLoader
        // std::vector<tinyobj::shape_t> shapes;
        // std::vector<tinyobj::material_t> materials;
        // std::string err;
        // tinyobj::attrib_t s;
        bool success = tinyobj::LoadObj(shapes, materials, err, objFilePath.c_str());

        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            throw std::runtime_error("failed to initialize SDL!");
        }

        std::cout << "HELLO" << std::endl;

        SDL_Window *window = SDL_CreateWindow(
            "SDL2 Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800, 600,
            SDL_WINDOW_SHOWN);

        SDL_Surface *surface = SDL_GetWindowSurface(window);

        // Event loop
        bool running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            // Access pixels of the surface
            uint32_t *pixels = (uint32_t *)surface->pixels;
            int pitch = surface->pitch / sizeof(uint32_t);

            for (int y = 0; y < surface->h; y++)
            {
                for (int x = 0; x < surface->w; x++)
                {
                    uint8_t r = 255;
                    uint8_t g = 0;
                    uint8_t b = 0;
                    uint8_t a = 255;

                    int index = surface->w * y + x;

                    pixels[index] = SDL_MapRGBA(surface->format, r, g, b, a);
                }
            }

            SDL_UpdateWindowSurface(window);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        std::cout << "Image created." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "EXCEPTION: \n"
                  << e.what() << std::endl;
        return 1;
    }
    return 0;
}