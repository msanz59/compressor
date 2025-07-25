//
// Created by Miguel on 10/07/2025.
//

#include "../include/escritor.h"


using namespace std;
escritor::escritor() {
    cout << "Inicializando escritor" << endl;
}
void escritor::escribir(const string &texto, const vector<unsigned char> &comprimido) {
    ofstream archivo(texto, ios::binary);

    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(comprimido.data()), comprimido.size());
        archivo.close();
        cout << "Archivo escrito correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo para escribir." << endl;
    }
}
vector<unsigned char> escritor::leer(const string &texto) {
    ifstream archivo(texto, ios::binary);
    vector<unsigned char> contenido;
    if (archivo.is_open()) {
        unsigned char byte;
        while (archivo.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
            contenido.push_back(byte);
        }
        archivo.close();
        cout << "Archivo leído correctamente." << endl;
    } else {
        cout << "Error al abrir el archivo para leer." << endl;
    }

    cout << "Contenido del archivo: " << endl;
    for (unsigned char byte : contenido) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(byte) << " ";
    }

    return contenido;
}

