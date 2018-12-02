O QUE FOI FEITO:
	- Função de inserir tabelas.
		+ Foi implementada função na inserção onde obrigatoriamente a primeira coluna deve ser uma chave primaria do tipo inteiro, que diferente das outras colunas o usuario não tem a opção de escolher o tipo de dado.
		+ Foi adicionada a funcionalidade exta que verifica se já existe uma tabela com o nome inserido pelo usuario.
	- Função de listar tabelas.
	- Função de criar uma nova linha em uma tabela.
		+ Foi adicionada a funcionalidade exta que verifica se existe uma tabela com o nome inserido pelo usuario para continuar com a inserção.
		+ Foi implementada a função que faz a chegem se já existe um registro com a chave primaria digitada pelo usuario.
	- Função de listar os dados de uma tabela. 
		+ Foi adicionada a funcionalidade exta que verifica se existe uma tabela com o nome inserido pelo usuario para continuar com a exibição.
	- Apagar uma tabela.	
		+ Foi adicionada a funcionalidade exta que verifica se existe uma tabela com o nome inserido pelo usuario para continuar com a exclusão.

O QUE NÃO FOI FEITO:
	- Apagar valor de uma tabela.
	- Pesquisar valor em uma tabela.


O QUE FARIA DIFERENTE:
	- Teria implementado uma função para fazer validação do tipo de dado inserido pelo usuario.

COMO COMPILAR:

	- O projeto foi desenvolvido no Linux sendo necessario os seguintes comandos para compilar:
		gcc -c main.c lib.c	
		gcc main.o lib.o -o itpSQL
	- E para execultar:
		./itpSQL

AUTORES:
	- HILTON KEVIN DE CARVALHO
	- HASLLER MATAUS RIBEIRO MEDEIROS

QUEM FEZ O QUE:
	- HASLLER
		- Função que checa o nome da tabela.
		- Função que chega se chave primaria já existe.
		- Função para listar a tabela.
		- Função para deletar a tabela.
		- Menu.
	HILTON:
		- Função que cria a tabela.
		- Função que inseri um resgistro na tabela.
		- Função que mostra os dados da tabela.
		- Mensagem de retorno das funções.

