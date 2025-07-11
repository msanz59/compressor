#include <iostream>

#include "../include/escritor.h"
#include "../include/rlc.h"
#include "../include/huffman.h"

using namespace std;
int main() {
    escritor escritor;
    rlc compresorRLC;
    huffman compresorHuffman;
    string nombreArchivo;


    char opcion;
    do {
        cout << "\n----------------------------------------------------------------";
        cout << "\n| 1. Comprimir con RLC                                         |";
        cout << "\n| 2. Descomprimir con RLC                                      |";
        cout << "\n| 3. Comprimir con Huffman                                     |";
        cout << "\n| 4. Descomprimir con Huffman                                  |";
        cout << "\n| q. Salir                                                     |";
        cout << "\n----------------------------------------------------------------";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                cout << "Comprimir con RLC" << endl;
                cout << "Ingrese el nombre del archivo a comprimir: ";
                cin >> nombreArchivo;
                vector<unsigned char> datosRLC = escritor.leer(nombreArchivo + ".txt");
                vector<unsigned char> comprimidoRLC = compresorRLC.comprimir(datosRLC);
                escritor.escribir(nombreArchivo + "_comprimidoRLC.txt", comprimidoRLC);
                break;
            }
            case '2': {
                cout << "Descomprimir con RLC" << endl;
                cout << "Ingrese el nombre del archivo a descomprimir: ";
                cin >> nombreArchivo;
                vector<unsigned char> comprimidoRLC = escritor.leer(nombreArchivo + ".txt");
                vector<unsigned char> descomprimidoRLC = compresorRLC.descomprimir(comprimidoRLC);
                escritor.escribir(nombreArchivo + "_descomprimidoRLC.txt", descomprimidoRLC);
                break;
            }
            case '3': {
                cout << "Comprimir con Huffman" << endl;
                cout << "Ingrese el nombre del archivo a descomprimir: ";
                cin >> nombreArchivo;

                vector<unsigned char> datosHuffman = escritor.leer(nombreArchivo + ".txt");
                vector<unsigned char> comprimidoHuffman = compresorHuffman.comprimir(datosHuffman);
                escritor.escribir(nombreArchivo + "_comprimidoHuff.bin", comprimidoHuffman);
                compresorHuffman.guardarMapa(nombreArchivo + "_codigosHuff.txt");
                break;
            }
            case '4': {
                cout << "Descomprimir con Huffman" << endl;
                cout << "Ingrese el nombre del archivo comprimido: ";
                cin >> nombreArchivo;
                cout << "Ingrese el nombre del archivo de codigos: ";
                string nombreCodigos;
                cin >> nombreCodigos;
                vector<unsigned char> comprimidoHuffman = escritor.leer(nombreArchivo + ".bin");
                vector<unsigned char> descomprimidoHuffman = compresorHuffman.descomprimir(comprimidoHuffman, nombreCodigos + ".txt");
                escritor.escribir(nombreArchivo + "_descomprimidoHuff.txt", descomprimidoHuffman);
                break;
            }
            case 'q':
            case 'Q':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }



    } while (opcion != 'q' && opcion != 'Q');

}