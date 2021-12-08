#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Função de cálculo dos limites de tolerância, com 2 parâmetros (p, imp) que são, respetivamente, a tolerância (valores de 0,1 a 5 %)
 e a impedância introduzida, nomeadamente, o valor que o utilizador procura atingir com a junção de resistências, e com dois pointers 
 limi (limite inferior) e lims (limite superior)
*/

void toll(float p, float imp, float* limi, float* lims) {     //calcula os limites da margem de tolerancia
    float perc;
    perc = imp * p / 100;
    *limi = imp - perc; // Aqui definimos o * antes da variável para buscar o valor armazenado no pointer 
    *lims = imp + perc;
}

int main() {       

// Declaração de variáveis e respetiva explicação

    float imp;     // Impedancia introduzida
    float tol;      // Valores de tolerancia [0,1 - 5]% 
    int tola;       // Tolerancia aceitavel 
    int i, j, k, l;       // Variáveis a ser usadas nos loops
    char impiv;      // Verifica a disponibilidade das tolerâncias (nomeadamente se o valor pretendido pelo usuário pode ser atingido por um resistor existente no laboratório).
    char exi;       // pergunta se a impedancia pretendida esta disponivel (Caso a resposta seja não (n para abreviar), corremos o programa para achar a junções possíveis.)
    exi = 'n';     // inicializaçao de exi
    float limi, lims; // limites da tolerancia
    int impd[13] = { 0,100,200,330,470,680,1000,2000,3300,4700,6800,33000,100000 };  // declaracao dos valores de impedancia disponiveis                                                                       //int r1, r2, r3, r4, r5, r6, r7, r8;  // variavel para testar redundancia
    char repeat;


    printf("Estes sao os valores de impedancia disponiveis: \n");
    printf("100, 200, 330, 470, 680, 1k, 2k, 3.3k, 4.7k, 6.8k, 33k, 100k\n\n"); // Introdução dos valores disponíveis ao utilizador  
    printf("O valor de impedancia pretendido esta disponivel s/n ?\n"); // 
    scanf("%c", &exi);

    if (exi == 's') { return 0; }  // Acaba o programa com exit code: 0

    else {                         // Corre o programa de o valor de impedancia pretendido não existir em laboratório
        do {
            impiv = 'n';        // Inicialização da variável
            printf("\n Introduza a impedancia a obter: \n"); // Introdução do valor de impedancia a obter 
            scanf("%f", &imp);

            for (i = 12; i >= 0; i--) {    // verifica se a impedancia a obter esta disponivel (para o caso de alguem nao saber ler a pergunta a cima
                if (impd[i] == imp) {
                    impiv = 's';
                    printf("Esse valor esta disponivel \n");
                    return 0;
                }
                else { impiv = 'n'; }
            }
        } while (impiv == 's');

        do {             // Loop da introdução do valor da tolerancia, até este respeitar a condição (0.1% < tol < 5%)
            tola = 0;                                                             // inicialização da variável 'tola' com o valor inicial de 0
            printf("Introduza um valor de tolerancia contido no seguinte intervalo[0,1 ; 5]: \n");
            scanf("%f", &tol);
            if (tol <= 5 && tol >= 0.1) {
                tola = 1;
                printf("O seu valor de tolerancia é: %g.\n\n", tol);
            }
            else {
                printf("O valor de tolerancia introduzido nao se encontra no limite, introduza outro valor de tolerancia.\n\n");
            }
        } while (tola == 0);

        printf("Pode usar as seguintes resistencias em serie \n\n");        
        for (i = 12; i >= 0; i--) {                  // Verifica em serie grupos de 4 resistências
            for (j = i; j >= 0; j--) {
                for (k = j; k >= 0; k--) {
                    for (l = k; l >= 0; l--) {
                        toll(tol, imp, &limi, &lims);       // determina o limite da tolerancia
                        if ((impd[i] + impd[j] + impd[k] + impd[l]) >= limi && (impd[i] + impd[j] + impd[k] + impd[l]) <= lims) {
                            printf("  %d, %d, %d, %d  \n\n ", impd[j], impd[i], impd[k], impd[l]);
                        } 
                    }
                }
            }
        }

        for (i = 12; i >= 0; i--) {                  //verifica em paralelo grupos de 4 resistências
            for (j = i; j >= 0; j--) {
                for (k = j; k >= 0; k--) {
                    for (l = k; l >= 0; l--) {
                        toll(tol, imp, &limi, &lims);       // determina o limite da tolerancia
                        if ((1.0 / ((1.0 / impd[i]) + (1.0 / impd[j]) + (1.0 / impd[k]) + (1.0 / impd[l]))) >= limi && (1.0 / ((1.0 / impd[i]) + (1.0 / impd[j]) + (1.0 / impd[k]) + (1.0 / impd[l]))) <= lims) {
                            printf("Pode usar estas resistencias em paralelo \n\n %d, %d, %d, %d  \n\n", impd[j], impd[i], impd[k], impd[l]);
                        }
                    }
                }
            }
        }

     /*   O que foi feito nestes loops foi o seguinte.
        Não queremos redundância, apenas queremos que o programa seja rápido e eficaz, assim sendo, é ilógico compararmos, por ex., a primeira resistência com a segunda,
         quando fazes 1->n e voltarmos a fazer a mesma coisa quando comparamos a segunda com a anterior. Não há essa necessidade visto que a comparação já aconteceu,
          Assim sendo, usei nested loops em que a variável inicial, é igual ao valor da do loop anterior, resolvendo assim este problema.*/
    }
}