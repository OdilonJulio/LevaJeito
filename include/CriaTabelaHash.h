/**
 * @file CriaTabelaHash.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que gera uma tabela com "hash's".
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _CRIA_TABELA_HASH_H_
#define _CRIA_TABELA_HASH_H_

#include <string>  
#include <vector>
#include "Registro.h"
using namespace std;

class CriaTabelaHash {
  
  private:
    
    vector<Registro> tabelaHash_;
    void setNovaHashNaTabela(Registro);

  public:
    
    void mostrarRegistros();
    vector<Registro> getTabelaHash();
    CriaTabelaHash(vector<string>);
    CriaTabelaHash(vector<string>, string);
    ~CriaTabelaHash();
};

#endif // _CRIA_TABELA_HASH_H_