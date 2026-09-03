#include "dominios.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

// Implementação dos métodos da classe Email

void Email::validar(string valor){
    // Verificacao inicial de tamanho 
    if (valor.empty() || valor.size() > 320)
        throw std::invalid_argument("O TAMANHO DO EMAIL EH INVALIDO!");
    

    size_t posArroba = valor.find('@'); 
    size_t posPonto = valor.find('.');

    if (posArroba == string::npos || posArroba != valor.rfind('@'))
        throw std::invalid_argument("NAO HA @ NO EMAIL OU HA MAIS DE UM @!");
    
    // Validacao da parte local do email

    string parte_local = valor.substr(0, posArroba);
    
    if (parte_local.empty() || parte_local.size() > 64)
        throw std::invalid_argument("A PARTE LOCAL DO EMAIL EH INVALIDA!");
    
    char primeiroCaracterePL = parte_local.front();
    char ultimoCaraceterePL = parte_local.back();

    if (primeiroCaracterePL == '.' || primeiroCaracterePL == '-' ||
        ultimoCaraceterePL == '.'  || ultimoCaraceterePL == '-')
        throw std::invalid_argument("O EMAIL NAO PODE COMECAR OU TERMINAR COM '-' OU '.'!");

    for (size_t i = 0; i < parte_local.size(); i++){
        char c = parte_local[i];

        if (!isalnum(c) && c != '.' && c != '-')
            throw std::invalid_argument("CARACTERE INVALIDO!");

        // Checa se o ponto/hifen é seguido por caractere valido (ex.: não é '..' ou '--')
        if ((c == '.' || c == '-') && i + 1 < parte_local.size()){
            char prox = parte_local[i + 1];
            if (!isalnum(prox))
                throw std::invalid_argument("PONTO OU HIFEN DEVE SER SEGUIDO POR LETRA(S) OU DIGITO(S)! ");
        }    
    }

    // Validacao do dominio do email
    
    string parte_dominio = valor.substr(posArroba + 1);

    if (parte_dominio.empty() || parte_dominio.size() > 255)
        throw std::invalid_argument("O DOMINIO DO EMAIL EH INVALIDO!");
    
    if (parte_dominio.find('.') == string::npos) 
        throw std::invalid_argument("O DOMINIO PRECISA TER PELO MENOS UM PONTO!");
    
    char primeiroCaractereDom = parte_dominio.front();
    char ultimoCaractereDom = parte_dominio.back();

    if (primeiroCaractereDom == '-' || ultimoCaractereDom == '-' ||
        primeiroCaractereDom == '.' || ultimoCaractereDom == '.')
        throw std::invalid_argument("O DOMINIO DO EMAIL NAO PODE COMECAR NEM TERMINAR EM HIFEN!");

    for (size_t i = 0; i < parte_dominio.size(); i++){
        char c = parte_dominio[i];
        if (!isalnum(c) && c != '.' && c != '-')
            throw std::invalid_argument("CARACTERE INVALIDO NO DOMINIO!");

        if ((c == '.' || c == '-') && i + 1 < parte_dominio.size()){
            char prox = parte_dominio[i+1];
            if (prox == '.' || prox == '-')
                throw std::invalid_argument("SEPARADORES CONSECUTIVOS NO DOMINIO!");
        }
    }   

}


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
        throw std::invalid_argument("LIMITE INVÁLIDO!"); //Erro se o limite for fora dos limites de 1 < valor < 25
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
        throw std::invalid_argument("NOME EXCEDE 15 CARACTERES!");
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

