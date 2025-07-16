#pragma once
#include <string>

class CifradoVigenere {
public:
    static std::string cifrar(const std::string& texto, const std::string& clave);
    static std::string descifrar(const std::string& texto, const std::string& clave);
};