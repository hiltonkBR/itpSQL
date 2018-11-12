#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void writeFile(char *tableName, char *itemTable, char *operation)
{
  
  FILE *arq, *allTables;


  arq = fopen(tableName, operation);

  fprintf(arq, " %s ", itemTable);

  fclose(arq);
}


int criarTabela(){
        int qtd_colunas, n, qtd_lines; 
        char ***tabela, nomeTabela[100], nomeEstruT[100], nomeDadosT[100];
        FILE *estruTabela, *dadosTabela, *todasTabelas;

        tabela = (char***) malloc(50 * sizeof(char **));

        printf("Digite o nome da tabela:\n");
        scanf("%s", nomeTabela);
	
        todasTabelas = fopen("todasTabelas.txt", "a+");
        fprintf(todasTabelas, "%s\n", nomeTabela);
        fclose(todasTabelas);
	
	strcpy(nomeEstruT, nomeTabela);
	strcpy(nomeDadosT, nomeTabela);
		
	strcat(nomeEstruT, "ESTRU");
	strcat(nomeDadosT, "DADOS");
	estruTabela = fopen(nomeEstruT, "a+");
	dadosTabela = fopen(nomeDadosT, "w");
	
	fprintf(estruTabela, "%s\n", nomeTabela);
	fprintf(dadosTabela, "%s\n", nomeTabela);
        //fclose(estruTabela);
        fclose(dadosTabela);


	printf("Digite a quantidade de colunas:\n");
	scanf("%d", &qtd_colunas);
	n = qtd_colunas;
	int i = 0;
	char tipo[100], nomeCOL[100], insertCOL[100];


	for (int j = 1; j < qtd_colunas + 1; j++){
		
		if(j == 1){   
			printf("Digite o nome de sua chave primaria %d : ", j);
                        scanf("%s", nomeCOL); //Esse seria o array das variaveis
                        //printf("1 - Int / 2 - Double / 3 - Float / 4 - String\n");
                        //printf("Digite o tipo de variavel da coluna [%d] :", j);
                        //scanf("%s", tipo); //Esse seria o array das variaveis	
			strcpy(tipo, "1");
		}else{
			printf("Digite o nome da coluna %d : ", j);		
			scanf("%s", nomeCOL); //Esse seria o array das variaveis
			printf("1 - Int / 2 - Double / 3 - Float / 4 - String\n");
			printf("Digite o tipo de variavel da coluna [%d] :", j);
			scanf("%s", tipo); //Esse seria o array das variaveis
		}
		strcat(tipo, " | ");
		strcat(tipo, nomeCOL);
		fprintf(estruTabela, "%s\n", tipo);
	
	i++;
	}
	fclose(estruTabela);	

}


void menu()
{
    printf("---------------- itpSQL ----------------\n");
    printf("--------- ITP/PTP 2018.2 N12 -----------\n");
    printf("     Feito por Hilton & Hasler\n");
    printf("\n");

    int option;
    printf("selecione uma opção:\n1. Criar uma Tabela\n2. Listar tabelas\n3. Inserir registros em uma tabela\n4. Mostrar dados de uma tabela\n5. Pesquisar em uma tabela\n6. Apagar valor de uma Tabela\n7. Apagar uma Tabela\n" );

    while (option <  9) {
      scanf("%d", &option);

      switch (option)
      {
        case 1:
          criarTabela();
          printf ("\n");
        break;

        case 2 :
          //insertItensAfterFile();
          printf ("\n");
        break;

        case 3 :
          //showAllTables();
          printf ("\n");
        break;

        case 4 :
          //showTables();
          printf ("\n");
        break;

        case 5 :
          //search();
          printf ("\n");
        break;

        case 6 :
          //deleteItemTable();
          printf ("\n");
        break;

        case 7:
          //deleteTable();
          printf ("\n");
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }

    printf("Encerrando programa!\n");
}
