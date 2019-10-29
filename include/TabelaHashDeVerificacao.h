/**
 * @file TabelaHashDeVerificacao.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que verifica igualdade entre o arquivo e "hashs" da tabela.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _TABELA_HASH_DE_VERIFICAO_H_
#define _TABELA_HASH_DE_VERIFICAO_H_
#include <vector>
#include <string>
#include "Registro.h"

using namespace std;

class TabelaHashDeVerificacao {
 
  private:
  
    void montarNovoEstado(string, string);
    vector<Registro> registrosDeEstados_;
  
  public:
  
    void mostrarRegistroDeEstados();
    vector<Registro> getStatusLogVector();
    TabelaHashDeVerificacao(vector<string>, vector<Registro>);
    TabelaHashDeVerificacao(vector<string>, vector<Registro>, string);
    ~TabelaHashDeVerificacao();
};

#endif // _TABELA_HASH_DE_VERIFICAO_H_