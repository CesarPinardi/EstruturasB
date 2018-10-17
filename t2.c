#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogos{
  int chave;
  char nome[20];
  char tipo[20];
  int ano;
}t_jogos;

// tentativa com vetores

// void inserir(t_jogos jogos[]){
  // int i;
  // int tamVet = sizeof(t_jogos)-1;
  // FILE *arq;
  // arq = fopen("dados.txt", "ab");

	// if(arq != NULL)
	// {
		// for(i = 0; i < tamVet; i++)
			// escreve cada elemento do vetor no arquivo
			// fwrite(&jogos[i], sizeof(t_jogos), 4, arq);
		// fclose(arq); // aborta o programa
	// }
	// else
	// {
		// printf("\nErro ao abrir o arquivo para leitura!\n");
		// exit(1); // aborta o programa
	// }
//
//
// }


int main(int argc, char const *argv[]) {

  int op, opImp, chave, chaveAux, anoAux;
  char nomeAux[20], tipoAux[20];
  chave = 0;
  char var[100];
  FILE *fp;
  int a,b;
  char c[100];
  char vet[100];

  printf("\n\n");
v:printf("\t\t Bem vindo.\n");
  printf("\n Selecione uma das opções abaixo:\n");
  printf("\n [1] Consultar um jogo;\n [2] Alterar/Atualizar um campo do jogo;\n [3] Excluir um jogo;\n [4] Inserir um jogo;\n [5] Imprimir jogos;\n [0] Sair.\n");
  printf("\n Opção: ");
  scanf("%d",  &op);
  do {
    switch (op) {
      case 1: //consulta
        printf("\n\n");
        printf("\t\t---Consulta---\n\n" );
        printf("Digite a chave: \n");
        // printf("Chave:");
        // scanf("%d", &chaveAux);
        printf("\n\n");
        goto v;

      case 2: //alterar
        printf("\n\n");
        printf("\t\t---Alteração---\n\n" );
        printf("Digite a chave: \n");
        // printf("Chave:");
        // scanf("%d", &chave);
        printf("\n\n");
        goto v;

      case 3: //excluir
        printf("\n\n");
        printf("\t\t---Exclusão---\n\n" );
        printf("\n\n");
        goto v;

      case 4: //inserir
        printf("\n\n");
        printf("\t\t---Inserção---\n\n" );

        printf(" Digite a chave: ");
        scanf("%i", &chaveAux);
        printf(" Digite o nome: ");
        scanf("%s", nomeAux);
        printf(" Digite o tipo: ");
        scanf("%s", tipoAux);
        printf(" Digite o ano: ");
        scanf("%i", &anoAux);

        FILE *fp;
        fp = fopen ("dados.bin","ab");
        if (fp!=NULL)
        {
          fprintf(fp,"\n%i %s %s %i", chaveAux,nomeAux,tipoAux, anoAux);
          fclose (fp);
        }

        // t_jogos jogos[] = {chaveAux, nomeAux[20], tipoAux[20], anoAux};

        // void inserir(t_jogos jogos[]);

        printf("\n\n");
        goto v;

      case 5: //Imprimir

        fp = fopen ("dados.bin","rb");
        if (fp!=NULL)
        {

              fscanf(fp,"%i %s %s %i\n", &a, c, var, &b);
              printf(" Chave do jogo: %i\n Nome do jogo: %s\n Tipo do jogo: %s\n Ano de lançamento: %i\n", a,c,var,b);

        }
          fclose (fp);
        }

        // printf("\n\n");
        // printf("\t\t---Impressão---\n\n" );
        // printf("Digite de que modo deseja a impressão: \n");
        // printf("\n [1] Impressão por chave;\n [2] Impressão por campo2; \n [4] Impressão por categoria ordenada pela chave;\n");
        // printf(" [4] Impressão por categoria ordenada pelo campo2;\n [5] Impressão desordenada.\n");
        // scanf("%d", &opImp);
        // switch (opImp) {
          // case 1:
            // printf("Impressão por chave: \n");
            // break;
          // case 2:
            // printf("Impressão por campo2: \n");
            // break;
          // case 3:
            // printf("Impressão por categoria ordenada pela chave: \n");
            // break;
          // case 4:
            // printf("Impressão por categoria ordenada pelo campo2: \n");
            // break;
          // case 5:
            // printf("Impressão desordenada: \n");
            // break;

        // }

        printf("\n\n");
        goto v;
   // }

  } while(op != 0);

  return 0;
}
