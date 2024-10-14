#include "Desenho.h"

/*As 5 funções que geram as figuras no quadro.
Parametros geral: char matrizAsterisco[20][80] = Representa o quadro e todas as suas posições.
                  int N = Numero de figuras escolhida pelo usuario.

Logica geral: Logica que gera posições aleatorias para a matrizAsterisca. Adequada a cada função/figura.
              Há uma logica condicional, que impede que posições sejam sobrepostas ou que ultrapassem o limite do "quadro".
*/


/*
Função: Atribui o caractere '*', a uma posição aleatoria da matrizAterisco, caso esta posição esteja "vazia". 
*/
void asteriscoSimples(char matrizAsterisco[20][80], int N){
    char aux = '*';
    int min1 = 1, max1 = 18; 
    int min2 = 1, max2 = 78;
    int numAleatorio,numAleatorio2;
    
    for(int a = 0; a < N; a ++){ 
     do {
        numAleatorio = (rand() % (max1 - min1 + 1)) + min1;   // Linha aleatória
        numAleatorio2 = (rand() % (max2 - min2 + 1)) + min2;  // Coluna aleatória
    } while (matrizAsterisco[numAleatorio][numAleatorio2] == '*');

   matrizAsterisco[numAleatorio][numAleatorio2] = aux;
   }
}

/*
Função: Atribui o caractere '*', a posições da matrizAterisco, de forma que formem uma figura "+" quando impresso na tela.
*/

void maisAsterisco(char matrizAsterisco[20][80], int N){
   char aux = '*';
   int min1 = 2, max1 = 17; 
   int min2 = 2, max2 = 77;
   int linhaA,colunaA;

   for(int a = 0;a < N; a ++){ 
     do {
        linhaA = (rand() % (max1 - min1 + 1)) + min1;   // Linha aleatória
        colunaA = (rand() % (max2 - min2 + 1)) + min2;  // Coluna aleatória
    } while (matrizAsterisco[linhaA][colunaA] != ' '||
            matrizAsterisco[linhaA + 1][colunaA] != ' ' || 
            matrizAsterisco[linhaA - 1][colunaA] != ' ' || 
            matrizAsterisco[linhaA][colunaA + 1] != ' ' || 
            matrizAsterisco[linhaA][colunaA - 1] != ' ');
            
            matrizAsterisco[linhaA][colunaA] = aux;
            matrizAsterisco[linhaA +1][colunaA] = aux;
            matrizAsterisco[linhaA -1][colunaA] = aux;
            matrizAsterisco[linhaA][colunaA +1] = aux;
            matrizAsterisco[linhaA][colunaA -1] = aux;

     }  
}

/*
Função: Atribui o caractere '*', a posições da matrizAterisco, de forma que formem uma figura "X" quando impresso na tela.
*/

void letraXAsterisco(char matrizAsterisco[20][80], int N){
   char aux = '*';
   int min1 = 2, max1 = 17; 
   int min2 = 2, max2 = 77;
   int linhaA,colunaA;

   for(int a = 0;a < N; a ++){ 
     do {
        linhaA = (rand() % (max1 - min1 + 1)) + min1;   // Linha aleatória
        colunaA = (rand() % (max2 - min2 + 1)) + min2;  // Coluna aleatória
    } while (matrizAsterisco[linhaA][colunaA] != ' ' ||
            matrizAsterisco[linhaA + 1][colunaA +1] != ' ' || 
            matrizAsterisco[linhaA - 1][colunaA -1] != ' ' || 
            matrizAsterisco[linhaA -1][colunaA + 1] != ' ' || 
            matrizAsterisco[linhaA +1][colunaA - 1] != ' ');
     
            matrizAsterisco[linhaA][colunaA] = aux;
            matrizAsterisco[linhaA -1][colunaA -1] = aux;
            matrizAsterisco[linhaA +1][colunaA +1] = aux;
            matrizAsterisco[linhaA -1][colunaA +1] = aux;
            matrizAsterisco[linhaA +1][colunaA -1] = aux;
     }  

}

/*
Função: Dado um numero N de figuras, a função gera uma mistura de desenhos,chamando uma quantidade aleatoria 
        de vezes cada uma das funções, que geram figuras.
*/

