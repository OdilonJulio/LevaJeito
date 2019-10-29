/**
 * @file HashDeArquivo.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que gera a hash de um determinado arquivo.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _HASH_DE_ARQUIVO_H_
#define _HASH_DE_ARQUIVO_H_

#include <string>
using namespace std;

class HashDeArquivo {

  private:
    
    string hash_;
    void setHASH(string);
    void setHMAC(string, string);

  public:
    
    string getHASH();
    HashDeArquivo(string);
    HashDeArquivo(string, string);
    ~HashDeArquivo();
};

#endif // _HASH_DE_ARQUIVO_H_