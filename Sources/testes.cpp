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