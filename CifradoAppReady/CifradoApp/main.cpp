#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "CifradoCesar.h"
#include "CifradoXOR.h"
#include "CifradoVigenere.h"

void mostrarMenu() {
    std::cout << "\n--- MENU DE CIFRADO ---\n";
    std::cout << "1. Cifrado Cesar\n";
    std::cout << "2. Cifrado XOR\n";
    std::cout << "3. Cifrado Vigenere\n";
    std::cout << "4. Descifrar Cesar\n";
    std::cout << "5. Descifrar XOR\n";
    std::cout << "6. Descifrar Vigenere\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

std::string leerArchivo(const std::string& ruta) {
    std::ifstream entrada(ruta);
    if (!entrada) {
        std::cerr << "\n[ERROR] No se pudo abrir el archivo: " << ruta << "\n";
        return "";
    }
    return std::string((std::istreambuf_iterator<char>(entrada)), std::istreambuf_iterator<char>());
}

void guardarArchivo(const std::string& ruta, const std::string& contenido) {
    std::ofstream salida(ruta);
    if (!salida) {
        std::cerr << "\n[ERROR] No se pudo escribir el archivo: " << ruta << "\n";
        return;
    }
    salida << contenido;
    std::cout << "\nArchivo guardado exitosamente en: " << ruta << "\n";
}

int main() {
    std::string rutaEntrada = "../datos/crudos/datos.txt";
    std::string rutaSalidaCesar = "../datos/cifrados/datos_cifrados.txt";
    std::string rutaSalidaXOR = "../datos/cifrados/datos_cifrados_xor.txt";
    std::string rutaSalidaVigenere = "../datos/cifrados/datos_cifrados_vigenere.txt";
    std::string rutaDescifradoCesar = "../datos/crudos/datos_descifrado.txt";
    std::string rutaDescifradoXOR = "../datos/crudos/datos_descifrado_xor.txt";
    std::string rutaDescifradoVigenere = "../datos/crudos/datos_descifrado_vigenere.txt";

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        std::string contenido, resultado;
        switch (opcion) {
        case 1: {
            contenido = leerArchivo(rutaEntrada);
            if (contenido.empty()) break;
            int clave;
            std::cout << "Ingrese clave numerica para Cesar: ";
            std::cin >> clave;
            resultado = CifradoCesar::cifrar(contenido, clave);
            std::cout << "\nTexto cifrado:\n" << resultado << "\n";
            guardarArchivo(rutaSalidaCesar, resultado);
            break;
        }
        case 2: {
            contenido = leerArchivo(rutaEntrada);
            if (contenido.empty()) break;
            char clave;
            std::cout << "Ingrese clave (caracter) para XOR: ";
            std::cin >> clave;
            resultado = CifradoXOR::cifrar(contenido, clave);
            std::cout << "\nTexto cifrado:\n" << resultado << "\n";
            guardarArchivo(rutaSalidaXOR, resultado);
            break;
        }
        case 3: {
            contenido = leerArchivo(rutaEntrada);
            if (contenido.empty()) break;
            std::string clave;
            std::cout << "Ingrese palabra clave para Vigenere: ";
            std::cin >> clave;
            resultado = CifradoVigenere::cifrar(contenido, clave);
            std::cout << "\nTexto cifrado:\n" << resultado << "\n";
            guardarArchivo(rutaSalidaVigenere, resultado);
            break;
        }
        case 4: {
            contenido = leerArchivo(rutaSalidaCesar);
            if (contenido.empty()) break;
            int clave;
            std::cout << "Ingrese clave numerica para descifrado Cesar: ";
            std::cin >> clave;
            resultado = CifradoCesar::descifrar(contenido, clave);
            std::cout << "\nTexto descifrado:\n" << resultado << "\n";
            guardarArchivo(rutaDescifradoCesar, resultado);
            break;
        }
        case 5: {
            contenido = leerArchivo(rutaSalidaXOR);
            if (contenido.empty()) break;
            char clave;
            std::cout << "Ingrese clave (caracter) para descifrado XOR: ";
            std::cin >> clave;
            resultado = CifradoXOR::descifrar(contenido, clave);
            std::cout << "\nTexto descifrado:\n" << resultado << "\n";
            guardarArchivo(rutaDescifradoXOR, resultado);
            break;
        }
        case 6: {
            contenido = leerArchivo(rutaSalidaVigenere);
            if (contenido.empty()) break;
            std::string clave;
            std::cout << "Ingrese palabra clave para descifrado Vigenere: ";
            std::cin >> clave;
            resultado = CifradoVigenere::descifrar(contenido, clave);
            std::cout << "\nTexto descifrado:\n" << resultado << "\n";
            guardarArchivo(rutaDescifradoVigenere, resultado);
            break;
        }
        case 7:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    return 0;
}
