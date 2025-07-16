#include "CifradoVigenere.h"

static char cifrarLetra(char letra, char clave) {
    if (isupper(letra))
        return 'A' + (letra - 'A' + (toupper(clave) - 'A')) % 26;
    else if (islower(letra))
        return 'a' + (letra - 'a' + (tolower(clave) - 'a')) % 26;
    else
        return letra;
}

static char descifrarLetra(char letra, char clave) {
    if (isupper(letra))
        return 'A' + (26 + (letra - 'A') - (toupper(clave) - 'A')) % 26;
    else if (islower(letra))
        return 'a' + (26 + (letra - 'a') - (tolower(clave) - 'a')) % 26;
    else
        return letra;
}

std::string CifradoVigenere::cifrar(const std::string& texto, const std::string& clave) {
    std::string resultado;
    int j = 0;
    for (char c : texto) {
        if (isalpha(c)) {
            resultado += cifrarLetra(c, clave[j % clave.length()]);
            j++;
        }
        else {
            resultado += c;
        }
    }
    return resultado;
}

std::string CifradoVigenere::descifrar(const std::string& texto, const std::string& clave) {
    std::string resultado;
    int j = 0;
    for (char c : texto) {
        if (isalpha(c)) {
            resultado += descifrarLetra(c, clave[j % clave.length()]);
            j++;
        }
        else {
            resultado += c;
        }
    }
    return resultado;
}