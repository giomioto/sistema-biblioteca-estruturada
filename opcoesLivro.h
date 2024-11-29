#ifndef OPCOESLIVRO_H_INCLUDED
#define OPCOESLIVRO_H_INCLUDED

#include "Livro.h"
#include "Usuario.h"

void entradaLivro(rgLivro *lstLivro, int *nLivro);

void excluirLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario);
void listarLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario);

void emprestarLivro(rgLivro *lstLivro, int nLivro, rgUsuario *lstUsuario, int nUsuario);

void importarLivros(rgLivro *lstLivro, int *nLivro, rgUsuario *lstUsuario, int nUsuario);
void exportarLivro(rgLivro *lstLivro, int nLivro);

#endif
