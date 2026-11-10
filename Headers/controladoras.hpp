#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

#include "interfaces.hpp"
#include "entidades.hpp"
#include <unordered_map>
#include <vector>

/**
 * @file controladoras.hpp
 * @brief Declaração das controladoras de apresentação e serviço.
 * @author Mateus Christ Neves Pereira (apresentação) e Ítalo Miranda Gomes (serviço)
 */

// Declaracao das controladoras da camada de apresentacao







// Declaracao das controladoras da camada de servico

/**
 * @class CntrSerAutenticacao
 * @brief Controladora de serviço responsável por gerenciar a autenticação/login de um usuário no sistema.
 */
class CntrSerAutenticacao : public ISerAutenticacao {
public:
    /**
     * @brief Autentica as credenciais de e-mail e senha do usuário.
     * @param email Instância de email contendo a identificação do usuário.
     * @param senha Instância de senha contendo a credencial do usuário.
     * @return true Se a instância é válida/existe no sistema.
     * @return false Caso contrário.
     */
    bool autenticar(const Email& email, const Senha& senha) override;
};

/**
 * @class CntrSerPessoas
 * @brief Controladora responsável pela gestão dos serviços CRUD da entidade Pessoa.
 */
class CntrSerPessoas : public ISerPessoas {
public:
    /**
     * @brief Método responsável por registrar os dados de um novo usuário.
     * @param pessoa Referência para o objeto Pessoa com os dados a serem registrados.
     * @return true Se o registro foi efetuado com sucesso.
     * @return false Caso contrário.
     */
    bool criar(const Pessoa& pessoa) override;

    /**
     * @brief Método responsável por consultar e recuperar os dados de um usuário no sistema de software.
     * @param pessoaRetorno Ponteiro para o objeto Pessoa onde serão preenchidos e retornados os dados completos.
     * @return true Se os dados foram encontrados.
     * @return false Caso contrário.
     */
    bool ler(Pessoa* pessoaRetorno) override;

    /**
     * @brief Método responsável por atualizar os dados registrados de um usuário.
     * @param pessoa Referência para o objeto Pessoa contendo os novos dados.
     * @return true Se a operação foi realizada com sucesso.
     * @return false Caso contrário.
     */
    bool atualizar(const Pessoa& pessoa) override;

    /**
     * @brief Método responsável por remover o registro de uma pessoa do sistema.
     * @param email Referência para o Email associado à conta a ser removida.
     * @return true Se a remoção foi realizada com sucesso.
     * @return false Caso contrário.
     */
    bool excluir(const Email& email) override;
};

/**
 * @class CntrSerProjetos
 * @brief Controladora responsável pela gestão dos serviços CRUD da entidade Projeto.
 */
class CntrSerProjetos : public ISerProjetos {
public:
    /**
     * @brief Método responsável por registrar os dados de um novo projeto.
     * @param projeto Referência para o objeto Projeto a ser cadastrado.
     * @return true Se a criação teve sucesso.
     * @return false Caso contrário.
     */
    bool criar(const Projeto& projeto) override;

    /**
     * @brief Recupera as informações de um projeto.
     * @param projetoRetorno Ponteiro para o objeto Projeto onde serão armazenados os dados recuperados.
     * @return true Se o projeto foi encontrado.
     * @return false Caso contrário.
     */
    bool ler(Projeto* projetoRetorno) override;

    /**
     * @brief Atualiza as informações de um projeto existente.
     * @param projeto Referência para o objeto Projeto com as informações modificadas.
     * @return true Se a alteração for realizada com sucesso.
     * @return false Caso contrário.
     */
    bool atualizar(const Projeto& projeto) override;

    /**
     * @brief Remove um projeto cadastrado.
     * @param identificador Referência para a chave de identificação do projeto a ser removido.
     * @return true Se a remoção for realizada com sucesso.
     * @return false Caso contrário.
     */
    bool excluir(const Identificador& identificador) override;
};

/**
 * @class CntrSerQuadros
 * @brief Controladora responsável pela gestão dos serviços CRUD e Listar das entidades Quadros e Cartões de Atividade.
 * @details Centraliza as operações de serviço responsáveis pelo manejamento de quadros, bem como os cartões de atividade que os compõem. 
 * Além disso, é responsável pelo cálculo das métricas de cartões de atividade.
 */
