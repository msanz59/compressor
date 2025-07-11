#include <iostream>

#include "../include/escritor.h"
#include "../include/rlc.h"
#include "../include/huffman.h"


int main() {
    escritor escritor;
    rlc compresorRLC;
    huffman compresorHuffman;
    std::string nombreArchivo = "prueba.txt";
    std::vector<unsigned char> datos = escritor.leer(nombreArchivo);
    std::vector<unsigned char> datosComprimidos = compresorRLC.comprimir(datos);
    std::vector<unsigned char> datosDescomprimidos = compresorRLC.descomprimir(datosComprimidos);
    escritor.escribir("prueba_comprimida.txt", datosComprimidos);
    std::vector<unsigned char> datosLeidos = escritor.leer("prueba_comprimida.txt");
    std::vector<unsigned char> datosDescomprimidosLeidos = compresorRLC.descomprimir(datosLeidos);
    escritor.escribir("prueba_descomprimida.txt", datosDescomprimidosLeidos);

    std::vector<unsigned char> datosHuffman = compresorHuffman.comprimir(datosDescomprimidosLeidos);
    escritor.escribir("prueba_huffman.bin", datosHuffman);
    compresorHuffman.guardarMapa("codigos.txt");

}