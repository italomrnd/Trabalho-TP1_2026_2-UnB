#include "dominios.hpp"
#include <iostream>
<<<<<<< HEAD

// Implementação dos métodos da classe Email




//////////////////////////////////////////////


// Implementação do métodos da classe Estado

void Estado :: validar(string valor){
    if (valor != "A FAZER" &&
        valor != "FAZENDO" &&
        valor != "FEITO"){
            throw std::invalid_argument("DIGITE UM ESTADO VÁLIDO! ");
        }
};

void Estado::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

///////////////////////////////////////////////

// Implementação dos métodos da classe Identificador







///////////////////////////////////////////////

// Implementação dos métodos da classe Limite








///////////////////////////////////////////////

// Implementação dos métodos da classe Nome









////////////////////////////////////////////////


// Implementação dos métodos da classe Papel








////////////////////////////////////////////////


// Implementação dos métodos da classe Prioridade









////////////////////////////////////////////////


// Implementação dos métodos da classe Senha








////////////////////////////////////////////////

// Implementação dos métodos da classe Tamanho






////////////////////////////////////////////////

// Implementação dos métodos da classe Texto






/////////////////////////////////////////////////

// Implementação dos métodos da classe Timestamp









/////////////////////////////////////////////////
=======
>>>>>>> bc3a4f8 (Implementação de mais classes domínio)

void Limite :: validar(int n){ //n = limite desejado
    if(n > 25 && n < 1){
        throw std::length_error("LIMITE INVÁLIDO!\n"); //Erro se o limite for fora dos limites de 1 < n < 25
    }
}

void Limite :: setValor(int n){
    validar(n);
    valor = n;
}

void Prioridade :: validar(string p){
    if(p != "ALTA" && p != "MEDIA" && p!= "BAIXA"){
        throw std :: invalid_argument("PRIORIDADE INVÁLIDA!");  
    }
}

void Prioridade :: setValor(string p){
    validar(p);
    valor = p;
}

void Nome :: validar(string n){
    if(size(n) > 15){
        throw std :: length_error("NOME EXCEDE 15 CARACTÉRES!");
    }
}