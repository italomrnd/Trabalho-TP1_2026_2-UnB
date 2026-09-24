#ifndef TESTES_HPP
#define TESTES_HPP

#include "dominios.hpp"
#include "entidades.hpp"
#include <string>

using namespace std;

//////// Declaracao dos testes de dominios /////////



class TUEmail{
    private:
        const string VALOR_VALIDO = "user2026@dom.com";
        const string VALOR_INVALIDO = "emailnaovalido@";

        Email *email;
        int estado;

        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();
    
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();

};

class Estado{
    private:
        const string VALOR_VALIDO = "A FAZER";
        const string VALOR_INVALIDO = "ESTOU FAZENDO ESSA TAREFA!";

        Estado* estado;
        int estado;

        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class Identificador{
    private:
        const string VALOR_VALIDO = "AAA000";
        const string VALOR_INVALIDO = "000AAA";

        Identificador* identificador;
        int estado;

        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarCenarioInvalido();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


////// Declaracao dos testes de entidades ///////////

#endif