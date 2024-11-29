#ifndef OPCOESUSUARIO_H_INCLUDED
#define OPCOESUSUARIO_H_INCLUDED

#include "Livro.h"
#include "Usuario.h"

void entradaUsuario(rgUsuario *lstUsuario, int *nUsuario);

void excluirUsuario(rgUsuario *lstUsuario, int nUsuario, rgLivro *lstLivro, int nLivro);
void listarUsuario(rgUsuario *lstUsuario, int nUsuario, rgLivro *lstLivro, int nLivro);

void importarUsuarios(rgUsuario *lstUsuario, int *nUsuario);
void exportarUsuario(rgUsuario *lstUsuario, int nUsuario);

void exportarListaLivrosUsuario(rgUsuario *lstUsuario, int nUsuario, rgLivro *lstLivro, int nLivro);

#endif // OPCOESUSUARIO_H_INCLUDED
