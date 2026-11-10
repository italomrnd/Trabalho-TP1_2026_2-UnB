#include "controladoras.hpp"
#include "containers.hpp"
#include <list>
#include <string>
#include <ctime>
#include <cstdio>

// Instanciacao dos containers 

static ContainerPessoa containerPessoa;
static ContainerProjeto containerProjeto;
static ContainerQuadro containerQuadro;
static ContainerCartao containerCartao;

// Implementacao das controladoras de apresentacao




// Implementacao das controladoras de servico


// Controladora de servico de Autenticacao

bool CntrSerAutenticacao::autenticar(const Email& email, const Senha& senha){
    Pessoa pessoaRetorno;

    if (!containerPessoa.pesquisar(email, &pessoaRetorno)){ // essa pessoa nao está cadastrada.
        return false;
    }
    return (pessoaRetorno.getSenha().getValor() == senha.getValor()); // se as senhas batem
}

// Controladora de servico relativo a Pessoas

bool CntrSerPessoas::criar(const Pessoa& pessoa){
    return containerPessoa.incluir(pessoa);
}

bool CntrSerPessoas::ler(Pessoa* pessoaRetorno){
    if (pessoaRetorno == nullptr)
        return false;
    return containerPessoa.pesquisar(pessoaRetorno->getEmail(), pessoaRetorno);
}

bool CntrSerPessoas::atualizar(const Pessoa& pessoa){
    return containerPessoa.atualizar(pessoa);
}

bool CntrSerPessoas::excluir(const Email& email){
    std::list<Projeto> projetosGestor;
    if (containerProjeto.listar(email, &projetosGestor) && !projetosGestor.empty())
        return false; // se a pessoa tem projetos, não é possivel excluir seu cadastro

    std::list<CartaodeAtividade> cartoesdoDev;
    if (containerCartao.listarPorDesenvolvedor(email, &cartoesdoDev) && !cartoesdoDev.empty())
        return false; // se a pessoa tem cartoes de atividade, não é possivel excluir seu cadastro
    
    return containerPessoa.remover(email);
}

// Controladora de servicos relativo a Projetos

bool CntrSerProjetos::criar(const Projeto& projeto){
    Pessoa gestorRetorno;
    if (!containerPessoa.pesquisar(projeto.getGestor(), &gestorRetorno))
        return false;
    return containerProjeto.incluir(projeto);
}

bool CntrSerProjetos::ler(Projeto* projetoRetorno){
    if (projetoRetorno == nullptr)
        return false;
    return containerProjeto.pesquisar(projetoRetorno->getIdentificador(), projetoRetorno);
}

bool CntrSerProjetos::atualizar(const Projeto& projeto){
    return containerProjeto.atualizar(projeto);
}

bool CntrSerProjetos::excluir(const Identificador& identificador){
    std::list<Quadro> quadrosDoProjeto;
    containerQuadro.listar(identificador, &quadrosDoProjeto);

    for (auto itQuadro = quadrosDoProjeto.begin(); itQuadro != quadrosDoProjeto.end(); ++itQuadro){
        std::list<CartaodeAtividade> cartoesDoQuadro;
        containerCartao.listar(itQuadro->getIdentificador(), &cartoesDoQuadro);

        for (auto itCartao = cartoesDoQuadro.begin(); itCartao != cartoesDoQuadro.end(); ++itCartao){
            containerCartao.remover(itCartao->getIdentificador());
        }
        containerQuadro.remover(itQuadro->getIdentificador());
    }

    return containerProjeto.remover(identificador);
}

// Controladora de servicos relativo a Quadros

bool CntrSerQuadros::criar(const Quadro& quadro){
    Projeto projetoRetorno;
    if (!containerProjeto.pesquisar(quadro.getIdProjeto(), &projetoRetorno))
        return false;
    return containerQuadro.incluir(quadro);
}

bool CntrSerQuadros::ler(Quadro* quadroRetorno){
    if (quadroRetorno == nullptr)
        return false;
    return containerQuadro.pesquisar(quadroRetorno->getIdentificador(), quadroRetorno);
}

bool CntrSerQuadros::atualizar(const Quadro& quadro){
    return containerQuadro.atualizar(quadro);
}

bool CntrSerQuadros::excluir(const Identificador& identificador){
    std::list<CartaodeAtividade> cartoesDoQuadro;
    containerCartao.listar(identificador, &cartoesDoQuadro);

    for (auto it = cartoesDoQuadro.begin(); it != cartoesDoQuadro.end(); ++it){
        containerCartao.remover(it->getIdentificador());
    }

    return containerQuadro.remover(identificador);
}

