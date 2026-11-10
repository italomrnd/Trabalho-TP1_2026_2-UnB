#include "controladoras.hpp"
#include "containers.hpp"
#include "interfaces.hpp"
#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <ctime>
#include <cstdio>

// ============================================================================
// Instanciação estática dos Containers em memória
// ============================================================================

static ContainerPessoa containerPessoa;
static ContainerProjeto containerProjeto;
static ContainerQuadro containerQuadro;
static ContainerCartao containerCartao;

// ============================================================================
// IMPLEMENTAÇÃO DAS CONTROLADORAS DE SERVIÇO
// ============================================================================

// 1. Controladora de Serviço de Autenticação

bool CntrSerAutenticacao::autenticar(const Email& email, const Senha& senha){
    Pessoa pessoaRetorno;

    if (!containerPessoa.pesquisar(email, &pessoaRetorno)){
        return false;
    }
    return (pessoaRetorno.getSenha().getValor() == senha.getValor());
}

// 2. Controladora de Serviço relativa a Pessoas

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
        return false;

    std::list<CartaodeAtividade> cartoesdoDev;
    if (containerCartao.listarPorDesenvolvedor(email, &cartoesdoDev) && !cartoesdoDev.empty())
        return false;
    
    return containerPessoa.remover(email);
}

// 3. Controladora de Serviço relativa a Projetos

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

// 4. Controladora de Serviço relativa a Quadros e Cartões

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

// ============================================================================
// FUNÇÕES AUXILIARES PARA A INTERFACE GRÁFICA (ncurses)
// ============================================================================

static void desenharCabecalho(const char* titulo){
    clear();
    mvprintw(1, 4, "==========================================================");
    mvprintw(2, 4, "                   SISTEMA KANBAN                         ");
    mvprintw(3, 4, " %s", titulo);
    mvprintw(4, 4, "==========================================================");
}

static void lerString(int y, int x, const char* rotulo, char* destino, int tamanhoMax, bool esconder = false){
    mvprintw(y, x, "%s", rotulo);
    refresh();

    if(esconder){
        noecho();
    }
    else{
        echo();
    }

    curs_set(1);
    move(y, x + strlen(rotulo));

    getnstr(destino, tamanhoMax);
    curs_set(0);

    noecho();
}

static void exibirMensagem(const char* mensagem){
    mvprintw(18, 4, "[ %s ]", mensagem);
    mvprintw(20, 4, "Pressione qualquer tecla para continuar...");
    refresh();
    getch();
}

// ============================================================================
// IMPLEMENTAÇÃO DAS CONTROLADORAS DE APRESENTAÇÃO
// ============================================================================

// 1. Módulo de Autenticação (cntrAprAutenticacao)

void cntrAprAutenticacao::setCntrServico(ISerAutenticacao* cntr){
    this->cntrServico = cntr;
}

bool cntrAprAutenticacao::autenticar(Email* email){
    char emailBuffer[80];
    char senhaBuffer[80];

    desenharCabecalho("AUTENTICACAO DO UTILIZADOR");

    lerString(7, 4, "Email: ", emailBuffer, 79);
    lerString(9, 4, "Senha: ", senhaBuffer, 79, true);

    try{
        Email emailInserido;
        emailInserido.setValor(emailBuffer);
        Senha senhaInserida;
        senhaInserida.setValor(senhaBuffer);

        if(cntrServico != nullptr && cntrServico->autenticar(emailInserido, senhaInserida)){
            *email = emailInserido;
            exibirMensagem("Autenticacao realizada com sucesso!");
            return true;
        }
        else{
            exibirMensagem("Erro: Credenciais invalidas ou falha no servico.");
            return false;
        }
    } catch(const std::invalid_argument& e){
        exibirMensagem(e.what());
        return false;
    }
}

// 2. Módulo de Pessoas (cntrAprPessoas)

