#ifndef ALGORITMOCIFRADECESAR_H
#define ALGORITMOCIFRADECESAR_H

#include <string>

class AlgoritmoCifraDeCesar
{
public:
    AlgoritmoCifraDeCesar(int chave);
    std::string criptografar(const std::string& mensagem, int chave); // Adicione o parâmetro chave
    std::string descriptografar(const std::string& mensagem, int chave);

private:
    int chave;
};

#endif // ALGORITMOCIFRADECESAR_H

