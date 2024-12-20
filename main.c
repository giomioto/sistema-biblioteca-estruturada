/*----------------------------------------
PROJETO FINAL I - TECNICAS DE PROGRAMACAO
------------------------------------------
ESTUDANTE: GIOVANNI MIOTO
RA: 2603454
------------------------------------------
BIBLIOTECA EM LINGUAGEM ESTRUTURADA
----------------------------------------*/




#include <stdio.h>
#include <ctype.h>
#include "Livro.h"
#include "Usuario.h"
#include "Geral.h"
#include "opcoesLivro.h"
#include "opcoesUsuario.h"

#define maxTam 100

int main()
{
    int opcao;


    rgUsuario lstUsuario[maxTam];
    int nUsuario = 0;
    importarUsuarios(lstUsuario, &nUsuario);

    rgLivro lstLivro[maxTam];
    int nLivro = 0;
    importarLivros(lstLivro, &nLivro, lstUsuario, nUsuario);

    do
    {
        cls();
        printf("********* MENU PRINCIPAL *********\n");
        printf("[ 1 ] Cadastrar Livros\n");
        printf("[ 2 ] Excluir Livros\n");
        printf("[ 3 ] Listar Livros\n");
        printf("[ 4 ] Emprestar Livro\n");
        printf("[ 5 ] Devolver Livro\n");
        printf("[ 6 ] Cadastrar Usuários\n");
        printf("[ 7 ] Excluir Usuários\n");
        printf("[ 8 ] Listar Usuários\n");
        printf("[ 0 ] Encerrar\n");
        printf("**********************************\n");

        do
        {
            printf("Opção Desejada? ");
            scanf("%d", &opcao);
        } while ((opcao < 0) || (opcao > 8));

        printf("\n");
        if (opcao == 1)
            entradaLivro(lstLivro, &nLivro);
        else if (opcao == 2)
            excluirLivro(lstLivro, nLivro, lstUsuario, nUsuario);
        else if (opcao == 3)
            listarLivro(lstLivro, nLivro, lstUsuario, nUsuario);
        else if (opcao == 4)
            emprestarLivro(lstLivro, nLivro, lstUsuario, nUsuario);
        else if (opcao == 5)
            devolverLivro(lstLivro, nLivro, lstUsuario, nUsuario);
        else if (opcao == 6)
            entradaUsuario(lstUsuario, &nUsuario);
        else if (opcao == 7)
            excluirUsuario(lstUsuario, nUsuario, lstLivro, nLivro);
        else if (opcao == 8)
            listarUsuario(lstUsuario, nUsuario, lstLivro, nLivro);

    } while (opcao != 0);

    exportarUsuario(lstUsuario, nUsuario);
    exportarLivro(lstLivro, nLivro);
    exportarListaLivrosUsuario(lstUsuario, nUsuario, lstLivro, nLivro);

    return (0);
}