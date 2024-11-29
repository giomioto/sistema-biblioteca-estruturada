#include "Livro.h"
#include "Usuario.h"
#include "Geral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

rgLivro Livro(int codigo, char titulo[], char autor[], int ano, char sit){
    rgLivro livro;
    livro.codigo = codigo;
    strcpy(livro.titulo, titulo);
    strcpy(livro.autor, autor);
    livro.ano = ano;
    livro.idUsuario = -1;
    livro.sit = sit;
    return livro;
}

char getSitLivro(rgLivro *livro){
    return livro->sit;
}
void setSitLivro(rgLivro *livro, char sit){
    livro->sit = sit;
}

char getTituloLivro(rgLivro *livro){
    return *livro->titulo;
}
void setTituloLivro(rgLivro *livro, char titulo[]){
    strcpy(livro->titulo, titulo);
}

char getAutorLivro(rgLivro *livro){
    return *livro->autor;
}
void setAutorLivro(rgLivro *livro, char autor[]){
    strcpy(livro->autor, autor);
}

int getAnoLivro(rgLivro *livro){
    return livro->ano;
}
void setAnoLivro(rgLivro *livro, int ano){
    livro->ano = ano;
}
int getIdUsuarioLivro(rgLivro *livro){
    return livro->idUsuario;
}
void setIdUsuarioLivro(rgLivro *livro, int idUsuario){
    livro->idUsuario = idUsuario;
}

int acharLivro(rgLivro lstLivro[], int nLivro, int codigo){
    for (int i = 0; i < nLivro; i++){
        if (lstLivro[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}
char *toStringLivro(rgLivro *livro){
    char *str = (char *) malloc(150 * sizeof(char));
    sprintf(str, "Código: %d\nTítulo: %s\nAutor: %s\nAno: %d\nSituação: %c\nID Usuário: %d\n", livro->codigo, livro->titulo, livro->autor, livro->ano, livro->sit, livro->idUsuario);
    return str;
}

