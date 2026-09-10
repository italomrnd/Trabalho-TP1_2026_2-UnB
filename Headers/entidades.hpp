#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

class Pessoa{
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;
    public:
        Email getEmail() const;
        Nome getNome() const;
        Senha getSenha() const;
        Papel getPapel() const;

        void setEmail(const Email&);
        void setNome(const Nome&);
        void setPapel(const Papel&);
        void setSenha(const Senha&);
};

class Projeto{
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
    public:
        Identificador getIdentificador() const;
        Nome getNome() const;
        Texto getDescricao() const;
        Timestamp getInicio() const;
        Timestamp getTermino() const;

        void setIdentificador(const Identificador&);
        void setNome(const Nome&);
        void setDescricao(const Texto&);
        void setInicio(const Timestamp&);
        void setTermino(const Timestamp&);
};

class CartaodeAtividade{
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Estado estado;
        Tamanho tamanho;
        Timestamp entrada;
        Timestamp inicio;
        Timestamp termino;
    public:
        Identificador getIdentificador() const;
        Nome getNome() const;
        Texto getDescricao() const;
        Prioridade getPrioridade() const;
        Estado getEstado() const;
        Tamanho getTamanho() const;
        Timestamp getEntrada() const;
        Timestamp getInicio() const;
        Timestamp getTermino() const;

        void setIdentificador(const Identificador&);
        void setNome(const Nome&);
        void setDescricao(const Texto&);
        void setPrioridade(const Prioridade&);
        void setEstado(const Estado&);
        void setTamanho(const Tamanho&);
        void setEntrada(const Timestamp&);
        void setInicio(const Timestamp&);
        void setTermino(const Timestamp&);

};

class Quadro{
    private:
        Identificador identificador;
        Nome nome;
        Limite limite;
    public:
        Identificador getIdentificador() const;
        Nome getNome() const;
        Limite getLimite() const;

        void setIdentificador(const Identificador&);
        void setNome(const Nome&);
        void setLimite(const Limite&);
};

#endif