/**
 * @file AbreArquivoDeRegistro.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que abre arquivos de registros.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ABRE_ARQUIVO_DE_REGISTROS_H_
#define ABRE_ARQUIVO_DE_REGISTROS_H_

#include <string> 
#include <vector>  
#include "Registro.h"

using namespace std;

class AbreArquivoDeRegistro {
  
  private:

    vector<Registro> tabelaDeRegistros_;
    void getRegistros(string);

  public:
    
    vector<Registro> getTabelaDeRegistros();
    AbreArquivoDeRegistro(string);
    ~AbreArquivoDeRegistro();
};

#endif // ABRE_ARQUIVO_DE_REGISTROS_H_