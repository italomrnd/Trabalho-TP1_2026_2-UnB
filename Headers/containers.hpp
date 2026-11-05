#ifndef CONTEINERS_HPP
#define CONTEINERS_HPP

#include "entidades.hpp"
#include <unordered_map>
#include <string>

/**
 * @file containers.hpp
 * @brief Declaração dos containers utilizados pelo sistema para armazenamento das entidades
 * @author Mateus Christ Neves Pereira
 */

/**
 * @class ContainerPessoa
 * @brief Classe que representa o armazenamento de instâncias da classe Pessoa.
 * @details A classe utiliza da estrutura mapa para armazenar as instâncias e facilitar o encontro e remoção
 * dessas utilizando o Email como chave primária de procura.
 */
class ContainerPessoa {
private:
    std::unordered_map<std::string, Pessoa> mapaPessoas; ///< Instância de Mapa que irá armazenar as instâncias de Pessoa.

public:
/**
 * @brief Adiciona uma instância dada de Pessoa no mapa.
 * @param pessoa Pessoa que deseja-se adicionar.
 * @return true Se foi possível adicionar ao mapa.
 * @return false Se não foi possível adicionar ao mapa, já existe uma instância no mapa com aquele identificador.
 */
    bool incluir(const Pessoa& pessoa);

/**
 * @brief Remove uma pessoa do mapa a partir de um Email informado.
 * @param email Email que será utilizado para a procura da instância a ser removida.
 * @return true Se houve remoção.
 * @return false Se aquele identificador não está presente no mapa.
 */
    bool remover(const Email& email);

/**
 * @brief Procura pela existência de uma Pessoa através de um Email informado e atualiza os dados de um ponteiro de Pessoa
 * para copiar os dados encontrados.
 * @param email Email usado para a procura.
 * @param pessoaRetorno Ponteiro de Pessoa que retornará os dados encontrados.
 * @return true Se encontrou aquele Email no Mapa.
 * @return false Se não encontrou.
 */
    bool pesquisar(const Email& email, Pessoa* pessoaRetorno);

/**
 * @brief Procura por uma instância de Pessoa com o mesmo identificador Email e a substitui pela dada.
 * @param pessoa Novos dados que serão colocados no lugar dos anteriores.
 * @return true Se houve a atualização.
 * @return false Se não foi encontrada nenhuma instância com o mesmo identificador informado.
 */
    bool atualizar(const Pessoa& pessoa);
};


/**
 * @class ContainerProjeto
 * @brief Classe que representa o armazenamento de instâncias da classe Projeto.
 * @details A classe utiliza da estrutura mapa para armazenar as instâncias e facilitar o encontro e remoção
 * dessas utilizando o Identificador como chave primária de procura.
 */
class ContainerProjeto {
private:
    std::unordered_map<std::string, Projeto> mapaProjeto; ///< Instância de Mapa que irá armazenar as instâncias de Projeto.

public:
/**
 * @brief Adiciona uma instância dada de Projeto no mapa.
 * @param projeto Projeto que deseja-se adicionar.
 * @return true Se foi possível adicionar ao mapa.
 * @return false Se não foi possível adicionar ao mapa, já existe uma instância no mapa com aquele identificador.
 */
    bool incluir(const Projeto& projeto);

/**
 * @brief Remove um projeto do mapa a partir de um Identificador informado.
 * @param identificador Identificador que será utilizado para a procura da instância a ser removida.
 * @return true Se houve remoção.
 * @return false Se aquele identificador não está presente no mapa.
 */
    bool remover(const Identificador& identificador);

/**
 * @brief Procura pela existência de um Projeto através de um Identificador informado e atualiza os dados de um ponteiro de Projeto
 * para copiar os dados encontrados.
 * @param identificador Identificador usado para a procura.
 * @param projetoRetorno Ponteiro de Projeto que retornará os dados encontrados.
 * @return true Se encontrou aquele Identificador no Mapa.
 * @return false Se não encontrou.
 */
    bool pesquisar(const Identificador& identificador, Projeto* projetoRetorno);

/**
 * @brief Procura por uma instância de Projeto com o mesmo Identificador e a substitui pela dada.
 * @param projeto Novos dados que serão colocados no lugar dos anteriores.
 * @return true Se houve a atualização.
 * @return false Se não foi encontrada nenhuma instância com o mesmo identificador informado.
 */
    bool atualizar(const Projeto& projeto);
};


