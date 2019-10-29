


#include <dirent.h>
#include <cstring>
#include <fstream>   
#include <iostream> 
#include <string>    
#include <vector>    
#include "Registro.h"
#include "RelatorioDeSaida.h"


RelatorioDeSaida::RelatorioDeSaida(vector<Registro> Registros, string caminho_) {
  setArquivoDeSaida(Registros, caminho_);
}

RelatorioDeSaida::~RelatorioDeSaida() {}

void RelatorioDeSaida::setArquivoDeSaida(vector<Registro> registros, string caminho_) {
  try {
    char c = '/';
    string buff{""};
    vector<string> v;
    for (auto n : caminho_) {
      if (n != c) {
        buff += n;
      } else if (n == c && buff != "") {
        v.push_back(buff);
        buff = "";
      }
    }
    if (buff != "") {
      v.push_back(buff);
    }
    string novo_ = "";
    for (auto i(0u); i < (v.size() - 1); ++i) {
      novo_ += v[i];
      novo_.push_back('/');
    }
    DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char ehArquivo = 0x8;
    dir = opendir(novo_.c_str());
    if (dir == 0) {
      string t = "mkdir " + novo_;    
      char a[t.size() + 1];
      strcpy(a, t.c_str());
      system(a);
    }
    ofstream newFile;
    string nomeDoArquivo = caminho_;
    newFile.open(nomeDoArquivo, ios::trunc);
    for (auto i(0u); i < Registros.size(); ++i) {
      newFile << Registros[i].getHash() << " " << Registros[i].getFilecaminho_() << endl;
    }
    newFile.close();
  } catch (const ios_base::failure &e) {
    cerr << e.what() << '\n';
  }
}