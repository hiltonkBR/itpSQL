#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inteiro responsavel por controlar a mensagem de evento.
int tes;

//Struct utilizado para instanciar a estrutura da tabela.
struct Tipo{
    	char tipoColuna[200];
	char nomeColuna[200];
};
//Struct utilizado para instanciar as chaves primairas de uma tabela.
struct Chave{
	char id[200];
};
//Struct utilizado para instanciar os dados de uma tabela.
struct Dados{
	char data[200];
};

//função que checa se uma tabela já existe no arquivo todasTabelas.txt
int checaNome(char nomeCheca[200]){
        char str[200];
        FILE *fp;
	//foi utilizado o a+ para caso o arquivo não existe ele crie no momento de fazer a checagem.
        fp = fopen("todasTabelas.txt","a+");
	//faz o laço até o fim do arquivo comparando com o strcmp o nome que o usuario entrou e foi entregue na função e as linhas do arquivo, se for = o returna 1, se for diferente retorna 1.
        while (fscanf(fp, "%s",str)!=EOF){
                if (strcmp(str,nomeCheca)==0){
                        fclose(fp);
                        return 1;
                }else{
                        fclose(fp);
                        return 0;
                }

        }
}

//Função que checa se uma chave primaria já existe.
int checaChave(char chaveID[200], char nomeTabela[200]){
        char str[200], aux[200];
        int contador=0, i;
        char * linha;
        FILE *fp;
        fp = fopen(nomeTabela, "r");
        if(fp != NULL){
		//conta quantas linhas tem no arquivo.
                while   (fscanf(fp, "%s", aux) != EOF){
                        contador++;
                }
                fseek(fp, 0, SEEK_SET);
                struct Chave chave[contador];
		//o laço percorre todas as linhas dos dados da tabela, quebra a primeira coluna, que sempre é a chave primaria, com o strtok indicando o token divisor e dentro do laço faço a comparação se a chave que o usuario digitou já existe na tabela.
                for(i=0;i<contador;i++){
                        strcpy(chave[i].id, " ");
                        linha = malloc( sizeof(char) * 100 );
                        fscanf(fp,"%s\n", linha);
                        char * linha_token = strtok( linha, "|");
                        strcpy(chave[i].id, linha_token);
                        free(linha);
                        if(strcmp(chave[i].id,chaveID)==0){
                                fclose(fp);
				//se já existir ele retorna 1, se não retorna 0
                                return 1;
                        }else{

                        }
                  }fclose(fp);
                        return 0;

        }else{
	//se houver erro ao abrir o arquivo ele retorna erro.
        return 10;
        }
}


