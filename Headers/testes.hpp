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

class TUNome{
    private:
        const string VALOR_VALIDO = "Jonas Ribeiro";
        const string VALOR_INVALIDO = " Jonas Ribeiro ";

        Nome* nome;
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

class TUPapel{
    private:
        const string VALOR_VALIDO = "DESENVOLVEDOR";
        const string VALOR_INVALIDO = "DIRETOR";

        Papel* papel;
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

class TUPessoa{
    private:
        const string EMAIL_VALIDO = "user2026@dom.com";
        const string NOME_VALIDO = "Italo Miranda";
        const string SENHA_VALIDA = "S3nha";
        const string PAPEL_VALIDO = "GESTOR";

        Pessoa *pessoa;
        int estado;
        
        void setUp();
        void tearDown();
        void testarCenarioV();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};

class TUProjeto{
    private:
        string IDENTIFICADOR_VALIDO = "OOO111";
        string NOME_VALIDO = "Jonas Ribeiro";
        string TEXTO_VALIDO = "O rato roeu a roupa do rei de Roma";
        string INICIO_VALIDO = "14-ABR-2007-14:00";
        string TERMINO_VALIDO = "02-FEB-2008-14:00";
        
        Projeto *projeto;
        int estado;

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};

class TUCartaoDeAtividade{
    private:
        string IDENTIFICADOR_VALIDO = "OOO111";
        string NOME_VALIDO = "Jonas Ribeiro";
        string DESCRICAO_VALIDA = "Essa eh uma atividade valida";
        string PRIORIDADE_VALIDA = "ALTA";
        string TAMANHO_VALIDO = "GRANDE";
        string ENTRADA_VALIDA = "24-JUN-2007-12:10";
        string INICIO_VALIDO = "14-ABR-2007-14:00";
        string TERMINO_VALIDO = "02-FEB-2008-14:00";

        CartaodeAtividade *cartaoDeAtividade;
        int estado;

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
};







#endif // TESTES_HPP