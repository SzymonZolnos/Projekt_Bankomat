#include <stdio.h>


void wyswietlMenu() {
    printf("(  -MENU-  )\n");
    printf("1. Sprawdz saldo\n");
    printf("2. Wplata\n");
    printf("3. Wyplata\n");
    printf("4. Zakoncz\n");
    printf("Wybierz opcje: ");
}


void sprawdzSaldo(float saldo) {
    printf("\nTwoje saldo wynosi: %.2f\n", saldo);
}


void wplata(float *saldo) {
    float kwota;
    printf("\nPodaj kwote do wplaty: ");
    scanf("%f", &kwota);
    if (kwota > 0) {
        *saldo += kwota;
        printf("Wplata zakonczona pomyslnie.\n");
    } else
        printf("Nieprawidlowa kwota.\n");
}



void wyplata(float *saldo) {
    float kwota;
    printf("\nPodaj kwotę do wyplaty: ");
    scanf("%f", &kwota);
    if (kwota > 0 && kwota <= *saldo) {
        *saldo -= kwota;
        printf("Wyplata zakonczona pomyslnie.\n");
    } else {
        printf("Nieprawidłowa kwota lub niewystarczające srodki.\n");
    }
}

int main() {
    float saldo = 1000.00;
    int opcja;

    do {
        wyswietlMenu();
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                sprawdzSaldo(saldo);
                break;
            case 2:
                wplata(&saldo);
                break;
            case 3:
                wyplata(&saldo);
                break;
            case 4:
                printf("Dziekujemy za skorzystanie z naszego bankomatu.\n");
                break;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
        }
    } while (opcja != 4);

    return 0;
}