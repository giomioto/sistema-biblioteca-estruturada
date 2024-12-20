#include "OpcoesUsuario.h"
#include "Livro.h"
#include "Usuario.h"
#include "Geral.h"
#include <ctype.h>

void entradaUsuario(rgUsuario *lstUsuario, int *nUsuario)
{
    rgUsuario usuario;
    int idUsuario;
    char *nome = (char *)malloc(100 * sizeof(char));
    char *sexo = (char *)malloc(1 * sizeof(char));
    int idade;
    int cpf;
    
    while (1)
    {
        cls();
        printf("<<<<< CADASTRAR USUARIOS >>>>>\n\n");
        printf("Identificacao (0 para encerrar): ");
        scanf("%d", &idUsuario);
        if (idUsuario == 0)
            break;
        if (acharUsuario(lstUsuario, *nUsuario, idUsuario) != -1)
        {
            printf("Identificação já cadastrada!\n\n");
            pause();
            continue;
        }

        printf("\nNome do Usuario.........: ");
        scanf(" %[^\n]s", nome);

        do {
        printf("Sexo do Usuario (M/F)....: ");
        scanf(" %c", sexo);
        esvaziar();
        *sexo = toupper(*sexo);
        } while (*sexo != 'M' && *sexo != 'F');

        printf("Idade do Usuario.......: ");
        scanf("%d", &idade);

        printf("CPF do Usuario.......: ");
        scanf("%d", &cpf);

        if (confirmou("Confirma o cadastro? (S/*): "))
        {
            usuario = Usuario(idUsuario, nome, *sexo, idade, cpf, 'X');
            lstUsuario[*nUsuario] = usuario;
            *nUsuario = *nUsuario + 1;
            printf("<<<< Confirmado >>>>\n\n\n");
        }
        else
        {
            printf("<<<< Não Confirmado >>>>\n\n\n\n");
        }

        esvaziar(); // esvazia o buffer de entrada de dados
        pause();
    }
    free(nome);
    free(sexo);
}
void excluirUsuario(rgUsuario *lstUsuario, int nUsuario, rgLivro *lstLivro, int nLivro)
{
    int idUsuario;
    int posicao;
    cls();
    printf("<<<<< EXCLUIR USUARIOS >>>>>\n\n");
    printf("Identificacao do Usuario (0 para encerrar): ");
    scanf("%d", &idUsuario);
    if (idUsuario == 0)
    {
        return;
    }
    posicao = acharUsuario(lstUsuario, nUsuario, idUsuario);
    if (posicao == -1)
    {
        printf("Usuario não encontrado!\n\n");
    }
    else
    {
        if (confirmou("Confirma a exclusão? (S/*): "))
        {
            printf("Id do usuario: %d | Posicao: %d | Nome: %s\n", idUsuario, posicao, lstUsuario[posicao].nome);
            setSitUsuario(&lstUsuario[posicao], ' ');
            for(int i = 0; i < nLivro; i++)
            {
                if(getIdUsuarioLivro(&lstLivro[i]) == idUsuario)
                {
                    setIdUsuarioLivro(&lstLivro[i], -1);
                }
            }
            printf("<<<< Confirmado >>>>\n\n\n");
        }
        else
        {
            printf("<<<< Não Confirmado >>>>\n\n\n\n");
        }
    }
    pause();
}
void listarUsuario(rgUsuario *lstUsuario, int nUsuario, rgLivro *lstLivro, int nLivro)
{
    cls();
    int posicaoLivro;
    printf("<<<<< LISTAR USUARIOS >>>>>\n\n");
    for (int i = 0; i < nUsuario; i++)
    {
        if (getSitUsuario(&lstUsuario[i]) == 'X')  // Verifica se o usuário está ativo
        {
            printf("Identificacao: %d\n", lstUsuario[i].id);
            printf("Nome: %s\n", lstUsuario[i].nome);
            printf("Sexo: %c\n", lstUsuario[i].sexo);
            printf("Idade: %d\n", lstUsuario[i].idade);
            printf("CPF: %d\n", lstUsuario[i].cpf);
            printf("Livros emprestados: \n");
            
            // Verifica se o usuário tem livros emprestados
            int temLivrosEmprestados = 0;
            for(int j = 0; j < MAXLIVROS; j++)
            {
                if(lstUsuario[i].livrosEmprestados[j] != -1)  // Se o livro foi emprestado
                {
                    posicaoLivro = acharLivro(lstLivro, nLivro, lstUsuario[i].livrosEmprestados[j]);
                    if(posicaoLivro != -1)  // Verifica se o livro existe
                    {
                        printf("id: %d - Titulo: %s\n", lstLivro[posicaoLivro].codigo, lstLivro[posicaoLivro].titulo);
                        temLivrosEmprestados = 1;
                    }
                }
            }

            if(!temLivrosEmprestados)  // Se o usuário não tem livros emprestados
            {
                printf("Nenhum livro emprestado");
                printf("\n");
            }

            printf("Situação: %c\n\n", getSitUsuario(&lstUsuario[i]));
        }
    }
    pause();
}

void importarUsuarios(rgUsuario *usuarios, int *nUsuarios) {
    FILE *arq;
    arq = fopen("usuarios.txt", "r");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo pessoas.txt\n");
        return;
    }

    while (fscanf(arq, "%d;%99[^;];%c;%d;%d;%c\n", 
                &usuarios[*nUsuarios].id, 
                usuarios[*nUsuarios].nome, 
                &usuarios[*nUsuarios].sexo, 
                &usuarios[*nUsuarios].idade, 
                &usuarios[*nUsuarios].cpf, 
                &usuarios[*nUsuarios].sit) != EOF) {
        
        (*nUsuarios)++;
    }
    fclose(arq);
}

void exportarListaLivrosUsuario(rgUsuario *usuarios, int nUsuarios, rgLivro *livros, int nLivros) {
    FILE *arq;
    arq = fopen("listalivros.txt", "w");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo livros_usuario.txt\n");
        return;
    }

    for (int i = 0; i < nUsuarios; i++) {
        for (int j = 0; j < MAXLIVROS; j++) {
            if (usuarios[i].livrosEmprestados[j] != -1) {
                int posicaoLivro = acharLivro(livros, nLivros, usuarios[i].livrosEmprestados[j]);
                if (posicaoLivro != -1) {
                    fprintf(arq, "%d;%d;%s\n", 
                            usuarios[i].id, 
                            livros[posicaoLivro].codigo, 
                            livros[posicaoLivro].titulo);
                }
            }
        }
    }
    fclose(arq);
}

void exportarUsuario(rgUsuario *usuarios, int nUsuarios) {
    FILE *arq;
    arq = fopen("usuarios.txt", "w");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo pessoas.txt\n");
        return;
    }

    for (int i = 0; i < nUsuarios; i++) {
        fprintf(arq, "%d;%s;%c;%d;%d;%c\n", 
                usuarios[i].id, 
                usuarios[i].nome, 
                usuarios[i].sexo, 
                usuarios[i].idade, 
                usuarios[i].cpf, 
                usuarios[i].sit);
    }
    fclose(arq);
}