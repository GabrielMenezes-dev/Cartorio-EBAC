#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registrar() {
	char arquivo[40];//começo da criação de variáveis com o char
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser registrado: \n\n");
	scanf("%s", cpf);//%s refere-se a string e o scanf scaneia ela

	strcpy(arquivo, cpf);//responsável por copiar o valor das strings

	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo com o "w"
	fprintf(file,cpf);//salva o valor da variável
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

	printf("Digite o CPF a ser consultado: ");//começo da consulta
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");//o "r" lê o arquivo

	if(file == NULL) {
		printf("\nNão foi possivel encontrar o cpf.");
	}

	while(fgets(conteudo, 100, file) != NULL)//fgets busca o conteúdo

		printf("\nEssas são as informações do usuário:\n\n");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");

}

int deletar() {

	char cpf[40];

	printf("Digite o usuário a ser deletado:");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL) {

		printf("\nUsuário não encontrado.\n\n");
		system("pause");
	}

	else {

		remove(cpf);//remove o arquivo
		printf("\nUsuário Deletado.\n\n");
		system("pause");

	}


}

int main()

{
	int opcao=0;  //definindo variáveis
	int laco=1;

	for(laco=1; laco=1;) {

		system("cls");

		setlocale(LC_ALL, "Portuguese");//definindo linguagem

		printf("\tCartório da Loja do Gabriel \n\n");//começo do menu
		printf("Escolha a opção desejada \n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar cpf \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do cartório \n\n");
		printf("Opção: ");//fim do menu

		scanf("%d",&opcao);

		system("cls");//limpar a tela quando escolher uma opção

		switch(opcao) { //estrutura de decisão
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
				printf("Opção não existente\n");
				system("pause");
		}


	}
}



