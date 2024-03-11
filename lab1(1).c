#include <stdio.h>

struct produs_cosmetic {
    char nume[30];
    int an;
    char brand[10];
    char tip[10];
    int cantitate;
    char review[100];
};

void read_data(struct produs_cosmetic pc[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Numele produsului cosmetic %d : ", i + 1);
        scanf("%s", pc[i].nume);
        printf("Anul lansarii produsului %d : ", i + 1);
        scanf("%d", &pc[i].an);

        printf("Brandul produsului %d : ", i + 1);
        scanf("%s", pc[i].brand);

        printf("Tipul produsului %d : ", i + 1);
        scanf("%s", pc[i].tip);

        printf("Cantitatea produsului %d : ", i + 1);
        scanf("%d", &pc[i].cantitate);

        printf("Review pentru produsul %d : ", i + 1);
        scanf("%s", pc[i].review);
    }
}

void print(struct produs_cosmetic pc[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nInformatii despre produsul cosmetic %d:\n", i + 1);
        printf("Nume: %s\n", pc[i].nume);
        printf("Anul lansarii: %d\n", pc[i].an);
        printf("Brand: %s\n", pc[i].brand);
        printf("Tip: %s\n", pc[i].tip);
        printf("Cantitate: %d\n", pc[i].cantitate);
        printf("Review: %s\n", pc[i].review);
    }
}

void search_by_year(struct produs_cosmetic pc[], int n, int an) {
    for (int i = 0; i < n; i++) {
        if (an == pc[i].an) {
            printf("\nInformatii despre produsul cosmetic gasit: Nr. %d \n", i + 1);
            printf("Nume: %s\n", pc[i].nume);
            printf("Anul lansarii: %d\n", pc[i].an);
            printf("Brand: %s\n", pc[i].brand);
            printf("Tip: %s\n", pc[i].tip);
            printf("Cantitate: %d\n", pc[i].cantitate);
            printf("Review: %s\n", pc[i].review);
        }
    }
}

int main() {
    int n;

    printf("Introduceti numarul de produse cosmetice: ");
    scanf("%d", &n);

    struct produs_cosmetic pc[n];

    read_data(pc, n);

    print(pc, n);

    int an_cautare;
    printf("Cauta dupa anul de lansare al produsului cosmetic: ");
    scanf("%d", &an_cautare);
    search_by_year(pc, n, an_cautare);

    return 0;
}
