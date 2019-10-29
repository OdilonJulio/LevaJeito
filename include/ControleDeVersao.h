/**
 * @file ControleDeVersao.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que gerencia o processo de controle de versões.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _CONTROLE_DE_VERSAO_H_
#define _CONTROLE_DE_VERSAO_H_

#include <string>
using namespace std;

class ControleDeVersao {
  
  private:

    string saidaDeArquivoDeDados = ".guarda/log.txt"; // diretório oculto
    void setSaidaDeArquivoDeDados(string);
    string consertoDeCaminho(string);

  public:

    ControleDeVersao(string, string);
    ControleDeVersao(string, string, string);
    ControleDeVersao(string, string, bool, string);
    ControleDeVersao(string, string, string, bool, string);
    ~ControleDeVersao();
};

#endif // _CONTROLE_DE_VERSAO_H_