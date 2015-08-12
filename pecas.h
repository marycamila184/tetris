/*Alunos:

HELOISE CRISTINI MAGATON            1248103
OSMARY CAMILA BORTONCELLO GLOBER    1249207
VINICIUS FRANCISCO DE PAULA         1245872

*/


#include <stdio.h>
#include <stdlib.h>

int tabuleiro[42][12]; //campo de jogo, incluindo bordas.
int posX=0; //variavel X para movimeta��o.
int posY=0; //variavel Y para movimeta��o.
int pos[8]; // cont�m as posi��es do eixo X (0 a 3) e eixo Y (4 a 7) de cada pe�a
int cores[4]; // cada cor desse vetor ser� alocada em um doa quatro blocos da pe�a.
int contador=0; // auxilia na pausa do jogo.

typedef struct jogador { //o registro foi criado com o objetivo de armazenar informa��es referentes ao jogador,
    char nome[20];      //ou seja, o nome e sua respectiva pontua��o.
    int pontos;
}Jogador;

// insere uma pe�a j� com a cor sorteada (que est� no vetor cores[])
void armazenarPeca(int nroPeca, int nroRotacao){
    switch(nroPeca) {
        case 0: // quadrado
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+0][posY+6]=cores[1];
                    tabuleiro[posX+1][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+6]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+5]=cores[2];
                    tabuleiro[posX+0][posY+6]=cores[0]; //notamos que a o recebimento de um elemento do vetor cores
                    tabuleiro[posX+1][posY+5]=cores[3]; //n�o segue um padr�o, pois isso varia de pe�a para pe�a
                    tabuleiro[posX+1][posY+6]=cores[1]; //juntamente com sua rota��o.
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+0][posY+5]=cores[3];
                    tabuleiro[posX+0][posY+6]=cores[2];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+6]=cores[0];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+0][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+6]=cores[3];
                    tabuleiro[posX+1][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+6]=cores[2];
                    break;
            }
            break;
        case 1:	//barra
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+0][posY+3]=cores[0];
                    tabuleiro[posX+0][posY+4]=cores[1];
                    tabuleiro[posX+0][posY+5]=cores[2];
                    tabuleiro[posX+0][posY+6]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+2][posY+5]=cores[2];
                    tabuleiro[posX+3][posY+5]=cores[3];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+0][posY+3]=cores[3];
                    tabuleiro[posX+0][posY+4]=cores[2];
                    tabuleiro[posX+0][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+6]=cores[0];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+0][posY+5]=cores[3];
                    tabuleiro[posX+1][posY+5]=cores[2];
                    tabuleiro[posX+2][posY+5]=cores[1];
                    tabuleiro[posX+3][posY+5]=cores[0];
                    break;
            }
            break;
        case 2: //L
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+2][posY+5]=cores[2];
                    tabuleiro[posX+2][posY+6]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+6]=cores[0];
                    tabuleiro[posX+0][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+4]=cores[2];
                    tabuleiro[posX+1][posY+4]=cores[3];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+2][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+5]=cores[2];
                    tabuleiro[posX+0][posY+4]=cores[3];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+1][posY+4]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+6]=cores[2];
                    tabuleiro[posX+0][posY+6]=cores[3];
                    break;
            }
            break;
        case 3://L invertido
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+0][posY+6]=cores[0];
                    tabuleiro[posX+1][posY+6]=cores[1];
                    tabuleiro[posX+2][posY+6]=cores[2];
                    tabuleiro[posX+2][posY+5]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+1][posY+7]=cores[0];
                    tabuleiro[posX+1][posY+6]=cores[1];
                    tabuleiro[posX+1][posY+5]=cores[2];
                    tabuleiro[posX+0][posY+5]=cores[3];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+2][posY+6]=cores[0];
                    tabuleiro[posX+1][posY+6]=cores[1];
                    tabuleiro[posX+0][posY+6]=cores[2];
                    tabuleiro[posX+0][posY+7]=cores[3];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+0][posY+6]=cores[1];
                    tabuleiro[posX+0][posY+7]=cores[2];
                    tabuleiro[posX+1][posY+7]=cores[3];
                    break;
            }
            break;
        case 4: //N
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+0][posY+7]=cores[0];
                    tabuleiro[posX+1][posY+7]=cores[1];
                    tabuleiro[posX+1][posY+6]=cores[2];
                    tabuleiro[posX+2][posY+6]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+5]=cores[3];
                    tabuleiro[posX+0][posY+6]=cores[2];
                    tabuleiro[posX+1][posY+6]=cores[1];
                    tabuleiro[posX+1][posY+7]=cores[0];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+0][posY+7]=cores[3];
                    tabuleiro[posX+1][posY+7]=cores[2];
                    tabuleiro[posX+1][posY+6]=cores[1];
                    tabuleiro[posX+2][posY+6]=cores[0];
                    break;
                case 3://posi��o 4
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+0][posY+6]=cores[1];
                    tabuleiro[posX+1][posY+6]=cores[2];
                    tabuleiro[posX+1][posY+7]=cores[3];
                    break;
            }
            break;
        case 5: //N invertido
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+2][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+4]=cores[2];
                    tabuleiro[posX+0][posY+4]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+6]=cores[3];
                    tabuleiro[posX+0][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+4]=cores[0];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+2][posY+5]=cores[3];
                    tabuleiro[posX+1][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+4]=cores[1];
                    tabuleiro[posX+0][posY+4]=cores[0];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+0][posY+6]=cores[0];
                    tabuleiro[posX+0][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+4]=cores[3];
                    break;
            }
            break;
        case 6: //T
            switch(nroRotacao) {
                case 0: //posi��o 1
                    tabuleiro[posX+2][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+6]=cores[3];
                    break;
                case 1: //posi��o 2
                    tabuleiro[posX+0][posY+4]=cores[0];
                    tabuleiro[posX+0][posY+5]=cores[1];
                    tabuleiro[posX+0][posY+6]=cores[2];
                    tabuleiro[posX+1][posY+5]=cores[3];
                    break;
                case 2: //posi��o 3
                    tabuleiro[posX+0][posY+5]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+2][posY+5]=cores[2];
                    tabuleiro[posX+1][posY+4]=cores[3];
                    break;
                case 3: //posi��o 4
                    tabuleiro[posX+1][posY+6]=cores[0];
                    tabuleiro[posX+1][posY+5]=cores[1];
                    tabuleiro[posX+1][posY+4]=cores[2];
                    tabuleiro[posX+0][posY+5]=cores[3];
                    break;
            }
            break;
    }
}

