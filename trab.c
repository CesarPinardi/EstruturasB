#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 3

struct cadJogos {
    int id;
    char nome[10];
    char cat[10];
    int ano;
};

int main(int argc, char const *argv[]) {
  FILE *arq1;
  FILE *arq2;
  FILE *ind;


      int matrizIndice[TAM][2];
      int pos = 0;
      int i2, j2;
  struct cadJogos jogos[TAM];
  int i, count = 0; //count = 50 pois já existem 49 cadastros (de 0 a 49)
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
        jogos[i].id = rand() % 100;
        printf("\n Nome: ");
        scanf("%s", &jogos[i].nome);
        printf("\n Categoria: ");
        scanf("%s", &jogos[i].cat);
        printf("\n Ano: ");
        scanf("%d", &jogos[i].ano);
        count++;
      }


      arq1 = fopen("cadJogos.dat", "wb");
      if (arq1 == NULL) {
        printf("ERRO\n");
        exit(1);
      }
      fwrite(&jogos[0], sizeof(struct cadJogos), cadOp, arq1);
      fclose(arq1);

    goto v;

    case 5:
      arq2 = fopen("cadJogos.dat", "rb");
      //no indice denso contem as chaves ordenadas e a posicao relativa na linear no arquivo
      if (arq2 == NULL) {
        printf("ERRO\n");
        exit(1);
      }
      printf("\n\n");
      fread(&jogos[0], sizeof(jogos), 1, arq2);
      for (i = 0; i < count; i++) {
        printf("ID = %d\nNOME = %s\nCATEGORIA = %s\nANO = %d\n", jogos[i].id, jogos[i].nome, jogos[i].cat, jogos[i].ano);
      }

      //pegar valores e jogar em uma matriz
      fclose(arq2);

    goto v;

    case 6:


    ind = fopen("cadJogos.dat", "rb");
    if (ind!=NULL)
    {
      fread(&jogos[0], sizeof(jogos), 1, ind);
      for (i2 = 0; i2 < TAM; i2++) {
              pos++;
              printf ("\n Chave(ID) = [%d] \n Posição relativa linear no arquivo = [%d]\n",jogos[i2].id,pos);
      }

      pos = 0;
      fclose (ind);
    }

    goto v;

  }

} while(op != 0);

  return 0;
}


void menu(){

  printf("\n\n");
  printf("\t\t Bem vindo.\n");
  printf("\n Selecione uma das opções abaixo:\n");
  printf("\n [1] Consultar um jogo;\n [2] Alterar/Atualizar um campo do jogo;\n [3] Excluir um jogo;\n [4] Inserir um jogo;\n [5] Imprimir jogos;\n [0] Sair.\n [6] Teste da matriz(Indice Denso)\n");

}
