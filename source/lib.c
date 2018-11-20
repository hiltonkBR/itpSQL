#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tes;

int checaNome(char nomeCheca[200]){
        char str[100];
        FILE *fp;
        fp = fopen("todasTabelas.txt","a+");
        //nomeCheca[strlen(nomeCheca)-1]=nomeCheca[strlen(nomeCheca)];
        while (fscanf(fp, "%s",str)!=EOF){
                if (strcmp(str,nomeCheca)==0){
                        //printf("String existe!\n");
                        fclose(fp);
                        return 1;
                }else{
                        fclose(fp);
                        return 0;
                }

        }
}


int criarTabela(){
	system("clear");
        int qtd_colunas, n;
	int conta = 0; 
        char ***tabela, nomeTabela[200], nomeEstruT[200], nomeDadosT[200];
        FILE *estruTabela, *dadosTabela, *todasTabelas;

        tabela = (char***) malloc(50 * sizeof(char **));
	
	while (conta < 1){
        	printf("Digite o nome da tabela:\n");
        	scanf("%s", nomeTabela);
		
		if(checaNome(nomeTabela) == 1){
			printf("--------------------------------------------------\n");
                	printf("-- Tabela já existe tente com um nome diferente --\n");
			printf("--------------------------------------------------\n");
        	}else{
			conta++;
		}
		
	}

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
        fclose(dadosTabela);


	printf("Digite a quantidade de colunas:\n");
	scanf("%d", &qtd_colunas);
	n = qtd_colunas;
	char tipo[100], nomeCOL[100], insertCOL[100];


	for (int j = 1; j < qtd_colunas + 1; j++){
		
		if(j == 1){   
			printf("Digite o nome de sua chave primaria: ");
                        scanf("%s", nomeCOL); 
			strcpy(tipo, "1");
		}else{
			printf("Digite o nome da coluna %d : ", j);		
			scanf("%s", nomeCOL); 
			printf("1 - Int / 2 - Double / 3 - Float / 4 - String\n");
			printf("Digite o tipo de variavel da coluna [%d] :", j);
			scanf("%s", tipo); 
		}
		strcat(tipo, " | ");
		strcat(tipo, nomeCOL);
		fprintf(estruTabela, "%s\n", tipo);
	}
	fclose(estruTabela);
	tes= 10;	
}

void listarTabelas(){
  	
	FILE *arq;
  	char table[200];
	system("clear");
	
  	arq = fopen("todasTabelas.txt", "r");
  	printf("\nTabelas:\n");

  	while (fscanf(arq, " %s", table) != EOF) {
  		printf("%s\n", table);
  	}
	printf("\nPressione enter para retornar ao MENU");
	getchar(); // This will store the enter key
    	getchar();  
}


void menu(){
system("clear");
	if(tes ==10){
 		printf("----------------------------------------\n");
 		printf("----- Tabela inserida com sucesso ------\n");
 		printf("----------------------------------------\n\n");
	}

    	printf("---------------- itpSQL ----------------\n");
    	printf("--------- ITP/PTP 2018.2 N12 -----------\n");
    	printf("     Feito por Hilton & Hasller\n");
    	printf("\n");
tes = 0 ;
    int option;
    printf("selecione uma opção:\n1. Criar uma Tabela\n2. Listar tabelas\n3. Inserir registros em uma tabela\n4. Mostrar dados de uma tabela\n5. Pesquisar em uma tabela\n6. Apagar valor de uma Tabela\n7. Apagar uma Tabela\n" );

    while (option <  9) {
      scanf("%d", &option);

      switch (option)
      {
        case 1:
        criarTabela();
        printf ("\n");
        system("clear");
        menu();
	break;

        case 2 :
          listarTabelas();
          printf ("\n");
	  system("clear");
          menu();
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
