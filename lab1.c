#include <stdio.h>
#include <stdlib.h>

struct produs_cosmetic {
    char nume[30];
    int an;
    char brand[30];
    char tip[20];
    float pret;
    char review[100];
};

void delete(struct produs_cosmetic **pc, int *num, int *poz) {
    for (int i = *poz - 1; i < *num; i++) {
        (*pc)[i] = (*pc)[i + 1];
    }
    (*num)--;
    *pc = realloc(*pc, (*num) * sizeof(struct produs_cosmetic));
    printf("Produs cosmetic eliminat cu succes\n");
}

void add(struct produs_cosmetic **pc, int *num) {
    (*num)++;
    *pc = realloc(*pc, (*num) * sizeof(struct produs_cosmetic));
    printf("Introduceți informațiile pentru noul produs cosmetic:\n");
    printf("\nNume Produs Cosmetic: ");
    scanf("%s", (*pc)[*num - 1].nume);
    printf("Anul lansării: ");
    scanf("%d", &(*pc)[*num - 1].an);
    printf("Brand: ");
    scanf("%s", (*pc)[*num - 1].brand);
    printf("Tip: ");
    scanf("%s", (*pc)[*num - 1].tip);
    printf("Pret: ");
    scanf("%f", &(*pc)[*num - 1].pret);
    printf("Review: ");
    scanf("%s", (*pc)[*num - 1].review);
    printf("\nProdus cosmetic nou adăugat cu succes\n");
}

void add_poz(struct produs_cosmetic **pc, int *num, int *poz) {
    (*num)++;
    *pc = realloc(*pc, (*num) * sizeof(struct produs_cosmetic));
    for (int i = *num - 1; i > *poz - 1; i--) {
        (*pc)[i] = (*pc)[i - 1];
    }
    printf("Introduceți informațiile pentru noul produs cosmetic:\n");
    printf("\nNume Produs Cosmetic la poziția %d: ", *poz);
    scanf("%s", (*pc)[*poz - 1].nume);
    printf("Anul lansării: ");
    scanf("%d", &(*pc)[*poz - 1].an);
    printf("Brand: ");
    scanf("%s", (*pc)[*poz - 1].brand);
    printf("Tip: ");
    scanf("%s", (*pc)[*poz - 1].tip);
    printf("Pret: ");
    scanf("%f", &(*pc)[*poz - 1].pret);
    printf("Review: ");
    scanf("%s", (*pc)[*poz - 1].review);
    printf("\nProdus cosmetic nou adăugat cu succes la poziția %d\n", *poz);
}

void add_begin(struct produs_cosmetic **pc, int *num) {
    (*num)++;
    *pc = realloc(*pc, (*num) * sizeof(struct produs_cosmetic));
    for (int i = *num - 1; i > 0; i--) {
        (*pc)[i] = (*pc)[i - 1];
    }
    printf("Introduceți informațiile pentru noul produs cosmetic:\n");
    printf("\nNume Produs Cosmetic: ");
    scanf("%s", (*pc)[0].nume);
    printf("Anul lansării: ");
    scanf("%d", &(*pc)[0].an);
    printf("Brand: ");
    scanf("%s", (*pc)[0].brand);
    printf("Tip: ");
    scanf("%s", (*pc)[0].tip);
    printf("Pret: ");
    scanf("%f", &(*pc)[0].pret);
    printf("Review: ");
    scanf("%s", (*pc)[0].review);
    printf("\nProdus cosmetic nou adăugat cu succes la început\n");
}

void sort_by_year(struct produs_cosmetic *pc, int num) {
    struct produs_cosmetic temp;
    for (int j = 0; j < num - 1; j++) {
        for (int i = 0; i < num - 1; i++) {
            if (pc[i].an > pc[i + 1].an) {
                temp = pc[i + 1];
                pc[i + 1] = pc[i];
                pc[i] = temp;
            }
        }
    }
}

void print(struct produs_cosmetic *pc, int num) {
    for (int i = 0; i < num; i++) {
        printf("\nInformații despre produsul cosmetic %d:", i + 1);
        printf("\nNume: %s", pc[i].nume);
        printf("\nAnul lansării: %d", pc[i].an);
        printf("\nBrand: %s", pc[i].brand);
        printf("\nTip: %s", pc[i].tip);
        printf("\nPret: %.2f", pc[i].pret);
        printf("\nReview: %s \n", pc[i].review);
    }
}

void search_by_year(struct produs_cosmetic *pc, int num, int an) {
    for (int i = 0; i < num; i++) {
        if (an == pc[i].an) {
            printf("\nInformații despre produsul cosmetic găsit (Numărul %d): \n", i + 1);
            printf("Nume: %s\n", pc[i].nume);
            printf("Anul lansării: %d\n", pc[i].an);
            printf("Brand: %s\n", pc[i].brand);
            printf("Tip: %s\n", pc[i].tip);
            printf("Pret: %.2f\n", pc[i].pret);
            printf("Review: %s\n", pc[i].review);
        }
    }
}

int main() {
    int optiune, numProduse, an, pozitie;
    struct produs_cosmetic *produse;

    printf("\nMeniu:\n");
    printf("1. Creare tablou de produse cosmetice\n");
    printf("2. Afișare elemente\n");
    printf("3. Cautare element\n");
    printf("4. Eliberare memorie\n");
    printf("5. Sortare elemente\n");
    printf("6. Inserare la capat\n");
    printf("7. Inserare la inceput\n");
    printf("8. Inserare la o anumita pozitie\n");
    printf("9. Stergere element de la o anumita pozitie\n");
    printf("0. Iesire\n");

    do {
        printf("Introduceți opțiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceți numărul de produse cosmetice: ");
                scanf("%d", &numProduse);
                produse = (struct produs_cosmetic *)malloc(numProduse * sizeof(struct produs_cosmetic));
                break;
            case 2:
                print(produse, numProduse);
                break;
            case 3:
                printf("\nIntroduceți anul pentru a căuta un produs cosmetic: ");
                scanf("%d", &an);
                search_by_year(produse, numProduse, an);
                break;
            case 4:
                free(produse);
                printf("Memoria a fost eliberată cu succes!");
                break;
            case 5:
                sort_by_year(produse, numProduse);
                printf("\n\nProduse sortate după anul de lansare\n\n");
                break;
            case 6:
                add(&produse, &numProduse);
                break;
            case 7:
                add_begin(&produse, &numProduse);
                break;
            case 8:
                printf("\nIntroduceți poziția: \n");
                scanf("%d", &pozitie);
                add_poz(&produse, &numProduse, &pozitie);
                break;
            case 9:
                printf("\nIntroduceți poziția: \n");
                scanf("%d", &pozitie);
                delete(&produse, &numProduse, &pozitie);
                break;
        }
    } while (optiune != 0);

    return 0;
}