//pega as cordenadas dos blocos da pe�a (0,1,2,3 para X) e (4,5,6,7 para Y)
//essa � uma etapa muito importante, pois, atrav�s das coordenadas, fazemos a mudan�a de posi��o.
void coordenadas(int nroPeca, int nroRotacao)
{
    switch(nroPeca) {

        case 0: //quadrado
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 2: //posi��o 3
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 3: //posi��o 4
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=5;
                    pos[7]=6;
                    break;
            }
            break;

        case 1: //I
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    pos[3]=0;
                    pos[4]=3;
                    pos[5]=4;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=2;
                    pos[3]=3;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=5;
                    break;
                case 2: //posi��o 3
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    pos[3]=0;
                    pos[4]=3;
                    pos[5]=4;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                 case 3: //posi��o 4
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=2;
                    pos[3]=3;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=5;
                    break;
            }
            break;

        case 2: //L
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=2;
                    pos[3]=2;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    pos[3]=1;
                    pos[4]=6;
                    pos[5]=5;
                    pos[6]=4;
                    pos[7]=4;
                    break;
                case 2: //posi��o 3
                    pos[0]=2;
                    pos[1]=1;
                    pos[2]=0;
                    pos[3]=0;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=4;
                    break;
                case 3: //posi��o 4
                    pos[0]=1;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=0;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=6;
                    pos[7]=6;
                    break;
            }
            break;

        case 3: //L invertido
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=2;
                    pos[3]=2;
                    pos[4]=6;
                    pos[5]=6;
                    pos[6]=6;
                    pos[7]=5;
                    break;
                case 1: //posi��o 2
                    pos[0]=1;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=0;
                    pos[4]=7;
                    pos[5]=6;
                    pos[6]=5;
                    pos[7]=5;
                    break;
                case 2: //posi��o 3
                    pos[0]=2;
                    pos[1]=1;
                    pos[2]=0;
                    pos[3]=0;
                    pos[4]=6;
                    pos[5]=6;
                    pos[6]=6;
                    pos[7]=7;
                    break;
                case 3: //posi��o 4
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=7;
                    pos[7]=7;
                    break;
            }
            break;

        case 4: //N
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=2;
                    pos[4]=7;
                    pos[5]=7;
                    pos[6]=6;
                    pos[7]=6;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=6;
                    pos[7]=7;
                    break;
                case 2: //posi��o 3
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=2;
                    pos[4]=7;
                    pos[5]=7;
                    pos[6]=6;
                    pos[7]=6;
                    break;
                case 3: //posi��o 4
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=6;
                    pos[6]=6;
                    pos[7]=7;
                    break;

            }
            break;

        case 5: //N invertido
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=2;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=0;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=4;
                    pos[7]=4;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=6;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=4;
                    break;
                case 2: //posi��o 3
                    pos[0]=2;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=0;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=4;
                    pos[7]=4;
                    break;
                case 3: //posi��o 4
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=1;
                    pos[3]=1;
                    pos[4]=6;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=4;
                    break;
            }
            break;

        case 6: //T
            switch(nroRotacao) {
                case 0: //posi��o 1
                    pos[0]=2;
                    pos[1]=1;
                    pos[2]=0;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=6;
                    break;
                case 1: //posi��o 2
                    pos[0]=0;
                    pos[1]=0;
                    pos[2]=0;
                    pos[3]=1;
                    pos[4]=4;
                    pos[5]=5;
                    pos[6]=6;
                    pos[7]=5;
                    break;
                case 2: //posi��o 3
                    pos[0]=0;
                    pos[1]=1;
                    pos[2]=2;
                    pos[3]=1;
                    pos[4]=5;
                    pos[5]=5;
                    pos[6]=5;
                    pos[7]=4;
                    break;
                case 3: //posi��o 4
                    pos[0]=1;
                    pos[1]=1;
                    pos[2]=1;
                    pos[3]=0;
                    pos[4]=6;
                    pos[5]=5;
                    pos[6]=4;
                    pos[7]=5;
                    break;

            }
            break;
    }
}

