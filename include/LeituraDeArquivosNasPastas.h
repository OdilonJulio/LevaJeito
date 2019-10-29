/**
 * @file LeituraDeArquivosNasPastas.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe que faz gestão da leitura dos arquivos recursivamente.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _LEITURA_DE_ARQUIVOS_NAS_PASTAS_H_
#define _LEITURA_DE_ARQUIVOS_NAS_PASTAS_H_

#include <string>  
#include <vector>

using namespace std;

class LeituraDeArquivosNasPastas {
  private:
    
    vector<string> relacaoDeCaminhos_;
    void getCaminhoDoArquivo(string);

  public:
    
    vector<string> getRelacaoDeCaminhos();
    LeituraDeArquivosNasPastas(string);
    ~LeituraDeArquivosNasPastas();
};

#endif // _LEITURA_DE_ARQUIVOS_NAS_PASTAS_H_