#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <vector>

class video {
    public:
        void video_extract(std::string video_path, int second_a, int second_b, std::string folder_out);
};

class mavm {
    public:
        void extract(std::string file_path);
        void extract_on_folder(std::string file_path, std::string out_path);
};

class tools {
    public:
        static std::vector<std::string> split(const std::string& s, const std::string& delimiter);
        static std::vector<std::pair<std::string, bool>> folder_contents(const std::string& folder);
        void file_search_engine(const std::string& folder);
};


#endif   