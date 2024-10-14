#include "Desenho.h"

/*
 Inicializa srand, gera o quadro e chama a função menu.
*/

int main(){

    srand(time(NULL));
    char matrizAsteristico[20][80];

    memset(matrizAsteristico, ' ', sizeof(matrizAsteristico));

    for(int i = 0; i < 20; i ++){
    matrizAsteristico[i][0] = '|';
    matrizAsteristico[i][79] = '|';
    }

    for(int i = 0; i < 80; i ++){
    matrizAsteristico[0][i] = '-';
    matrizAsteristico[19][i] = '-';
    }

    menu(matrizAsteristico);

    return 0;
}