void figurasAleatorias(char matrizAsterisco[20][80], int N)
{
    for(int a = 0; a < N; a++)
    {
        int aux = 1 + (rand() % 3);
    
        switch (aux)
        {
        case 1:
            asteriscoSimples(matrizAsterisco, 1);
            break;

        case 2:
            maisAsterisco(matrizAsterisco, 1);
        break;

        case 3:
            letraXAsterisco(matrizAsterisco, 1);
        break;
        
        default:
            break;
       
        }
    }

}

/*
Função: Atribui o caractere '*', a posições da matrizAterisco, que quando impresso, formam um desenho.
*/

void figuraEspecial(char matrizAsterisco[20][80], int N) {
    int min1 = 1, max1 = 16; 
    int min2 = 3, max2 = 76;
    int linhaA, colunaA, tentativasMax = 100, contagem = 0;

    for (int a = 0; a < N; a++) {
        int tentativas = 0;

        do {
            linhaA = (rand() % (max1 - min1 + 1)) + min1;   // Linha aleatória
            colunaA = (rand() % (max2 - min2 + 1)) + min2;  // Coluna aleatória
            tentativas++;
        } while ((matrizAsterisco[linhaA][colunaA] != ' ' ||
                 matrizAsterisco[linhaA][colunaA + 1] != ' ' || matrizAsterisco[linhaA][colunaA + 2] != ' ' ||
                 matrizAsterisco[linhaA][colunaA - 1] != ' ' || matrizAsterisco[linhaA][colunaA - 2] != ' ' ||
                 matrizAsterisco[linhaA + 1][colunaA + 1] != ' ' || matrizAsterisco[linhaA + 1][colunaA] != ' ' ||
                 matrizAsterisco[linhaA + 1][colunaA - 1] != ' ' || matrizAsterisco[linhaA + 1][colunaA - 2] != ' ' ||
                 matrizAsterisco[linhaA + 2][colunaA] != ' ' || matrizAsterisco[linhaA + 2][colunaA - 1] != ' ') &&
                 tentativas < tentativasMax);

        if (tentativas >= tentativasMax) {
            printf(" [ESPAÇO INSUFICIENTE]\n |Contagem de bonecos|:[%d]\n", a);
            break;
        }
        contagem++;
        if((contagem % 10 == 0) && (linhaA + colunaA) % 2 == 0){
            // Origem
            matrizAsterisco[linhaA][colunaA] = '*';
            // Cabeça
            matrizAsterisco[linhaA][colunaA + 1] = ')';
            matrizAsterisco[linhaA][colunaA + 2] = '>';
            matrizAsterisco[linhaA][colunaA - 1] = '(';
            matrizAsterisco[linhaA][colunaA - 2] = '<';
            // Corpo
            matrizAsterisco[linhaA + 1][colunaA + 1] = '~';
            matrizAsterisco[linhaA + 1][colunaA] = ')';
            matrizAsterisco[linhaA + 1][colunaA - 1] = '(';
            matrizAsterisco[linhaA + 1][colunaA - 2] = '~';
            // Pernas
            matrizAsterisco[linhaA + 2][colunaA] = '+';
            matrizAsterisco[linhaA + 2][colunaA - 1] = '+';

            }
        else if(contagem % 5 == 0){

            // Origem
            matrizAsterisco[linhaA][colunaA] = '-';
            // Cabeça
            matrizAsterisco[linhaA][colunaA + 1] = '^';
            matrizAsterisco[linhaA][colunaA + 2] = ')';
            matrizAsterisco[linhaA][colunaA - 1] = '^';
            matrizAsterisco[linhaA][colunaA - 2] = '(';
            // Corpo
            matrizAsterisco[linhaA + 1][colunaA + 1] = '>';
            matrizAsterisco[linhaA + 1][colunaA] = ')';
            matrizAsterisco[linhaA + 1][colunaA - 1] = '(';
            matrizAsterisco[linhaA + 1][colunaA - 2] = '/';
            // Pernas
            matrizAsterisco[linhaA + 2][colunaA] = '|';
            matrizAsterisco[linhaA + 2][colunaA - 1] = '|';

        }
        else{
            //origem
            matrizAsterisco[linhaA][colunaA] = '_';
            //Cabeça
            matrizAsterisco[linhaA][colunaA + 1] = '-';
            matrizAsterisco[linhaA][colunaA + 2] = ')';
            matrizAsterisco[linhaA][colunaA - 1] = '-';
            matrizAsterisco[linhaA][colunaA - 2] = '(';
            //Corpo
            matrizAsterisco[linhaA + 1][colunaA + 1] = '>';
            matrizAsterisco[linhaA + 1][colunaA] = ')';
            matrizAsterisco[linhaA + 1][colunaA - 1] = '(';
            matrizAsterisco[linhaA + 1][colunaA - 2] = '/';
            //Perna
            matrizAsterisco[linhaA + 2][colunaA] = '|';
            matrizAsterisco[linhaA + 2][colunaA - 1] = '|';
            }
    }
}

