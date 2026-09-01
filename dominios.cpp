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