void cntrAprPessoas::setCntrServico(ISerPessoas* cntr){
    this->cntrServico = cntr;
}

void cntrAprPessoas::criar(){
    char nomeBuffer[80];
    char emailBuffer[80];
    char senhaBuffer[80];
    char papelBuffer[80];

    desenharCabecalho("CADASTRO DE NOVO UTILIZADOR");

    lerString(6, 4, "Nome:                                    ", nomeBuffer, 79);
    lerString(8, 4, "Email:                                   ", emailBuffer, 79);
    lerString(10, 4, "Papel (GESTOR ou DESENVOLVEDOR):         ", papelBuffer, 79);
    lerString(12, 4, "Senha (5 caracteres: letras e digitos): ", senhaBuffer, 79, true);

    try{
        Nome nome; nome.setValor(nomeBuffer);
        Email email; email.setValor(emailBuffer);
        Papel papel; papel.setValor(papelBuffer);
        Senha senha; senha.setValor(senhaBuffer);

        Pessoa pessoaNova;
        pessoaNova.setNome(nome);
        pessoaNova.setEmail(email);
        pessoaNova.setPapel(papel);
        pessoaNova.setSenha(senha);

        if(cntrServico != nullptr && cntrServico->criar(pessoaNova)){
            exibirMensagem("Conta criada com sucesso!");
        }
        else{
            exibirMensagem("Erro ao cadastrar, email ja registrado ou erro no servico.");
        }
    } catch(const std::invalid_argument& e){
        exibirMensagem(e.what());
    }
}

bool cntrAprPessoas::exec(const Email& email){
    int opcao;
    bool continuarSessao = true;

    while(continuarSessao){
        desenharCabecalho("GESTÃO DA CONTA PESSOAL");

        mvprintw(6, 4, "Utilizador autenticado: %s", email.getValor().c_str());
        mvprintw(8, 6, "1. Visualizar meus dados");
        mvprintw(9, 6, "2. Atualizar meus dados");
        mvprintw(10, 6, "3. Excluir minha conta");
        mvprintw(11, 6, "4. Voltar ao menu principal");
        mvprintw(13, 4, "Selecione uma opção: ");

        refresh();
        opcao = getch();
        
        switch(opcao){
            case '1': {
                desenharCabecalho("MEUS DADOS");
                Pessoa pessoa; 
                pessoa.setEmail(email);

                if(cntrServico != nullptr && cntrServico->ler(&pessoa)){
                    mvprintw(7, 4, "Nome:  %s", pessoa.getNome().getValor().c_str());
                    mvprintw(8, 4, "Email: %s", pessoa.getEmail().getValor().c_str());
                    mvprintw(9, 4, "Papel: %s", pessoa.getPapel().getValor().c_str());
                }
                else{
                    mvprintw(7, 4, "Nao foi possivel carregar os dados.");
                }

                exibirMensagem("Fim da visualizacao.");
                break;   
            }

            case '2': {
                char novoNome[80], novaSenha[80], novoPapel[80];
                desenharCabecalho("ATUALIZAR DADOS");

                lerString(7, 4, "Novo nome:                ", novoNome, 79);
                lerString(8, 4, "Nova senha:               ", novaSenha, 79, true);
                lerString(9, 4, "Novo papel:               ", novoPapel, 79);

                try{
                    Nome n; n.setValor(novoNome);
                    Senha s; s.setValor(novaSenha);
                    Papel p; p.setValor(novoPapel);

                    Pessoa pessoaAtualizada;
                    pessoaAtualizada.setEmail(email);
                    pessoaAtualizada.setNome(n);
                    pessoaAtualizada.setSenha(s);
                    pessoaAtualizada.setPapel(p);

                    if(cntrServico != nullptr && cntrServico->atualizar(pessoaAtualizada)){
                        exibirMensagem("Dados atualizados com sucesso!");
                    }
                    else{
                        exibirMensagem("Falha ao atualizar dados.");
                    }
                } catch(const std::invalid_argument& e){
                    exibirMensagem(e.what());
                }
                break;
            }

            case '3': {
                desenharCabecalho("EXCLUIR CONTA");
                mvprintw(7, 4, "Tem certeza que deseja excluir a conta? [S/N]: ");
                refresh();

                int conferir = getch();

                if(conferir == 'S' || conferir == 's'){
                    if(cntrServico != nullptr && cntrServico->excluir(email)){
                        exibirMensagem("Conta excluida com sucesso.");
                        continuarSessao = false;
                    }
                    else{
                        exibirMensagem("Falha ao excluir conta.");
                    }
                }
                break;
            }

            case '4':
                return continuarSessao;

            default:
                exibirMensagem("Opcao invalida!");
                break;
        }
    }

    return continuarSessao;
}