//função que cira a tabela
int criarTabela(){
	system("clear");
        int qtd_colunas, n;
	int conta = 0; 
        char ***tabela, nomeTabela[200], nomeEstruT[200], nomeDadosT[200];
        FILE *estruTabela, *dadosTabela, *todasTabelas;

        tabela = (char***) malloc(50 * sizeof(char **));
	//Laço que chama a função que checa se uma tabela já existe, ele só incrementa e sai do laço se o usuaruio digitar um nome de tabela que não existe no arquivo.
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

//função que lista as tabelas existentes
void listarTabelas(){	
	FILE *arq;
  	char table[200];
	system("clear");
	
  	arq = fopen("todasTabelas.txt", "r");
  	printf("\nTabelas:\n");
	
	//laço que percorre toodo o arquivo onde é salvo o nome das tabelas e sai printando todas as linhas. 
  	while (fscanf(arq, " %s", table) != EOF) {
  		printf("%s\n", table);
  	}
	printf("\nPressione enter para retornar ao MENU");
	getchar();
    	getchar();  
}


//função que inseri um registro em uma tabela.
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
	//laço que chama a função que verifica se já existe uma tabela com esse nome.
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
		//laço que joga par o struct tipo, o tipo da coluna lendo o arquivo de estrutura da tabela e para cada coluna salvando o tipo do dado e o nome da coluna. 	
		for(i=0;i<contador;i++){
            		strcpy( tipo[i].tipoColuna, " " );
            		linha = malloc( sizeof(char) * 100 );
            		fscanf( estruTabela, "%s\n", linha);
            		char * linha_tokenizada = strtok( linha, "|" );
			strcpy( tipo[i].nomeColuna, linha_tokenizada );
            		linha_tokenizada = strtok( NULL, "|" );
            		strcpy( tipo[i].tipoColuna, linha_tokenizada );
            		free(linha);
        	}

		//laço que baseado na quantidade de colunas da tabela começa a requisitar os dados conforme a estrutura, trazendo a esturutra da tabela via struct.
		for(i=0;i<contador;i++){
            		linha = malloc( sizeof(char) * 100 );
			//if que faz a requisição dos dados baseado no tipo de coluna da tabela.
            		if (strcmp(tipo[i].tipoColuna, "1")==0){
				//esse contados serve para para que o laço onde é feito o teste se é chave primaria rode apenas na primeira coluna do tipo inteiro que existir, para não fazer checagem que outras colunas do tipo inteiro que venha a ser inseridas.
				if(c == 0){	
					//laço que verifica se já existe um valor de chave primaria na tabela onde os dados estão sendo inseridos.
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
                		scanf(" %[^\n]%*c", linha);
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

//função que exibe os dados de uma tabela.
void mostrarDados(){
	FILE *estruTabela;
        FILE *dadosTabela;
        char nomeTabela[300], nomeEstruT[200], nomeDadosT[200], aux[200], aux2[200];
        int conta =0, contador=0, contador2=0, i, ii, t;
        char * linha;
        char * linha2;
	const char s ='|';
	system("clear");
	//contador que chama o teste para verificar se a tabela existe.
	while (conta < 1){
                printf("Digite o nome da tabela que deseja exibir os registro:\n");
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
        dadosTabela = fopen(nomeDadosT, "r");
	
	//contador para pegar a quantidade de colunas da tabela
	while (fscanf(estruTabela, "%s", aux) != EOF) {
		contador++;
	}
	fseek(estruTabela, 0, SEEK_SET );
	struct Tipo tipo[contador];
	// laço que regasta e formata a exibição das colunas da tabela inserida pelo usuario.
	for(i=0;i<contador;i++){
		strcpy( tipo[i].tipoColuna, " " );
		linha = malloc( sizeof(char) * 100 * contador );
		fscanf( estruTabela, "%s\n", linha);
		char * linha_tokenizada = strtok( linha, "|" );
		strcpy( tipo[i].nomeColuna, linha_tokenizada );
		linha_tokenizada = strtok( NULL, "|" );
		strcpy( tipo[i].tipoColuna, linha_tokenizada );
		if (i == contador-1){
			printf("%s\n",tipo[i].nomeColuna);
               	}else{
			printf("%s\t || ",tipo[i].nomeColuna);
                }
                free(linha);
	}
	//contador para a quantidade de registros na tabela
	while(fscanf(dadosTabela, "%[^\n]%*c", aux2) != EOF){
		contador2++;
	}
	fseek(dadosTabela, 0, SEEK_SET );
	struct Dados dados[contador2];
	
	//laço que regasgata e formata os dados da tabela para exibição ao usuario.	
	for(i=0;i<contador2;i++){
		strcpy( dados[i].data, " ");
		linha2 = malloc( sizeof(char) * 400 * contador2 );
		fscanf( dadosTabela, "%[^\n]%*c\n", linha2);
		char * linha_token2 = strtok( linha2, "|" );
		for(t=0;t<contador;t++){
			strcpy( dados[i].data, linha_token2);
			if (t == contador-1){
				printf("%s\t", dados[i].data);
			}else{
				printf("%s\t || ", dados[i].data);
			}
			linha_token2 = strtok( NULL, "|" );	
		}
		t=0;
		printf("\n");
		free(linha2);	
	}
	printf("\n\nPressione uma tecla para retornar ao menu\n");
	getchar();
	getchar();
	

}


//função que deleta a tabela.
void deletarTabela(){
	char nomeTabela[30], nomeExclu[100], auxTabela[200], tabela[200];
	char text[200], letra = '\n';
	int i, operadorLogico,status, linha=0,contadorLinhas=0, conta=0;
	FILE *nomeTabelas = fopen("todasTabelas.txt", "r");
    	if(nomeTabelas != NULL){
		fread (&text, sizeof(char), 200, nomeTabelas);
		for (int i = 0; i < strlen(text); i++){
			if(text[i] == letra){
				contadorLinhas++;
	 		}
        	}
                fseek(nomeTabelas, 0, SEEK_SET);
		//laço que chama a função que testa se a tabela existe.
		while (conta < 1){
                	printf("Digite o nome da tabela que deseja excluir:\n");
                	scanf("%s", nomeTabela);
                	if(checaNome(nomeTabela) == 0){
                        	printf("--------------------------------------------------\n");
                        	printf("-- Tabela não existe tente com um nome diferente --\n");
                        	printf("--------------------------------------------------\n");
                	}else{
                        	conta++;
                	}

        	}
		//cas a tabela exista ele remove os arquvios de dados e estrutura da tabela.
		strcpy(nomeExclu,"rm -rf ");
		strcat(nomeExclu,nomeTabela);
		strcat(nomeExclu,"*");
		system(nomeExclu);
		fclose(nomeTabelas);
                FILE *output = fopen("todasTabelas.txt", "r");
                FILE *input = fopen("copia.txt", "w+");
		//ele pega as linhas do arquivo onde é guardada o nome das tabelas e copia linha a linha para um arquivo auxiliar, pulando apenas na linha onde consta o nome da tabela que queremos remover, e depois copia os dados da tabela auxiliar para a tabela original ao final e depois excluir o arquivo auxiliar.
                if(output!=NULL && input!=NULL){
	                for(i=0;i<contadorLinhas;i++){
				fscanf(output,"%s\n", auxTabela);
				if(strcmp(auxTabela,nomeTabela)==0){
                                        //printf("%s foi pego\n",auxTabela);
				}else{
					fprintf(input,"%s\n",auxTabela);
                                        //printf("%s não foi pego\n",auxTabela);
					
				}
   			}
			fclose(output);
                        fclose(input);
                        FILE *output = fopen("copia.txt", "r");
                        FILE *input = fopen("todasTabelas.txt", "w");
                        while (fscanf(output, "%s", tabela) != EOF){
	                        fprintf(input,"%s\n",tabela);
        		}
                        fclose(output);
                        fclose(input);
			system("rm -rf copia.txt");
			tes =12;
		}else{
                	printf("errp\n");

             	}
	}else{
        	printf("Ocorreu um erro ao abrir o arquivo!\n");
        }
}

//função que carrega o menu.
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
	if(tes ==12){
                printf("-----------------------------------------\n");
                printf("----- Tabela apagado com sucesso ------\n");
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
          mostrarDados();
          printf ("\n");
	  system("clear");
	  menu();
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
          deletarTabela();
          printf ("\n");
	  system("clear");
	  menu();
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }

    printf("Encerrando programa!\n");
}
