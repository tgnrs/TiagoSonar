#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;
int history[5];
int position = 0;
int zero = 0;

int game(){
    int guess; 
    int match;
    int attempt = 1;
    int secret = 1 + (rand() % 1);
    do {
        printf("Eu escolhi um numero!! Tente adivinhar esse numero de 1 a 100\n");
        scanf("%d", &guess);
        if(guess > secret){
            printf("Muito alto! Tente um valor mais baixo\n");
        }else if(guess < secret){
            printf("Muito baixo! Tente um valor mais alto!\n");
        }else if(guess == secret){
            printf("\nParabens, voce acertou em [%d] tentativas!", attempt);
        }
        attempt++; 
        }    
    while (guess != secret);

    if(position >= 5){
        for (i = 0; i < 5; i++){
            history[i-1] = history[i];        
        }
        history[4] = attempt;
    } else {
        history[position] = attempt;
    }

    position++;

    return attempt;
    }

int menu(){
    int option;
    printf("\nOla, seja bem vindo! Selecione uma opcao abaixoooooo: \n 1 - Novo Jogo\n 2 - Ver Historico \n 3 - Limpar Historico (alpha)\n 4 - Sair\n");
    scanf("%d", &option);
    return option;
}

int main(){

    srand(time(NULL));
    int option, attempt = 1;
    int finished = 0;
    
    while(finished == 0) {
        option = menu();
        switch (option){
            case 1:
                attempt = game();
                break;
            case 2:
            printf("Ultimos jogos \n");
            if(position > 0){
                for (i = 0; i < 5; i++){
                    if(history[i] != zero) {
                        printf(" #%d -> %d \n", i + 1, history[i] - 1);
                    }
                }
            }
                break;
            case 3:
               position = 0;
               for(i = 0; i < 5; i++){
                   history[0] = zero;
                   history[1] = zero;
                   history[2] = zero;
                   history[3] = zero;
                   history[4] = zero;
               }
                break;
            case 4:
                finished = 1;
                break;
            default:
                printf("\n--------Digite uma opcao valida!----------");
        }
    }
    return 0;
}
