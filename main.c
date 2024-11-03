#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int MIN = 0;

    int MAX = 0;

    int n, num, vite, diff;
    printf("    Benvenuto su:\n");
    printf("--||GUESS THE NUMBER||--\n");

    printf("|1| -Facile-\n");
    printf("|2| -Medio-\n");
    printf("|3| -Difficile-\n");
    printf("|4| -Impossibile- (per i piu' coraggiosi);\n");
    printf("seleziona la difficoltà con cui preferisci giocare:");
    scanf("%d", &diff);
    printf("\n");
    switch (diff) {
        case 1:
            MIN = 0;
            MAX = 10;
            vite = 5;
            srand(time(NULL/*oppure 0*/));
            n = rand() % (MAX - MIN + 1) + MIN;
            break;
        case 2:
            MIN = 0;
            MAX = 25;
            vite = 3;
            srand(time(NULL/*oppure 0*/));
            n = rand() % (MAX - MIN + 1) + MIN;
            break;
        case 3:
            MIN = 0;
            MAX = 50;
            vite = 2;
            srand(time(NULL/*oppure 0*/));
            n = rand() % (MAX - MIN + 1) + MIN;
            break;
        default:
            MIN = 0;
            MAX = 200;
            vite = 1;
            srand(time(NULL/*oppure 0*/));
            n = rand() % (MAX - MIN + 1) + MIN;
            break;
    }
    printf("vite a disposizione %d\n\n", vite);
    do {
        printf("inserisci il numero generato in modo casuale tra %d e %d: ", MIN, MAX);
        scanf("%d", &num);
        if (num < MIN || num > MAX) {
            printf("il numero non e' compreso tra %d e %d.\n", MIN, MAX);
        } else if (num < n) {
            printf("il numero da indovinare e' piu' grande %d\n", num);
            vite--;
        } else if (num > n) {
            printf("il numero da indovinare e' piu' piccolo %d\n", num);
            vite--;
        } else /*if (num == n) */ {
            printf("hai indovinato\n");
        }
        if (vite == 0) {
            printf("--||GAME OVER||--\n");
            printf("il numero generato era %d", n);
            break;
        } else {
            printf(" Vite rimanenti %d\n", vite);
        }
    } while (num != n);
    return 0;
}