bool CntrSerQuadros::listar(const Email& emailDono, std::list<Quadro>* listaQuadrosRetorno){
    if (listaQuadrosRetorno == nullptr)
        return false;
    listaQuadrosRetorno->clear();

    std::list<Projeto> projetosDoGestor;
    containerProjeto.listar(emailDono, &projetosDoGestor);

    for (auto itProj = projetosDoGestor.begin(); itProj != projetosDoGestor.end(); ++itProj){
        std::list<Quadro> quadrosDoProj;
        if (containerQuadro.listar(itProj->getIdentificador(), &quadrosDoProj)){
            listaQuadrosRetorno->insert(listaQuadrosRetorno->end(), quadrosDoProj.begin(), quadrosDoProj.end());
        }
    }

    return !listaQuadrosRetorno->empty();
}

bool CntrSerQuadros::criarCartao(const CartaodeAtividade& cartao, const Identificador& idQuadro){
    Quadro quadroRetorno;
    if (!containerQuadro.pesquisar(idQuadro, &quadroRetorno))
        return false;

    CartaodeAtividade novoCartao = cartao;
    novoCartao.setIdQuadro(idQuadro);

    return containerCartao.incluir(novoCartao);
}

bool CntrSerQuadros::lerCartao(CartaodeAtividade* cartaoRetorno){
    if (cartaoRetorno == nullptr)
        return false;
    return containerCartao.pesquisar(cartaoRetorno->getIdentificador(), cartaoRetorno);
}

bool CntrSerQuadros::atualizarCartao(const CartaodeAtividade& cartao){
    return containerCartao.atualizar(cartao);
}

bool CntrSerQuadros::excluirCartao(const Identificador& identificador){
    return containerCartao.remover(identificador);
}

bool CntrSerQuadros::listarCartoes(const Identificador& idQuadro, std::list<CartaodeAtividade>* listaCartoesRetorno){
    return containerCartao.listar(idQuadro, listaCartoesRetorno);
}

bool CntrSerQuadros::moverCartao(const Identificador& idCartao, const Estado& novoEstado, const Timestamp& momentoAtual){
    CartaodeAtividade cartaoRetorno;
    if (!containerCartao.pesquisar(idCartao, &cartaoRetorno))
        return false;

    std::string estadoAtual = cartaoRetorno.getEstado().getValor();
    std::string destino = novoEstado.getValor();

    if (estadoAtual == "A FAZER" && destino == "FAZENDO"){
        int wipAtual = 0;
        lerWIP(cartaoRetorno.getIdQuadro(), &wipAtual);

        Quadro quadroRetorno;
        if (!containerQuadro.pesquisar(cartaoRetorno.getIdQuadro(), &quadroRetorno))
            return false;

        int limiteWip = quadroRetorno.getLimite().getValor();
        if (wipAtual >= limiteWip)
            return false;

        cartaoRetorno.setEstado(novoEstado);
        cartaoRetorno.setInicio(momentoAtual);
    }
    else if (estadoAtual == "FAZENDO" && destino == "FEITO"){
        cartaoRetorno.setEstado(novoEstado);
        cartaoRetorno.setTermino(momentoAtual);
    }
    else {
        return false;
    }

    return containerCartao.atualizar(cartaoRetorno);
}

bool CntrSerQuadros::lerWIP(const Identificador& idQuadro, int* quantidadeWIPRetorno){
    if (quantidadeWIPRetorno == nullptr)
        return false;

    std::list<CartaodeAtividade> cartoes;
    containerCartao.listar(idQuadro, &cartoes);

    int count = 0;
    for (auto it = cartoes.begin(); it != cartoes.end(); ++it){
        if (it->getEstado().getValor() == "FAZENDO"){
            count++;
        }
    }

    *quantidadeWIPRetorno = count;
    return true;
}

