#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registrar() {
	char arquivo[40];//come�o da cria��o de vari�veis com o char
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser registrado: \n\n");
	scanf("%s", cpf);//%s refere-se a string e o scanf scaneia ela

	strcpy(arquivo, cpf);//respons�vel por copiar o valor das strings

	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo com o "w"
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo

	file = fopen(arquivo, "a");// atualiza o arquivo com o "a"
	fprintf(file, ", Nome:");
	fclose(file);

	printf("\nDigite o nome a ser registrado: \n\n");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", Sobrenome:");
	fclose(file);

	printf("\n Digite o sobrenome a ser registrado: \n\n");
	scanf("%s", sobrenome);

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", Cargo:");
	fclose(file);

	printf("\n Digite o cargo a ser registrado: \n\n");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	system("pause");
}

int consultar() {

	setlocale(LC_ALL, "Portuguese");//define a linguagem

	char cpf[40];
	char conteudo[100];

	printf("Digite o CPF a ser consultado: ");//come�o da consulta
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");//o "r" l� o arquivo

	if(file == NULL) {
		printf("\nN�o foi possivel encontrar o cpf.");
	}

	while(fgets(conteudo, 100, file) != NULL)//fgets busca o conte�do

		printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");

}

int deletar() {

	char cpf[40];

	printf("Digite o usu�rio a ser deletado:");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL) {

		printf("\nUsu�rio n�o encontrado.\n\n");
		system("pause");
	}

	else {

		remove(cpf);//remove o arquivo
		printf("\nUsu�rio Deletado.\n\n");
		system("pause");

	}


}

int main()

{
	int opcao=0;  //definindo vari�veis
	int laco=1;

	for(laco=1; laco=1;) {

		system("cls");

		setlocale(LC_ALL, "Portuguese");//definindo linguagem

		printf("\tCart�rio da Loja do Gabriel \n\n");//come�o do menu
		printf("Escolha a op��o desejada \n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar cpf \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do cart�rio \n\n");
		printf("Op��o: ");//fim do menu

		scanf("%d",&opcao);

		system("cls");//limpar a tela quando escolher uma op��o

		switch(opcao) { //estrutura de decis�o
			case 1:
				registrar();//primeiro caso
				break;

			case 2:
				consultar();
				break;

			case 3:
				deletar();
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;

			default://ultimo caso
				printf("Op��o n�o existente\n");
				system("pause");
		}


	}
}



