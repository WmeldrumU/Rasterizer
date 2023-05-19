#include <iostream>
#include <fstream>
#include <vector>

#include "SDL2/SDL.h"

#define WIDTH 1080
#define HEIGHT 720

using Vec3 = float[3];
using Tri = Vec3[3];


int main(int argc, char* argv[]) {
    std::cout << "HELLO" << std::endl;

    std::ofstream image("image.ppm");
    image << "P3" << std::endl;
    image << WIDTH << " " << HEIGHT << std::endl;
    image << "255" << std::endl;

    int r, g, b;
    r = 0, g = 0, b = 0;
    for (auto i = 0; i < HEIGHT; i++) {
        for (auto j = 0; j < WIDTH; j++) {
            int r_norm = ( 1.0 * r / (HEIGHT * WIDTH)) * 255;
            int g_norm = (1.0 * g / (HEIGHT * WIDTH) ) * 255;
            int b_norm = (1.0 * b / (HEIGHT * WIDTH)) * 255;
            r++;
            g++;
            b++;
            image << r_norm << " " << g_norm << " " << b_norm << " ";
            
        }
        image << std::endl;
    }
    image.close();
    std::cout << "Image created." << std::endl;
    return 0;
}