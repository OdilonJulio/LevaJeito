


#include <iomanip>
#include <iostream> 
#include <string>    
#include <vector>   
#include "HashDeArquivo.h"
#include "Registro.h"
#include "TabelaHashDeVerificacao.h"

using namespace std;


TabelaHashDeVerificacao::TabelaHashDeVerificacao(vector<string> tabelaDeArquivos_, vector<Registro> tabelaDeRegistros_) {
  for (Registro registro : tabelaDeRegistros_) {
    bool marcador_ = true;
    for (auto i(0u); i < tabelaDeArquivos_.size(); ++i) {
      if (registro.getCaminhoDoArquivo() == tabelaDeArquivos_[i]) {
        marcador_ = false;
        HashDeArquivo hashDeArquivoTemporaria(tabelaDeArquivos_[i]);
        string hashTemporaria_ = hashDeArquivoTemporaria.getHASH();
        if (registro.getHASH() == hashTemporaria_) {
        
        } else {
          setEstadoNovo_("Arquivo Alterado.", registro.getCaminhoDoArquivo());
        }
        tabelaDeArquivos_.erase(tabelaDeArquivos_.begin() + i);
        --i;
        break;
      }
    }
    if (marcador_) {
      setEstadoNovo_("Arquivo excluído.", registro.getCaminhoDoArquivo());
    }
  }
  for (string caminho_ : tabelaDeArquivos_) {
    setEstadoNovo_("Arquivo gerado!", caminho_);
  }
}

TabelaHashDeVerificacao::TabelaHashDeVerificacao(vector<string> tabelaDeArquivos_,
                               vector<registro> tabelaDeRegistros_, string key) {
  for (Registro registro : tabelaDeRegistros_) {
    bool marcador_ = true;
    for (auto i(0u); i < tabelaDeArquivos_.size(); ++i) {
      if (registro.getCaminhoDoArquivo() == tabelaDeArquivos_[i]) {
        marcador_ = false;
        HashDeArquivo hashDeArquivoTemporaria(tabelaDeArquivos_[i], key);
        string hashTemporaria_ = hashDeArquivoTemporaria.getHASH();
        if (registro.getHASH() == hashTemporaria_) {

        } else {
          setEstadoNovo_("Arquivo alterado.", registro.getCaminhoDoArquivo());
        }
        tabelaDeArquivos_.erase(tabelaDeArquivos_.begin() + i);
        --i;
        break;
      }
    }
    if (marcador_) {
      setEstadoNovo_("Arquivo excluído.", registro.getCaminhoDoArquivo());
    }
  }
  for (string caminho_ : tabelaDeArquivos_) {
    setEstadoNovo_("Arquivo gerado.", caminho_);
  }
}

TabelaHashDeVerificacao::~TabelaHashDeVerificacao() {}


void TabelaHashDeVerificacao::setEstadoNovo_(string status, string path) {
  Registro registroTemporario(estado_, caminho_);
  registrosDeEstados_.push_back(registroTemporario);
}

vector<Registro> TabelaHashDeVerificacao::getVetorDeRegistrosDeEstados() {
  return registrosDeEstados_;
}

void TabelaHashDeVerificacao::mostrarRegistroDeEstados() {
  unsigned int tamanhoDoCaminho = 0;
  unsigned int tamanhoDoEstado = 0;
  for (Registro registro : registrosDeEstados_) {
    unsigned int tamanhoDoCaminhoTemporario = registro.getCaminhoDoArquivo().size();
    if (tamanhoDoCaminhoTemporario > tamanhoDoCaminho) {
      tamanhoDoCaminho = tamanhoDoCaminhoTemporario;
    }
    unsigned int tamanhoDoEstadoTemp = registro.getHASH().size();
    if (tamanhoDoEstadoTemp > tamanhoDoEstado) {
      tamanhoDoEstado = tamanhoDoEstadoTemp;
    }
  }
  tamanhoDoCaminho += 3;
  tamanhoDoEstado += 3;
  cout << "+";
  cout << setw(tamanhoDoCaminho) << setfill('-') << "";
  cout << "+";
  cout << setw(tamanhoDoEstado) << "";
  cout << "+" << endl;
  cout << "|";
  cout << setw(tamanhoDoCaminho) << setfill(' ') << left
            << " CAMINHO";
  cout << "|";
  cout << setw(tamanhoDoEstado) << " STATUS";
  cout << "|" << endl;
  cout << "+";
  cout << setw(tamanhoDoCaminho) << setfill('-') << "";
  cout << "+";
  cout << setw(tamanhoDoEstado) << "";
  cout << "+" << endl;
  cout << setfill(' ');
  const string red("\033[0;31m");
  const string green("\033[1;32m");
  const string yellow("\033[1;33m");
  const string cyan("\033[0;36m");
  const string reset("\033[0m");
  for (Registro registro : registrosDeEstados_) {
    if (registro.getHASH() == "Arquivo intacto.") {

    } else {
      if (registro.getHASH() == "Arquivo gerado.") {
        cout << "|| ";
        cout << setw(tamanhoDoCaminho - 1) << registro.getCaminhoDoArquivo() << "";
        cout << "|| ";
        cout << green + registro.getHASH() + reset
                  << setw(tamanhoDoEstado - registro.getHASH().size() - 1) << "";
        cout << "||" << endl;
      }
      if (registro.getHASH() == "Arquivo excluído.") {
        cout << "| ";
        cout << setw(tamanhoDoCaminho - 1) << registro.getCaminhoDoArquivo() << "";
        cout << "| ";
        cout << red + registro.getHASH() + reset
                  << setw(tamanhoDoEstado - registro.getHASH().size() - 1) << "";
        cout << "|" << endl;
      }
      if (registro.getHASH() == "Arquivo alterado.") {
        cout << "| ";
        cout << setw(tamanhoDoCaminho - 1) << registro.getCaminhoDoArquivo() << "";
        cout << "| ";
        cout << yellow + registro.getHASH() + reset
                  << setw(tamanhoDoEstado - registro.getHASH().size() - 1) << "";
        cout << "|" << endl;
      }
    }
  }
  cout << "+";
  cout << setw(tamanhoDoCaminho) << setfill('-') << "";
  cout << "+";
  cout << setw(tamanhoDoEstado) << "";
  cout << "+" << endl;
  cout << endl;
}