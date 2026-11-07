#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <string>
#include <list>
#include "entidades.hpp"

/**
 * @file interfaces.hpp
 * @brief Declaração das interfaces do sistema de software.
 * @author Ítalo Miranda Gomes
 */

/**
 * @class IAprAutenticacao
 * @brief Interface para a camada de apresentação do fluxo de autenticação.
 */
class IAprAutenticacao {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAprAutenticacao() = default;

        /**
         * @brief Solicita as credenciais ao usuário e registra a identificação autenticada.
         * @param email Ponteiro para o objeto Email onde será retornado o e-mail do usuário autenticado.
         * @return true Se a autenticação for bem-sucedida.
         * @return false Caso contrário.
         */
        virtual bool autenticar(Email*) = 0;
};

/**
 * @class ISerAutenticacao
 * @brief Interface para a camada de serviço de validação de credenciais do usuário.
 */
class ISerAutenticacao {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISerAutenticacao() = default;

        /**
         * @brief Valida as credenciais fornecidas.
         * @param email Referência para a entidade Email contendo a identificação obtida.
         * @param senha Referência para a entidade Senha contendo a credencial obtida.
         * @return true Se as credenciais forem válidas.
         * @return false Caso contrário.
         */
        virtual bool autenticar(const Email& email, const Senha& senha) = 0;
};

/**
 * @class IAprPessoas 
 * @brief Interface para a camada de apresentação da gestão de contas de pessoas.
 */
class IAprPessoas {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAprPessoas() = default;

        /**
         * @brief Método responsável por solicitar dados e realizar o cadastro inicial de um usuário do sistema.
         */
        virtual void criar() = 0;

        /**
         * @brief Gerencia a execução do submenu de opções de conta do utilizador logado.
         * @param email Referência para o e-mail do utilizador autenticado na sessão.
         * @return true Se a sessão deve continuar ativa.
         * @return false Caso contrário.
         */
        virtual bool exec(const Email& email) = 0; 
};

/**
 * @class ISerPessoas
 * @brief Interface para a camada de serviço de gestão de pessoas.
 */
class ISerPessoas {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISerPessoas() = default;

        /**
         * @brief Método responsável por registrar os dados de um novo usuário.
         * @param pessoa Referência para o objeto Pessoa com os dados a serem registrados.
         * @return true Se o registro foi efetuado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Pessoa& pessoa) = 0;

        /**
         * @brief Método responsável por consultar e recuperar os dados de um usuário no sistema de software.
         * @param pessoa Ponteiro para o objeto Pessoa preenchido com a chave primária e onde serão retornados os dados completos.
         * @return true Se os dados foram encontrados.
         * @return false Caso contrário.
         */
        virtual bool ler(Pessoa* pessoa) = 0;

        /**
         * @brief Método responsável por atualizar os dados registrados de um usuário.
         * @param pessoa Referência para o objeto Pessoa contendo os novos dados.
         * @return true Se a operação foi realizada com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizar(const Pessoa& pessoa) = 0;
        
        /**
         * @brief Método responsável por remover o registro de uma pessoa do sistema.
         * @param email Referência para o Email associado à conta a ser removida.
         * @return true Se a remoção foi realizada com sucesso.
         * @return false Caso contrário.
         */
        virtual bool excluir(const Email& email) = 0;
};

/**
 * @class IAprProjetos
 * @brief Interface para a camada de apresentação da gestão de projetos.
 */
class IAprProjetos {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAprProjetos() = default;

        /**
         * @brief Gerencia a execução do submenu de navegação e operações de projetos.
         * @param email Referência para o Email do utilizador autenticado na sessão.
         */
        virtual void exec(const Email& email) = 0;
};

/**
 * @class ISerProjetos
 * @brief Interface para camada de serviço de gestão de projetos.
 */
class ISerProjetos {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISerProjetos() = default;

        /**
         * @brief Método responsável por registrar os dados de um novo projeto.
         * @param projeto Referência para o objeto Projeto a ser cadastrado.
         * @return true Se a criação teve sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Projeto& projeto) = 0;

        /**
         * @brief Recupera as informações de um projeto.
         * @param projeto Ponteiro para o objeto Projeto a ser preenchido com o código de busca.
         * @return true Se o projeto foi encontrado.
         * @return false Caso contrário.
         */
        virtual bool ler(Projeto* projeto) = 0;

