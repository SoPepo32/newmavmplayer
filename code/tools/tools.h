// mi_clase.h
#ifndef TOOLS_H
#define TOOLS_H

#include <string>

// Declaración de la clase
class video {
    public:
        void video_extract(std::string video_path, int second_a, int second_b);
};

class mavm {
    public:
        void extract(std::string file_path);
};

#endif   