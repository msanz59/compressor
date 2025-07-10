#include <iostream>

#include "../include/escritor.h"
#include "../include/rlc.h"


int main() {
    escritor escritor;
    rlc compresorRLC;
    std::string nombreArchivo = "prueba.txt";
    std::vector<unsigned char> datos = escritor.leer(nombreArchivo);
    std::vector<unsigned char> datosComprimidos = compresorRLC.comprimir(datos);
    std::vector<unsigned char> datosDescomprimidos = compresorRLC.descomprimir(datosComprimidos);
    escritor.escribir("prueba_comprimida.txt", datosDescomprimidos);

}