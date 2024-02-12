//
// Created by МеredovN on 10.4.2023.
// Cline 2022.2.4
// For ZPRPR2 FIIT STU
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Presenter {
    char firstName[300];
    char lastName[300];
    char role[100];
    struct Presenter* next;
};
struct Id {
    char typ[3];
    char id[9];
};
struct Zoznam {
    struct Id id;
    char nazov[150];
    int velkN;
    char date[13];
    int COUNT;
    struct Zoznam* next;
};

void n(FILE*,struct Zoznam**,struct Presenter**,int*);
void v(struct Zoznam*,struct Presenter*);
void p(struct Zoznam**,struct Presenter**,int);
void z(struct Zoznam**,struct Presenter**);
void r(struct Zoznam**,struct Presenter**,int);
void a(struct Zoznam**,struct Presenter**);
void k(struct Zoznam**,struct Presenter**);
void error(void);

int main(void) {
    FILE *myfile = NULL;
    struct Zoznam *zoznam = NULL;
    struct Presenter *presenter = NULL;

    int Count = 0;
    while (1) {
        char c;
        printf("Zadajte prikaz:");
        scanf(" %c", &c);
        switch (c) {
            case 'n':
                n(myfile, &zoznam,&presenter,&Count);
                break;
            case 'v':
                v(zoznam,presenter);
                break;
            case 'p':
                p(&zoznam,&presenter,Count);
                break;
            case 'z':
                z(&zoznam,&presenter);
                break;
            case 'r':
                r(&zoznam,&presenter,Count);
                break;
            case 'a':
                a(&zoznam,&presenter);
                break;
            case 'k':
                k(&zoznam,&presenter);
                return 0;
            default:
                error();
                break;
        }
    }
}

void error(void) {
    printf("Zadali ste nemoznu moznost!(Len n,v,p,z,a,r,k,x)\n");
}

void n(FILE *myfile, struct Zoznam **zoznam,struct Presenter **presenter,int *Count) {
    if (*zoznam != NULL || *presenter != NULL) {
        free(*zoznam);
        free(*presenter);
        *zoznam = NULL;
        *presenter = NULL;
    }

    myfile = fopen("../files/KonferencnyZoznam2.txt", "r");
    if (myfile == NULL) {
        printf("Zaznamy neboli nacitane!\n");
        return;
    }

    char ID[11];
    char typID[3];
    char numID[9];
    char NAZOV[150];
    char DATE[13];
    char trash[100];
    char NAME[300];
    char Name[300];
    char firstNAME[150];
    char lastNAME[150];
    char roleNAME[100];

    struct Zoznam* last = NULL;
    struct Presenter* last2 = NULL;

    int count = 0;
    int Velk;
    while (!feof(myfile)) {
        struct Zoznam* new_zoznam = (struct Zoznam*)malloc(sizeof(struct Zoznam));
        new_zoznam->next = NULL;

        fscanf(myfile,"%s\n%s\n%[^\n]\n%[^\n]\n%[^\n]",trash,ID,NAZOV,NAME,DATE);
        sscanf(ID,"%[^0-9]%[0-9]",typID,numID);

        char *token = strtok(NAME, "#");
        Velk=0;
        while (token != NULL) {
            struct Presenter* new_zoznam2 = (struct Presenter*)malloc(sizeof(struct Presenter));
            new_zoznam2->next = NULL;

            strncpy(Name, token, sizeof(Name) - 1);
            Name[sizeof(Name) - 1] = '\0';

            token = strtok(NULL, "#");
            if (token != NULL) {
                Velk++;

                strncpy(roleNAME, token, sizeof(roleNAME) - 1);
                roleNAME[sizeof(roleNAME) - 1] = '\0';
                token = strtok(NULL, "#");

                sscanf(Name, "%s %s", firstNAME, lastNAME);
                strcpy(new_zoznam2->firstName, firstNAME);
                strcpy(new_zoznam2->lastName, lastNAME);
                strcpy(new_zoznam2->role, roleNAME);
            }
            new_zoznam->velkN = Velk;

            if (*presenter == NULL) {
                *presenter = new_zoznam2;
                last2 = *presenter;
            } else {
                last2->next = new_zoznam2;
                last2 = new_zoznam2;
            }
        }
        count++;
        new_zoznam->COUNT = (*Count)++;
        strcpy(new_zoznam->id.typ, typID);
        strcpy(new_zoznam->id.id, numID);
        strcpy(new_zoznam->nazov, NAZOV);
        strcpy(new_zoznam->date, DATE);

        if (*zoznam == NULL) {
            *zoznam = new_zoznam;
            last = *zoznam;
        } else {
            last->next = new_zoznam;
            last = new_zoznam;
        }
    }
    fclose(myfile);

    printf("Nacitalo sa %d zaznamov\n",count);
    *Count = count;
}

