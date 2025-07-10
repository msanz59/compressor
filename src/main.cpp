#include <iostream>

#include "../include/escritor.h"


int main() {
    escritor escritor;
    std::string nombreArchivo = "prueba.txt";
    escritor.leer(nombreArchivo);
}