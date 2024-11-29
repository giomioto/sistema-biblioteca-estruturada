#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  char titulo[100];
  char autor[100];
  int ano;
  int idUsuario;
  char sit; // * - Excluído, X - Ativo
} rgLivro;

rgLivro Livro(int codigo, char titulo[], char autor[], int ano, char sit);

char getSitLivro(rgLivro *livro);
void setSitLivro(rgLivro *livro, char sit);

int getIdUsuarioLivro(rgLivro *livro);
void setIdUsuarioLivro(rgLivro *livro, int idUsuario);

char getTituloLivro(rgLivro *livro);
void setTituloLivro(rgLivro *livro, char titulo[]);

char getAutorLivro(rgLivro *livro);
void setAutorLivro(rgLivro *livro, char autor[]);

int getAnoLivro(rgLivro *livro);
void setAnoLivro(rgLivro *livro, int ano);

int acharLivro(rgLivro lstLivro[], int nLivro, int codigo);
char *toStringLivro(rgLivro *livro);

#endif // LIVRO_H_INCLUDED

