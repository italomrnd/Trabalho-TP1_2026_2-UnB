#include "entidades.hpp"

    ///// Declaração dos métodos das entidades

    ///// Implementação dos métodos da entidade Pessoa


void Pessoa::setEmail(const Email& email){
    this->email = email;
}

void Pessoa::setNome(const Nome& nome){
    this->nome = nome;
}

void Pessoa::setSenha(const Senha& senha){
    this->senha = senha;
}

void Pessoa::setPapel(const Papel& papel){
    this->papel = papel;
}

Email Pessoa::getEmail()const{
    return email;
}

Nome Pessoa::getNome()const{
    return nome;
}

Senha Pessoa::getSenha()const{
    return senha;
}

Papel Pessoa::getPapel()const{
    return papel;
}
    ///// Implementação dos métodos da entidade Projeto

void Projeto::setIdentificador(const Identificador& identificador){
    this->identificador = identificador;
}

void Projeto::setNome(const Nome& nome){
    this->nome = nome;
}

void Projeto::setDescricao(const Texto& descricao){
    this->descricao = descricao;
}


void Projeto::setInicio(const Timestamp& inicio){
    this->inicio = inicio;
}

void Projeto::setTermino(const Timestamp& termino){
    this->termino = termino;
}

Identificador Projeto::getIdentificador()const{
    return identificador;
}

Nome Projeto::getNome()const{
    return nome;
}

Texto Projeto::getDescricao()const{
    return descricao;
}

Timestamp Projeto::getInicio()const{
    return inicio;
}

Timestamp Projeto::getTermino()const{
    return termino;
}

    ///// Implementação dos métodos da entidade Cartão de atividade




    ///// Implementação dos métodos da entidade Quadro



Identificador Quadro::getIdentificador()const{
    return identificador;
}

Nome Quadro::getNome()const{
    return nome;
}

Limite Quadro::getLimite()const{
    return limite;
}

