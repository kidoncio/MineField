/*
 1 - Definir duas Matrizes tipo CHAR quadradas com tamanho de 20 a 50 escolhida pela usuário.
 2 - Escolher aleatoriamente X posições da matriz principal e marcar com uma letra "B". X deve ser no mínimo 20% do total de posições da matriz e no máximo 40%. Cada "B"é uma bomba.
 3 - Solicitar uma linha e uma coluna para o usuário e o que tem lá? O que pode acontecer:
 Acertou:    Bomba - Marcar a Matriz B com  "Bomba"
 Vazia - Marcar com o Nº de bombas na vizinhança.
 Errou - Perdeu
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int main() {
    
    int Tamanho, Porcentagem, PorcentagemBombas, Linha = 0, Coluna = 0, Cont = 0, Vida = 3, Opcao = 0;
    
    
    printf("Bem vindo ao Campo Minado Jesus Barrado.\n\n");
    
    
    
    //Solicita o tamnho da Matriz.
    do {
        printf("Digite o tamanho do campo minado: ");
        scanf("%d",&Tamanho);
        if (Tamanho < 20 || Tamanho > 50){
            printf("Valor digitado é inválido, por favor digite outro valor.\n");
        }
    }while (Tamanho < 20 || Tamanho > 50);
    
    
    
    //Gera aleatoriamente a porcentagem e quantidades de bombas na Matriz.
    srand(time(NULL));
    Porcentagem = 20 + rand() % 20;
    printf("Porcentagem  = %d\n",Porcentagem);
    PorcentagemBombas = ((Tamanho * Tamanho) * Porcentagem) / 100;
    printf("Bombas  = %d\n",PorcentagemBombas);
    
    
    
    
    //Declara as Matrizes e coloca "." em todas as posições.
    char Minas[Tamanho][Tamanho], Tabuleiro[Tamanho][Tamanho];
    
    for(int i = 0; i < Tamanho ; i++){
        for(int j = 0 ; j < Tamanho ; j++){
            Minas[i][j] = '.' ;
            Tabuleiro[i][j] = '.';
        }
    }
    
    
    
    //Coloca uma bomba "B" nas posições aleatorias na Matriz "Minas" e testa para ver se não tem repetida.
    do {
        Linha = rand() % Tamanho;
        Coluna = rand() % Tamanho;
        if (Minas[Linha][Coluna] == '.'){
            Minas[Linha][Coluna] = 'B';
        }else{
            Cont--;
        }
        Cont++;
        
    }while (Cont < PorcentagemBombas);
    
    
    //Faz a contagem de bombas e numera as casa vizinhas.
    Cont = 0;
    for(int i = 0; i < Tamanho ; i++){
        for(int j = 0; j < Tamanho ; j++){
            if (Minas[i][j] == '.') {
                if (Minas[i][j + 1] == 'B') {
                    Cont++;
                }
                if (Minas[i][j - 1] == 'B') {
                    Cont++;
                }
                if (Minas[i + 1][j] == 'B') {
                    Cont++;
                }
                if (Minas[i - 1][j] == 'B') {
                    Cont++;
                }
                if (Minas[i - 1][j + 1] == 'B') {
                    Cont++;
                }
                if (Minas[i + 1][j + 1] == 'B') {
                    Cont++;
                }
                if (Minas[i + 1][j - 1] == 'B') {
                    Cont++;
                }
                if (Minas[i - 1][j - 1] == 'B') {
                    Cont++;
                }
                if (Cont == 0) {
                    Minas[i][j] = '0';
                }
                if (Cont == 1) {
                    Minas[i][j] = '1';
                }
                if (Cont == 2) {
                    Minas[i][j] = '2';
                }
                if (Cont == 3) {
                    Minas[i][j] = '3';
                }
                if (Cont == 4) {
                    Minas[i][j] = '4';
                }
                if (Cont == 5) {
                    Minas[i][j] = '5';
                }
                if (Cont == 6) {
                    Minas[i][j] = '6';
                }
                if (Cont == 7) {
                    Minas[i][j] = '7';
                }
                if (Cont == 8) {
                    Minas[i][j] = '8';
                }
            }
            
            Cont = 0;
        }
    }
    
    
    //-------------------------- Mostrar a Matriz do Tabuleiro --------------------------
    
    
    
    
    //Mostrar o numero de Colunas do Tabuleiro
    Cont = 0;
    for (int i = 0; i < 10; i++) {
        printf(" %d ",Cont);
        Cont++;
    }
    for (int i = 0; i < Tamanho - 10; i++) {
        printf(" %d",Cont);
        Cont++;
    }
    printf("\n");
    
    
    //Mostrar o numero de Linhas do Tabuleiro
    Cont = 0;
    for(int i = 0; i < Tamanho ; i++){
        for(int j = 0 ; j < Tamanho ; j++){
            printf(" %c ",Tabuleiro[i][j]);
        }
        printf(" | %d",Cont);
        Cont++;
        printf("\n");
    }
    printf("\n\n");
    
    printf("Vamos jogar!!!\n\n\n");
    
    do{
        
        //Teste para linhas
        do {
            printf("Digite o número da LINHA desejada: ");
            scanf("%d",&Linha);
            if (Linha > Tamanho - 1) {
                printf("Valor digitado é maior que o número de linhas. Digite novamente.\n");
            }
        }while (Linha > Tamanho - 1);
        
        
        //Teste para colunas
        do {
            printf("Digite o número da COLUNA desejada: ");
            scanf("%d",&Coluna);
            if (Coluna > Tamanho - 1) {
                printf("Valor digitado é maior que o número de colunas. Digite novamente.\n");
            }
        }while(Coluna > Tamanho - 1);
        
        
        //-------------------------- Seleciona a opção de Mina ou Vazio --------------------------
        
        
        
        printf("O que voce acha que tem? (Digite 1 para BOMBA e 2 para VAZIO): ");
        scanf("%d",&Opcao);
        
        //Bomba
        
        if(Opcao == 1 && Minas[Linha][Coluna] == 'B' ){
            printf("\n\nVocê acertou! Encontrou uma mina!\n\n\n");
            Tabuleiro[Linha][Coluna] = 'X';
        }
        
        if(Opcao == 1 && Minas[Linha][Coluna] != 'B' ){
            Vida--;
            printf("\n\nVocê errou! Aqui não tem nenhuma bomba. Perdeu uma vida, restam ainda %d vida(s). \n\n\n",Vida);
        }
        //Vazio
        
        if(Opcao == 2 && Minas[Linha][Coluna] != 'B' ){
            printf("\n\nVocê acertou! Aqui não tem nenhuma mina!\n\n\n");
            
            if (Minas[Linha][Coluna] == '0') {
                
                
                //Varredura Coluna Direita / Linha Baixo
                for (int i = Coluna; Minas[Linha][i] != 'B'; i++) {
                    if (i == Tamanho || i == 0) {
                        break;
                    }
                    for (int z = Linha; Minas[z][i] != 'B'; z++) {
                        Tabuleiro[z][i] = Minas[z][i];
                        if (z == Tamanho || z == 0) {
                            break;
                        }
                    }
                    
                }
                
                
                //Varredura Coluna Esquerda / Linha Cima
                for (int i = Coluna; Minas[Linha][i] != 'B'; i--) {
                    if (i == 0 || i == Tamanho) {
                        break;
                    }
                    for (int z = Linha; Minas[z][i] != 'B'; z--) {
                        if (z == 0 || z == Tamanho) {
                            break;
                        }
                        Tabuleiro[z][i] = Minas[z][i];
                    }
                    
                }
                
                
                //Varredura Coluna Esquerda / Linha Baixo
                for (int i = Linha; Minas[i][Coluna] != 'B'; i++) {
                    if (i == 0 || i == Tamanho) {
                        break;
                    }
                    for (int z = Coluna; Minas[i][z] != 'B'; z--) {
                        if (z == 0 || z == Tamanho) {
                            break;
                        }
                        Tabuleiro[i][z] = Minas[i][z];
                    }
                    
                }
                //Varredura Culuna Direita // Linha Cima
                for (int i = Linha; Minas[i][Coluna] != 'B'; i--) {
                    if (i == Tamanho || i == 0) {
                        break;
                    }
                    for (int z = Coluna; Minas[i][z] != 'B'; z++) {
                        if (z == 0 || z == Tamanho) {
                            break;
                        }
                        Tabuleiro[i][z] = Minas[i][z];
                    }
                    
                }
            }
            if (Minas[Linha][Coluna] != '0' && Minas[Linha][Coluna] != 'B') {
                Tabuleiro[Linha][Coluna] = Minas[Linha][Coluna];
            }
            
        }
        
        
        
        
        if(Opcao == 2 && Minas[Linha][Coluna] == 'B' ){
            Vida--;
            printf("\n\nBOOMMMMM!!! Você pisou em uma mina! Acaba de perder uma vida, ainda restam %d vida(s). \n\n\n",Vida);
        }
        
        
        
        
        
        //-------------------------- Mostrar a Matriz do Tabuleiro --------------------------
        
        
        //Mostrar o numero de Colunas do Tabuleiro
        Cont = 0;
        for (int i = 0; i < 10; i++) {
            printf(" %d ",Cont);
            Cont++;
        }
        for (int i = 0; i < Tamanho - 10; i++) {
            printf(" %d",Cont);
            Cont++;
        }
        printf("\n");
        
        
        //Mostrar o numero de Linhas do Tabuleiro
        Cont = 0;
        for(int i = 0; i < Tamanho ; i++){
            for(int j = 0 ; j < Tamanho ; j++){
                printf(" %c ",Tabuleiro[i][j]);
            }
            printf(" | %d",Cont);
            Cont++;
            printf("\n");
        }
        printf("\n\n");
        
        
    }while(Vida > 0);
    
    
    printf("\n\nASSIM COMO NA VIDA SEU LIXO, VOCÊ PERDEU...      G A M E   O V E R \n\n\n");
    
    
    //--------------------------Mostrar a Matriz das Bombas--------------------------
    
    
    
    
    //Mostrar numero de Colunas das Bombas
    Cont = 0;
    for (int i = 0; i < 10; i++) {
        printf(" %d ",Cont);
        Cont++;
    }
    for (int i = 0; i < Tamanho - 10; i++) {
        printf(" %d",Cont);
        Cont++;
    }
    printf("\n");
    
    //Mostrar numero de Linhas das Bombas
    Cont = 0;
    
    for(int i = 0; i < Tamanho ; i++){
        for(int j = 0 ; j < Tamanho ; j++){
            printf(" %c ",Minas[i][j]);
        }
        printf(" | %d",Cont);
        Cont++;
        printf("\n");
    }
    
    
    
    return 0;
    
}