/**
 * @class ContainerQuadro
 * @brief Classe que representa o armazenamento de instâncias da classe Quadro.
 * @details A classe utiliza da estrutura mapa para armazenar as instâncias e facilitar o encontro e remoção
 * dessas utilizando o Identificador como chave primária de procura.
 */
class ContainerQuadro {
private:
    std::unordered_map<std::string, Quadro> mapaQuadro; ///< Instância de Mapa que irá armazenar as instâncias de Quadro.

public:
/**
 * @brief Adiciona uma instância dada de Quadro no mapa.
 * @param quadro Quadro que deseja-se adicionar.
 * @return true Se foi possível adicionar ao mapa.
 * @return false Se não foi possível adicionar ao mapa, já existe uma instância no mapa com aquele identificador.
 */
    bool incluir(const Quadro& quadro);

/**
 * @brief Remove um Quadro do mapa a partir de um Identificador informado.
 * @param identificador Identificador que será utilizado para a procura da instância a ser removida.
 * @return true Se houve remoção.
 * @return false Se aquele identificador não está presente no mapa.
 */
    bool remover(const Identificador& identificador);

/**
 * @brief Procura pela existência de um Quadro através de um Identificador informado e atualiza os dados de um ponteiro de Quadro
 * para copiar os dados encontrados.
 * @param identificador Identificador usado para a procura.
 * @param quadroRetorno Ponteiro de Quadro que retornará os dados encontrados.
 * @return true Se encontrou aquele Identificador no Mapa.
 * @return false Se não encontrou.
 */
    bool pesquisar(const Identificador& identificador, Quadro* quadroRetorno);

/**
 * @brief Procura por uma instância de Quadro com o mesmo Identificador e a substitui pela dada.
 * @param quadro Novos dados que serão colocados no lugar dos anteriores.
 * @return true Se houve a atualização.
 * @return false Se não foi encontrada nenhuma instância com o mesmo identificador informado.
 */
    bool atualizar(const Quadro& quadro);
};


/**
 * @class ContainerCartao
 * @brief Classe que representa o armazenamento de instâncias da classe CartaodeAtividade.
 * @details A classe utiliza da estrutura mapa para armazenar as instâncias e facilitar o encontro e remoção
 * dessas utilizando o Identificador como chave primária de procura.
 */
class ContainerCartao {
private:
    std::unordered_map<std::string, CartaodeAtividade> mapaCartao; ///< Instância de Mapa que irá armazenar as instâncias de CartaodeAtividade.

public:
/**
 * @brief Adiciona uma instância dada de CartaodeAtividade no mapa.
 * @param cartao CartaodeAtividade que deseja-se adicionar.
 * @return true Se foi possível adicionar ao mapa.
 * @return false Se não foi possível adicionar ao mapa, já existe uma instância no mapa com aquele identificador.
 */
    bool incluir(const CartaodeAtividade& cartao);

/**
 * @brief Remove um CartaodeAtividade do mapa a partir de um Identificador informado.
 * @param identificador Identificador que será utilizado para a procura da instância a ser removida.
 * @return true Se houve remoção.
 * @return false Se aquele identificador não está presente no mapa.
 */
    bool remover(const Identificador& identificador);

/**
 * @brief Procura pela existência de um CartaodeAtividade através de um Identificador informado e atualiza os dados de um ponteiro de CartaodeAtividade
 * para copiar os dados encontrados.
 * @param identificador Identificador usado para a procura.
 * @param cartaoRetorno Ponteiro de CartaodeAtividade que retornará os dados encontrados.
 * @return true Se encontrou aquele Identificador no Mapa.
 * @return false Se não encontrou.
 */
    bool pesquisar(const Identificador& identificador, CartaodeAtividade* cartaoRetorno);

/**
 * @brief Procura por uma instância de CartaodeAtividade com o mesmo Identificador e a substitui pela dada.
 * @param cartao Novos dados que serão colocados no lugar dos anteriores.
 * @return true Se houve a atualização.
 * @return false Se não foi encontrada nenhuma instância com o mesmo identificador informado.
 */
    bool atualizar(const CartaodeAtividade& cartao);
};

#endif // CONTEINERS_HPP