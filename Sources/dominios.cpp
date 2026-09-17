#include "dominios.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

// Implementação dos métodos da classe Email

void Email::validar(const string& valor){
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

void Estado::validar(const string& valor){
    if (valor != "A FAZER" &&
        valor != "FAZENDO" &&
        valor != "FEITO"){
            throw std::invalid_argument("DIGITE UM ESTADO VALIDO! ");
        }
}

void Estado::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}

///////////////////////////////////////////////

// Implementação dos métodos da classe Identificador


void Identificador::validar(const string& valor){
    if (valor.size() != 6)
        throw std::invalid_argument("O IDENTIFICADOR PRECISA TER 6 CARACTERES!");

    for (size_t i = 0; i < 3; i++){
        if (!isalpha(valor[i]))
            throw std::invalid_argument("OS TRES PRIMEIROS CARACTERES PRECISAM SER LETRAS!");
    }

    for (size_t i = 3; i < valor.size(); i++){
        if (!isdigit(valor[i]))
            throw std::invalid_argument("OS TRES ULTIMOS CARACTERES PRECISAM SER NUMEROS!");
    }
}

void Identificador::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}


///////////////////////////////////////////////

// Implementação dos métodos da classe Limite



void Limite::validar(int valor){ //
    if(valor > 25 || valor < 1){ // 
        throw std::invalid_argument("LIMITE INVALIDO!"); 
    }
}

void Limite::setValor(int valor){
    validar(valor);
    this->valor = valor;
}


///////////////////////////////////////////////

// Implementação dos métodos da classe Nome


void Nome::validar(const string& valor){
    if(valor.size() > 15 || valor.empty()){ // antes tava size(valor) -> isso retorna o tamanho de um vetor
        throw std::invalid_argument("NOME EXCEDE 15 CARACTERES!");
    }
    if(valor.front() == ' ' || valor.back() == ' ') {
        throw std::invalid_argument("NOME NÃO PODE COMEÇAR OU TERMINAR COM ESPAÇO!");
    }

    for(size_t i = 0; i < valor.size(); i++){
        char c = valor[i];

        if(!std::isalpha(static_cast<unsigned char>(c)) && c != ' '){
            throw std::invalid_argument("NOME CONTEM CARACTERES INVALiDOS!");
        }

        if(c == ' '){
            if(!std::isalpha(static_cast<unsigned char>(valor[i + 1]))){
                throw std::invalid_argument("ESPACO DEVE SER SEGUIDO POR LETRA!");
            }
        }
    }
}

void Nome::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}  


////////////////////////////////////////////////


// Implementação dos métodos da classe Papel

void Papel::validar(const string& valor){
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR"){
        throw std::invalid_argument("PAPEL INVALIDO: DEVE SER GESTOR OU DESENVOLVEDOR!");
    }
}

void Papel::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}



////////////////////////////////////////////////


// Implementação dos métodos da classe Prioridade

void Prioridade::validar(const string& valor){
    if(valor != "ALTA" && valor != "MEDIA" && valor!= "BAIXA"){
        throw std:: invalid_argument("PRIORIDADE INVALIDA!");  
    }
}

void Prioridade::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}

////////////////////////////////////////////////


// Implementação dos métodos da classe Senha

/*5 caracteres
Caractere pode ser letra (a-z ou A-Z) ou dígito (0-9); existe pelo menos uma letra e um dígito. */

void Senha::validar(const string& valor){
    if (valor.size() != 5)
        throw std::invalid_argument("A SENHA PRECISA TER 5 CARACTERES!");
        
    bool temLetra = false;
    bool temDigito = false;

    for (size_t i = 0; i < valor.size(); i++){
        char c = valor[i];

        if (!isalnum(c))
            throw std::invalid_argument("A SENHA PRECISA SER UM CARACTERE ALFANUMERICO!");
        if (isalpha(c))
            temLetra = true;
        if (isdigit(c))
            temDigito = true;
    }

    if (!temDigito || !temLetra )
        throw std::invalid_argument("A SENHA PRECISA TER PELO MENOS UMA LETRA E UM DIGITO!");
}



void Senha::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}



////////////////////////////////////////////////

// Implementação dos métodos da classe Tamanho

void Tamanho::validar(const string& valor){
    if (valor != "GRANDE" && valor != "MEDIO" && valor != "PEQUENO")
        throw std::invalid_argument("O TAMANHO EH INVALIDO!");
}

