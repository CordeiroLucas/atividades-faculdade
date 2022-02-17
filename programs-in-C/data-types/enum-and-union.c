#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definição da união, podendo receber qualquer um dos 4 tipos declarados*/
union exUniao {
	int inteiro;
	float flutuante;
	char caracter;
	char string[15];
};

/*Definição do tipo enumerado weekDays (dias da semana)*/
enum weekDays { null, Seg, Ter, Qua, Qui, Sex, Sab, Dom };

/*Definição da estrutura dados*/
struct dados {
	int idade;
	char nome[10];
	float altura;
};

int main(void) 
{
	/*Declaração da estrutura de dados pessoa1*/	
	struct dados *pessoa1;
	pessoa1 = (struct dados*) malloc(sizeof(struct dados));

	strcpy(pessoa1->nome, "lucas");
	pessoa1->idade = 19;
	pessoa1->altura = 1.73;

	/*Declaração da união*/
	union exUniao uniao;

	uniao.inteiro = 20;
	strcpy(uniao.string, "bondia");	
	uniao.flutuante = 23.4;
	uniao.caracter = 'o';


	/*Declaração de dia do tipo enumerado weekDays*/
	enum weekDays dia;
	/*1 a 7*/
	dia = 7;

	printf("\nPessoa\n\nNome: %s\nIdade: %d\nAltura: %.2f\n", pessoa1->nome, pessoa1->idade, pessoa1->altura);
	
	printf("\nUnions\n\nInt %d\nFloat %.2f\nChar %c\nString %s\n", uniao.inteiro, uniao.flutuante, uniao.caracter, uniao.string);


	printf("\nEnum int = %d\n", dia);

	if (dia == null)
		printf("\ninválido!\n");
	else if (dia == Seg)
		printf("\nSegunda-Feira\n");
	else if (dia == Ter)
		printf ("\nTerça-Feira\n");
	else if (dia == Qua)
		printf("\nQuarta-Feira\n");
	else if (dia == Qui)
		printf("\nQuinta-Feira\n");
	else if (dia == Sex)
		printf("\nSexta-Feira\n");
	else if (dia == Sab)
		printf("\nSábado\n");
	else if (dia == Dom)
		printf("\nDomingo\n");
	

	return 0;
}