#include "containers.hpp"
#include <unordered_map>
#include <string>

using namespace std;

// Implementacao dos metodos da classe ContainerPessoa

bool ContainerPessoa::incluir(const Pessoa& pessoa){
    string chave = pessoa.getEmail().getValor();

    if (mapaPessoas.find(chave) != mapaPessoas.end())
        return false;
    
    mapaPessoas[chave] = pessoa;
    return true;
}

bool ContainerPessoa::remover(const Email& email){
    string chave = email.getValor();
    
    return mapaPessoas.erase(chave) > 0; // Se foi deletado retorna 1
}

bool ContainerPessoa::pesquisar(const Email& email, Pessoa* pessoaRetorno){
    string chave = email.getValor();

    auto it = mapaPessoas.find(chave);
    if (it != mapaPessoas.end()){
        *pessoaRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerPessoa::atualizar(const Pessoa& pessoa){
    string chave = pessoa.getEmail().getValor();

    if (mapaPessoas.find(chave) != mapaPessoas.end()){ // se a pessoa existe no sistema
        mapaPessoas[chave] = pessoa;
        return true;
    } 
    return false;
}

// Implementacao dos métodos da classe ContainerProjeto

bool ContainerProjeto::incluir(const Projeto& projeto){
    string chave = projeto.getIdentificador().getValor();

    if (mapaProjeto.find(chave) != mapaProjeto.end())
        return false;
    mapaProjeto[chave] = projeto;
    return true;
}

bool ContainerProjeto::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    return mapaProjeto.erase(chave) > 0;
}

bool ContainerProjeto::pesquisar(const Identificador& identificador, Projeto* projetoRetorno){
    string chave = identificador.getValor();
    
    auto it = mapaProjeto.find(chave);
    if (it != mapaProjeto.end()){
        *projetoRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerProjeto::atualizar(const Projeto& projeto){
    string chave = projeto.getIdentificador().getValor();

    if (mapaProjeto.find(chave) != mapaProjeto.end()){
        mapaProjeto[chave] = projeto;
        return true;
    }
    return false;
}

// Implementacao dos métodos da classe ContainerQuadro

bool ContainerQuadro::incluir(const Quadro& quadro, const Email& emailDono){
    string chaveQuadro = quadro.getIdentificador().getValor();
    string chaveDono = emailDono.getValor();

    if (mapaQuadro.find(chaveQuadro) != mapaQuadro.end())
        return false;

    mapaQuadro[chaveQuadro] = quadro;

    //insere o email do dono no hashmap e adiciona o id do quadro no vetor associado a esse email
    // ex.: relacaoPessoaQuadro[email@abc.com] -> ["quadroA", "quadroB"]
    relacaoPessoaQuadro[chaveDono].push_back(chaveQuadro); 
    return true;
}

bool ContainerQuadro::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    if (mapaQuadro.erase(chave) == 0) // não esta presente
        return false;

    for (auto itMapa = relacaoPessoaQuadro.begin(); itMapa != relacaoPessoaQuadro.end(); ++itMapa){
        // itMapa->second é o vetor de strings de quadros (["QA, "QB", ...])
        for (auto itVetor = itMapa->second.begin(); itVetor != itMapa->second.end(); ++itVetor){
            if (*itVetor == chave){
                itMapa->second.erase(itVetor);
                break;
            }
        }
    }

    return true;
}

bool ContainerQuadro::pesquisar(const Identificador& identificador, Quadro* quadroRetorno){
    string chave = identificador.getValor();

    auto it = mapaQuadro.find(chave);
    if (it != mapaQuadro.end()){
        *quadroRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerQuadro::atualizar(const Quadro& quadro){
    string chave = quadro.getIdentificador().getValor();

    if (mapaQuadro.find(chave) != mapaQuadro.end()){
        mapaQuadro[chave] = quadro;
        return true;
    }
    return false;
}

bool ContainerQuadro::listar(const Email& emailDono, std::list<Quadro>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    auto itRelacao = relacaoPessoaQuadro.find(emailDono.getValor());

    if (itRelacao != relacaoPessoaQuadro.end()){
        for (auto it = itRelacao->second.begin(); it != itRelacao->second.end(); ++it){
            auto itQuadro = mapaQuadro.find(*it);
            if (itQuadro != mapaQuadro.end())
                listaRetorno->push_back(itQuadro->second);
        }
    }
    return !listaRetorno->empty();
}


// Implementacao dos métodos da classe ContainerCartao

bool ContainerCartao::incluir(const CartaodeAtividade& cartao, const Identificador& idQuadro){
    string chaveCartao = cartao.getIdentificador().getValor();
    string chaveQuadroRelacionado = idQuadro.getValor();

    if (mapaCartao.find(chaveCartao) != mapaCartao.end())
        return false;

    mapaCartao[chaveCartao] = cartao;

    // insere o quadro no hashmap e adiciona o id dos cartoes de atividade associados
    // ex.:relacaoQuadroCartoes["quadroA"] -> ["fazer A", "refazer B"] 
    relacaoQuadroCartoes[chaveQuadroRelacionado].push_back(chaveCartao);
    return true;
}

bool ContainerCartao::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    if (mapaCartao.erase(chave) == 0) // não esta presente
        return false;

    for (auto itMapa = relacaoQuadroCartoes.begin(); itMapa != relacaoQuadroCartoes.end(); ++itMapa){
        // itMapa->second é o vetor de strings de cartoes (["Atv. A", "Atv. B", ...])
        for (auto itVetor = itMapa->second.begin(); itVetor != itMapa->second.end(); ++itVetor){
            if (*itVetor == chave){
                itMapa->second.erase(itVetor);
                break;
            }
        }
    }

    return true;
}

bool ContainerCartao::pesquisar(const Identificador& identificador, CartaodeAtividade* cartaoRetorno){
    string chave = identificador.getValor();

    auto it = mapaCartao.find(chave);
    if (it != mapaCartao.end()){
        *cartaoRetorno = it->second;
        return true;
    }
    return false;
}


bool ContainerCartao::atualizar(const CartaodeAtividade& cartao){
    string chave = cartao.getIdentificador().getValor();

    if (mapaCartao.find(chave) != mapaCartao.end()){
        mapaCartao[chave] = cartao;
        return true;
    }
    return false;
}

bool ContainerCartao::listar(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    auto itRelacao = relacaoQuadroCartoes.find(idQuadro.getValor());

    if (itRelacao != relacaoQuadroCartoes.end()){
        for (auto it = itRelacao->second.begin(); it != itRelacao->second.end(); ++it){
            auto itQuadro = mapaCartao.find(*it);
            if (itQuadro != mapaCartao.end())
                listaRetorno->push_back(itQuadro->second);
        }
    }
    return !listaRetorno->empty();
}
