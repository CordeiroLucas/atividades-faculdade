#include <stdio.h>
 
int main() {
    int nMoedas, i, salto, soma, isPrime;
    
    while (scanf(" %d", &nMoedas) != EOF) {
        if (nMoedas >= 2 && nMoedas <= 20) {
            i = 1;
    
            int valorMoedas[nMoedas];
            
            while (i <= nMoedas) {
                scanf(" %d", &valorMoedas[i]);
                i++;
            };
            
            soma = 0;
            i = nMoedas;
            
            scanf(" %d", &salto);
            if (salto >= 1 && salto <= nMoedas) {
                do {
                    soma = soma + valorMoedas[i];
                    i = i - salto;
                } while (i >= 1);
                
                isPrime = 0;
                
                for (i = 2; i < soma/2; i++) {
                    if (soma % i == 0) {
                        isPrime++;
                        break;
                    };
                };
                
                if (isPrime == 0)
                    return(printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n"));
                else 
                    printf("Bad boy! I’ll hit you.\n");
            }
        }
    }
 
    return 0;
}