// 3. Módulo de Projetos (cntrAprProjetos)

void cntrAprProjetos::setCntrServico(ISerProjetos* cntr) {
    this->cntrServico = cntr;
}

void cntrAprProjetos::exec(const Email& email) {
    int opcao;
    bool rodando = true;

    while (rodando) {
        desenharCabecalho("GESTÃO DE PROJETOS");

        mvprintw(6, 6, "1. Criar Projeto");
        mvprintw(7, 6, "2. Visualizar Projeto");
        mvprintw(8, 6, "3. Atualizar Projeto");
        mvprintw(9, 6, "4. Excluir Projeto");
        mvprintw(10, 6, "5. Voltar");
        mvprintw(12, 4, "Selecione uma opcao: ");
        refresh();

        opcao = getch();

        switch (opcao) {
            case '1': {
                char idBuf[80], nomeBuf[80], descBuf[80], inicioBuf[80], terminoBuf[80];
                desenharCabecalho("CRIAR PROJETO");
                lerString(6, 4, "Codigo (3 letras + 3 digitos):   ", idBuf, 79);
                lerString(8, 4, "Nome do Projeto:                 ", nomeBuf, 79);
                lerString(10, 4, "Descricao (Maiuscula e fim '.'):  ", descBuf, 79);
                lerString(12, 4, "Inicio (DD-MES-AAAA-HH:MM):       ", inicioBuf, 79);
                lerString(14, 4, "Termino (DD-MES-AAAA-HH:MM):      ", terminoBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    Nome nome;         nome.setValor(nomeBuf);
                    Texto desc;        desc.setValor(descBuf);
                    Timestamp inicio;  inicio.setValor(inicioBuf);
                    Timestamp termino; termino.setValor(terminoBuf);

                    Projeto proj;
                    proj.setIdentificador(id);
                    proj.setNome(nome);
                    proj.setDescricao(desc);
                    proj.setInicio(inicio);
                    proj.setTermino(termino);

                    if (cntrServico != nullptr && cntrServico->criar(proj)) {
                        exibirMensagem("Projeto criado com sucesso!");
                    } else {
                        exibirMensagem("Erro ao criar projeto.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '2': {
                char idBuf[80];
                desenharCabecalho("VISUALIZAR PROJETO");
                lerString(6, 4, "Informe o Identificador do Projeto: ", idBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    Projeto proj;
                    proj.setIdentificador(id);

                    if (cntrServico != nullptr && cntrServico->ler(&proj)) {
                        mvprintw(8, 4, "Nome:      %s", proj.getNome().getValor().c_str());
                        mvprintw(9, 4, "Descrição: %s", proj.getDescricao().getValor().c_str());
                        mvprintw(10, 4, "Início:    %s", proj.getInicio().getValor().c_str());
                        mvprintw(11, 4, "Término:   %s", proj.getTermino().getValor().c_str());
                    } else {
                        mvprintw(8, 4, "Projeto nao encontrado.");
                    }
                    exibirMensagem("Consulta concluida.");
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '3': {
                char idBuf[80], nomeBuf[80], descBuf[80], inicioBuf[80], terminoBuf[80];
                desenharCabecalho("ATUALIZAR PROJETO");
                lerString(6, 4, "Codigo do Projeto a alterar:     ", idBuf, 79);
                lerString(8, 4, "Novo Nome do Projeto:            ", nomeBuf, 79);
                lerString(10, 4, "Nova Descricao (Maiuscula + '.'): ", descBuf, 79);
                lerString(12, 4, "Novo Inicio (DD-MES-AAAA-HH:MM): ", inicioBuf, 79);
                lerString(14, 4, "Novo Termino (DD-MES-AAAA-HH:MM):", terminoBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    Nome nome;         nome.setValor(nomeBuf);
                    Texto desc;        desc.setValor(descBuf);
                    Timestamp inicio;  inicio.setValor(inicioBuf);
                    Timestamp termino; termino.setValor(terminoBuf);

                    Projeto proj;
                    proj.setIdentificador(id);
                    proj.setNome(nome);
                    proj.setDescricao(desc);
                    proj.setInicio(inicio);
                    proj.setTermino(termino);

                    if (cntrServico != nullptr && cntrServico->atualizar(proj)) {
                        exibirMensagem("Projeto atualizado com sucesso!");
                    } else {
                        exibirMensagem("Erro ao atualizar projeto.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '4': {
                char idBuf[80];
                desenharCabecalho("EXCLUIR PROJETO");
                lerString(6, 4, "Informe o Identificador do Projeto a excluir: ", idBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    if (cntrServico != nullptr && cntrServico->excluir(id)) {
                        exibirMensagem("Projeto excluido com sucesso.");
                    } else {
                        exibirMensagem("Erro ao excluir projeto.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '5':
                rodando = false;
                break;
            default:
                exibirMensagem("Opcao invalida!");
                break;
        }
    }
}

// 4. Módulo de Quadros e Cartões (cntrAprQuadros)

void cntrAprQuadros::setCntrServico(ISerQuadros* cntr) {
    this->cntrServico = cntr;
}

void cntrAprQuadros::exec(const Email& email) {
    int opcao;
    bool rodando = true;

    while (rodando) {
        desenharCabecalho("GESTÃO DE QUADROS E CARTÕES DE ATIVIDADE");

        mvprintw(6, 6, "1. Criar Quadro");
        mvprintw(7, 6, "2. Visualizar Quadro");
        mvprintw(8, 6, "3. Excluir Quadro");
        mvprintw(9, 6, "4. Criar Cartao de Atividade");
        mvprintw(10, 6, "5. Excluir Cartao de Atividade");
        mvprintw(11, 6, "6. Voltar");
        mvprintw(13, 4, "Selecione uma opcao: ");
        refresh();

        opcao = getch();

        switch (opcao) {
            case '1': {
                char idBuf[80], nomeBuf[80], limiteBuf[80];
                desenharCabecalho("CRIAR QUADRO");
                lerString(6, 4, "Identificador (3 letras + 3 digitos): ", idBuf, 79);
                lerString(8, 4, "Nome:                                 ", nomeBuf, 79);
                lerString(10, 4, "Limite WIP (1 a 25):                  ", limiteBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    Nome nome;         nome.setValor(nomeBuf);

                    int valorLimite = std::stoi(limiteBuf);
                    Limite limite;     limite.setValor(valorLimite);

                    Quadro q;
                    q.setIdentificador(id);
                    q.setNome(nome);
                    q.setLimite(limite);

                    if (cntrServico != nullptr && cntrServico->criar(q)) {
                        exibirMensagem("Quadro criado com sucesso!");
                    } else {
                        exibirMensagem("Erro ao criar quadro.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                } catch (const std::out_of_range&) {
                    exibirMensagem("Erro: O limite informado esta fora do alcance numerico!");
                }
                break;
            }
            case '2': {
                char idBuf[80];
                desenharCabecalho("VISUALIZAR QUADRO");
                lerString(6, 4, "Identificador do Quadro: ", idBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    Quadro q;
                    q.setIdentificador(id);

                    if (cntrServico != nullptr && cntrServico->ler(&q)) {
                        mvprintw(8, 4, "Nome:       %s", q.getNome().getValor().c_str());
                        mvprintw(9, 4, "Limite WIP: %d", q.getLimite().getValor());
                    } else {
                        mvprintw(8, 4, "Quadro nao encontrado.");
                    }
                    exibirMensagem("Consulta concluida.");
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '3': {
                char idBuf[80];
                desenharCabecalho("EXCLUIR QUADRO");
                lerString(6, 4, "Identificador do Quadro a apagar: ", idBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    if (cntrServico != nullptr && cntrServico->excluir(id)) {
                        exibirMensagem("Quadro excluido com sucesso.");
                    } else {
                        exibirMensagem("Erro ao excluir quadro.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '4': {
                char idCartaoBuf[80], idQuadroBuf[80], nomeBuf[80], descBuf[80];
                char prioBuf[80], estBuf[80], tamBuf[80];
                char inicoBuf[80], entBuf[80], termBuf[80];

                desenharCabecalho("CRIAR CARTÃO DE ATIVIDADE");
                lerString(5, 4, "ID do Quadro Destino:             ", idQuadroBuf, 79);
                lerString(6, 4, "ID do Cartao (3 letras+3 digitos):", idCartaoBuf, 79);
                lerString(7, 4, "Nome:                             ", nomeBuf, 79);
                lerString(8, 4, "Descricao (Maiuscula e fim '.'):   ", descBuf, 79);
                lerString(9, 4, "Prioridade (ALTA/MEDIA/BAIXA):    ", prioBuf, 79);
                lerString(10, 4, "Estado (A FAZER/FAZENDO/FEITO):   ", estBuf, 79);
                lerString(11, 4, "Tamanho (GRANDE/MEDIO/PEQUENO):   ", tamBuf, 79);
                lerString(12, 4, "Entrada (DD-MES-AAAA-HH:MM):      ", entBuf, 79);
                lerString(13, 4, "Inicio  (DD-MES-AAAA-HH:MM):      ", inicoBuf, 79);
                lerString(14, 4, "Termino (DD-MES-AAAA-HH:MM):      ", termBuf, 79);

                try {
                    Identificador idQuadro; idQuadro.setValor(idQuadroBuf);
                    Identificador idCartao; idCartao.setValor(idCartaoBuf);
                    Nome nome;              nome.setValor(nomeBuf);
                    Texto desc;             desc.setValor(descBuf);
                    Prioridade prio;        prio.setValor(prioBuf);
                    Estado est;             est.setValor(estBuf);
                    Tamanho tam;            tam.setValor(tamBuf);
                    Timestamp ent;          ent.setValor(entBuf);
                    Timestamp ini;          ini.setValor(inicoBuf);
                    Timestamp term;         term.setValor(termBuf);

                    CartaodeAtividade cartao;
                    cartao.setIdentificador(idCartao);
                    cartao.setNome(nome);
                    cartao.setDescricao(desc);
                    cartao.setPrioridade(prio);
                    cartao.setEstado(est);
                    cartao.setTamanho(tam);
                    cartao.setEntrada(ent);
                    cartao.setInicio(ini);
                    cartao.setTermino(term);

                    if (cntrServico != nullptr && cntrServico->criarCartao(cartao, idQuadro)) {
                        exibirMensagem("Cartao de atividade criado com sucesso!");
                    } else {
                        exibirMensagem("Erro ao criar cartao no quadro informado.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '5': {
                char idBuf[80];
                desenharCabecalho("EXCLUIR CARTÃO DE ATIVIDADE");
                lerString(6, 4, "Identificador do Cartao a apagar: ", idBuf, 79);
                try {
                    Identificador id; id.setValor(idBuf);
                    if (cntrServico != nullptr && cntrServico->excluirCartao(id)) {
                        exibirMensagem("Cartao excluido com sucesso.");
                    } else {
                        exibirMensagem("Erro ao excluir cartao.");
                    }
                } catch (const std::invalid_argument& e) {
                    exibirMensagem(e.what());
                }
                break;
            }
            case '6':
                rodando = false;
                break;
            default:
                exibirMensagem("Opcao invalida!");
                break;
        }
    }
}

// 5. Controladora Principal da Aplicação (cntrControlePrincipal)

void cntrControlePrincipal::setCntrAprAutenticacao(IAprAutenticacao* cntr) {
    this->cntrAprAutenticacao = cntr;
}

void cntrControlePrincipal::setCntrAprPessoas(IAprPessoas* cntr) {
    this->cntrAprPessoas = cntr;
}

void cntrControlePrincipal::setCntrAprProjetos(IAprProjetos* cntr) {
    this->cntrAprProjetos = cntr;
}

void cntrControlePrincipal::setCntrAprQuadros(IAprQuadros* cntr) {
    this->cntrAprQuadros = cntr;
}

void cntrControlePrincipal::executar() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    bool sistemaRodando = true;
    bool autenticado = false;
    Email emailLogado;

    while (sistemaRodando) {
        if (!autenticado) {
            desenharCabecalho("SISTEMA KANBAN - MENU INICIAL");
            mvprintw(7, 6, "1. Entrar (Autenticar)");
            mvprintw(8, 6, "2. Cadastrar Nova Conta");
            mvprintw(9, 6, "3. Sair do Sistema");
            mvprintw(11, 4, "Selecione uma opcao: ");
            refresh();

            int op = getch();

            switch (op) {
                case '1':
                    if (cntrAprAutenticacao != nullptr) {
                        autenticado = cntrAprAutenticacao->autenticar(&emailLogado);
                    } else {
                        exibirMensagem("Modulo de autenticacao nao conectado.");
                    }
                    break;
                case '2':
                    if (cntrAprPessoas != nullptr) {
                        cntrAprPessoas->criar();
                    } else {
                        exibirMensagem("Modulo de pessoas nao conectado.");
                    }
                    break;
                case '3':
                    sistemaRodando = false;
                    break;
                default:
                    exibirMensagem("Opcao invalida!");
                    break;
            }
        } else {
            desenharCabecalho("PAINEL PRINCIPAL KANBAN");
            mvprintw(6, 4, "Sessao ativa: %s", emailLogado.getValor().c_str());
            mvprintw(8, 6, "1. Minha Conta (Pessoas)");
            mvprintw(9, 6, "2. Gestao de Projetos");
            mvprintw(10, 6, "3. Gestao de Quadros e Cartoes");
            mvprintw(11, 6, "4. Encerrar Sessao (Logout)");
            mvprintw(12, 6, "5. Sair do Sistema");
            mvprintw(14, 4, "Selecione uma opcao: ");
            refresh();

            int op = getch();

            switch (op) {
                case '1':
                    if (cntrAprPessoas != nullptr) {
                        autenticado = cntrAprPessoas->exec(emailLogado);
                    }
                    break;
                case '2':
                    if (cntrAprProjetos != nullptr) {
                        cntrAprProjetos->exec(emailLogado);
                    }
                    break;
                case '3':
                    if (cntrAprQuadros != nullptr) {
                        cntrAprQuadros->exec(emailLogado);
                    }
                    break;
                case '4':
                    autenticado = false;
                    exibirMensagem("Sessao encerrada.");
                    break;
                case '5':
                    sistemaRodando = false;
                    break;
                default:
                    exibirMensagem("Opcao invalida!");
                    break;
            }
        }
    }

    endwin();
}