#include "controladoras.hpp"
#include "interfaces.hpp"
#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <stdexcept>

// Funções auxiliares para a realização da interface gráfica:

// Função auxiliar para desenhar o cabeçalho padrão da interface atual
static void desenharCabecalho(const char* titulo){
    clear();

    mvprintw(1, 4, "==========================================================");
    mvprintw(2, 4, "                   SISTEMA KANBAN                         ");
    mvprintw(3, 4, " %s", titulo);
    mvprintw(4, 4, "==========================================================");
}

// Função auxiliar para capturar uma string do usuário na posição (y, x)
static void lerString(int y, int x, const char* rotulo, char* destino, int tamanhoMax, bool esconder = false){
    mvprintw(y, x, "%s", rotulo);
    refresh();

    if(esconder){
        noecho(); // Esconde a senha digitada por default
    }
    else{
        echo(); // Corrigido: adicionado ()
    }

    curs_set(1); // Exibe o cursor
    move(y, x + strlen(rotulo));

    getnstr(destino, tamanhoMax);
    curs_set(0); // Oculta o cursor

    noecho();
}

// Função para exibir mensagens de sucesso/falha e aguardar confirmação
static void exibirMensagem(const char* mensagem){
    mvprintw(18, 4, "[ %s ]", mensagem);
    mvprintw(20, 4, "Pressione qualquer tecla para continuar...");
    refresh();
    getch();
}

// ============================================================================
// Realização das controladoras de apresentação:
// ============================================================================

// Módulo de autenticação (cntrAprAutenticacao):

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
        exibirMensagem(e.what()); // Exibe a mensagem dinâmica da exceção do domínio
        return false;
    }
}


// Módulo de Pessoas (cntrAprPessoas)

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

    // Adicionado o laço while para manter o menu ativo durante a navegação
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