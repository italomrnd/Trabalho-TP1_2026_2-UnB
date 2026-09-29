#include "testes.hpp"
#include <stdexcept>
#include <string>

// Implementacao dos metodos de testes de dominios

//Teste unitario do dominio Email


void TUEmail::setUp(){
    email = new Email();
    estado = SUCESSO;
}

void TUEmail::tearDown(){
    delete email;
}

void TUEmail::testarCenarioValido(){
    try{
        email->setValor(VALOR_VALIDO);
        if (email->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUEmail::testarCenarioInvalido(){
    try{
        email->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (email->getValor() == VALOR_INVALIDO) //
            estado = FALHA; 
    }
}

int TUEmail::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Estado


void TUEstado::setUp(){
    objEstado = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete objEstado;
}

void TUEstado::testarCenarioValido(){
    try{
        objEstado->setValor(VALOR_VALIDO);
        if (objEstado->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUEstado::testarCenarioInvalido(){
    try{
        objEstado->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (objEstado->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUEstado::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Identificador

void TUIdentificador::setUp(){
    identificador = new Identificador();
    estado = SUCESSO;
}

void TUIdentificador::tearDown(){
    delete identificador;
}

void TUIdentificador::testarCenarioValido(){
    try{
        identificador->setValor(VALOR_VALIDO);
        if (identificador->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUIdentificador::testarCenarioInvalido(){
    try{
        identificador->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (identificador->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUIdentificador::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Limite

void TULimite::setUp(){
    limite = new Limite();
    estado = SUCESSO;
}

void TULimite::tearDown(){
    delete limite;
}

void TULimite::testarCenarioValido(){
    try{
        limite->setValor(VALOR_VALIDO);
        if (limite->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TULimite::testarCenarioInvalido(){
    try{
        limite->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (limite->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TULimite::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioValido(){
    try{
        nome->setValor(VALOR_VALIDO);
        if (nome->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUNome::testarCenarioInvalido(){
    try{
        nome->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (nome->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUNome::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

void TUPapel::setUp(){
    papel = new Papel();
    estado = SUCESSO;
}

void TUPapel::tearDown(){
    delete papel;
}

void TUPapel::testarCenarioValido(){
    try{
        papel->setValor(VALOR_VALIDO);
        if (papel->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUPapel::testarCenarioInvalido(){
    try{
        papel->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (papel->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUPapel::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

void TUPrioridade::setUp(){
    prioridade = new Prioridade();
    estado = SUCESSO;
}

void TUPrioridade::tearDown(){
    delete prioridade;
}

void TUPrioridade::testarCenarioValido(){
    try{
        prioridade->setValor(VALOR_VALIDO);
        if (prioridade->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUPrioridade::testarCenarioInvalido(){
    try{
        prioridade->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(invalid_argument &excecao){ 
        if (prioridade->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUPrioridade::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Senha

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioValido(){
    try{
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(const invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUSenha::testarCenarioInvalido(){
    try{
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(const invalid_argument &excecao){ 
        if (senha->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Tamanho

void TUTamanho::setUp(){
    tamanho = new Tamanho();
    estado = SUCESSO;
}

void TUTamanho::tearDown(){
    delete tamanho;
}

void TUTamanho::testarCenarioValido(){
    try{
        tamanho->setValor(VALOR_VALIDO);
        if (tamanho->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(const invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUTamanho::testarCenarioInvalido(){
    try{
        tamanho->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(const invalid_argument &excecao){ 
        if (tamanho->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUTamanho::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Texto

void TUTexto::setUp(){
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown(){
    delete texto;
}

void TUTexto::testarCenarioValido(){
    try{
        texto->setValor(VALOR_VALIDO);
        if (texto->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(const invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUTexto::testarCenarioInvalido(){
    try{
        texto->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(const invalid_argument &excecao){ 
        if (texto->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUTexto::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

// Teste unitario do dominio Timestamp

void TUTimestamp::setUp(){
    timestamp = new Timestamp();
    estado = SUCESSO;
}

void TUTimestamp::tearDown(){
    delete timestamp;
}

void TUTimestamp::testarCenarioValido(){
    try{
        timestamp->setValor(VALOR_VALIDO);
        if (timestamp->getValor() != VALOR_VALIDO) 
            estado = FALHA; 
    }
    catch(const invalid_argument &excecao){
        estado = FALHA; 
    }
}

void TUTimestamp::testarCenarioInvalido(){
    try{
        timestamp->setValor(VALOR_INVALIDO);
        estado = FALHA; 
    }
    catch(const invalid_argument &excecao){ 
        if (timestamp->getValor() == VALOR_INVALIDO) 
            estado = FALHA; 
    }
}

int TUTimestamp::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}










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

