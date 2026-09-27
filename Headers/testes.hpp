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

class TUEstado{
    private:
        const string VALOR_VALIDO = "A FAZER";
        const string VALOR_INVALIDO = "ESTOU FAZENDO ESSA TAREFA!";

        Estado* objEstado;
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

class TUIdentificador{
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

class TULimite{
    private:
        const int VALOR_VALIDO = 14;
        const int VALOR_INVALIDO = 0;

        Limite* limite;
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

class TUPrioridade{
    private:
        const string VALOR_VALIDO = "MEDIA";
        const string VALOR_INVALIDO = "MAXIMA";

        Prioridade* prioridade;
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

class TUSenha{
    private:
        const string VALOR_VALIDO = "S3nha";
        const string VALOR_INVALIDO = "senha";

        Senha* senha;
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

class TUTamanho{
    private:
        const string VALOR_VALIDO = "GRANDE";
        const string VALOR_INVALIDO = "ENORME";

        Tamanho* tamanho;
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

class TUTexto{
    private:
        const string VALOR_VALIDO = "Esse eh um texto valido e aceito.";
        const string VALOR_INVALIDO = "esse texto nao deve ser validado!!";

        Texto* texto;
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

class TUTimestamp{
    private:
        const string VALOR_VALIDO = "14-ABR-2007-14:00";
        const string VALOR_INVALIDO = "14/04/2007-14:00";

        Timestamp* timestamp;
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

#endif // TESTES_HPP