class CntrSerQuadros : public ISerQuadros {
public:
    /**
     * @brief Registra um novo quadro de atividades no sistema.
     * @param quadro Referência para o objeto Quadro a ser salvo.
     * @return true Se o registro for efetuado com sucesso.
     * @return false Caso o projeto pai não exista ou a inclusão falhe.
     */
    bool criar(const Quadro& quadro) override;

    /**
     * @brief Consulta e carrega as informações de um quadro de atividades.
     * @param quadroRetorno Ponteiro para o objeto Quadro onde os dados recuperados serão armazenados.
     * @return true Se o quadro for localizado.
     * @return false Caso contrário.
     */
    bool ler(Quadro* quadroRetorno) override;

    /**
     * @brief Atualiza as informações de um quadro existente.
     * @param quadro Referência para o objeto Quadro contendo as novas informações.
     * @return true Se a atualização for concluída com sucesso.
     * @return false Caso contrário.
     */
    bool atualizar(const Quadro& quadro) override;

    /**
     * @brief Remove um quadro registrado do sistema e seus cartões vinculados (exclusão em cascata).
     * @param identificador Referência para a chave de identificação do quadro a ser removido.
     * @return true Se a remoção for realizada com sucesso.
     * @return false Caso contrário.
     */
    bool excluir(const Identificador& identificador) override;

    /**
     * @brief Lista todos os quadros associados a um usuário (gestor) do sistema.
     * @param emailDono O e-mail do usuário utilizado para buscar os quadros associados.
     * @param listaQuadrosRetorno Ponteiro para a lista onde serão inseridos os quadros encontrados.
     * @return true Se a busca foi bem-sucedida.
     * @return false Caso contrário.
     */
    bool listar(const Email& emailDono, std::list<Quadro>* listaQuadrosRetorno) override;

    /**
     * @brief Registra um novo cartão de atividade no sistema associando-o a um quadro.
     * @param cartao Referência para o objeto CartaodeAtividade a ser salvo.
     * @param idQuadro Identificador do quadro ao qual o cartão pertencerá.
     * @return true Se o registro for efetuado com sucesso.
     * @return false Caso o quadro não exista.
     */
    bool criarCartao(const CartaodeAtividade& cartao, const Identificador& idQuadro) override;

    /**
     * @brief Consulta e carrega as informações de um cartão de atividade.
     * @param cartaoRetorno Ponteiro para o objeto CartaodeAtividade onde os dados serão armazenados.
     * @return true Se o cartão for localizado.
     * @return false Caso contrário.
     */
    bool lerCartao(CartaodeAtividade* cartaoRetorno) override;

    /**
     * @brief Atualiza as informações de um cartão de atividade existente, validando o limite de WIP do quadro.
     * @param cartao Referência para o objeto CartaodeAtividade contendo as novas informações.
     * @return true Se a atualização for concluída com sucesso.
     * @return false Se a transição estourar o limite de WIP ou o cartão não for localizado.
     */
    bool atualizarCartao(const CartaodeAtividade& cartao) override;

    /**
     * @brief Remove um cartão de atividade registrado do sistema.
     * @param identificador Referência para a chave de identificação do cartão a ser removido.
     * @return true Se o cartão foi excluído com sucesso.
     * @return false Caso contrário.
     */
    bool excluirCartao(const Identificador& identificador) override;

    /**
     * @brief Lista todos os cartões de atividades associados a um quadro específico.
     * @param idQuadro O identificador do quadro do qual se deseja listar os cartões.
     * @param listaCartoesRetorno Ponteiro para a lista onde serão armazenados os cartões obtidos.
     * @return true Se a busca foi bem-sucedida.
     * @return false Caso contrário.
     */
    bool listarCartoes(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaCartoesRetorno) override;

