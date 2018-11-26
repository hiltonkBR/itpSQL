#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tes;

struct Tipo{
    	char tipoColuna[200];
	char nomeColuna[200];
};
struct Chave{
	char id[200];
};


int checaNome(char nomeCheca[200]){
        char str[200];
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




int checaChave(char chaveID[200], char nomeTabela[200]){
        char str[200], aux[200];
        int contador=0, i;
        char * linha;
        FILE *fp;
        fp = fopen(nomeTabela, "r");
        if(fp != NULL){
                while   (fscanf(fp, "%s", aux) != EOF){
                        contador++;
                }
                fseek(fp, 0, SEEK_SET);
                struct Chave chave[contador];
                for(i=0;i<contador;i++){
                        strcpy(chave[i].id, " ");
                        linha = malloc( sizeof(char) * 100 );
                        fscanf(fp,"%s\n", linha);
                        char * linha_token = strtok( linha, "|");
                        strcpy(chave[i].id, linha_token);
                        free(linha);
                        if(strcmp(chave[i].id,chaveID)==0){
                                fclose(fp);
                                return 1;
                        }else{

                        }
                  }fclose(fp);
                        return 0;

        }else{

        return 10;
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
	
	//fprintf(estruTabela, "%s\n", nomeTabela);
	//fprintf(dadosTabela, "%s\n", nomeTabela);
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
		strcat(nomeCOL, "|");
		strcat(nomeCOL, tipo);
		fprintf(estruTabela, "%s\n", nomeCOL);
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



void inseriRegistro(){
	FILE *todasTabelas;
	FILE *estruTabela;
	FILE *dadosTabela;
	char nomeTabela[300], nomeEstruT[200], nomeDadosT[200];
	int conta =0, conta2=0, contador=0, i, c=0;
	char aux[200];	
	const char s[2] ="\n";
	char * linha;	
	system("clear");
	
	while (conta < 1){
                printf("Digite o nome da tabela onde será inserido o registro:\n");
                scanf("%s", nomeTabela);

                if(checaNome(nomeTabela) == 0){
                        printf("------------------------------------------------------------\n");
                        printf("-- A tabela '%s' não existe --\n", nomeTabela);
                        printf("------------------------------------------------------------\n");
                }else{
                        conta++;
                }

        }
	
	strcpy(nomeEstruT, nomeTabela);
	strcpy(nomeDadosT, nomeTabela);
	strcat(nomeEstruT, "ESTRU");
        strcat(nomeDadosT, "DADOS");
	
	estruTabela = fopen(nomeEstruT, "r");
        dadosTabela = fopen(nomeDadosT, "a+");
	
	if(estruTabela != NULL && dadosTabela != NULL){

		while (fscanf(estruTabela, "%s", aux) != EOF) {
			contador++;
		}
		fseek(estruTabela, 0, SEEK_SET );
		struct Tipo tipo[contador];
		//printf("%i\n", contador);

		for(i=0;i<contador;i++){
            		strcpy( tipo[i].tipoColuna, " " );
            		linha = malloc( sizeof(char) * 100 );
            		fscanf( estruTabela, "%s\n", linha);
            		char * linha_tokenizada = strtok( linha, "|" );
			strcpy( tipo[i].nomeColuna, linha_tokenizada );
            		linha_tokenizada = strtok( NULL, "|" );
            		strcpy( tipo[i].tipoColuna, linha_tokenizada );
            	//	printf("%s ",tipo[i].tipoColuna);
            	//	printf("%s\n",tipo[i].nomeColuna);
            		free(linha);
        	}


		for(i=0;i<contador;i++){
            		linha = malloc( sizeof(char) * 100 );
            		if (strcmp(tipo[i].tipoColuna, "1")==0){

				if(c == 0){	
					while (conta2 < 1){
                				printf("Digite o valor da coluna '%s' do tipo INT!\n", tipo[i].nomeColuna);
                				scanf("%s", linha);
						if(checaChave(linha,nomeDadosT) == 1){
                        				printf("-------------------------------------------------------------------\n");
                       	 				printf("-- Já existe uma registro com a chave '%s' por favor tente outra --\n", linha);
                        				printf("-------------------------------------------------------------------\n");
                				}else{
                        				conta2++;
                				}

        				}
					c++;
				}else{
                		printf("Digite o valor da coluna '%s' do tipo INT!\n", tipo[i].nomeColuna);
                		scanf("%s", linha);
				}
	
				if (i == contador-1){
					fprintf(dadosTabela, "%s", linha);
				}else{	
					fprintf(dadosTabela, "%s|", linha);
				}
            		}
            		if (strcmp(tipo[i].tipoColuna, "2")==0){
                		printf("Digite o valor da coluna '%s' do tipo DOUBLE!\n", tipo[i].nomeColuna);
                		scanf("%s", linha);
            			if (i == contador-1){
                                        fprintf(dadosTabela, "%s", linha);
                                }else{
                                        fprintf(dadosTabela, "%s|", linha);
                                }
			}
            		if (strcmp(tipo[i].tipoColuna, "3")==0){
                		printf("Digite o valor da coluna '%s' do tipo FLOAT!\n", tipo[i].nomeColuna);
                		scanf("%s", linha);
				if (i == contador-1){
                                        fprintf(dadosTabela, "%s", linha);
                                }else{
                                        fprintf(dadosTabela, "%s|", linha);
                                }
            		}
            		if (strcmp(tipo[i].tipoColuna, "4")==0){
                		printf("Digite o valor da coluna '%s' do tipo STRING!\n", tipo[i].nomeColuna);
                		scanf("%s", linha);
				if (i == contador-1){
                                        fprintf(dadosTabela, "%s", linha);
                                }else{
                                        fprintf(dadosTabela, "%s|", linha);
                                }
            		}
            		if (i == contador-1){
                		fprintf(dadosTabela, "\n");
            		}
            		free(linha);
        	} 
		
	}
		

	
	fclose(dadosTabela);
	fclose(estruTabela);
	tes =11;	
	
}



void menu(){
system("clear");
	if(tes ==10){
 		printf("----------------------------------------\n");
 		printf("----- Tabela inserida com sucesso ------\n");
 		printf("----------------------------------------\n\n");
	}
	if(tes ==11){
                printf("-----------------------------------------\n");
                printf("----- Registro inserido com sucesso ------\n");
                printf("-----------------------------------------\n\n");
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
          inseriRegistro();
          printf ("\n");
	  system("clear");
 	  menu();
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