/*
Função: (Auxiliar) Imprimi posição por posição da matrizAsterisco, para formar o quadro.
*/

void ImprimirQuadro(char matrizAsterisco[20][80]){
   for(int i = 0; i < 20; i ++){
        for(int j =0; j < 80; j ++){
            printf("%c", matrizAsterisco[i][j]);void figuraAleatoria(char matrizAsterisco[20][80], int N);
        }
        printf("\n");
    }void figuraAleatoria(char matrizAsterisco[20][80], int N);
}

/*
Função: (Auxiliar) Limpa o quadro, atribuindo a cada posição da matrizAsterisco (' ') .
*/

void LimparQuadro(char matrizAsterisco[20][80]){
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 79; j++) {
            matrizAsterisco[i][j] = ' ';
        }
    }

}

/*
Função: (Menu) Gera a interface interativa, para que o programa possa funcioar.
*/

void menu(char matrizAsterisco[20][80]){
 printf("            \n          [PROGRAMA GERADOR DE OBRA DE ARTE] \n"
         "|================================================================|\n"
         "|Escolha o tipo de figura basica a ser usada para criar a obra:  |\n"
         "|[1] - Asterisco simples.                                        |\n"
         "|[2] - Simbolo de soma com asteriscos.                           |\n"
         "|[3] - Letra X com asteriscos.                                   |\n"
         "|[4] - Figuras aleatorias                                        |\n"
         "|[5] ou [Outro] - Especial                                       |\n"
         "|================================================================|\n");
      printf("Digite o tipo de figura :");
      int escolha, auxLoop = 0, qntdF;
      scanf("%d",&escolha);
      printf("\nDigite a quantidade de figuras - [Para quantidade aleatoria digite 0 ou menor]:");
      scanf("%d",&qntdF);

      if(qntdF > 100){
         qntdF = 100;
      }
      if(qntdF <= 0){
       qntdF = (rand() % 100) + 1;
      }

      switch (escolha)
      {
      case 1:
         while(auxLoop == 0){
         asteriscoSimples(matrizAsterisco, qntdF);
         ImprimirQuadro(matrizAsterisco);
         printf("Novo quadro? [0]-> Sim - [Outro]-> Não\n");
         scanf("%d", &auxLoop);
         if(auxLoop == 0){
            LimparQuadro(matrizAsterisco);
         }
         }
         break;
      
      case 2:
         while(auxLoop == 0){
         maisAsterisco(matrizAsterisco, qntdF);
         ImprimirQuadro(matrizAsterisco);
         printf("Novo quadro? [0]-> Sim - [Outro]-> Não\n");
         scanf("%d", &auxLoop);
         if(auxLoop == 0){
            LimparQuadro(matrizAsterisco);
         }
         }
         break;
      
      case 3:
         while(auxLoop == 0){
         letraXAsterisco(matrizAsterisco, qntdF);
         ImprimirQuadro(matrizAsterisco);
         printf("Novo quadro? [0]-> Sim - [Outro]-> Não\n");
         scanf("%d", &auxLoop);
         if(auxLoop == 0){
            LimparQuadro(matrizAsterisco);
         }
         }
         break;
      
      case 4:
         while(auxLoop == 0){
         
         figurasAleatorias(matrizAsterisco,qntdF);
         ImprimirQuadro(matrizAsterisco);
         printf("Novo quadro? [0]-> Sim - [Outro]-> Não\n");
         scanf("%d", &auxLoop);
         if(auxLoop == 0){
            LimparQuadro(matrizAsterisco);
         }
         }
         break;
      
      default:
         while(auxLoop == 0){
         figuraEspecial(matrizAsterisco, qntdF);
         ImprimirQuadro(matrizAsterisco);
         printf("Novo quadro? [0]-> Sim - [Outro]-> Não\n");
         scanf("%d", &auxLoop);
         if(auxLoop == 0){
            LimparQuadro(matrizAsterisco);
         }
         }
         break;
      }

}
