#include "tools.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void mavm::extract(std::string file_path) {
    ifstream archivo(file_path, ios::binary);

    if (archivo.is_open()) {
        // Obtener tamaño
        archivo.seekg(0, ios::end);
        streampos tamaño = archivo.tellg();
        archivo.seekg(0, ios::beg);
        
        // Crear string del tamaño exacto
        string bytes;
        bytes.resize(tamaño);

        // Leer el archivo
        archivo.read(&bytes[0], tamaño);
        archivo.close();

        if (bytes.size() >= 3) {
            // Obtener los primeros 3 bytes
            unsigned char byte1 = (unsigned char)bytes[0];
            unsigned char byte2 = (unsigned char)bytes[1];
            unsigned char byte3 = (unsigned char)bytes[2];
            
            // -++
            if (byte1 == 0x2D && byte2 == 0x2B && byte3 == 0x2B) {
                cout << "el archivo es MaVM" << endl;
            } else {
                cout << "el archivo no es MaVM, por favor habra un archivo MaVM" << endl;
            }
        }
    }
}