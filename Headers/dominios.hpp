#ifndef DOMINIOS_HPP
#define DOMINIOS_HPP


#include <string>
using namespace std;


class Email{
    private:
        string valor;
        void validar(const string&);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Estado{
    private:
        string valor;
        void validar(const string&);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Identificador{
    private:
        string valor;
        void validar(const string&);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Limite{
    private:
        int valor;
        void validar(int);
    public:
        int getValor() const{
            return valor;
        }
        void setValor(int);
};

class Nome{
    private:
        string valor;
        void validar(const string&); 

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Papel{
    private:
        string valor;
        void validar(const string&);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Prioridade{
    private:
        string valor;
        void validar(const string&);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Senha{
    private:
        string valor;
        void validar(const string&);
    
    public:
        string getValor() const{
                return valor;
        }
        void setValor(const string&);
};

class Tamanho{
    private:
        string valor;
        void validar(const string&);
    
    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);      
};

class Texto{
    private:
        string valor;
        void validar(const string&);
        static bool ehPontuacaoAceita(char);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

class Timestamp{
    private:
        string valor;
        void validar(const string&);
        static int quantidadeDiasNoMes(const string&, int);
        static bool ehMesValido(const string&);
        static bool ehDigito(const string&);
    public:
        string getValor() const{
            return valor;
        }
        void setValor(const string&);
};

#endif // DOMINIOS_HPP