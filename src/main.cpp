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
    std::string nombreHuffman = "prueba_huffman";
    escritor.escribir(nombreHuffman + ".bin", datosHuffman);
    compresorHuffman.guardarMapa(nombreHuffman + "codigos.txt");
    std::vector<unsigned char> datosHuffmanLeidos = escritor.leer("prueba_huffman.bin");
    std::vector<unsigned char> datosHuffmanDescomprimidos = compresorHuffman.descomprimir(datosHuffmanLeidos, nombreHuffman + "codigos.txt");
    escritor.escribir("prueba_huffman_descomprimida.txt", datosHuffmanDescomprimidos);

}