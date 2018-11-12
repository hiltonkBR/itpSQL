#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char nome[20], str[100];
    FILE *fp;
    fp = fopen("file.txt","r");
    if (!fp)
       exit(1);
    printf("Introduza a string para pesquisa: ");
    fgets(nome,sizeof(nome),stdin); //lê uma string do teclado
    nome[strlen(nome)-1]=nome[strlen(nome)]; //retira o \n lido pelo fget
    while (fgets(str,sizeof(str),fp)!=NULL) //lê linha a linha do ficheiro
          if (strstr(str,nome)!=NULL) //Verifica se uma string existe dentro de outra
             printf("String existe!\n");
    fclose(fp);
    return 0;
}
