#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>

#define MAXLIVROS 5

typedef struct {
  int id;
  char nome[100];
  char sexo;
  int idade;
  int cpf;
  int livrosEmprestados[MAXLIVROS];
  char sit; // * - Excluído, X - Ativo
} rgUsuario;

rgUsuario Usuario(int id, char nome[], char sexo, int idade, int cpf, char sit);

char getSitUsuario(rgUsuario *usuario);
void setSitUsuario(rgUsuario *usuario, char sit);

int getIdUsuario(rgUsuario *usuario);
void setIdUsuario(rgUsuario *usuario, int id);

int *getLivrosEmprestadosUsuario(rgUsuario *usuario);
void setLivrosEmprestadosUsuario(rgUsuario *usuario, int idLivro);

void excluirLivroUsuario(rgUsuario *usuario, int idLivro);

int acharUsuario(rgUsuario lstUsuario[], int nUsuario, int id);

char *toSringUsuario(rgUsuario *usuario);

#endif // USUARIO_H