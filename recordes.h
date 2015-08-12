/*Alunos:

HELOISE CRISTINI MAGATON            1248103
OSMARY CAMILA BORTONCELLO GLOBER    1249207
VINICIUS FRANCISCO DE PAULA         1245872

*/


#include <stdio.h>
#include <stdlib.h>

//apenas lê os recordes
void lerRecordes(Jogador *player)
{
int i;
FILE *record;

    record=fopen("Recordes.bin", "rb");

    if(record==NULL){ // caso não haja recordes salvos, imprime-se um valores "nulos" no arquivo.
        for(i=0; i<5; i++) {
            strcpy(player[i].nome, "-"); //copia de "-" em "player[i].nome"
            player[i].pontos=0;
        }
        record=fopen("Recordes.bin", "wb");
        fwrite(player,sizeof(Jogador),5,record);//copia a struct para o arquivo binário.
    }

    else
        fread(player,sizeof(Jogador),5,record);

    fclose(record);//fecha o arquivo binário para não haver danos.
}

//grava o recorde apenas se o jogador atingiu os pontos necessários.
void gravarRecordes(char *nome, int pontos)
{
int i, j;
Jogador player[5];
FILE *record;

    lerRecordes(player);

    for(i=0; i<5; i++) {
        if(pontos>player[i].pontos){ //caso a pontuação seja maior que as do recorde (copiadas para uma struct).
            for(j=4; j>i; j--){
                strcpy(player[j].nome, player[j-1].nome); //mudança na struct que foi lida anteriormente.
                player[j].pontos=player[j-1].pontos;
            }
            strcpy(player[i].nome, nome);
            player[i].pontos=pontos;
            break;
        }
    }

    record=fopen("Recordes.bin", "wb");
    fwrite(&player,sizeof(Jogador),5,record); //grava-se a struct no arquivo binário.
    fclose(record);
}

//escreve os recordes na tela.
void escreveRecordes(Jogador *player)
{
int i;

    printf("\tRECORDES:\n");

    for(i=0; i<5; i++){
        printf("%d - %s %d\n",i+1,player[i].nome, player[i].pontos);
    }
}