void Tamanho::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}




////////////////////////////////////////////////

// Implementação dos métodos da classe Texto
bool Texto::ehPontuacaoAceita(char c){
    return c == '.' || c == ',' || c == ';'
        || c == ':' || c == '?' || c == '!';
}
void Texto::validar(const string& valor){
    if(valor.size() > 30 || valor.empty()){
        throw std :: invalid_argument("NOME DE TAMANHO INVALIDO!");
    } 
    char c = valor.front(); 

    if(!isupper(c)){
        throw std :: invalid_argument("TEXTO DEVE COMECAR COM LETRA MAIUSCULA!");
    }

    c = valor.back();

    if(c != '.'){
        throw std :: invalid_argument("TEXTO DEVE TERMINAR COM PONTO FINAL!");
    }

    for(size_t i = 0; i < valor.size(); i++){
        c = valor[i];
        if(!isalpha(c) && !isspace(c) && !isdigit(c) && !ehPontuacaoAceita(c)){
            throw std :: invalid_argument("TEXTO CONTEM CARACTERES INVALIDOS!");
        }

        if(ehPontuacaoAceita(c) && (i + 1 < valor.size()) && ehPontuacaoAceita(valor[i+1])){
            throw std :: invalid_argument("PONTUACAO NAO PODE SER SEGUIDA DE PONTUACAO!");
        }
    }
}

void Texto::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}


/////////////////////////////////////////////////

// Implementação dos métodos da classe Timestamp

bool Timestamp::ehDigito(const string& str){
    for (size_t i = 0; i < str.size(); i++){
        char c = str[i]; 
        if (!isdigit(c))
            return false;
    }
    return true;
}

int Timestamp::quantidadeDiasNoMes(const string& mes, int ano){
    if(mes == "JAN" || mes == "MAR" || mes == "MAI" || mes == "JUL" 
        || mes == "AGO" || mes == "OUT" || mes == "DEZ"){
            return 31;
        }
    
    if(mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV"){
        return 30;
    }
    if(mes == "FEV"){
        if((ano % 4  == 0 && ano % 100 != 0) || ano % 400 == 0) return 29;

        else return 28;
    }
    return 0;
}


bool Timestamp::ehMesValido(const string& mes){
    return mes == "JAN" || mes == "MAR" || mes == "MAI" || mes == "JUL" 
        || mes == "AGO" || mes == "OUT" || mes == "DEZ" || mes == "ABR" || 
        mes == "JUN" || mes == "SET" || mes == "NOV" || mes == "FEV";
}

void Timestamp::validar(const string& valor){
    
    if(valor.size() != 17){
        throw std::invalid_argument("TAMANHO INVALIDO!");
    }

    if(valor[2] != '-' || valor[6] != '-' || valor[11] != '-'|| valor[14] != ':'){
        throw std::invalid_argument("O FORMATO ADEQUADO DEVE SER DIA-MES-ANO-HORA:MINUTO!");
    }

    string str_dia = valor.substr(0, 2);
    string str_mes = valor.substr(3, 3);
    string str_ano = valor.substr(7, 4);
    string str_hora = valor.substr(12, 2);
    string str_minutos = valor.substr(15, 2);

    if(!ehDigito(str_dia) || !ehDigito(str_ano) || !ehDigito(str_hora) || !ehDigito(str_minutos)){
        throw std::invalid_argument("DIA, ANO OU HORARIO CONTEM CARACTERES NAO NUMERICOS!");
    }


    int dia = std::stoi(str_dia);
    int ano = std::stoi(str_ano);
    int hora = std::stoi(str_hora);
    int minutos = std::stoi(str_minutos);
    
    if(ano < 2000 || ano > 2099){
        throw std::invalid_argument("ANO INVALIDO!");
    }
    if(!ehMesValido(str_mes)){
        throw std::invalid_argument("MES INVALIDO!");
    }

    if(dia < 1 || dia > quantidadeDiasNoMes(str_mes, ano)){
        throw std::invalid_argument("QUANTIDADE DE DIAS INVALIDA PARA O MES DADO!");
    }

    if(hora < 0 || hora > 23 || minutos < 0 || minutos > 59){
        throw std::invalid_argument("HORARIO INFORMADO INVALIDO!");
    }    
}

void Timestamp::setValor(const string& valor){
    validar(valor);
    this->valor = valor;
}

/////////////////////////////////////////////////