//fun��o que sorteia uma pe�a
int sortearPeca ()
{
int nroPeca;

    srand(time(NULL));
    nroPeca = rand() % 7;

 return nroPeca;
}

//fun��o que sorteia uma rota��o para a pe�a.
int sortearRotacao ()
{
int nroRotacao;

    srand(time(NULL));
    nroRotacao = rand() % 4;

 return nroRotacao;
}

//fun��o que sorteia "cores" para os blocos das pe�as.
void sortearCor()
{
int i;

    srand(time(NULL));

    for(i = 0; i < 4; i++){
          cores[i] = rand()% 4+1; //"cor" est� aqui para que cada bloco da pe�a possa receber uma cor diferente.
    }
}

//verifica se h� colis�o com a pe�a abaixo.
int colisaoBaixo()
{
int i;
    for(i=0; i<4; i++)
        if(tabuleiro[posX+pos[i]+1][posY+pos[i+4]]>4) // maior que 4, pois as pe�as recebem n�meros maiores que 4, inclusive a borda (9).
            return 1;
    return 0;
}

//verifica colis�es com a esquerda
int colisaoEsquerda()
{
int i;
    for(i=0; i<4; i++)
        if(tabuleiro[posX+pos[i]+1][posY+pos[i+4]-1]>4) // maior que 4, pois as pe�as recebem n�meros maiores que 4, inclusive a borda (9).
            return 1;
    return 0;
}

//verifica colis�es com a direita
int colisaoDireita()
{
int i;
    for(i=0; i<4; i++)
        if(tabuleiro[posX+pos[i]+1][posY+pos[i+4]+1]>4) // maior que 4, pois as pe�as recebem n�meros maiores que 4, inclusive a borda (9).
            return 1;
    return 0;
}

