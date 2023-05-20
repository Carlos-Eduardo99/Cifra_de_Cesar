#include "algoritmocifradecesar.h"

AlgoritmoCifraDeCesar::AlgoritmoCifraDeCesar(int chave) {
    this->chave = chave;
}

std::string AlgoritmoCifraDeCesar::criptografar(const std::string& mensagem, int chave) {
    std::string mensagemCriptografada;

    for (size_t i = 0; i < mensagem.length(); i++) {
        char caractere = mensagem[i];

        if (caractere == ' ') {
            mensagemCriptografada += ' ';
        } else {
            char letraCriptografada = caractere;
            if (islower(caractere)) {
                letraCriptografada = static_cast<char>((caractere - 'a' + chave) % 26 + 'a');
            } else if (isupper(caractere)) {
                letraCriptografada = static_cast<char>((caractere - 'A' + chave) % 26 + 'A');
            }

            mensagemCriptografada += letraCriptografada;
        }
    }

    return mensagemCriptografada;
}


std::string AlgoritmoCifraDeCesar::descriptografar(const std::string& mensagem, int chave) {
    std::string mensagemDescriptografada;

    for (size_t i = 0; i < mensagem.length(); i++) {
        char caractere = mensagem[i];

        if (caractere == ' ') {
            mensagemDescriptografada += ' ';
        } else {
            char letraDescriptografada = caractere;
            if (islower(caractere)) {
                letraDescriptografada = static_cast<char>((caractere - 'a' - chave + 26) % 26 + 'a');
            } else if (isupper(caractere)) {
                letraDescriptografada = static_cast<char>((caractere - 'A' - chave + 26) % 26 + 'A');
            }

            mensagemDescriptografada += letraDescriptografada;
        }
    }

    return mensagemDescriptografada;
}
