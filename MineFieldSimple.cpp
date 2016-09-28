/*
 1 - Definir duas Matrizes tipo CHAR quadradas com tamanho de 20 a 50 escolhida pela usuário.
 2 - Escolher aleatoriamente X posições da matriz principal e marcar com uma letra "B". X deve ser no mínimo 20% do total de posições da matriz e no máximo 40%. Cada "B"é uma bomba.
 3 - Solicitar uma linha e uma coluna para o usuário e o que tem lá? O que pode acontecer:
 Acertou:    Bomba - Marcar a Matriz B com  "Bomba"
 Vazia - Marcar com o Nº de bombas na vizinhança.
 Errou - Perdeu
 */


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define linhas 50
#define colunas 50
using namespace std;
int main()
{
    char mina[linhas][colunas],campo[linhas][colunas],bomba,valor;
    int perdeu=0,ganhou=0,tamanho=0,sorteio,porcentagem,cont,i,j;

    //aqui pedimos ao usuario o tamanho do campo minado;

    do
    {
        cout<<"entre escolha um valor entre 20 e 50"<<"\n";
        cin>>tamanho;
        if(tamanho<20||tamanho>50)
        {
            cout<<"voce digitou valor errado"<<"\n";
        }
    }
    while(tamanho<20||tamanho>50);

    //gerar matrizes campo e mina;

    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++)
        {
            mina[i][j]='.';
            campo[i][j]='.';
        }
    }

    //aqui sorteia a porcentagem de bombas;

    srand(time(NULL));
    porcentagem=20+rand()%20;
    sorteio=((tamanho*tamanho)*porcentagem)/100;
    cout<<"\n";
    cout<<"Quantidade de bombas: "<<sorteio<<"\n"<<"Porcentagem de bombas: "<<porcentagem;
    cout<<"\n\n";
    cont=0;

    //preenche a matriz com as bombas;

    do
    {
        i=rand()%tamanho;
        j=rand()%tamanho;
        if(mina[i][j]=='.')
        {
            mina[i][j]='b';
        }
        else
        {
            cont--;
        }
        cont++;
    }
    while(cont<sorteio);

    //contabiliza as bombas e atribui a matriz mina;

    int numerobombas=0;
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            if(mina[i][j]=='.'){
                if(mina[i-1][j]=='b')
                {
                    numerobombas++;
                }
                if(mina[i][j-1]=='b')
                {
                    numerobombas++;
                }
                if(mina[i+1][j]=='b')
                {
                    numerobombas++;
                }
                if(mina[i][j+1]=='b')
                {
                    numerobombas++;;
                }
                if(mina[i-1][j-1]=='b')
                {
                    numerobombas++;
                }
                if(numerobombas==0){
                    mina[i][j]='0';
                }
                if(numerobombas==1){
                    mina[i][j]='1';
                }
                if(numerobombas==2){
                    mina[i][j]='2';
                }
                if(numerobombas==3){
                    mina[i][j]='3';
                }
                if(numerobombas==4){
                    mina[i][j]='4';
                }
                if(numerobombas==5){
                    mina[i][j]='5';
                }
                if(numerobombas==6){
                    mina[i][j]='6';
                }
                if(numerobombas==7){
                    mina[i][j]='7';
                }
                if(numerobombas==8){
                    mina[i][j]='8';
                }
            }
            numerobombas=0;
        }
    }

    //imprime a matriz campo ao usuario para escolher uma posicao na matriz;

    for(i=0; i<10; i++)
    {
        cout<<i<<"  ";
    }
    for(i=10; i<tamanho; i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    cont=0;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++)
        {
            cout<<campo[i][j]<<"  ";
        }
        cout<<cont;
        cont++;
        cout<<"\n";
    }

    //pedido de entradas ao usuario;

    int vida=3;
    do{
    cout<<"entre com uma posicao digite o numero da linha pressione enter \n";
    cin>>i;
    cout<<"entre com uma posicao digite o numero da coluna e pressione enter \n";
    cin>>j;
    cout<<"o que voce imagina que tem na posicao que voce escolheu ? b para bomba e v para vazio \n";
    char teste;
    cin>>teste;

    //teste para saber se o usuario acertou ou errou;

    if( (teste=='v'||teste=='V') && (mina[i][j]=='.'|| mina[i][j]!='.'))
    {
        cout<<"VOCE ACERTOU \n";
        campo[i][j]='p';
                if(mina[i-1][j-1]!='b')
                {
                    campo[i-1][j-1]=mina[i-1][j-1];
                }
                if(mina[i-1][j]!='b')
                {
                    campo[i-1][j]=mina[i-1][j];
                }
                if(mina[i-1][j+1]!='b')
                {
                    campo[i-1][j+1]=mina[i-1][j+1];
                }
                if(mina[i][j-1]!='b')
                {
                    campo[i][j-1]=mina[i][j-1];
                }
                if(mina[i][j+1]!='b')
                {
                    campo[i][j+1]=mina[i][j+1];
                }
                if(mina[i+1][j-1]!='b')
                {
                    campo[i+1][j-1]=mina[i+1][j-1];
                }
                if(mina[i+1][j]!='b')
                {
                    campo[i+1][j]=mina[i+1][j];
                }
                if(mina[i+1][j+1]!='b')
                {
                    campo[i+1][j+1]=mina[i+1][j+1];
                }
    }
    if(mina[i][j]=='b'&& (teste=='v'||teste=='V'))
    {
        cout<<"VOCE ERROU \n"<<" Perde uma vida";
        campo[i][j]='b';
                if(mina[i-1][j-1]!='b')
                {
                    campo[i-1][j-1]=mina[i-1][j-1];
                }
                if(mina[i-1][j]!='b')
                {
                    campo[i-1][j]=mina[i-1][j];
                }
                if(mina[i-1][j+1]!='b')
                {
                    campo[i-1][j+1]=mina[i-1][j+1];
                }
                if(mina[i][j-1]!='b')
                {
                    campo[i][j-1]=mina[i][j-1];
                }
                if(mina[i][j+1]!='b')
                {
                    campo[i][j+1]=mina[i][j+1];
                }
                if(mina[i+1][j-1]!='b')
                {
                    campo[i+1][j-1]=mina[i+1][j-1];
                }
                if(mina[i+1][j]!='b')
                {
                    campo[i+1][j]=mina[i+1][j];
                }
                if(mina[i+1][j+1]!='b')
                {
                    campo[i+1][j+1]=mina[i+1][j+1];
                }
        vida--;
    }
    if( mina[i][j]=='b'&&(teste=='b' || teste=='B'))
    {
        cout<<"VOCE ACERTOU UMA BOMBA!\n";
        campo[i][j]='b';
    }
    if((teste=='b'|| teste=='B')&&(mina[i][j]=='.'|| mina[i][j]!='b'))
    {
        cout<<"VOCE ERROU \n"<<" Perde uma vida";
        campo[i][j]='p';
                if(mina[i-1][j-1]!='b')
                {
                    campo[i-1][j-1]=mina[i-1][j-1];
                }
                if(mina[i-1][j]!='b')
                {
                    campo[i-1][j]=mina[i-1][j];
                }
                if(mina[i-1][j+1]!='b')
                {
                    campo[i-1][j+1]=mina[i-1][j+1];
                }
                if(mina[i][j-1]!='b')
                {
                    campo[i][j-1]=mina[i][j-1];
                }
                if(mina[i][j+1]!='b')
                {
                    campo[i][j+1]=mina[i][j+1];
                }
                if(mina[i+1][j-1]!='b')
                {
                    campo[i+1][j-1]=mina[i+1][j-1];
                }
                if(mina[i+1][j]!='b')
                {
                    campo[i+1][j]=mina[i+1][j];
                }
                if(mina[i+1][j+1]!='b')
                {
                    campo[i+1][j+1]=mina[i+1][j+1];
                }
        vida--;
    }

    //imprime a matriz campo;

    for(i=0; i<10; i++)
    {
        cout<<i<<"  ";
    }
    for(i=10; i<tamanho; i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    cont=0;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++)
        {
            cout<<campo[i][j]<<"  ";
        }
        cout<<cont;
        cont++;
        cout<<"\n";
    }
    }while(vida!=0);
}
