#ifndef CONTAINERS_CPP
#define CONTAINERS_CPP

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

// Implementacao dos métodos da classe ContainerCartao

bool ContainerQuadro::incluir(const Quadro& quadro){
    string chave = quadro.getIdentificador().getValor();
}

bool ContainerQuadro::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    return mapaQuadro.erase(chave) > 0;
}

bool ContainerQuadro::pesquisar(const Identificador& identificador, Quadro* quadroRetorno){
    string chave = identificador.getValor();
    auto it = mapaQuadro.find(chave);
    if (it != mapaQuadro.end()){
        *quadroRetorno = it->second;
    }
}

bool ContainerQuadro::atualizar(const Quadro& quadro){
    string chave = quadro.getIdentificador().getValor();
    if (mapaQuadro.find(chave) != mapaQuadro.end()){
        mapaQuadro[chave] = quadro;
    }
}


#endif // CONTAINERS_CPP
