#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

/**
 * @file entidades.hpp
 * @brief Declaração das classes das entidades do sistema de software
 * @author Mateus Christ Neves Pereira
 */
 

 /**
  * @class Pessoa
  * @brief Classe que representa um usuário do programa(Desenvolvedor ou Gestor)  
  * * @details A classe Pessoa é responsável por gerenciar a identidade e o acesso 
 * dos usuários no sistema Kanban. A forma principal de identificação e unicidade 
 * no sistema é garantida pela chave primária, enquanto suas permissões sobre
 * projetos e quadros são ditadas pelo papel que exercem.
  *     
  * 
  */
class Pessoa{
    private:
        Email email; ///< Chave Primária (PK), que atua como forma principal de identificação.
        Nome nome; ///< Instância que armazena o nome do usuário.
        Senha senha; ///< Credencial de acesso ao sistema.
        Papel papel; ///< Identifica o usuário como Gestor ou Desenvolvedor.
    public:
    /**
     * @brief Obtém a instância Email que está armazenada na variável email
     * @return Email armazenado
     */
        Email getEmail() const;

    /**
     * @brief Obtém a instância Nome que está armazenada na variável nome
     * 
     * @return Nome armazenado
     */
        Nome getNome() const;

    /**
     * @brief Obtém a instância Senha que está armazenada na variável senha
     * 
     * @return Senha armazenada
     */
        Senha getSenha() const;
    /**
     * @brief Obtém a instância Papel que está armazenada na variável papel
     * 
     * @return Papel armazenado
     */
        Papel getPapel() const;

    /**
     * @brief Define o email 
     * @param email Instância da classe Email
     */
        void setEmail(const Email&);

    /**
     * @brief Define o nome
     * @param nome Instância da classe Nome
     */
        void setNome(const Nome&);
    /**
     * @brief Define o papel
     * @param papel Instância da classe Papel
     * 
     */
        void setPapel(const Papel&);
    
    /**
     * @brief Define a senha
     * @param senha Instância da classe Senha
     * 
     */
        void setSenha(const Senha&);
};

/**
 * @class Projeto
 * @brief Classe que define um projeto de software que será gerenciado utilizando o método Kanban.
 * Todo projeto deve ser criado e gerido por um gestor.
 * 
 */
class Projeto{
    private:
        Identificador identificador;///< Chave Primária (PK), sendo o código único do projeto.
        Nome nome;///< Título do Projeto.
        Texto descricao;///< Descreve o objetivo e escopo do Projeto.
        Timestamp inicio;///< Data e hora do início do projeto.
        Timestamp termino;///< Data e hora do fim do projeto.
    public:

    /**
     * @brief Obtém o Identificador armazenado na variável identificador.
     * @return Identificador Armazenado
     */
        Identificador getIdentificador() const;
    /**
     * @brief Obtém o Nome armazenado na variável nome.
     * 
     * @return Nome armazenado
     */
        Nome getNome() const;

    /**
     * @brief Obtém o Texto armazenado na variável descricao.
     * 
     * @return Texto armazenado
     */
        Texto getDescricao() const;
    
    /**
     * @brief Obtém o Timestamp armazenado na variável inicio.
     * 
     * @return Timestamp do início do projeto
     */
        Timestamp getInicio() const;

    /**
     * @brief Obtém o Timestamp armazenado na variável termino.
     * 
     * @return Timestamp do fim do projeto
     */
        Timestamp getTermino() const;

/**
 * @brief Define o identificador.
 * @param identificador Instância da classe Identificador
 */
        void setIdentificador(const Identificador&);

/**
 * @brief Define o nome.
 * @param nome Instância da classe Nome
 * 
 */
        void setNome(const Nome&);

/**
 * @brief Define a descricao.
 * @param descricao Instância da classe Texto
 * 
 */
        void setDescricao(const Texto&);

/**
 * @brief Define o inicio.
 * @param inicio Instância da classe Timestamp
 * 
 */
        void setInicio(const Timestamp&);
/**
 * @brief Define o termino.
 * @param termino Instância da classe Timestamp
 * 
 */
        void setTermino(const Timestamp&);
};


/**
 * @class CartaodeAtividade
 * @brief É a unidade de trabalho dentro do Kanban, representando uma tarefa que pode estar
 * sobre um de três estados: A FAZER, FAZENDO e FEITO. Suas instâncias de Timestamp são usadas
 * para o cálculo de métricas do sistema, como o Lead Time e o Cycle time.
 * 
 */
