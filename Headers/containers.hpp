#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <unordered_map>
#include <string>
#include <list>
#include "entidades.hpp"

/**
 * @file containers.hpp
 * @brief Declaração dos containers de memória (RAM) utilizando std::unordered_map.
 * @author Ítalo Miranda Gomes
 */

// Declaracao dos containers de Pessoas

/**
 * @class ContainerPessoa
 * @brief Gerencia o armazenamento em RAM das instâncias da classe Pessoa.
 */
class ContainerPessoa {
private:
    std::unordered_map<std::string, Pessoa> mapaPessoas; ///< Tabela hash de armazenamento das pessoas utilizando o e-mail como chave primária.

public:
    /**
     * @brief Insere uma nova pessoa no container.
     * @param pessoa Referência para o objeto Pessoa a ser cadastrado.
     * @return true Se o cadastro foi realizado com sucesso.
     * @return false Caso a pessoa já esteja cadastrada no sistema.
     */
    bool incluir(const Pessoa& pessoa);

    /**
     * @brief Remove o registro de uma pessoa do container.
     * @param email Referência para o Email que atua como chave primária de remoção.
     * @return true Se a remoção for concluída com sucesso.
     * @return false Caso a pessoa não exista.
     */
    bool remover(const Email& email);

    /**
     * @brief Pesquisa os dados de uma pessoa no container.
     * @param email Referência para o Email de busca.
     * @param pessoaRetorno Ponteiro onde os dados da pessoa localizada serão armazenados.
     * @return true Se a pessoa for localizada.
     * @return false Caso contrário.
     */
    bool pesquisar(const Email& email, Pessoa* pessoaRetorno);

    /**
     * @brief Atualiza as informações de uma pessoa cadastrada.
     * @param pessoa Referência para a entidade Pessoa com as novas informações.
     * @return true Se a alteração for realizada com sucesso.
     * @return false Caso a pessoa não seja encontrada.
     */
    bool atualizar(const Pessoa& pessoa);
};

// Declaracao dos containers de Projeto

/**
 * @class ContainerProjeto
 * @brief Gerencia o armazenamento em RAM das instâncias da classe Projeto.
 */
class ContainerProjeto {
private:
    std::unordered_map<std::string, Projeto> mapaProjetos; ///< Tabela hash de armazenamento dos projetos utilizando o identificador como chave primária.

public:
    /**
     * @brief Insere um novo projeto no container.
     * @param projeto Referência para o objeto Projeto a ser cadastrado.
     * @return true Se a inserção foi efetuada com sucesso.
     * @return false Se o projeto já existir no container.
     */
    bool incluir(const Projeto& projeto);

    /**
     * @brief Remove um projeto do container.
     * @param identificador Referência para o Identificador do projeto a ser removido.
     * @return true Se a remoção for bem-sucedida.
     * @return false Caso contrário.
     */
    bool remover(const Identificador& identificador);

    /**
     * @brief Pesquisa um projeto no container.
     * @param identificador Referência para o Identificador do projeto buscado.
     * @param projetoRetorno Ponteiro onde os dados do projeto localizado serão preenchidos.
     * @return true Se o projeto for localizado.
     * @return false Caso contrário.
     */
    bool pesquisar(const Identificador& identificador, Projeto* projetoRetorno);

    /**
     * @brief Atualiza as informações de um projeto armazenado.
     * @param projeto Referência para a entidade Projeto contendo as novas informações.
     * @return true Se o projeto for atualizado com sucesso.
     * @return false Caso o projeto não seja encontrado.
     */
    bool atualizar(const Projeto& projeto);

    /**
     * @brief Lista todos os projetos onde o e-mail fornecido é o gestor responsável.
     * @param gestor Referência para o Email do gestor responsável pelos projetos.
     * @param listaRetorno Ponteiro para a lista onde serão inseridos os projetos encontrados.
     * @return true Se for localizado pelo menos um projeto associado.
     * @return false Caso nenhum projeto seja encontrado.
     */
    bool listar(const Email& gestor, std::list<Projeto>* listaRetorno);
};

// Declaracao dos containers de Quadro

/**
 * @class ContainerQuadro
 * @brief Gerencia o armazenamento em RAM das instâncias da classe Quadro.
 */
