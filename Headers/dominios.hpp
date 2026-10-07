#ifndef DOMINIOS_HPP
#define DOMINIOS_HPP


#include <string>
using namespace std;

/**
 * @file dominios.hpp
 * @brief Declaração das classes do domínio do sistema de software
 * @author Ítalo Miranda Gomes
 */


/** 
 * @class Email
 * @brief Classe que representa o endereço de correio eletrônico de um usuário do sistema.
 * 
 * Formato válido: parte-local@dominio
 * 
 * Regras para a parte local (máx. 64 caracteres):
 * - Só aceita caracteres minúsculos;
 * - Contém apenas letras (a-z), dígitos (0-9), ponto(.) ou hífen(-);
 * - Não pode iniciar nem terminar  com ponto(.) ou hífen(-);
 * - Todo ponto ou hífen deve ser seguido imediatamente por número ou letra, ou seja, não é permitido dois hífens ou pontos seguidos.
 * 
 * Regras para o domínio (máx. 255 caracteres):
 * - Só aceita caracteres minúsculos;
 * - Composto por uma ou mais partes separadas por ponto (.);
 * - Cada parte possui apenas letras (a-z) ou dígitos (0-9);
 * - Nenhuma parte pode iniciar ou terminar com hífen (-).
*/


class Email{
    private:
        string valor;

        /**
         * @brief Verifica se a string atende às regras de formato do e-mail.
         * @param valor String contendo o e-mail a ser validado.
         * @throw std::invalid_argument Se a parte local ou domínio violarem os limites de tamanho,
         * caracteres permitidos ou regras de posicionamento de pontos ou hífens.
         */

        void validar(const string&);

    public:

        /**
         * @brief Obtém o e-mail armazenado na varíavel valor.
         * @return string Endereço de e-mail atual.
         */

        string getValor() const{
            return valor;
        }

        /**
         * @brief Define o endereço de e-mail após ser validado;
         * @param valor String com o endereço de e-mail.
         * @throw std::invalid_argument Se o endereço de e-mail fornecido for inválido. 
         * 
         */

        void setValor(const string&);
};

/**
 * @class Estado 
 * @brief Classe que define a condição de uma tarefa a ser representada no sistema.
 * Define o status de uma tarefa no sistema. O valor só pode ser definido como:
 * - A FAZER
 * - FAZENDO
 * - FEITO
 * Qualquer outra definição diferente destas é considerada inválida.
 * 
 */

class Estado{
    private:
        string valor;

        /**
         * @brief Verifica se a string pertence a um dos estados permitidos.
         * @param valor String contendo o estado a ser verificado.
         * @throw std::invalid_argument Se a string passada não representa nenhum dos estados permitidos ("A FAZER, "FAZENDO", "FEITO").
         */

        void validar(const string&);

    public:

        /**
         * @brief Obtém o estado atual da tarefa.
         * @return string O estado armazenado.
         */
        string getValor() const{
            return valor;
        }

        /**
         * @brief Define o estado da tarefa após validação.
         * @param valor A string a ser definida como o estado da tarefa
         * @throw std::invalid_argument Se o estado fornecido não é "A FAZER", "FEITO" ou "FAZENDO".
         */

        void setValor(const string&);
};

/**
 * @class Identificador
 * @brief Classe que define um código de identificação para entidades do sistema.
 * 
 * Define códigos de identificação única para entidades como Quadro, Projeto e Cartão de Atividade.
 * Regras de formatação:
 * - Possui 6 caracteres;
 * - Os três primeiros caracteres são letras (a-z ou A-Z) 
 * - Os três últimos caracteres são dígitos (0-9).
 */

class Identificador{
    private:
        string valor;

        /**
         * @brief Verifica se a string é um identificador que segue as regras de formatação.
         * @param valor String que carrega um identificador a ser validado.
         * @throw std::invalid_argument Se o identificador checado não é válido.
         * 
         */

        void validar(const string&);

    public:

        /**
         * @brief Obtém o identificador de um cartão de atividade, quadro ou projeto.
         * @return string O identificador esperado.
         */

        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o identificador de um cartão de atividade, quadro ou projeto.
         * @param valor String a ser definida como identificador.
         * @throw std::invalid_argument Se o identificador não segue às regras de formatação.
         */
        void setValor(const string&);
};

/**
 * @class Limite
 * @brief Define o número máximo de atividades em um quadro de atividades.
 * - É um inteiro entre 1 e 25.
 */

