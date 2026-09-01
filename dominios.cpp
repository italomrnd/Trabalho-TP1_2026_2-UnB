#include "dominios.hpp"
#include <iostream>
#include <stdexcept>


// Implementação dos métodos da classe Email




//////////////////////////////////////////////


// Implementação do métodos da classe Estado

void Estado::validar(string valor){
    if (valor != "A FAZER" &&
        valor != "FAZENDO" &&
        valor != "FEITO"){
            throw std::invalid_argument("DIGITE UM ESTADO VÁLIDO! ");
        }
}

void Estado::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

///////////////////////////////////////////////

// Implementação dos métodos da classe Identificador







///////////////////////////////////////////////

// Implementação dos métodos da classe Limite



void Limite::validar(int valor){ //valor = limite desejado
    if(valor > 25 || valor < 1){ // a logica tava errada nao? ele tem que ser ou menoor que 1 ou maior q 25 pra ta errado
        throw std::length_error("LIMITE INVÁLIDO!"); //Erro se o limite for fora dos limites de 1 < valor < 25
    }
}

void Limite::setValor(int valor){
    validar(valor);
    this->valor = valor;
}


///////////////////////////////////////////////

// Implementação dos métodos da classe Nome


void Nome::validar(string valor){
    if(valor.size() > 15 || valor.empty()){ // antes tava size(valor) -> isso retorna o tamanho de um vetor
        throw std::length_error("NOME EXCEDE 15 CARACTERES!");
    }
    
}

void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}  


////////////////////////////////////////////////


// Implementação dos métodos da classe Papel

void Papel::validar (string valor){
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR"){
        throw std::invalid_argument("PAPEL INVALIDO: DEVE SER GESTOR OU DESENVOLVEDOR!");
    }
}

void Papel::setValor(string valor){
    validar(valor);
    this->valor = valor;
}






////////////////////////////////////////////////


// Implementação dos métodos da classe Prioridade

void Prioridade::validar(string valor){
    if(valor != "ALTA" && valor != "MEDIA" && valor!= "BAIXA"){
        throw std:: invalid_argument("PRIORIDADE INVÁLIDA!");  
    }
}

void Prioridade::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

////////////////////////////////////////////////


// Implementação dos métodos da classe Senha








////////////////////////////////////////////////

// Implementação dos métodos da classe Tamanho

void Tamanho::validar(string valor){
    if (valor != "GRANDE" && valor != "MEDIO" && valor != "PEQUENO")
        throw std::invalid_argument("O TAMANHO É INVÁLIDO!");
}

void Tamanho::setValor(string valor){
    validar(valor);
    this->valor = valor;
}




////////////////////////////////////////////////

// Implementação dos métodos da classe Texto






/////////////////////////////////////////////////

// Implementação dos métodos da classe Timestamp









/////////////////////////////////////////////////

