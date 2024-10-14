#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//Funções que geram as figuras.
void asteriscoSimples(char matrizAsterisco[20][80], int N);
void maisAsterisco(char matrizAsterisco[20][80], int N);
void letraXAsterisco(char matrizAsterisco[20][80], int N);
void figurasAleatorias(char matrizAsterisco[20][80], int N);
void figuraEspecial(char matrizAsterisco[20][80], int N);

//Funções auxiliares e menu.
void ImprimirQuadro(char matrizAsterisco[20][80]);
void LimparQuadro(char matrizAsterisco[20][80]);
void menu(char matrizAsterisco[20][80]);