class Limite{
    private:
        int valor;
        /**
         * @brief Verifica se é válido o limite númerico de um quadro de atividades.
         * @param valor Inteiro que representa o limite de atividades a ser verificado.
         * @throw std::invalid_argument Se o valor não é um inteiro entre 1 e 25.
         * 
         */
        void validar(int);
    public:
        /**
         * @brief Obtém o limite de um quadro de atividades como retorno da função.
         * @return int O valor númerico do limite.
         */
        int getValor() const{
            return valor;
        }
        /**
         * @brief Define o limite de atividades em um quadro de atividades.
         * @param valor Um inteiro constante que representa o limite de atividades.
         * @throw std::invalid_argument Se o limite não é um inteiro válido e que respeite às regras de formatação.
         */
        void setValor(int);
};
/**
 * @class Nome
 * @brief Palavra que designa um usuário (Pessoa), um cartão de atividade, um quadro ou um projeto.
 * - Possui no máximo 25 caracteres;
 * - Não pode ser vazio;
 * - Pode ser composto letras maísculas(A-Z), minúsculas(a-z) ou espaço em branco;
 * - Espaço em branco é seguido por letra;
 * - Primeiro caractere não é espaço em branco;
 * - Último caractere não é espaço em branco.
 */
class Nome{
    private:
        string valor;
        /**
         * @brief Verifica se uma string que representa um nome segue as regras de formatação.
         * @param valor O nome a ser verificado.
         * @throw std::invalid_argument Se o nome não segue as regras de formatação.
         */
        void validar(const string&); 

    public:
        /**
         * @brief Obtém o nome de uma pessoa, cartão de atividade, quadro ou projeto.
         * @return string O nome atual.
        */
        
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o nome de uma pessoa, cartão de atividade, quadro ou projeto.
         * @param valor String a ser definida como nome.
         * @throw std::invalid_argument Se o nome não é um nome válido que segue as regras de formatação.
         */
        void setValor(const string&);
};

/**
 * @class Papel
 * @brief Define se a função (papel) de um usuário no sistema.
 * - Pode ser definido somente como "GESTOR" ou "DESENVOLVEDOR".
 */

class Papel{
    private:
        string valor;
        /**
         * @brief Verifica se a string corresponde a um papel válido, isto é, "GESTOR" ou "DESENVOLVEDOR".
         * @param valor A string que carrega o papel a ser verificado.
         * @throw std::invalid_argument Se a string não é "GESTOR" ou "DESENVOLVEDOR".
         * 
         */
        void validar(const string&);

    public:
        /**
         * @brief Obtém o papel de uma pessoa no sistema de software.
         * @return string O papel atual do usuário.
         */
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o papel de uma pessoa como "GESTOR" ou "DESENVOLVEDOR".
         * @param valor A string a ser definida como papel de uma pessoa.
         * @return std::invalid_argument Se a string não é "GESTOR" ou "DESENVOLVEDOR".
         */
        void setValor(const string&);
};

/**
 * @class Prioridade
 * @brief Define a urgência de um cartão de atividade no sistema.
 * - Pode ser definida somente como "ALTA", "MEDIA" ou "BAIXA".
 */

class Prioridade{
    private:
        string valor;
        /**
         * @brief Verifica se a string que representa a proridade de uma atividade é "ALTA", "MEDIA" ou "BAIXA".
         * @param valor A string que carrega a prioridade a ser verificada.
         * @throw std::invalid_argument Se a string a ser validada não segue as regras de formatação, isto é, não é "ALTA", "MEDIA" ou "BAIXA".
         * 
         */
        void validar(const string&);

    public:
        /**
         * @brief Obtém a prioridade de um cartão de atividade.
         * @return string A prioridade atual de um cartão de atividade.
         */
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define a prioridade de um cartão de atividade no sistema.
         * @param valor A string a ser definida como prioridade de um cartão de atividade.
         * @throw std::invalid_argument Se a string não é "ALTA", "MEDIA" ou "BAIXA".
         */
        void setValor(const string&);
};

/**
 * @class Senha
 * @brief Classe que representa uma sequência de caracteres alfanuméricos usada para proteger e liberar o acesso de um usuário do sistema.
 * - Possui exatamente 5 caracteres;
 * - Caractere por ser letra (a-z ou A-Z) ou dígito (0-9); 
 * - Existe pelo menos uma letra e um dígito;
 */

class Senha{
    private:
        string valor;
        /**
         * @brief Verifica se a string que representa uma senha segue as regras de formatação.
         * @param valor A string que carrega a senha a ser verificada.
         * @throw std::invalid_argument Se a string não é uma senha válida, isto é, não segue as regras de formatação.
         */
        void validar(const string&);
    
    public:
        /**
         * @brief Obtém a senha de uma pessoa do sistema.
         * @return string A senha atual de uma pessoa.
         */
        string getValor() const{
                return valor;
        }

        /**
         * @brief Define a senha de uma pessoa do sistema.
         * @param valor A senha a ser definida.
         * @throw std::invalid_argument Se a senha não é válida, isto é, não segue as regras de formatação.
         */
        void setValor(const string&);
};

