/**
 * @file Registro.h
 * @author Odilon Júlio dos Santos (odilonjulio@ufrn.edu.br)
 * @brief Classe para fazer gestão de registros.
 * @version 0.1
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
using namespace std;

class Registro {
  
  private:
  
    string md5sum_;
    string caminhoDoArquivo_;

  public:
  
    Registro(string, string);
    Registro();
    string getSum();
    string getCaminhoDoArquivo();
    void setSum(string);
    void setCaminhoDoArquivo(string);
    ~Registro();
};

#endif // _REGISTRO_H_