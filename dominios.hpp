#ifndef DOMINIOS_HPP
#define DOMINIOS_HPP


#include <string>
using namespace std;


class Email{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Estado{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Identificador{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
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
        void validar(string); 

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Papel{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Prioridade{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Senha{
    private:
        string valor;
        void validar(string);
    
    public:
        string getValor() const{
                return valor;
        }
        void setValor(string);
};

class Tamanho{
    private:
        string valor;
        void validar(string);
    
    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);      
};

class Texto{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

class Timestamp{
    private:
        string valor;
        void validar(string);

    public:
        string getValor() const{
            return valor;
        }
        void setValor(string);
};

#endif // DOMINIOS_HPP