void v(struct Zoznam *zoznam,struct Presenter *presenter){
    if (zoznam == NULL || presenter == NULL) {
        printf("Prazdny zoznam zaznamov.\n");
        return;
    }

    struct Zoznam *current = zoznam;
    struct Presenter *current2 = presenter;
    char formatted_date[20];
    while (current != NULL) {
        printf("\nID prispevku : %s%s\n", current->id.typ, current->id.id);
        printf("Nazov prispevku: %s\n", current->nazov);
        printf("Mena autorov:\n");

        for (int k = 1; k <= current->velkN; k++) {
            printf("%10d: %s %s (%s)\n", k, current2->firstName, current2->lastName, current2->role);
            current2 = current2->next;
        }
        sprintf(formatted_date, "%.4s.%.2s.%.2s %.2s:%.2s", current->date, current->date + 4, current->date + 6, current->date + 8, current->date + 10);
        printf("Datum a Cas: %s\n", formatted_date);
        current = current->next;
    }
}

void p(struct Zoznam **zoznam,struct Presenter **presenter,int Count) {
    int c;
    printf("Zadajte cislo pozicii (>1): ");
    scanf("%d", &c);

    char ID[9];
    char typ_ID[9];
    char num_ID[9];
    char NAZOV[150];
    char NAME[300];
    char firstNAME[300];
    char lastNAME[300];
    char roleNAME[300];
    char DATE[13];
    printf("Zadajte ID prispevku: ");
    scanf("%s", ID);
    sscanf(ID,"%[a-zA-Z]%[0-9]",typ_ID,num_ID);
    printf("Zadajte nazov prispevku: ");
    scanf(" %[^\n]", NAZOV);
    printf("Zadajte mena autorov: ");
    scanf("%[^#]#%s#", NAME, roleNAME);
    sscanf(NAME,"%s %s",firstNAME,lastNAME);
    printf("Zadajte datum a cas: ");
    scanf("%s", DATE);

    if(*zoznam == NULL){
        struct Zoznam *new_zoznam = (struct Zoznam *) malloc(sizeof(struct Zoznam));
        strncpy(new_zoznam->id.typ, typ_ID, 3);
        strncpy(new_zoznam->id.id, num_ID, 9);
        strncpy(new_zoznam->nazov, NAZOV, 150);
        new_zoznam->velkN = 1;
        strncpy(new_zoznam->date, DATE, 13);
        new_zoznam->next = NULL;

        struct Presenter *new_presenter = (struct Presenter *) malloc(sizeof(struct Presenter));
        strncpy(new_presenter->firstName, firstNAME, 300);
        strncpy(new_presenter->lastName, lastNAME, 300);
        strncpy(new_presenter->role, roleNAME, 100);
        new_presenter->next = NULL;

        *zoznam = new_zoznam;
        *presenter = new_presenter;

        printf("Uspesne vlozeny zaznam na zaciatok zoznamu!\n");
        return;
    }

    struct Zoznam *novy = (struct Zoznam *) malloc(sizeof(struct Zoznam));
    strncpy(novy->id.typ, typ_ID, 3);
    strncpy(novy->id.id, num_ID, 9);
    strncpy(novy->nazov, NAZOV, 150);
    novy->velkN = 1;
    strncpy(novy->date, DATE, 13);
    novy->next = NULL;

    struct Presenter *novy_presenter = (struct Presenter *) malloc(sizeof(struct Presenter));
    strncpy(novy_presenter->firstName, firstNAME, 300);
    strncpy(novy_presenter->lastName, lastNAME, 300);
    strncpy(novy_presenter->role, roleNAME, 100);
    novy_presenter->next = NULL;

    if (c == 1) {
        novy_presenter->next = *presenter;
        novy->next = *zoznam;
        printf("Uspesne vlozeny zaznam na zaciatok zoznamu!\n");
        return;
    }

    struct Zoznam *aktualny = *zoznam;
    struct Presenter *aktualny2 = *presenter;
    if (c < 1 || c > Count) {
        aktualny->next = novy;
        aktualny2->next = novy_presenter;
        printf("Uspesne vlozeny zaznam na koniec zoznamu!\n");
    } else {
        novy_presenter->next = aktualny2->next;
        aktualny2->next = novy_presenter;

        novy->next = aktualny->next;
        aktualny->next = novy;
        printf("Uspesne vlozeny zaznam na %d-tu poziciu!\n", c);
    }
}