class ContainerQuadro {
private:
    std::unordered_map<std::string, Quadro> mapaQuadros; ///< Tabela hash de armazenamento dos quadros utilizando o identificador como chave primária.

public:
    /**
     * @brief Insere um novo quadro no container.
     * @param quadro Referência para o objeto Quadro a ser cadastrado.
     * @return true Se a inserção foi realizada com sucesso.
     * @return false Caso o quadro já esteja armazenado.
     */
    bool incluir(const Quadro& quadro);

    /**
     * @brief Remove um quadro registrado do container.
     * @param identificador Referência para o Identificador do quadro a ser removido.
     * @return true Se a exclusão for efetuada com sucesso.
     * @return false Caso contrário.
     */
    bool remover(const Identificador& identificador);

    /**
     * @brief Pesquisa as informações de um quadro no container.
     * @param identificador Referência para o Identificador do quadro buscado.
     * @param quadroRetorno Ponteiro onde os dados do quadro localizado serão armazenados.
     * @return true Se o quadro for localizado.
     * @return false Caso contrário.
     */
    bool pesquisar(const Identificador& identificador, Quadro* quadroRetorno);

    /**
     * @brief Atualiza as informações de um quadro existente.
     * @param quadro Referência para a entidade Quadro com os novos dados.
     * @return true Se a alteração for realizada com sucesso.
     * @return false Caso o quadro não exista.
     */
    bool atualizar(const Quadro& quadro);

    /**
     * @brief Lista todos os quadros associados a um projeto específico.
     * @param idProjeto Referência para o Identificador do projeto pai.
     * @param listaRetorno Ponteiro para a lista onde os quadros recuperados serão inseridos.
     * @return true Se ao menos um quadro for localizado.
     * @return false Caso contrário.
     */
    bool listar(const Identificador& idProjeto, std::list<Quadro>* listaRetorno);
};

// Declaracao dos containers de Cartao

/**
 * @class ContainerCartao
 * @brief Gerencia o armazenamento em RAM das instâncias da classe CartaodeAtividade.
 */
class ContainerCartao {
private:
    std::unordered_map<std::string, CartaodeAtividade> mapaCartoes; ///< Tabela hash de armazenamento dos cartões utilizando o identificador como chave primária.

public:
    /**
     * @brief Insere um novo cartão de atividade no container.
     * @param cartao Referência para o objeto CartaodeAtividade a ser cadastrado.
     * @return true Se o cartão for cadastrado com sucesso.
     * @return false Se o cartão já existir no sistema.
     */
    bool incluir(const CartaodeAtividade& cartao);

    /**
     * @brief Remove um cartão de atividade do container.
     * @param identificador Referência para o Identificador do cartão a ser removido.
     * @return true Se a exclusão for concluída com sucesso.
     * @return false Caso contrário.
     */
    bool remover(const Identificador& identificador);

    /**
     * @brief Pesquisa as informações de um cartão no container.
     * @param identificador Referência para o Identificador do cartão buscado.
     * @param cartaoRetorno Ponteiro onde os dados do cartão localizado serão armazenados.
     * @return true Se o cartão for encontrado.
     * @return false Caso contrário.
     */
    bool pesquisar(const Identificador& identificador, CartaodeAtividade* cartaoRetorno);

    /**
     * @brief Atualiza as informações de um cartão existente no container.
     * @param cartao Referência para a entidade CartaodeAtividade contendo os dados modificados.
     * @return true Se a atualização for concluída com sucesso.
     * @return false Se o cartão não for localizado.
     */
    bool atualizar(const CartaodeAtividade& cartao);

    /**
     * @brief Lista todos os cartões de atividade vinculados a um quadro específico.
     * @param idQuadro Referência para o Identificador do quadro pai.
     * @param listaRetorno Ponteiro para a lista onde os cartões encontrados serão salvos.
     * @return true Se ao menos um cartão for encontrado.
     * @return false Caso contrário.
     */
    bool listar(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaRetorno);

    /**
     * @brief Lista todos os cartões de atividade atribuídos a um determinado desenvolvedor.
     * @param desenvolvedor Referência para o Email do desenvolvedor associado aos cartões.
     * @param listaRetorno Ponteiro para a lista onde os cartões encontrados serão salvos.
     * @return true Se ao menos um cartão for encontrado.
     * @return false Caso contrário.
     */
    bool listarPorDesenvolvedor(const Email& desenvolvedor, std::list<CartaodeAtividade>* listaRetorno);
};

#endif // CONTAINERS_HPP_INCLUDED