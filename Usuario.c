#include "Usuario.h"
#include "Geral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

rgUsuario Usuario(int id, char nome[], char sexo, int idade, int cpf, char sit){
    rgUsuario usuario;
    usuario.id = id;
    strcpy(usuario.nome, nome);
    usuario.sexo = sexo;
    usuario.idade = idade;
    usuario.cpf = cpf;
    for (int i = 0; i < MAXLIVROS; i++){
        usuario.livrosEmprestados[i] = 0;
    }
    usuario.sit = sit;
    return usuario;
}

char getSitUsuario(rgUsuario *usuario){
    return usuario->sit;
}
void setSitUsuario(rgUsuario *usuario, char sit){
    usuario->sit = sit;
}

int getIdUsuario(rgUsuario *usuario){
    return usuario->id;
}
void setIdUsuario(rgUsuario *usuario, int id){
    usuario->id = id;
}

int *getLivrosEmprestadosUsuario(rgUsuario *usuario){
    return usuario->livrosEmprestados;
}
void setLivrosEmprestadosUsuario(rgUsuario *usuario, int idLivro){
    int flag = 0;
    for (int i = 0; i < MAXLIVROS; i++){
        if (usuario->livrosEmprestados[i] == 0){
            usuario->livrosEmprestados[i] = idLivro;
            flag = 1;
            printf("<<<< Confirmado >>>>\n\n\n");
            break;
        }
        else if (usuario->livrosEmprestados[i] == idLivro){
            printf("Livro já emprestado!");
            break;
        }
    }
    if(flag == 0){
        printf("Usuário já atingiu o limite de livros emprestados!\n\n\n");
    }
}

void excluirLivroUsuario(rgUsuario *usuario, int idLivro){
    for (int i = 0; i < MAXLIVROS; i++){
        if (usuario->livrosEmprestados[i] == idLivro){
            usuario->livrosEmprestados[i] = -1;
            break;
        }
    }
}

int acharUsuario(rgUsuario lstUsuario[], int nUsuario, int id){
    for (int i = 0; i < nUsuario; i++){
        if (lstUsuario[i].id == id){
            return i;
        }
    }
    return -1;
}

char *toSringUsuario(rgUsuario *usuario){
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "ID: %d\nNome: %s\nSexo: %c\nIdade: %d\nCPF: %d\nSituação: %c\n", usuario->id, usuario->nome, usuario->sexo, usuario->idade, usuario->cpf, usuario->sit);
    return str;
}
