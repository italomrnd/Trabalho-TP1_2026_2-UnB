#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <string>
#include "entidades.hpp"

using namespace std;


// AUTENTICACAO

/**
 * @class IAprAutenticacao
 * @brief Interface para a camada de apresentação do fluxo de autenticação.
 */

class IAprAutenticacao{
    public:
    /**
     * @brief Solicita as credenciais ao usuário e registra a identificação autenticada.
     * @param email Ponteiro para o objeto Email onde será retornado o e-mail do usuário autenticado.
     * @return true Se a autenticação for bem-sucedida
     * @return false Caso contrário.
     */
        virtual bool autenticar(Email *) = 0;
};

/**
 * @class ISerAutenticacao
 * @brief Interface para a camada de serviço de validação de credenciais do usuário.
 */

class ISerAutenticacao{
    /**
     * @brief Valida as credenciais fornecidas.
     * @param email Referência para a entidade Email contendo a identificação obtida.
     * @param senha Referência para a entidade Senha contendo a credencial obtida.
     * @return true Se as credenciais forem válidas.
     * @return false Caso contrário.
     * 
     */
    public:
        virtual bool autenticar(const Email&, const Senha&) = 0;
};

// PESSOAS

/**
 * @class IAprPessoas 
 * @brief Interface para a camada de apresentação da gestão de contas de pessoas.
 */

class IAprPessoas{
    public:
        /**
         * @brief Método responsável por solicitar dados e realizar o cadastro inicial de um usuário do sistema de software
         */
        virtual void criar() = 0;

        /**
         * @brief Gerencia a execução do submenu de opções de conta do utilizador logado
         * @param Referência para o e-mail do utilizador autenticado na sessão.
         * @return true Se a sessão deve continuar ativa.
         * @return false Caso contrário. 
         */

        virtual bool exec(const Email&) = 0; 
};

/**
 * @class ISerPessoas
 * @brief Interface para a camada de serviço de gestão de pessoas.
 */

class ISerPessoas{
    public:
        /**
         * @brief Método responsável por registrar os dados de um novo usuário.
         * @param pessoa Referência para o objeto Pessoa com os dados a serem registrados.
         * @return true Se o registro foi efetuado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Pessoa&) = 0;

        /**
         * @brief Método responsável por consultar e recuperar os dados de um usuário no sistema de software.
         * @param pessoa Ponteiro para o objeto Pessoa preenchido com a chave primária e onde serão retornados os dados completos.
         * @return true Se os dados foram encontrados.
         * @return false Caso contrário.    
         */
        virtual bool ler(Pessoa*) = 0;

        /**
         * @brief Método responsável por atualizar os dados registrados de um usuário.
         * @param pessoa Referência para o objeto Pessoa contendo os dados 
         * @return true Se a operação foi realizada com sucesso.
         * @return false Caso contrário.
         */
        
        virtual bool atualizar(const Pessoa&) = 0;
        
        /**
         * @brief Método responsável por remover o registro de uma pessoa do sistema.
         * @param email Referência para o Email associado à conta a ser removida.
         * @return true Se a remoção foi realizada com sucesso.
         * @return false Caso contrário.  
         */

        virtual bool excluir(const Email&) = 0;
    // teremos no futuro o virtual bool listar no futuro, como resolver isso?
};

// PROJETOS

/**
 * @class IAprProjetos
 * @brief Interface para a camada de apresentação da gestão de projetos.
 */

class IAprProjetos{
    public:
        /**
         * @brief Gerencia a execução do submenu de navegação e operações de projetos.
         * @param email Referência para o Email do utilizador autenticado na sessão.
         */
        virtual void exec(const Email&) = 0;
};

/**
 * @class ISerProjetos
 * @brief Interface para camada de serviço de gestão de projetos.
 */

class ISerProjetos{
    public:
        /**
         * @brief Método responsável por registrar os dados de um novo projeto.
         * @param projeto Referência para o objeto Projeto a ser cadastrado.
         * @return true Se a criação teve sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Projeto&) = 0;

        /**
         * @brief Recupera as informações de um projeto.
         * @param projeto Ponteiro para o objeto Projeto a ser preenchido com o código de busca.
         * @return true Se o projeto foi encontrado.
         * @return false Caso contrário
         */
        virtual bool ler(Projeto*) = 0;

        /**
         * @brief Atualiza as informações de um projeto existente. 
         * @param projeto Referência para o objeto Projeto com as informações modificadas. 
         * @return true Se a alteração for realizada com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizar(const Projeto&) = 0;

        /**
         * @brief Remove um projeto cadastrado.
         * @param identificador Referência para a chave de identificação do projeto a ser removido.
         * @return true Se a remoção for realizada com sucesso.
         * @retrun false Caso contrário.
         */
        virtual bool excluir(const Identificador&) = 0;
};

// QUADROS 

/**
 * @class IAprQuadros
 * @brief Interface para a camada de apresentação da gestão de quadros.
 */

class IAprQuadros{
    public:
        /**
         * @brief Gerencia a execução do submenu de navegação e operações de quadros.
         * @param email Referência para o email do utilizador autenticado na sessão.
         */
        virtual void exec(const Email&) = 0;
};

/**
 * @class ISerQuadros
 * @brief Interface para a camada de serviço de gestão de quadros.
 */

class ISerQuadros{
    public:
        /**
         * @brief Registra um novo quadro de atividades no sistema.
         * @param quadro Referência para o objeto Quadro a ser salvo.
         * @return true Se o registro for efetuado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool criar(const Quadro&) = 0;

        /**
         * @brief Consulta e carrega as informações de um quadro de atividades.
         * @param quadro Ponteiro para o objeto Quadro contendo o código de busca e onde os dados recuperados serão armazenados.
         * @return true Se o quadro for localizado.
         * @return false Caso contrário.
         */
        virtual bool ler(Quadro*) = 0;

        /**
         * @brief Atualiza as informações de um quadro existente.
         * @param quadro Referência para o objeto Quadro contendo as novas informações.
         * @return true Se a atualização for concluída com sucesso.
         * @return false Caso contrário.
         */
        virtual bool atualizar(const Quadro&) = 0;


        /**
         * @brief Remove um quadro registrado do sistema.
         * @param identificador Referência para a chave de identificação do quadro a ser removido do sistema de software. 
         * @return true Se o quadro foi excluído com sucesso.
         * @return false Caso contrário.
         */
        virtual bool excluir(const Identificador) = 0;
};

#endif // INTERFACES_HPP_INCLUDED