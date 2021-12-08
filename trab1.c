#include <stdio.h>

#define MAX_VALS 40000



float valores[] = { 100,200,330,470,680,1000,2000,3300,4700,6800,33000,100000 };
//char descricao[][100];

float serie(int r1, int r2) {
    float rs;
    rs = r1 + r2;
    return rs;
}

float paralelo(int r1, int r2) {
    float rp;
    rp = (r1 * r2) / (r1 + r2);
    return rp;
}


int main() {
    float OOMH, erro;
    printf("Introduza o valor de resistencia pretendida:");
    scanf("%f", &OOMH);
    do {
        printf("introduza a percentagem do erro:");
        scanf("%f", &erro);
        } 
    
    while (erro <= 0.1 && erro >= 5);

    erro = erro / 100;

    for (int i = 0; i < 12; i++) {

        for (int j = i; j < 12; j++) {
            float rs;
            
            for (int k = j; k < 12; k++) {
                for (int l = k; l < 12; l++) {
                    if (serie(paralelo(valores[i], valores[j]), paralelo(valores[k], valores[l])) >= OOMH*(1 - (erro * OOMH)) && serie(paralelo(valores[i], valores[j]), paralelo(valores[k], valores[l])) <= OOMH*(1 + (erro * OOMH))) {
                        printf("%.1f=(%.1f%.1f)+(%.1f||%.1f)\n", OOMH, valores[i], valores[j], valores[k], valores[l]);
                        
                    if (serie(valores[i], valores[j]) >= OOMH*(1-(erro * OOMH)) && serie(valores[i], valores[j]) <= OOMH*(1 + (erro * OOMH))) {
                        printf("%.1f=%.1f+%.1f\n", OOMH, valores[i], valores[j]);

                    if (paralelo(valores[i], valores[j]) >= OOMH*(1 - (erro * OOMH)) && paralelo(valores[i], valores[j]) <= OOMH*(1 + (erro * OOMH))) {
                        printf("%.1f=%.1f%.1f\n", OOMH, valores[i], valores[j]);
                            }
                            }
                        }
                }
            }
        }
    }
}
