#include <stdio.h>
 
int main() {
    int nMoedas, i, salto, soma, isPrime;
    
    while (scanf(" %d", &nMoedas) != EOF) {
            i = 0;
    
            int valorMoedas[nMoedas];
            
            while (i < nMoedas) {
                scanf(" %d", &valorMoedas[i]);
                i++;
            };
            
            soma = 0;
            i = 0;
            
            scanf(" %d", &salto);
            
            do {
                soma = soma + valorMoedas[i];
                i = i + salto;
            } while (i < nMoedas);
            
            isPrime = 0;
            
            for (i = 2; i < soma/2; i++) {
                if (soma % i == 0) {
                    isPrime++;
                    break;
                };
            };
            
            if (isPrime == 0)
                printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
            else 
                printf("Bad boy! I’ll hit you.\n");
    }
 
    return 0;
}