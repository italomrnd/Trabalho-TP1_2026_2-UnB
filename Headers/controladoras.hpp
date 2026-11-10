#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

#include "interfaces.hpp"
#include "entidades.hpp"
#include <unordered_map>
#include <vector>


// Declaracao das controladoras da camada de apresentacao

class cntrAprAutenticacao : public IAprAutenticacao{

    private:
        ISerAutenticacao *cntrServico;
    public:
        bool autenticar(Email*) override;

        void setCntrServico(ISerAutenticacao* cntr);
};

class cntrAprPessoas : public IAprPessoas{

    private:
        ISerPessoas *cntrServico;

    public:

        void criar() override;
        
        bool exec(const Email& email) override;

        void setCntrServico(ISerPessoas* cntr);
};

class cntrAprProjetos : public IAprProjetos{

    private:
        ISerProjetos *cntrServico;

    public:

        void exec(const Email& email) override;

        void setCntrServico(ISerProjetos* cntr);

};


class cntrAprQuadros : public IAprQuadros{

    private:
        ISerQuadros* cntrServico;
    
    public:
        void exec(const Email& email) override;

        void setCntrServico(ISerQuadros* cntr);
    
};


class cntrControlePrincipal{
    
    private:
        IAprAutenticacao* cntrAprAutenticacao;
        IAprPessoas* cntrAprPessoas;
        IAprProjetos* cntrAprProjetos;
        IAprQuadros* cntrAprQuadros;

    public:

        void executar(); 

        void setCntrAprAutenticacao(IAprAutenticacao* cntr);
        void setCntrAprPessoas(IAprPessoas* cntr);
        void setCntrAprProjetos(IAprProjetos* cntr);
        void setCntrAprQuadros(IAprQuadros* cntr);

};

// Declaracao das controladoras da camada de servico



#endif // CONTROLADORAS_HPP