#include "opcoesLivro.h"
#include "Geral.h"
#include "Livro.h"
#include "Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void entradaLivro(rgLivro *lstLivro, int *nLivro)
{
    rgLivro livro;
    int idLivro, ano;
    char *titulo = (char *)malloc(50);
    char *autor = (char *)malloc(50);
    while (1)
    {
        cls();
        printf("<<<<< CADASTRAR LIVROS >>>>>\n\n");
        printf("Identificacao (0 para encerrar): ");
        scanf("%d", &idLivro);
        if (idLivro == 0)
            break;
        if (acharLivro(lstLivro, *nLivro, idLivro) != -1)
        {
            printf("Livro já cadastrado!\n\n");
            pause();
            continue;
        }
        printf("\nTitulo do Livro.........: ");
        scanf(" %[^\n]s", titulo);

        printf("Autor do Livro..........: ");
        scanf(" %[^\n]s", autor);

        printf("Ano de Publicacao.......: ");
        scanf("%d", &ano);

        if (confirmou("Confirma o cadastro? (S/*): "))
        {
            livro = Livro(idLivro, titulo, autor, ano, 'X');
            lstLivro[*nLivro] = livro;
            *nLivro = *nLivro + 1;
            printf("<<<< Confirmado >>>>\n\n\n");
        }
        else
        {
            printf("<<<< Não Confirmado >>>>\n\n\n\n");
        }

        esvaziar(); // esvazia o buffer de entrada de dados
        pause();
    }
    free(titulo);
    free(autor);
}

void excluirLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario)
{
    int idLivro;
    int posicao;
    int idUsuario;
    int posicaoUsuario;
    cls();
    printf("<<<<< EXCLUIR LIVROS >>>>>\n\n");
    printf("Identificacao do Livro: ");
    scanf("%d", &idLivro);
    posicao = acharLivro(lstLivro, nLivro, idLivro);
    if (posicao == -1)
    {
        printf("Livro não encontrado!\n\n");
    }
    else
    {
        if (confirmou("Confirma a exclusão? (S/*): "))
        {
            setSitLivro(&lstLivro[posicao], ' ');
            idUsuario = getIdUsuarioLivro(&lstLivro[posicao]);
            posicaoUsuario = acharUsuario(lstUsuario, nUsuario, idUsuario);
            excluirLivroUsuario(&lstUsuario[posicaoUsuario], idLivro);
            printf("Id do Livro: %d | Posicao: %d | Nome: %s\n", idLivro, posicao, lstLivro[posicao].titulo);
            printf("<<<< Confirmado >>>>\n\n\n");
        }
        else
        {
            printf("<<<< Não Confirmado >>>>\n\n\n\n");
        }
    }
    pause();
}
void listarLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario)
{
    cls();
    int posicaoUsuario;
    printf("<<<<< LISTAR LIVROS >>>>>\n\n");
    for (int i = 0; i < nLivro; i++)
    {
        if (getSitLivro(&lstLivro[i]) == 'X')
        {
            printf("Identificacao: %d\n", lstLivro[i].codigo);
            printf("Titulo: %s\n", lstLivro[i].titulo);
            printf("Autor: %s\n", lstLivro[i].autor);
            printf("Ano: %d\n", lstLivro[i].ano);
            printf("ID Usuário: %d | ", lstLivro[i].idUsuario);
            posicaoUsuario = acharUsuario(lstUsuario, nUsuario, lstLivro[i].idUsuario);
            if (posicaoUsuario != -1)
            {
                printf("Usuário: %s\n", lstUsuario[posicaoUsuario].nome);
            }
            printf("Situação: %c\n\n", getSitLivro(&lstLivro[i]));
        }
    }
    pause();
}
void emprestarLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario)
{
    int idLivro, idUsuario;
    int posicaoLivro, posicaoUsuario;
    cls();
    printf("<<<<< EMPRESTAR LIVRO >>>>>\n\n");
    printf("Identificacao do Livro (0 para encerrar): ");
    scanf("%d", &idLivro);
    if (idLivro == 0)
    {
        esvaziar();
        return;
    }
    posicaoLivro = acharLivro(lstLivro, nLivro, idLivro);
    if (posicaoLivro == -1)
    {
        printf("Livro não encontrado!\n\n");
        esvaziar();
    }
    else
    {
        if (getIdUsuarioLivro(&lstLivro[posicaoLivro]) != -1)
        {
            printf("Livro já emprestado!\n\n");
            pause();
            return;
        }
        else
        {
            printf("Titulo: %s\n", lstLivro[posicaoLivro].titulo);
        }
        printf("Identificacao do Usuario: (0 para encerrar): ");
        scanf("%d", &idUsuario);
        if (idUsuario == 0)
        {
            esvaziar();
            return;
        }
        posicaoUsuario = acharUsuario(lstUsuario, nUsuario, idUsuario);
        if (posicaoUsuario == -1)
        {
            printf("Usuario não encontrado!\n\n");
            esvaziar();
            return;
        }
        else
        {
            printf("Nome: %s\n", lstUsuario[posicaoUsuario].nome);
            if (confirmou("Confirma requisição para empréstimo? (S/*): "))
            {
                printf("Carregando");
                for (int i = 0; i < 3; i++) {
                    printf(".");
                    fflush(stdout);
                    Sleep(1000);
                }
                printf("\n");
                setIdUsuarioLivro(&lstLivro[posicaoLivro], idUsuario);
                setLivrosEmprestadosUsuario(&lstUsuario[posicaoUsuario], idLivro);
                // printf("<<<< Confirmado >>>>\n\n\n");
            }
            else
            {
                printf("<<<< Não Confirmado >>>>\n\n\n\n");
            }
        }
    }
    pause();
}

void devolverLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario)
{
    int idLivro;
    int posicaoLivro;
    int idUsuario;
    int posicaoUsuario;
    cls();
    printf("<<<<< DEVOLVER LIVRO >>>>>\n\n");
    printf("Identificacao do Livro (0 para encerrar): ");
    scanf("%d", &idLivro);
    if (idLivro == 0)
    {
        return;
    }
    posicaoLivro = acharLivro(lstLivro, nLivro, idLivro);
    if (posicaoLivro == -1)
    {
        printf("Livro não encontrado!\n\n");
    }
    else
    {
        if (getIdUsuarioLivro(&lstLivro[posicaoLivro]) == -1)
        {
            printf("Livro não emprestado!\n\n");
            pause();
            return;
        }
        idUsuario = getIdUsuarioLivro(&lstLivro[posicaoLivro]);
        posicaoUsuario = acharUsuario(lstUsuario, nUsuario, idUsuario);
        if (posicaoUsuario == -1)
        {
            printf("Usuario não encontrado!\n\n");
        }
        else
        {
            if (confirmou("Confirma a devolução? (S/*): "))
            {
                setIdUsuarioLivro(&lstLivro[posicaoLivro], -1);
                excluirLivroUsuario(&lstUsuario[posicaoUsuario], idLivro);
                printf("<<<< Confirmado >>>>\n\n\n");
            }
            else
            {
                printf("<<<< Não Confirmado >>>>\n\n\n\n");
            }
        }
    }
    pause();
}

void importarLivros(rgLivro *livros, int *nLivros, rgUsuario *usuarios, int nUsuarios)
{
    FILE *arq;
    arq = fopen("livros.txt", "r");

    if (arq == NULL)
    {
        // Se não conseguir abrir o arquivo
        printf("Erro ao abrir o arquivo livros.txt\n");
        return; // Retorna para não continuar com o processamento
    }

    while (fscanf(arq, "%d;%99[^;];%99[^;];%d;%d;%c\n",
                  &livros[*nLivros].codigo,
                  livros[*nLivros].titulo,
                  livros[*nLivros].autor,
                  &livros[*nLivros].ano,
                  &livros[*nLivros].idUsuario,
                  &livros[*nLivros].sit) != EOF)
    {
        (*nLivros)++;

        if (livros[*nLivros - 1].idUsuario != -1)
        {
            int idUsuario = livros[*nLivros - 1].idUsuario;

            if (idUsuario > 0 && idUsuario <= nUsuarios)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (usuarios[idUsuario - 1].livrosEmprestados[i] == 0)
                    {
                        usuarios[idUsuario - 1].livrosEmprestados[i] = livros[*nLivros - 1].codigo;
                        break;
                    }
                }
            }
        }
    }

    fclose(arq);
}

void exportarLivro(rgLivro *livros, int nLivros)
{
    FILE *arq;
    arq = fopen("livros.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo livros.txt\n");
        return;
    }

    for (int i = 0; i < nLivros; i++)
    {
        fprintf(arq, "%d;%s;%s;%d;%d;%c\n",
                livros[i].codigo,
                livros[i].titulo,
                livros[i].autor,
                livros[i].ano,
                livros[i].idUsuario,
                livros[i].sit);
    }

    fclose(arq);
}