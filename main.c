/*Alunos:

HELOISE CRISTINI MAGATON            1248103
OSMARY CAMILA BORTONCELLO GLOBER    1249207
VINICIUS FRANCISCO DE PAULA         1245872

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include "pecas.h"
#include "recordes.h"
#define BORDA 178
#define VINICIAL 1500
#define TROCANIVEL 500

//apenas imprime o menu na tela, a seleção da opção (getch) é feita no próprio main.
void imprimeMenu ()
{
     printf("\t\t TETRIS+COLLUMS\n\n\n");
     printf("Selecione uma opcao.\n\n");
     printf("1 - Novo jogo.\n");
     printf("2 - Continuar jogo.\n");
     printf("3 - Ver recordes.\n");
     printf("4 - Modo Automatico.\n");
     printf("5 - Sair.\n\n");

}

//iniciliza o tabuleiro, incluindo bordas.
void inicializaTabuleiro(int *pontos, int *nivel)
{
int l, c;

*pontos=0;
*nivel=1;

    for(c=0; c<12; c++){
        tabuleiro[41][c]=9;     //"inserindo" as bordas.
        tabuleiro[0][c]=9;
    }

    for(l=0; l<42; l++) {
        tabuleiro[l][0]=9;       //"inserindo" as bordas.
        tabuleiro[l][11]=9;
    }
    for(l=0; l<41; l++){
        for(c=1; c<11; c++){    //setando para 0 todas as "casas" do tabuleiro.
            tabuleiro[l][c]=0;
        }
    }
}

//zera a "casa" do tabuleiro caso não haja um bloco de peça no bloco do tabuleiro.
void zerarTabuleiro()
{
int l, c;

    for(l=0; l<42; l++)
        for(c=0; c<12; c++)
            if((tabuleiro[l][c]!=5)&&(tabuleiro[l][c]!=6)&&(tabuleiro[l][c]!=7)&&(tabuleiro[l][c]!=8)&&(tabuleiro[l][c]!=9))
            tabuleiro[l][c]=0;
}

//transfere os blocos de 1 a 4 para 5 a 8, o que auxiliará nas comparações.
void transferirJogo()
{
    int l, c;
    for(l=0; l<42; l++)
        for(c=0; c<12; c++) {
            if(tabuleiro[l][c]==1)
                tabuleiro[l][c]=5;
            else if(tabuleiro[l][c]==2)
                tabuleiro[l][c]=6;
            else if(tabuleiro[l][c]==3)
                tabuleiro[l][c]=7;
            else if(tabuleiro[l][c]==4)
                tabuleiro[l][c]=8;
        }
}

//imprime a metriz e outras informaçõs como teclas, pontuação e nível atuais.
void imprimeMatriz(int pontos, int nivel)
{
    int l,c,i;
    printf("\tTETRIS+COLLUMS\n\n");
    printf("P = Pausa o jogo.\n");
    printf("X = Desce a peça.\n");
    printf("A = Move para direita.\n");
    printf("D = Move para esquerda.\n");
    printf("W = Rotaciona a peça.\n\n");

    for(i=0;i<12;i++)
        printf("%2c", BORDA);   //imprime uma faixa antes da matriz, recurso utilizado pra simular uma borda
                                //pertinente ao campo de jogo.
    printf("\n");

    for(l=0; l<42; l++) {
        for(c=0; c<12; c++) {
            if(tabuleiro[l][c]==9)
                printf("%2c", BORDA); //BORDA está definido por um caractere especial.
            else if(tabuleiro[l][c]==5)
                printf("%2d", 1);
            else if(tabuleiro[l][c]==6)
                printf("%2d", 2);
            else if(tabuleiro[l][c]==7)
                printf("%2d", 3);
            else if(tabuleiro[l][c]==8)
                printf("%2d", 4);
            else if(tabuleiro[l][c]!=0)
                printf("%2d", tabuleiro[l][c]);
            else
                printf("%2c", ' ');
        }
        printf("\n");
    }
    printf("\n");
    printf("\tPontos: %d\n", pontos);
    printf("\tNivel: %d\n\n\n", nivel);
}

//função utilizada para rotacionar a peça
int mudarPosicao(int nroPeca, int posicao)
{
    int l, c;
    if(posicao==3) {
        posicao=0;
        coordenadas(nroPeca, posicao);
        for(l=0; l<4; l++)
            for(c=5; c<12; c++)
                if(tabuleiro[posX+pos[l]+1][posY+pos[l+4]]==c)
                    return posicao+3;
    }
    else {
        posicao++;
        coordenadas(nroPeca, posicao);
        for(l=0; l<4; l++)
            for(c=5; c<12; c++)
                if(tabuleiro[posX+pos[l]+1][posY+pos[l+4]]==c)
                    return posicao-1;
    }
    return posicao;
}

//modifica a pontuação do jogador
int modificarPontos(int *pontos, int cont)
{
    switch(cont){
        case 3:
            *pontos=*pontos+10;
            break;
        case 4:
            *pontos=*pontos+20;
            break;
        case 5:
            *pontos=*pontos+30;
            break;
        case 6:
            *pontos=*pontos+50;
            break;
    }
    return 0;
}

//muda o nível caso a pontuação seja maior que 500, isso implicará no aumento da velocidade.
void mudarNivel(int *pontos, int *nivel)
{
    if(*pontos>*nivel*TROCANIVEL){
        (*nivel)++;
    }
}

//pausar o jogo.
int pausarJogo()
{
char tecla;

    while(tecla!=2){
        main ();
        tecla = getch();
    }

return 0;
}

// checa se existe peça que já colidiu na primeira linha
int fimJogo()
{
int c, peca;

    for(c=1; c<12; c++){
        for(peca=5; peca<9; peca++){ // verifica se há um bloco que varia de 5 a 8
            if(tabuleiro[0][c]==peca){
                return 1;
            }
        }
    }

    return 0;
}



//principal função do jogo
void jogo(int *nroPeca, int *posicao, char *nome, int *pontos, int *nivel)
{
char tecla;

    do {

        if(posX==0) { // gera nova peça, incluindo cores e rotação inicial, apenas se houve colisão.
            sortearCor();
            *nroPeca=sortearPeca();
            *posicao=sortearRotacao();
        }

        coordenadas(*nroPeca, *posicao); //pega as coordenadas da nova peça

        for(;;) { //gera um loop infinito, que parará num break mais abaixo.

            contador++; //contador apenas auxilia na função de pausar o jogo, caso o contador seja diferente
                        //de zero, sabemos que um jogo foi iniciado.

            zerarTabuleiro(); //seta as posições sem peça para 0.

            if(kbhit()){  //a função kbhit() retorna 0 se o usuário não está precionando nenhuma tecla.

                    tecla = getch();

                    if(tecla=='w') { // rotaciona peça
                        *posicao=mudarPosicao(*nroPeca, *posicao);
                        armazenarPeca(*nroPeca, *posicao);
                        coordenadas(*nroPeca, *posicao);
                    }
                    if(tecla=='d') { // move para a direita
                        if(colisaoDireita()==0)
                            posY++; //posY, pois lemos (linha, coluna) e não (x,y).
                    }
                    if(tecla=='a') { // move para a esquerda
                        if(colisaoEsquerda()==0)
                            posY--;
                    }
                    if(tecla=='x'){ //move para baixo
                        if(colisaoEsquerda()==0)
                            while((colisaoBaixo()==0)||(colisaoDireita()==0)||(colisaoEsquerda==0))
                            { //enquanto não houver colisão a peça desce para baixo, ou seja, a peça "cai".
                                posX++;
                            }
                    }
                    else if(tecla=='p'){ //pausa o jogo e
                        pausarJogo();
                    }
            }
            armazenarPeca(*nroPeca, *posicao);
            if(colisaoBaixo()==0)
                posX++;
            else {
                transferirJogo();//mudas as posições para compará-las no "apagarPecas"
                posX=0;
                posY=0;
                break; //fim do loop, caso haja colisão
            }
            imprimeMatriz(*pontos, *nivel);
            Sleep(pow(0.9,*nivel-1)*VINICIAL); // de acordo com o nível é determinado a velocidade
            system("cls");
        }// fim do for

        apagarPecas(pontos); //apaga os blocos que devem ser apagados.

        mudarNivel(pontos, nivel); //muda de nivel, caso a pontuação seja atingida.

      } while(fimJogo()!=1);

      printf("     TETRIS + COLLUMS\n\n");
      printf("\n\n\tnFim de jogo!\n\n");
      printf("Sua pontuacao foi de %d pontos\n", *pontos);
      gravarRecordes(nome, *pontos); //grava em recordes apenas se a pontuação necessária for atingida
      getch();
      system("cls");
}


int main()
{
int nroPeca, posicao, nivel;
char opc;

Jogador j, player[5]; //j do jogador atual e player para acessar os recordes.

    do {

        imprimeMenu();

        opc=getch();

        system("cls");

        switch(opc) {
            case '1':
                printf("Digite seu nome:\n");
                fflush(stdin);
                scanf("%20[^\n]", &j.nome);
                system("cls");
                inicializaTabuleiro(&j.pontos, &nivel);
                jogo(&nroPeca, &posicao, j.nome, &j.pontos, &nivel);
                break;
            case '2':
                if(contador!=0) // para verificar se já houve o início de um jogo novo.
                    jogo(&nroPeca, &posicao, j.nome, &j.pontos, &nivel);
                else {
                    printf("\tNao ha jogo em execucao para continuar.\n\tPressione uma tecla para voltar ao menu.\n");
                    getch();
                    system("cls");
                }
                break;
            case '3':
                lerRecordes(player);
                escreveRecordes(player);
                getch();
                system("cls");
                break;
            case '4':
                printf("Nao implementado.\n");
                getch();
                system("cls");
        }
    } while(opc!='5');
    return 0;
}
