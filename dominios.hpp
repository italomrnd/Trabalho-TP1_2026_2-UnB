#include <iostream>
#include <string>
using namespace std;

class NOME{
    private:
        string Nome;
        bool validar(string);

    public:
        string getNome();
        bool setValor(string);
};

inline string NOME :: getNome(){
    return Nome;
}