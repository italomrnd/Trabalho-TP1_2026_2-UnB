#include "entidades.hpp"

// Implementação dos métodos da entidade Pessoa

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

Email Pessoa::getEmail() const{
    return email;
}

Nome Pessoa::getNome() const{
    return nome;
}

Senha Pessoa::getSenha() const{
    return senha;
}

Papel Pessoa::getPapel() const{
    return papel;
}

// Implementação dos métodos da entidade Projeto

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

void Projeto::setGestor(const Email& gestor){
    this->gestor = gestor;
}

Identificador Projeto::getIdentificador() const{
    return identificador;
}

Nome Projeto::getNome() const{
    return nome;
}

Texto Projeto::getDescricao() const{
    return descricao;
}

Timestamp Projeto::getInicio() const{
    return inicio;
}

Timestamp Projeto::getTermino() const{
    return termino;
}

Email Projeto::getGestor() const{
    return gestor;
}

// Implementação dos métodos da entidade Cartão de atividade

void CartaodeAtividade::setIdentificador(const Identificador& identificador){
    this->identificador = identificador;
}

void CartaodeAtividade::setNome(const Nome& nome){
    this->nome = nome;
}

void CartaodeAtividade::setDescricao(const Texto& descricao){
    this->descricao = descricao;
}

void CartaodeAtividade::setPrioridade(const Prioridade& prioridade){
    this->prioridade = prioridade;
}

void CartaodeAtividade::setEstado(const Estado& estado){
    this->estado = estado;
}

void CartaodeAtividade::setTamanho(const Tamanho& tamanho){
    this->tamanho = tamanho;
}

void CartaodeAtividade::setInicio(const Timestamp& inicio){
    this->inicio = inicio;
}

void CartaodeAtividade::setEntrada(const Timestamp& entrada){
    this->entrada = entrada;
}

void CartaodeAtividade::setTermino(const Timestamp& termino){
    this->termino = termino;
}

void CartaodeAtividade::setIdQuadro(const Identificador& idQuadro){
    this->idQuadro = idQuadro;
}

void CartaodeAtividade::setDesenvolvedor(const Email& desenvolvedor){
    this->desenvolvedor = desenvolvedor;
}

Identificador CartaodeAtividade::getIdentificador() const{
    return identificador;
}

Nome CartaodeAtividade::getNome() const{
    return nome;
}

Texto CartaodeAtividade::getDescricao() const{
    return descricao;
}

Prioridade CartaodeAtividade::getPrioridade() const{
    return prioridade;
}

Estado CartaodeAtividade::getEstado() const{
    return estado;
}

Tamanho CartaodeAtividade::getTamanho() const{
    return tamanho;
}

Timestamp CartaodeAtividade::getEntrada() const{
    return entrada;
}

Timestamp CartaodeAtividade::getInicio() const{
    return inicio;
}

Timestamp CartaodeAtividade::getTermino() const{
    return termino;
}

Identificador CartaodeAtividade::getIdQuadro() const{
    return idQuadro;
}

Email CartaodeAtividade::getDesenvolvedor() const{
    return desenvolvedor;
}

// Implementação dos métodos da entidade Quadro

void Quadro::setIdentificador(const Identificador& identificador){
    this->identificador = identificador;
}

void Quadro::setNome(const Nome& nome){
    this->nome = nome;
}

void Quadro::setLimite(const Limite& limite){
    this->limite = limite;
}

void Quadro::setIdProjeto(const Identificador& idProjeto){
    this->idProjeto = idProjeto;
}

Identificador Quadro::getIdentificador() const{
    return identificador;
}

Nome Quadro::getNome() const{
    return nome;
}

Limite Quadro::getLimite() const{
    return limite;
}

Identificador Quadro::getIdProjeto() const{
    return idProjeto;
}