//faz as elimina��es necess�rias
void apagarPecas(int *pontos)
{
int l,c;

    for(l=0;l<42;l++){
        for(c=0;c<12;c++){
            if((tabuleiro[l][c]!=0)&&(tabuleiro[l][c]!=9)){ //diferentes de 9 e 0, pois 9 simboliza a borda, e 0 blocos
                verificacaoPecas(l, c, pontos);             //vazios do tabuleiro.
            }
        }
    }

}

//as pr�ximas fun��es contam os vizinhos iguais dos blocos
//verifica vizinhos lateirais das pe�as
int vizinhosLaterais(int l,int c)
{
int cont=0;

    if((tabuleiro[l][c]==tabuleiro[l][c+1])||((tabuleiro[l][c]==tabuleiro[l][c-1])&&(tabuleiro[l][c+1]!=9))){
        cont+=1+vizinhosLaterais(l,c+1);
    }
    return cont; //returna o numero de vizinhos iguais
}

//verifica vizinhos verticais das pe�as
int vizinhosVerticais(int l,int c)
{
int cont=0;

    if((tabuleiro[l][c]==tabuleiro[l+1][c])&&(tabuleiro[l+1][c]!=9)){
        cont+=1+vizinhosVerticais(l+1,c);
    }
    return cont; //returna o numero de vizinhos iguais
}

//verifica vizinhos de uma das diagonais das pe�as
int vizinhosDiag1(int l,int c)
{
int cont=0;

    if(((tabuleiro[l][c]==tabuleiro[l+1][c-1])||(tabuleiro[l-1][c+1]==tabuleiro[l][c]))&&(l>=0)&&(tabuleiro[l+1][c-1]!=9)){ //diagonal
        cont+=1+vizinhosDiag1(l+1,c-1);
    }
    return cont; //returna o numero de vizinhos iguais
}

//verifica vizinhos da outra diagonal das pe�as
int vizinhosDiag2(int l,int c)
{
int cont=0;

    if(((tabuleiro[l][c]==tabuleiro[l+1][c+1])||(tabuleiro[l][c]==tabuleiro[l-1][c-1]))&&(tabuleiro[l+1][c+1]!=9)){
        cont+=1+vizinhosDiag2(l+1,c+1);
    }
    return cont;
}
/****************************************************/
//as fun��es abaixo inserem 0 onde as pe�as ser�o eliminadas
int horizontal(int l, int c)
{
int aux;

    aux=tabuleiro[l][c];
    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        c++;
    }

    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        c--;
    }
    return 0;
}

int vertical(int l,int c)
{
int aux;

    aux=tabuleiro[l][c];
    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        l++;
    }
    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        l--;
    }
    return 0;
}

int diag1(int l,int c)
{
int aux;

    aux=tabuleiro[l][c];
    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        l++;
        c--;
    }
    return 0;
}

int diag2(int l,int c)
{
int aux;

    aux=tabuleiro[l][c];
    while(tabuleiro[l][c]==aux){
        tabuleiro[l][c]=0;
        l++;
        c++;
    }
    return 0;
}
/****************************************************/

//essa fun��o verifica os vizinhos das pe�as e posteriormente chama a fun��o que "apagar�" os blocos.
int verificacaoPecas (int l, int c, int *pontos)
{
int hor,vert,diagc,diagd,aux,cont=0;

                hor=vizinhosLaterais(l,c);
                aux=modificarPontos(&*pontos,hor);
                vert=vizinhosVerticais(l,c);
                aux=modificarPontos(&*pontos,vert);
                diagc=vizinhosDiag1(l,c);
                aux=modificarPontos(&*pontos,diagc);
                diagd=vizinhosDiag2(l,c);
                aux=modificarPontos(&*pontos,diagd);
                if((hor>=3)&&(hor<=6)) //condi��o se h� de 3 a 6 vizinhos da mesma cor.
                    aux=horizontal(l,c);
                if((vert>=3)&&(vert<=6))
                    aux=vertical(l,c);
                if((diagc>=3)&&(diagc<=6))
                    aux=diag1(l,c);
                if((diagd>=3)&&(diagd<=6))
                    aux=diag2(l,c);
    return 0;
}

