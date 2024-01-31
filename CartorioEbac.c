#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca responsável pela alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

char direitos[60] = "Esse software é de direitos de Marchete informática LTDA\n\n";

int registra(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	//r - open a file in read mode
	//w - opens or create a text file in write mode
	//a - opens a file in append mode
	//r+ - opens a file in both read and write mode
	//a+ - opens a file in both read and write mode
	//w+ - opens a file in both read and write mode
	
	FILE *file; //Chamando a função FILE para criar um arquivo (file)
	file = fopen(arquivo, "w"); //"fopen" abre o arquivo com o nome da variável "arquivo" e usando o argumento w para criar ele
	fprintf(file,cpf); //salvando o valor da variável
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo e usa o argumento "a" para atualizar informações dentro dele
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo e usa o argumento "a" para atualizar informações dentro dele
	fprintf(file,nome);
	fclose(file);	
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo e usa o argumento "a" para atualizar informações dentro dele
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo e usa o argumento "a" para atualizar informações dentro dele
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");		

}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //Setando local para português	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta(){
	char cpf[40];
	char conteudo[200];
	char confirma[3];
	
	setlocale(LC_ALL, "Portuguese"); //Setando local para português	
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL){
		printf("O CPF digitado não está cadastrado em nossa base de dados");
	}
	
	while(fgets(conteudo,200,file)!=NULL){
		printf("\nO CPF informado contem essas informações: ");
		printf("%s", conteudo);
		printf("\n\nConfirma a exclusão da base de dados?\nDigite S para confirmar e N para cancelar.");
		printf("\nResposta: ");
		scanf("%s",confirma);
	}

		if(strcmp(confirma,"S")==0){
			printf("Cadastro removido com sucesso!\n");
			fclose(file);
			remove(cpf);
		}
		else if(strcmp(confirma,"N")==0){
			printf("Ação cancelada!");
		}
		else{
			printf("Você escolheu uma opção inválida, tente novamente\n");
		}
		system("pause");

	
	
}

int invalida(){
	printf("Você escolheu uma opção inválida, tente novamente\n");
	system("pause");
}

int main(){
	
	
	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;){
		
		system("cls");
			
		setlocale(LC_ALL, "Portuguese"); //Setando local para português
	
		printf(direitos); //chama a string direitos definida anteriormente
		printf("\t-----------------\n");
		printf("\t|Cartório da EBAC|\n");
		printf("\t-----------------\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n");
		printf("Opção: ");	
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao){
			case 1:
				registra();
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deleta();
				break;
				
			case 4:
				abort();
			
			default:
				invalida();
				break;
				
		}
	
			
	}
	
}