bool CntrSerQuadros::lerTempoCiclo(const Identificador& idCartao, double* tempoSegundosRetorno){
    if (tempoSegundosRetorno == nullptr)
        return false;

    CartaodeAtividade cartaoRetorno;
    if (!containerCartao.pesquisar(idCartao, &cartaoRetorno))
        return false;
    if (cartaoRetorno.getEstado().getValor() != "FEITO")
        return false;

    int d1, a1, h1, m1, d2, a2, h2, m2;
    char mes1[4], mes2[4];

    if (sscanf(cartaoRetorno.getInicio().getValor().c_str(), "%d-%3s-%d-%d:%d", &d1, mes1, &a1, &h1, &m1) != 5 ||
        sscanf(cartaoRetorno.getTermino().getValor().c_str(), "%d-%3s-%d-%d:%d", &d2, mes2, &a2, &h2, &m2) != 5) {
        return false;
    }

    const std::string meses[] = {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AGO","SET","OUT","NOV","DEZ"};
    int mon1 = 0, mon2 = 0;
    for (int i = 0; i < 12; ++i){
        if (std::string(mes1) == meses[i]) mon1 = i;
        if (std::string(mes2) == meses[i]) mon2 = i;
    }

    std::tm tInicio = {}, tTermino = {};
    tInicio.tm_mday = d1;  tInicio.tm_mon = mon1;  tInicio.tm_year = a1 - 1900; tInicio.tm_hour = h1;  tInicio.tm_min = m1;
    tTermino.tm_mday = d2; tTermino.tm_mon = mon2; tTermino.tm_year = a2 - 1900; tTermino.tm_hour = h2; tTermino.tm_min = m2;

    time_t timeInicio = std::mktime(&tInicio);
    time_t timeTermino = std::mktime(&tTermino);

    if (timeInicio == -1 || timeTermino == -1 || timeTermino < timeInicio)
        return false;

    *tempoSegundosRetorno = std::difftime(timeTermino, timeInicio);
    return true;
}

bool CntrSerQuadros::lerTempoCicloMedio(const Identificador& idQuadro, double* mediaSegundosRetorno){
    if (mediaSegundosRetorno == nullptr)
        return false;

    std::list<CartaodeAtividade> cartoes;
    if (!containerCartao.listar(idQuadro, &cartoes))
        return false;

    double somaSegundos = 0.0;
    int qtdConcluidos = 0;

    for (auto it = cartoes.begin(); it != cartoes.end(); ++it){
        if (it->getEstado().getValor() == "FEITO"){
            double tempoIndiv = 0.0;
            if (lerTempoCiclo(it->getIdentificador(), &tempoIndiv)){
                somaSegundos += tempoIndiv;
                qtdConcluidos++;
            }
        }
    }

    if (qtdConcluidos == 0)
        return false;

    *mediaSegundosRetorno = somaSegundos / qtdConcluidos;
    return true;
}

bool CntrSerQuadros::lerLeadTime(const Identificador& idCartao, double* tempoSegundosRetorno){
    if (tempoSegundosRetorno == nullptr)
        return false;

    CartaodeAtividade cartaoRetorno;
    if (!containerCartao.pesquisar(idCartao, &cartaoRetorno))
        return false;
    if (cartaoRetorno.getEstado().getValor() != "FEITO")
        return false;

    int d1, a1, h1, m1, d2, a2, h2, m2;
    char mes1[4], mes2[4];

    if (sscanf(cartaoRetorno.getEntrada().getValor().c_str(), "%d-%3s-%d-%d:%d", &d1, mes1, &a1, &h1, &m1) != 5 ||
        sscanf(cartaoRetorno.getTermino().getValor().c_str(), "%d-%3s-%d-%d:%d", &d2, mes2, &a2, &h2, &m2) != 5) {
        return false;
    }

    const std::string meses[] = {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AGO","SET","OUT","NOV","DEZ"};
    int mon1 = 0, mon2 = 0;
    for (int i = 0; i < 12; ++i){
        if (std::string(mes1) == meses[i]) mon1 = i;
        if (std::string(mes2) == meses[i]) mon2 = i;
    }

    std::tm tEntrada = {}, tTermino = {};
    tEntrada.tm_mday = d1;  tEntrada.tm_mon = mon1;  tEntrada.tm_year = a1 - 1900; tEntrada.tm_hour = h1;  tEntrada.tm_min = m1;
    tTermino.tm_mday = d2; tTermino.tm_mon = mon2; tTermino.tm_year = a2 - 1900; tTermino.tm_hour = h2; tTermino.tm_min = m2;

    time_t timeEntrada = std::mktime(&tEntrada);
    time_t timeTermino = std::mktime(&tTermino);

    if (timeEntrada == -1 || timeTermino == -1 || timeTermino < timeEntrada)
        return false;

    *tempoSegundosRetorno = std::difftime(timeTermino, timeEntrada);
    return true;
}

bool CntrSerQuadros::lerLeadTimeMedio(const Identificador& idQuadro, double* mediaSegundosRetorno){
    if (mediaSegundosRetorno == nullptr)
        return false;

    std::list<CartaodeAtividade> cartoes;
    if (!containerCartao.listar(idQuadro, &cartoes))
        return false;

    double somaSegundos = 0.0;
    int qtdConcluidos = 0;

    for (auto it = cartoes.begin(); it != cartoes.end(); ++it){
        if (it->getEstado().getValor() == "FEITO"){
            double tempoIndiv = 0.0;
            if (lerLeadTime(it->getIdentificador(), &tempoIndiv)){
                somaSegundos += tempoIndiv;
                qtdConcluidos++;
            }
        }
    }

    if (qtdConcluidos == 0)
        return false;

    *mediaSegundosRetorno = somaSegundos / qtdConcluidos;
    return true;
}