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

    if (mapaProjetos.find(chave) != mapaProjetos.end())
        return false;
    mapaProjetos[chave] = projeto;
    return true;
}

bool ContainerProjeto::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    return mapaProjetos.erase(chave) > 0;
}

bool ContainerProjeto::pesquisar(const Identificador& identificador, Projeto* projetoRetorno){
    string chave = identificador.getValor();
    
    auto it = mapaProjetos.find(chave);
    if (it != mapaProjetos.end()){
        *projetoRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerProjeto::atualizar(const Projeto& projeto){
    string chave = projeto.getIdentificador().getValor();

    if (mapaProjetos.find(chave) != mapaProjetos.end()){
        mapaProjetos[chave] = projeto;
        return true;
    }
    return false;
}

bool ContainerProjeto::listar(const Email& gestor, std::list<Projeto>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    string chaveGestor = gestor.getValor();

    for (auto it = mapaProjetos.begin(); it != mapaProjetos.end(); ++it){
        if (it->second.getGestor().getValor() == chaveGestor){
            listaRetorno->push_back(it->second);
        }
    }
    return !listaRetorno->empty();
}

// Implementacao dos métodos da classe ContainerQuadro

bool ContainerQuadro::incluir(const Quadro& quadro){
    string chaveQuadro = quadro.getIdentificador().getValor();

    if (mapaQuadros.find(chaveQuadro) != mapaQuadros.end())
        return false;

    mapaQuadros[chaveQuadro] = quadro;
    return true;
}

bool ContainerQuadro::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    return mapaQuadros.erase(chave) > 0;
}

bool ContainerQuadro::pesquisar(const Identificador& identificador, Quadro* quadroRetorno){
    string chave = identificador.getValor();

    auto it = mapaQuadros.find(chave);
    if (it != mapaQuadros.end()){
        *quadroRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerQuadro::atualizar(const Quadro& quadro){
    string chave = quadro.getIdentificador().getValor();

    if (mapaQuadros.find(chave) != mapaQuadros.end()){
        mapaQuadros[chave] = quadro;
        return true;
    }
    return false;
}

bool ContainerQuadro::listar(const Identificador& idProjeto, std::list<Quadro>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    string chaveProjeto = idProjeto.getValor();

    for (auto it = mapaQuadros.begin(); it != mapaQuadros.end(); ++it){
        if (it->second.getIdProjeto().getValor() == chaveProjeto){
            listaRetorno->push_back(it->second);
        }
    }
    return !listaRetorno->empty();
}

// Implementacao dos métodos da classe ContainerCartao

bool ContainerCartao::incluir(const CartaodeAtividade& cartao){
    string chaveCartao = cartao.getIdentificador().getValor();

    if (mapaCartoes.find(chaveCartao) != mapaCartoes.end())
        return false;

    mapaCartoes[chaveCartao] = cartao;
    return true;
}

bool ContainerCartao::remover(const Identificador& identificador){
    string chave = identificador.getValor();
    return mapaCartoes.erase(chave) > 0;
}

bool ContainerCartao::pesquisar(const Identificador& identificador, CartaodeAtividade* cartaoRetorno){
    string chave = identificador.getValor();

    auto it = mapaCartoes.find(chave);
    if (it != mapaCartoes.end()){
        *cartaoRetorno = it->second;
        return true;
    }
    return false;
}

bool ContainerCartao::atualizar(const CartaodeAtividade& cartao){
    string chave = cartao.getIdentificador().getValor();

    if (mapaCartoes.find(chave) != mapaCartoes.end()){
        mapaCartoes[chave] = cartao;
        return true;
    }
    return false;
}

bool ContainerCartao::listar(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    string chaveQuadro = idQuadro.getValor();

    for (auto it = mapaCartoes.begin(); it != mapaCartoes.end(); ++it){
        if (it->second.getIdQuadro().getValor() == chaveQuadro){
            listaRetorno->push_back(it->second);
        }
    }
    return !listaRetorno->empty();
}

bool ContainerCartao::listarPorDesenvolvedor(const Email& desenvolvedor, std::list<CartaodeAtividade>* listaRetorno){
    if (listaRetorno == nullptr)
        return false;

    listaRetorno->clear();
    string chaveDev = desenvolvedor.getValor();

    for (auto it = mapaCartoes.begin(); it != mapaCartoes.end(); ++it){
        if (it->second.getDesenvolvedor().getValor() == chaveDev){
            listaRetorno->push_back(it->second);
        }
    }
    return !listaRetorno->empty();
}