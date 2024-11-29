#include <stdio.h>
#include <stdlib.h>

void cls(void) {
  system("cls");
}

void pause(void) {
  system("PAUSE");
}

void esvaziar(void) {
  fflush(stdin); // esvazia o buffer de entrada de dados
}

void cabecalho(char *titulo, int *ctPag, int totPag, int *ctReg) {
  if (totPag == 0) {
     cls();
     printf("%s\n\n", titulo);
  }
  else {
    if (*ctPag != 0) {
        pause();
    }
    cls();
    *ctPag = *ctPag + 1;
    printf("%s Página %d de %d.\n\n", titulo, *ctPag, totPag);
    *ctReg = 0;
  }
}

int confirmou(char *titulo) {
  char cf;
  esvaziar();
  printf("\n%s", titulo);
  scanf("%c", &cf);
  if ((cf == 'S') || (cf == 's'))
     return(1);
  else return(0);
}