        /**
         * @brief Atualiza as informações de um projeto existente.
         * @param projeto Referência para o objeto Projeto com as informações modificadas.
         * @return true Se a alteração for realizada com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizar(const Projeto& projeto) = 0;

        /**
         * @brief Remove um projeto cadastrado.
         * @param identificador Referência para a chave de identificação do projeto a ser removido.
         * @return true Se a remoção for realizada com sucesso.
         * @return false Caso contrário.
         */
        virtual bool excluir(const Identificador& identificador) = 0;
};

/**
 * @class IAprQuadros
 * @brief Interface para a camada de apresentação da gestão de quadros e cartões de atividade.
 */
class IAprQuadros {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAprQuadros() = default;

        /**
         * @brief Gerencia a execução do submenu de navegação e operações de quadros e cartões.
         * @param email Referência para o email do utilizador autenticado na sessão.
         */
        virtual void exec(const Email& email) = 0;
};

/**
 * @class ISerQuadros
 * @brief Interface para a camada de serviço de gestão de quadros e cartões de atividade utilizando o padrão Facade.
 */
class ISerQuadros {
    public:
        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISerQuadros() = default;

        /**
         * @brief Registra um novo quadro de atividades no sistema.
         * @param quadro Referência para o objeto Quadro a ser salvo.
         * @return true Se o registro for efetuado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Quadro& quadro) = 0;

        /**
         * @brief Consulta e carrega as informações de um quadro de atividades.
         * @param quadro Ponteiro para o objeto Quadro contendo o código de busca e onde os dados recuperados serão armazenados.
         * @return true Se o quadro for localizado.
         * @return false Caso contrário.
         */
        virtual bool ler(Quadro* quadro) = 0;

        /**
         * @brief Atualiza as informações de um quadro existente.
         * @param quadro Referência para o objeto Quadro contendo as novas informações.
         * @return true Se a atualização for concluída com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizar(const Quadro& quadro) = 0;

        /**
         * @brief Remove um quadro registrado do sistema.
         * @param identificador Referência para a chave de identificação do quadro a ser removido.
         * @return true Se o quadro foi excluído com sucesso.
         * @return false Caso contrário.
         */
        virtual bool excluir(const Identificador& identificador) = 0;

        /**
         * @brief Lista todos os quadros associados a um usuário do sistema.
         * @param emailDono O email do usuário a ser utilizado para buscar os quadros associados.
         * @param listaRetorno Lista que carrega os dados obtidos na busca.
         * @return true Se a busca foi bem sucedida.
         * @return false Caso contrário.
         */
        virtual bool listar(const Email& emailDono, std::list<Quadro>* listaRetorno) = 0;

        /**
         * @brief Registra um novo cartão de atividade no sistema associando-o a um quadro.
         * @param cartao Referência para o objeto CartaodeAtividade a ser salvo.
         * @param idQuadro Identificador do quadro ao qual o cartão pertencerá.
         * @return true Se o registro for efetuado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool criarCartao(const CartaodeAtividade& cartao, const Identificador& idQuadro) = 0;

        /**
         * @brief Consulta e carrega as informações de um cartão de atividade.
         * @param cartao Ponteiro para o objeto CartaodeAtividade contendo o código de busca e onde os dados serão armazenados.
         * @return true Se o cartão for localizado.
         * @return false Caso contrário.
         */
        virtual bool lerCartao(CartaodeAtividade* cartao) = 0;

        /**
         * @brief Atualiza as informações de um cartão de atividade existente.
         * @param cartao Referência para o objeto CartaodeAtividade contendo as novas informações.
         * @return true Se a atualização for concluída com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizarCartao(const CartaodeAtividade& cartao) = 0;

        /**
         * @brief Remove um cartão de atividade registrado do sistema.
         * @param identificador Referência para a chave de identificação do cartão a ser removido.
         * @return true Se o cartão foi excluído com sucesso.
         * @return false Caso contrário.
         */
        virtual bool excluirCartao(const Identificador& identificador) = 0;

        /**
         * @brief Lista todos os cartões de atividades associados a um quadro específico.
         * @param idQuadro O identificador do quadro do qual se deseja listar os cartões.
         * @param listaRetorno Lista que carrega os dados obtidos na busca.
         * @return true Se a busca foi bem-sucedida.
         * @return false Caso contrário.
         */
        virtual bool listarCartoes(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaRetorno) = 0;
};

#endif // INTERFACES_HPP_INCLUDED