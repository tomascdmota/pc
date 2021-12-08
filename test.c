#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX_VALS 30000
#define MAX_STR 100
#define n_vals 12

float valores[MAX_VALS] = { 100,220,330,470,680,1000,2000,3300,4700,6800,33000,100000 };//lista dos valores
char descricao[MAX_VALS][100];
float paralelo(float res1, float res2)//calcular resistências em paralelo
{
    float resp;
    resp = (res1 * res2) / (res1 + res2);
    return resp;
}

float serie(float res1, float res2)//calcular resistências em série
{
    float ress;
    ress = (res1 + res2);
    return ress;
}
float paralelo4(float res1, float res2, float res3, float res4)//calcular resistências em paralelo em 4
{
    float resp;
    resp = (res1 * res2 * res3 * res4) / (res1 + res2 + res3 + res4);
    return resp;
}
float paralelo3(float res1, float res2, float res3)//calcular resistências em paralelo em 3
{
    float resp;
    resp = (res1 * res2 * res3) / (res1 + res2 + res3);
    return resp;
}

int main()
{
    float x,y,z;
    for (int i = 0; i < n_vals; i++)
    {
        for (int j = 0; j < n_vals; j++)
        {
            for (int k = 0; k < n_vals; k++)
            {
                for (int l = 0; l < n_vals; l++)
                {
                    x = paralelo(valores[i], valores[j]);
                    printf("%f = %f || %f\n", x, valores[i], valores[j]);
                    y = paralelo3(valores[i], valores[j], valores[k]);
                    printf("%f = %f || %f || %f\n", x, valores[i], valores[j],valores[k]);
                    z= paralelo4(valores[i], valores[j], valores[k], valores[l]);
                    printf("%f = %f || %f || %f || %f\n", x, valores[i], valores[j], valores[k],valores[l]);

                }
          
            }
        }
    }
    for (int i = 0; i < n_vals; i++)
    {

        for (int j = 0; j < n_vals; j++)
        {
            x = serie(valores[i], valores[j]);
            printf("%f = %f + %f\n", x, valores[i], valores[j]);
        }
    }
}