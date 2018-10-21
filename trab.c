
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
#define N 10


struct cadJogos {
    int id;
    char nome[10];
    char cat[10];
    int ano;
};




int main(int argc, char const *argv[]) {
  FILE *arq1;
  FILE *arq2;
  struct cadJogos jogos[TAM];
  int i, count = 1; //count = 50 pois já existem 49 cadastros (de 0 a 49)
  int op;

do {
  v:
  menu();

  printf("\n Opção: ");
  scanf("%d",  &op);

  switch (op) {
    case 1:
      printf("Consultar jogo:\n");

    goto v;

    case 2:
      printf("Atualizar/Alterar registro\n");
    goto v;

    case 3:
      printf("Excluir jogo\n");
    goto v;

    case 4:
      printf("\n\tCadastro\n");
      int cadOp;
      printf("Quantos jogos deseja cadastrar? \nR:");
      scanf("%d", &cadOp);


      for (i = 0; i < cadOp; i++) {
        jogos[i].id = count;
        printf("\n Nome: ");
        scanf("%s", &jogos[i].nome);
        printf("\n Categoria: ");
        scanf("%s", &jogos[i].cat);
        printf("\n Ano: ");
        scanf("%d", &jogos[i].ano);
        count++;
      }


      arq1 = fopen("cadJogos.dat", "ab");
      if (arq1 == NULL) {
        printf("ERRO\n");
        exit(1);
      }
      fwrite(&jogos[0], sizeof(struct cadJogos), cadOp, arq1);
      fclose(arq1);

    goto v;

    case 5:
      arq2 = fopen("cadJogos.dat", "rb");
      if (arq2 == NULL) {
        printf("ERRO\n");
        exit(1);
      }
      printf("\n\n");
      fread(&jogos[0], sizeof(jogos), 1, arq2);
      for (i = 0; i < count ; i++) {
        printf("ID = %d\nNOME = %s\nCATEGORIA = %s\nANO = %d\n", jogos[i].id, jogos[i].nome, jogos[i].cat, jogos[i].ano);
      }

      fclose(arq2);

    goto v;

  }




} while(op != 0);

  return 0;
}


void menu(){

  printf("\n\n");
  printf("\t\t Bem vindo.\n");
  printf("\n Selecione uma das opções abaixo:\n");
  printf("\n [1] Consultar um jogo;\n [2] Alterar/Atualizar um campo do jogo;\n [3] Excluir um jogo;\n [4] Inserir um jogo;\n [5] Imprimir jogos;\n [0] Sair.\n");

}
