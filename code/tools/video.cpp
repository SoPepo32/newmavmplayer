#include "tools.h"

#include <string>


using namespace std;

void video::video_extract(std::string video_path, int second_a, int second_b) {
    std::string command = "ffmpeg -ss " + std::to_string(second_a) +  " -i " + video_path +  " -to " + std::to_string(second_b) +  " frames/frame_%04d.jpg";
    std::system(command.c_str());
}