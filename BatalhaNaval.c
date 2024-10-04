#include <stdio.h>

int main() {
    //Tamanho do tabuleiro 10x10
    const int tamanho = 10;

    //Criação do tabuleiro vazio
    int tabuleiro[tamanho][tamanho];

    //Inicialização do tabuleiro com 0 (sem navios)
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    } 

    //Posicionamento de um navio verticalmente (coluna 1)
    for(int i = 0; i < 3; i++) {
        tabuleiro[i][1] = 3; //3 indica uma posição ocupada por um navio
        printf("Navio vertical em: (%d, 1)\n", i);
    }

    //Posicionamento de um navio verticalmente (coluna 2)
    for(int i = 0; i < 4; i++) {
        tabuleiro[i][2] = 3;
    }

    //Posicionamento de um navio horizontalmente (linha 3)
    for(int j = 0; j < 4; j++) {
        tabuleiro[3][j] = 3;
        printf("Navio horizontal em: (3, %d)\n", j);
    }

    //Posicionamento de um navio verticalmente (coluna 5)
    for(int j = 0; j < 5; j++) {
        tabuleiro[5][j] = 3;
    }    
    
    // Posicionamento de navios na diagonal principal (canto superior esquerdo para canto inferior direito)
    for(int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Posicionamento de navio na diagonal secundária (canto superior direito para canto inferior esquerdo)
    for(int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }    
    
    //Exibição do tabuleiro completo
    printf("Tabuleiro de Batalha Naval: \n");
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    void habilidade_cone(int matriz[5][5]) {
        printf("Habilidade: Cone\n");
        matriz[0][2] = 1;
        matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
        for (int j = 0; j < 5; j++) {
            matriz[2][j] = 1;
        }
    }
    
    void habilidade_cruz(int matriz [5][5]) {
        printf("Habilidade: Cruz\n");
        for(int i = 0; i < 5; i++) {
            matriz[i][2] = 1;
        }
        for(int j = 0; j < 5; j++) {
            matriz[2][j] = 1;
        }
    }

    void habilidade_octaedro(int matriz[5][5]) {
        printf("Habilidade: Octaedro\n");
        matriz[0][2] = 1;
        matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
        matriz[2][2] = 1;
    }

    void exibir_matriz(int matriz[5][5]) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }
    }

    int main() {
        int matriz[5][5] = {0}; //Inicializa a matriz com 0 (sem áreas afetadas)

        //Testando a habilidade de cone
        habilidade_cone(matriz);
        exibir_matriz(matriz);
        printf("\n");

        //Resetando a matriz para testar a cruz
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matriz[i][j] = 0;
            }
        }

        //Testando a habilidade de cruz
        habilidade_cruz(matriz);
        exibir_matriz(matriz);
        printf("\n");

        //Resetando a matriz para testar o octaedro
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matriz[i][j] = 0;
            }
        }
        
        //Testando a habilidade de octaedro
        habilidade_octaedro(matriz);
        exibir_matriz(matriz);

    
    }
    return 0;
}