/**
 * @class Tamanho
 * @brief Define o "tamanho" de uma tarefa (o esforço necessário para realizá-la) de um cartão de atividade.
 * Pode ser definido como:
 * - GRANDE;
 * - MEDIO;
 * - PEQUENO. 
 */

class Tamanho{
    private:
        string valor;
        /**
         * @brief Verifica se a string a ser definida como tamanho é "GRANDE", "MEDIO" ou "PEQUENO".
         * @param valor A string que carrega o tamanho a ser verificado.
         * @throw std::invalid_argument Se a string não é "GRANDE", "MEDIO" ou "PEQUENO".
         */
        void validar(const string&);
    
    public:
        /**
         * @brief Obtém o tamanho de um cartão de atividade.
         * @return string O tamanho atual de um cartão de atividade.
         */
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o tamanho de um cartão de atividade.
         * @param valor A string a ser definida como o tamanho de um cartão de atividade.
         * @throw std::invalid_argument Se a string não é "GRANDE", "MEDIO" ou "PEQUENO".
         */
        void setValor(const string&);      
};

/**
 * @class Texto
 * @brief Armazena a descrição de um projeto ou de um cartão de atividade.
 * Regras de formatação:
 * - Possui no máximo 30 caracteres;
 * - Não pode ser um texto vazio;
 * - Caractere pode ser letra (a-z ou A-Z), dígito (0-9), espaço em branco ou sinal de pontuação.
 * - Sinal de pontuação não pode ser seguido por sinal de pontuação;
 * - Primeiro caractere é maísculo e último caractere é ponto (.).
 */

class Texto{
    private:
        string valor;
        /**
         * @brief Verifica se a string que carrega o texto é válida, isto é, se segue as regras de formatação.
         * @param valor O texto a ser verificado.
         * @throw std::invalid_argument Se o texto verificado não segue as regras de formatação.
         */
        void validar(const string&);
        /**
         * @brief Método auxiliar para verificar se a pontuação é válida.
         * @param c O caractere a ser verificado.
         * @return true Se a pontuação é ponto-e-vírgula (;), vírgula (,), ponto (.), dois pontos (:), ponto de interrogação (?) ou ponto de exclamação (!).
         * @return false Caso contrário.
         */
        static bool ehPontuacaoAceita(char);

    public:
        /**
         * @brief Obtém o texto armazenado.
         * @return string O texto atual.
         */
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o texto atual.
         * @param valor A string a ser definida como o texto atual.
         * @throw std::invalid_argument Se o texto verificado não segue as regras de formatação.
         */
        void setValor(const string&);
};

/**
 * @class Timestamp Define sequência de caracteres ou números que identifica quando um evento específico ocorreu.
 * 
 * Pode descrever início ou término de um cartão de atividade, instante de entrada do cartão de atividade, bem como início ou término de um projeto.
 * Regras de formatação:
 * - Segue o formato DIA-MES-ANO-HORARIO
 * - DIA é número de 1 a 31;
 * - MES é sigla JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ;
 * - ANO é número de 2000 A 2099;
 * - HORÁRIO é valor de 00:00 a 23:59;
 * - A data é válida considerando anos bissextos.
 */

class Timestamp{
    private:
        string valor;
        /**
         * @brief Verifica se a string a ser definida como timestamp é válida, isto é, segue as regras de formatação.
         * @param valor A string que carrega o timestamp a ser verificado.
         * @throw std::invalid_argument Se o timestamp a ser verificado não segue as regras de formatação.
         */
        void validar(const string&);
        
        /**
         * @brief Método auxiliar que ajuda a verificar a quantidade de dias no mês de acordo com a string passada.
         * @param mes O mês que desejamos checar a quantidade de dias.
         * @param ano O ano em que esse mês está. Isso é importante para verificar se ele é ou não bissexto.
         * @return int A quantidade de dias daquele mês, atentando-se se o ano é bissexto ou não.
         */

        static int quantidadeDiasNoMes(const string&, int);

        /**
         * @brief Método auxiliar que ajuda a verificar se um mês existe e se está no formato correto.
         * @param mes O mês a ser verificado.
         * @return true Se o mês é válido, isto é, JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV ou DEZ.
         * @return false Caso contrário.
         */

        static bool ehMesValido(const string&);

        /**
         * @brief Método auxiliar que ajuda a verificar se uma string é composta apenas por dígitos.
         * 
         * @return true Se a string é composta por dígitos.
         * @return false Caso contrário.
         */
        static bool ehDigito(const string&);

    public:
        /**
         * @brief Obtém o timestamp armazenado.
         * @return string O timestamp atual.
         */
        string getValor() const{
            return valor;
        }
        /**
         * @brief Define o timestamp atual.
         * @param valor A string a ser definida como o timestamp atual.
         * @throw std::invalid_argument Se o timestamp a ser definido não segue as regras de formatação.
         * 
         */
        void setValor(const string&);
};

#endif // DOMINIOS_HPP