#include "dominios.hpp"
#include <iostream>
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



void Limite :: validar(int n){ //n = limite desejado
    if(n > 25 && n < 1){
        throw std::length_error("LIMITE INVÁLIDO!\n"); //Erro se o limite for fora dos limites de 1 < n < 25
    }
}

void Limite :: setValor(int n){
    validar(n);
    valor = n;
}





///////////////////////////////////////////////

// Implementação dos métodos da classe Nome




void Nome :: validar(string valor){
    if(size(valor) > 15){
        throw std :: length_error("NOME EXCEDE 15 CARACTÉRES!");
    }
    
}

void Nome :: setValor(string valor){

}






////////////////////////////////////////////////


// Implementação dos métodos da classe Papel








////////////////////////////////////////////////


// Implementação dos métodos da classe Prioridade




void Prioridade :: validar(string p){
    if(p != "ALTA" && p != "MEDIA" && p!= "BAIXA"){
        throw std :: invalid_argument("PRIORIDADE INVÁLIDA!");  
    }
}

void Prioridade :: setValor(string p){
    validar(p);
    valor = p;
}





////////////////////////////////////////////////


// Implementação dos métodos da classe Senha








////////////////////////////////////////////////

// Implementação dos métodos da classe Tamanho






////////////////////////////////////////////////

// Implementação dos métodos da classe Texto






/////////////////////////////////////////////////

// Implementação dos métodos da classe Timestamp









/////////////////////////////////////////////////

