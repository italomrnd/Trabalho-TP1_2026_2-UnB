#include "testes.hpp"
#include <stdexcept>
#include <string>

// Implementacao dos metodos de testes de dominios








// Implementacao dos metodos de testes de entidades

//Nome:

void TUPessoa::setUp(){
    pessoa = new Pessoa();
    estado = SUCESSO;
}

void TUPessoa::tearDown(){
    delete pessoa;
}

void TUPessoa::testarCenario(){

    Email email;
    email.setValor(EMAIL_VALIDO);
    pessoa->setEmail(email);
    if(pessoa->getEmail().getValor() != EMAIL_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    pessoa->setNome(nome);
    if(pessoa->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.setValor(SENHA_VALIDA);
    pessoa->setSenha(senha);
    if(pessoa->getSenha().getValor()!= SENHA_VALIDA)
        estado = FALHA;

    Papel papel;
    papel.setValor(PAPEL_VALIDO);
    pessoa->setPapel(papel);
    if(pessoa->getPapel().getValor() != PAPEL_VALIDO)
        estado = FALHA;
}

int TUPessoa::run(){
    setUp();
    testarCenario();
    tearDown();

    return estado;
}

//Projeto:

void TUProjeto::setUp(){
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown(){
    delete projeto;
}

void TUProjeto::testarCenario(){

    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    projeto->setIdentificador(identificador);
    if(projeto->getIdentificador().getValor()!=IDENTIFICADOR_VALIDO)
        estado = FALHA;
    
    Nome nome;
    nome.setValor(NOME_VALIDO);
    projeto->setNome(nome);
    if(projeto->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(TEXTO_VALIDO);
    projeto->setDescricao(descricao);
    if(projeto->getDescricao().getValor() != TEXTO_VALIDO)
        estado = FALHA;
    
    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    projeto->setInicio(inicio);
    if(projeto->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;

    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    projeto->setTermino(termino);
    if(projeto->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;
}

int TUProjeto::run(){
    setUp();
    testarCenario();
    tearDown();

    return estado;
}

//Cartão de Atividade:

void TUCartaoDeAtividade::setUp(){
    cartaoDeAtividade = new CartaodeAtividade();
    estado = SUCESSO;
}

void TUCartaoDeAtividade::tearDown(){
    delete cartaoDeAtividade;
}

void TUCartaoDeAtividade::testarCenario(){

    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    cartaoDeAtividade->setIdentificador(identificador);
    if(cartaoDeAtividade->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;
    
    Nome nome;
    nome.setValor(NOME_VALIDO);
    cartaoDeAtividade->setNome(nome);
    if(cartaoDeAtividade->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(DESCRICAO_VALIDA);
    cartaoDeAtividade->setDescricao(descricao);
    if(cartaoDeAtividade->getDescricao().getValor() != DESCRICAO_VALIDA)
        estado = FALHA;
    
    Prioridade prioridade;
    prioridade.setValor(PRIORIDADE_VALIDA);
    cartaoDeAtividade->setPrioridade(prioridade);
    if(cartaoDeAtividade->getPrioridade().getValor() != PRIORIDADE_VALIDA)
        estado = FALHA;

    Tamanho tamanho;
    tamanho.setValor(TAMANHO_VALIDO);
    cartaoDeAtividade->setTamanho(tamanho);
    if(cartaoDeAtividade->getTamanho().getValor() != TAMANHO_VALIDO)
        estado = FALHA;

    Timestamp entrada;
    entrada.setValor(ENTRADA_VALIDA);
    cartaoDeAtividade->setEntrada(entrada);
    if(cartaoDeAtividade->getEntrada().getValor() != ENTRADA_VALIDA)
        estado = FALHA;

    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    cartaoDeAtividade->setInicio(inicio);
    if(cartaoDeAtividade->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;
    
    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    cartaoDeAtividade->setTermino(termino);
    if(cartaoDeAtividade->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;
}

int TUCartaoDeAtividade::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

//Quadro:

void TUQuadro::setUp(){
    quadro = new Quadro();
    estado = SUCESSO;
}

void TUQuadro::tearDown(){
    delete quadro;
}

void TUQuadro::testarCenario(){

    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    quadro->setIdentificador(identificador);
    if(quadro->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;
    
    Nome nome;
    nome.setValor(NOME_VALIDO);
    quadro->setNome(nome);
    if(quadro->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;
    
    Limite limite;
    limite.setValor(LIMITE_VALIDO);
    quadro->setLimite(limite);
    if(quadro->getLimite().getValor()!= LIMITE_VALIDO)
        estado = FALHA;
}

int TUQuadro::run(){
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