class CartaodeAtividade{
    private:
        Identificador identificador; ///< Chave primária (PK) do tipo Identificador, atua como código único do cartão
        Nome nome;///< Título da atividade.
        Texto descricao;///< Descrição do que deve ser feito.
        Prioridade prioridade;///< Nível de urgência de realização do projeto (BAIXA, MÉDIA, ALTA).
        Estado estado;///< Coluna do Quadro em que se encontra (A FAZER, FAZENDO, FEITO).
        Tamanho tamanho;///< Estimativa do esforço para realização (PEQUENO, MEDIO, GRANDE).
        Timestamp entrada;///< Data e Hora em que a atividade entra na coluna "A FAZER".
        Timestamp inicio;///< Data e hora em que a a atividade entra na coluna "FAZENDO".
        Timestamp termino;///< Data e hora em que a atividade entra na coluna "FEITO".
    public:
/**
 * @brief Obtém o Identificador armazenado na variavel identificador.
 * 
 * @return Identificador armazenado
 */
        Identificador getIdentificador() const;

/**
 * @brief Obtém o Nome armazenado na variável nome.
 * 
 * @return Nome armazenado
 */
        Nome getNome() const;

/**
 * @brief Obtém a Descricao armazenada na variável descricao.
 * 
 * @return Texto que tem a descricao armazenada
 */
        Texto getDescricao() const;

/**
 * @brief Obtém a prioridade armazenada na variável prioridade.
 * 
 * @return Prioridade armazenada
 */
        Prioridade getPrioridade() const;

/**
 * @brief Obtém o Estado armazenado na variável estado.
 * 
 * @return Estado armazenado
 */
        Estado getEstado() const;

/**
 * @brief Obtém o Tamanho armazenado na variável tamanho.
 * 
 * @return Tamanho armazenado
 */
        Tamanho getTamanho() const;

/**
 * @brief Obtém o Timestamp armazenado na variável entrada.
 * 
 * @return Timestamp do momento em que a atividade entra na coluna "A FAZER"
 */
        Timestamp getEntrada() const;

/**
 * @brief Obtém o Timestamp armazenado na variável inicio.
 * 
 * @return Timestamp do momento em que a atividade entra na coluna "FAZENDO"
 */
        Timestamp getInicio() const;

/**
 * @brief Obtém o Timestamp armazenado na variável termino.
 * 
 * @return Timestamp do momento em que a atividade entra na coluna "FEITO"
 */
        Timestamp getTermino() const;

/**
 * @brief Define o identificador.
 * @param identificador instância da classe Identificador
 */
        void setIdentificador(const Identificador&);

/**
 * @brief Define o nome.
 * @param nome instância da classe Nome
 */
        void setNome(const Nome&);

/**
 * @brief Define a descricao.
 * @param descricao instância da classe Texto
 */
        void setDescricao(const Texto&);

/**
 * @brief Define a prioridade.
 * @param prioridade instância da classe Prioridade
 */
        void setPrioridade(const Prioridade&);

/**
 * @brief Define o estado.
 * @param estado instância da classe Estado
 */
        void setEstado(const Estado&);

/**
 * @brief Define o tamanho.
 * @param tamanho instância da classe Tamanho
 */
        void setTamanho(const Tamanho&);

/**
 * @brief Define a entrada.
 * @param entrada instância da classe Timestamp
 */
        void setEntrada(const Timestamp&);


/**
 * @brief Define o inicio.
 * @param inicio instância da classe Timestamp
 */
        void setInicio(const Timestamp&);


/**
 * @brief Define o termino.
 * @param termino instância da classe Timestamp
 */
        void setTermino(const Timestamp&);

};


/**
 * @class Quadro
 * @brief Representa o quadro Kanban pertencente a um projeto específico. Ele organiza o fluxo
 * de trabalho.
 */

class Quadro{
    private:
        Identificador identificador;///< Chave primária (PK) do tipo Identificador, código único do quadro.
        Nome nome;///< Título do quadro.
        Limite limite;///< Valor que controla a quantidade máxima de cartões de atividade na coluna "FAZENDO".
    public:

/**
 * @brief Obtém o Identificador armazenado na variável identificador.
 * 
 * @return Identificador armazenado
 */
        Identificador getIdentificador() const;

/**
 * @brief Obtém o Nome armazenado na variável nome.
 * @return Nome armazenado
 */
        Nome getNome() const;

/**
 * @brief Obtém o Limite armazenado na variável limite
 * 
 * @return Limite armazenado
 */
        Limite getLimite() const;

/**
 * @brief Define o identificador.
 * @param identificador instância da classe Identificador
 */
        void setIdentificador(const Identificador&);

/**
 * @brief Define o nome.
 * @param nome instância da classe Nome
 */
        void setNome(const Nome&);

/**
 * @brief Define o limite.
 * @param limite instância da classe Limite
 */
        void setLimite(const Limite&);
};

#endif