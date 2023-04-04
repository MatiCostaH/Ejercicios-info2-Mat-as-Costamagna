#include <stdio.h>
#include <math.h>
#define N 5 

int main() {
    double monto;
    double principal = 1000.0;
    double tasa[N] = {5.0, 6.0, 8.0, 9.0, 10.0};
    
    int anio;
    
    printf("%4s %21s\n", "añio", "monto del deposito");
    
    for (int i = 0; i < N; i++) { 
        for (anio = 1; anio <= 10; anio++) {
            monto = principal * pow(1.0 + tasa[i]/100, anio); 
            printf("\n%4d %21.2f\n", anio, monto);
        }
        printf ("para la tasa de interes %f",tasa[i]);
    }
    
    return 0;
}
