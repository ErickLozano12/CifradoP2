#pragma once
#pragma once
#include <string>

class CifradoXOR {
public:
    static std::string cifrar(const std::string& texto, char clave);
    static std::string descifrar(const std::string& texto, char clave);
};