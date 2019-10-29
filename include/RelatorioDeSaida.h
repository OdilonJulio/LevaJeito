/**
 * @file RelatorioDeSaida.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que faz gestão da saída arquivos de registro.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _RELATORIO_DE_SAIDA_H_
#define _RELATORIO_DE_SAIDA_H_

#include <vector>
#include <string>
#include "Registro.h"
using namespace std;

class RelatorioDeSaida {
  
  private:
    
    void setArquivoDeSaida(vector<Registro>, string);

  public:
  
    RelatorioDeSaida(vector<Registro>, string);
    ~RelatorioDeSaida();
};

#endif // _RELATORIO_DE_SAIDA_H_