    /**
     * @brief Promove a transição de estado de um cartão no fluxo Kanban.
     * @details Realiza as movimentações permitidas pelo sistema (A FAZER -> FAZENDO e FAZENDO -> FEITO).
     * Ao mover para FAZENDO, valida se a quantidade de cartões em execução não excede o Limite de WIP do Quadro
     * e grava a marca temporal no atributo de início. Ao mover para FEITO, registra a marca temporal no atributo de término.
     * @param idCartao Identificador da atividade a ser movimentada.
     * @param novoEstado Instância com o novo estado de destino.
     * @param momentoAtual Instância de Timestamp registrando o momento da transição.
     * @return true Se a movimentação for realizada com sucesso.
     * @return false Caso a transição seja inválida ou o limite de WIP seja excedido.
     */
    bool moverCartao(const Identificador& idCartao, const Estado& novoEstado, const Timestamp& momentoAtual) override;

    /**
     * @brief Consulta o Tempo de Ciclo (Cycle Time) de uma atividade concluída.
     * @details Calcula o tempo de execução ativa medindo a diferença temporal a partir do momento em que o cartão
     * entra na coluna FAZENDO até o instante em que chega à coluna FEITO (Término - Início).
     * @param idCartao Identificador do cartão consultado.
     * @param tempoSegundosRetorno Ponteiro onde será armazenado o valor do tempo obtido em segundos.
     * @return true Se a medição for realizada com sucesso.
     * @return false Caso o cartão não exista ou ainda não esteja no estado FEITO.
     */
    bool lerTempoCiclo(const Identificador& idCartao, double* tempoSegundosRetorno) override;

    /**
     * @brief Consulta o Tempo de Ciclo médio dos cartões concluídos de um quadro.
     * @details Realiza a média aritmética do Tempo de Ciclo (Cycle Time) de todas as atividades que se encontram
     * na coluna FEITO pertencentes a um determinado quadro.
     * @param idQuadro Identificador do quadro alvo.
     * @param mediaSegundosRetorno Ponteiro onde será armazenada a média calculada em segundos.
     * @return true Se a média for calculada com sucesso.
     * @return false Caso não existam cartões concluídos no quadro.
     */
    bool lerTempoCicloMedio(const Identificador& idQuadro, double* mediaSegundosRetorno) override;

    /**
     * @brief Consulta o Lead Time de uma atividade concluída.
     * @details Calcula o tempo total de permanência da tarefa no sistema medindo a diferença temporal a partir do momento
     * em que o cartão entra na coluna A FAZER até o instante em que chega à coluna FEITO (Término - Entrada).
     * @param idCartao Identificador do cartão consultado.
     * @param tempoSegundosRetorno Ponteiro onde será armazenado o valor do tempo obtido em segundos.
     * @return true Se a medição for realizada com sucesso.
     * @return false Caso o cartão não exista ou ainda não esteja no estado FEITO.
     */
    bool lerLeadTime(const Identificador& idCartao, double* tempoSegundosRetorno) override;

    /**
     * @brief Consulta o Lead Time médio dos cartões concluídos de um quadro.
     * @details Realiza a média aritmética do Lead Time de todas as atividades que se encontram na coluna FEITO
     * pertencentes a um determinado quadro.
     * @param idQuadro Identificador do quadro alvo.
     * @param mediaSegundosRetorno Ponteiro onde será armazenada a média calculada em segundos.
     * @return true Se a média for calculada com sucesso.
     * @return false Caso não existam cartões concluídos no quadro.
     */
    bool lerLeadTimeMedio(const Identificador& idQuadro, double* mediaSegundosRetorno) override;

    /**
     * @brief Consulta a métrica de Work in Progress (WIP) de um quadro.
     * @details Contabiliza o número total de cartões de atividade que estão sendo executados simultaneamente,
     * identificando quantos cartões estão alocados na coluna FAZENDO do quadro especificado.
     * @param idQuadro Identificador do quadro alvo.
     * @param quantidadeWIPRetorno Ponteiro onde será armazenado o valor inteiro com a contagem de tarefas em andamento.
     * @return true Se a contagem for realizada com sucesso.
     * @return false Caso contrário.
     */
    bool lerWIP(const Identificador& idQuadro, int* quantidadeWIPRetorno) override;
};

#endif // CONTROLADORAS_HPP