void z(struct Zoznam **zoznam,struct Presenter **presenter){
    bool k = true;
    char typ[2] = "A";
    char first_name[20];
    char last_name[20];
    printf("Zadajte autora ktoroho chcete vymazat: ");
    scanf("%s %s", first_name, last_name);

    int i = 0;
    while (first_name[i] && last_name[i]) {
        first_name[i] = tolower(first_name[i]);
        last_name[i] = tolower(last_name[i]);
        i++;
    }

    struct Zoznam *current = *zoznam;
    struct Zoznam *prev = NULL;
    struct Presenter *current_presenter = *presenter;
    struct Presenter *prev_presenter = NULL;

    while (current != NULL) {
        char low_first_name[300];
        char low_last_name[300];

        strcpy(low_first_name, current_presenter->firstName);
        for (int j = 0; low_first_name[j]; j++) {
            low_first_name[j] = tolower(low_first_name[j]);
        }
        strcpy(low_last_name, current_presenter->lastName);
        for (int j = 0; low_last_name[j]; j++) {
            low_last_name[j] = tolower(low_last_name[j]);
        }

        if (strcmp(low_first_name, first_name) == 0 && strcmp(low_last_name, last_name) == 0 && strcmp(current_presenter->role, typ) == 0) {
            k=false;
            printf("Prispevok s nazvom %s vymazany.\n", current->nazov);
            if (prev == NULL) {
                *zoznam = current->next;
                *presenter = current_presenter->next;
            } else {
                prev->next = current->next;
                prev_presenter->next = current_presenter->next;
            }
            free(current);
            free(current_presenter);
            current = prev == NULL ? *zoznam : prev->next;
            current_presenter = prev_presenter == NULL ? *presenter : prev_presenter->next;
        } else {
            prev = current;
            current = current->next;
            prev_presenter = current_presenter;
            current_presenter = current_presenter->next;
        }
    }
    if(k==true){
        printf("Zoznam s menom '%s' nenasiel.\n", first_name);
    }
}

void r(struct Zoznam **zoznam, struct Presenter **presenter, int Count) {
    int c1, c2;
    printf("Napiste 1 cislo(>0):");
    scanf("%d", &c1);
    printf("Napiste 2 cislo(>0):");
    scanf("%d", &c2);

    if (c1 <= 0 || c2 <= 0) {
        printf("Zadali ste cisla<=0!\n");
        return;
    }
    if (c1 == c2) {
        printf("Error cislo1=cislo2!\n");
        return;
    }
    if (c1 > Count || c2 > Count) {
        printf("Error cisla>Zoznamov!\n");
        return;
    }

    struct Zoznam *prev1 = NULL, *curr1 = *zoznam;
    struct Presenter *prev1_presenter = NULL, *curr1_presenter = *presenter;
    for (int i = 1; i < c1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;

        prev1_presenter = curr1_presenter;
        curr1_presenter = curr1_presenter->next;
    }

    struct Zoznam *prev2 = NULL, *curr2 = *zoznam;
    struct Presenter *prev2_presenter = NULL, *curr2_presenter = *presenter;
    for (int i = 1; i < c2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;

        prev2_presenter = curr2_presenter;
        curr2_presenter = curr2_presenter->next;
    }

    if (prev1) {
        prev1->next = curr2;
        prev1_presenter->next = curr2_presenter;
    } else {
        *zoznam = curr2;
        *presenter = curr2_presenter;
    }
    if (prev2) {
        prev2->next = curr1;
        prev2_presenter->next = curr1_presenter;
    } else {
        *zoznam = curr1;
        *presenter = curr1_presenter;
    }
    struct Zoznam *tmp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = tmp;

    struct Presenter *tmp2 = curr2_presenter->next;
    curr2_presenter->next = curr1_presenter->next;
    curr1_presenter->next = tmp2;
}

void a(struct Zoznam **zoznam, struct Presenter **presenter) {
    char Id[9];
    char Typ[3];
    char novyTyp[3];
    char staryTyp[3];

    printf("Napiste ID a TYP: ");
    scanf("%8s %2s", Id, Typ);

    while ((strcmp(Typ, "PD") != 0 && strcmp(Typ, "UD") != 0 && strcmp(Typ, "PP") != 0 && strcmp(Typ, "UP") != 0) || (atoi(Id) % 15 != 0)) {
        printf("Zadane udaje nie su korektne, zadaj novy retazec: ");
        scanf("%8s %2s", Id, Typ);
    }

    struct Zoznam *current = *zoznam;
    while (current != NULL) {
        if (strcmp(current->id.id, Id) == 0) {
            printf("Zadajte novy TYP pre ID %s: ", Id);
            scanf("%2s", novyTyp);
            strcpy(staryTyp, current->id.typ);
            strcpy(current->id.typ, novyTyp);

            printf("Prispevok s nazvom %s sa bude prezentovat %s [%s].\n", current->nazov,novyTyp,staryTyp);
            return;
        }
        current = current->next;
    }
    printf("ID %s nebol najdeny v zozname.\n", Id);
}

void k(struct Zoznam **zoznam,struct Presenter **presenter){
    if (*zoznam != NULL) {
        free(*zoznam);
        *zoznam = NULL;
    }
    if (*presenter != NULL) {
        free(*presenter);
        *presenter = NULL;
    }
}