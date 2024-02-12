#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void v(FILE**,char ***id, char ***nazov, char ***name, char ***data,char ***typ,int Vel);
void p(char ***id, char ***nazov, char ***name, char ***data,char ***typ,int *Vel);
void n(FILE*,char ***id,char ***nazov,char ***name,char ***data,char ***typ,int *Vel);
void s(char **id,char **nazov,char **name,char **data,char **typ,int Vel);
void w(char **id,char **nazov,char **name,char **data,char **typ,int Vel,char ***MENA,int *VelM);
void h(char **id,char **nazov,char **name,char **data,char **typ,int Vel);
void z(char **id,char **nazov,char **name,char **data,char **typ,int *Vel);
void d(char ***id, char ***nazov, char ***name, char ***data,char ***typ,int Vel);
void k(char ***id,char ***nazov,char ***name,char ***data,char ***typ,int Vel,char ***MENA,int VelM);
void error();

#define TYP_NUM 3
#define ID_NUM 9
#define NAZOV_NUM 150
#define MENO_NUM 300
#define DATE_NUM 13

int main(void) {
    FILE *myfile = NULL;
    char **id=NULL,**nazov=NULL,**name= NULL,**data=NULL,**typ=NULL,**MENA=NULL;
    id=nazov=name=data=NULL;
    int Vel=0;
    int VelM=0;
    int Veld;

    while (1) {
        char c;
        Veld = Vel;
        printf("Zadajte prikaz:");
        scanf("%s", &c);
        Vel = Veld;
        switch (c) {
            case 'v':
                v(&myfile,&id,&nazov,&name,&data,&typ, Vel);
                break;
            case 'p':
                p(&id,&nazov,&name,&data,&typ,&Vel);
                break;
            case 'n':
                n(myfile,&id,&nazov,&name,&data,&typ, &Vel);
                break;
            case 's':
                s(id,nazov,name,data,typ,Vel);
                break;
            case 'w':
                w(id,nazov,name,data,typ,Vel,&MENA,&VelM);
                break;
            case 'h':
                h(id,nazov,name,data,typ,Vel);
                break;
            case 'z':
                z(id,nazov,name,data,typ,&Vel);
                break;
            case 'd':
                d(&id,&nazov,&name,&data,&typ,Vel);
                break;
            case 'k':
                k(&id,&nazov,&name,&data,&typ,Vel,&MENA,VelM);
                break;
            case 'X':
                return 0;
            default:
                error();
                break;
        }
    }
}

void v(FILE **myfile,char ***id, char ***nazov, char ***name, char ***data,char ***typ,int Vel) {
    if (*myfile == NULL) {
        *myfile = fopen("../FILES/KonferencnyZoznam.txt", "r");
    }else if (*myfile == NULL) {
        printf("Neotvoreny subor.\n");
    }
    if (*id != NULL && *nazov != NULL && *name != NULL && *data != NULL && *typ != NULL){
        for (int i = 0; i < Vel; i++) {
            printf("%s%s\n",(*typ)[i],(*id)[i]);
            printf("%s\n",(*nazov)[i]);
            printf("%s\n",(*name)[i]);
            printf("%s\n",(*data)[i]);
            printf("\n");
        }
    }else{
            char ID[11];
            char NAZOV[150];
            char NAME[300];
            char DATE[13];

            rewind(*myfile);
            while (!feof(*myfile)) {
                fscanf(*myfile,"%s\n%[^\n]\n%[^\n]\n%[^\n]",ID,NAZOV,NAME,DATE);

                printf("ID prispevku: %s \n",ID);
                printf("Nazov prispevku: %s \n",NAZOV);
                printf("Mena autorov: %s \n",NAME);
                printf("Datum a cas prezentovania: %s \n",DATE);
                printf("\n");
            }
        }
    }

void p(char ***id, char ***nazov, char ***name, char ***data,char ***typ,int *Vel){
    char ID2[11];
    char ID[9];
    char TYP[3];
    char NAZOV[150];
    char NAME[300];
    char DATE[13];

    printf("Ukazte ID:");
    scanf("\n%[^\n]",ID2);
    sscanf(ID2,"%[^0-9]%[0-9]",TYP,ID);

    printf("Ukazte nazov prispevku:");
    scanf("\n%[^\n]",NAZOV);

    printf("Ukazte vase meno a priezvisko:");
    scanf("\n%[^\n]",NAME);

    printf("Ukazte datum:");
    scanf("\n%[^\n]",DATE);

    *Vel=*Vel+1;
    *id = (char **) realloc(*id, *Vel * sizeof(char *));
    *typ = (char **) realloc(*typ, *Vel * sizeof(char *));
    *nazov = (char **) realloc(*nazov, *Vel * sizeof(char *));
    *name = (char **) realloc(*name, *Vel * sizeof(char *));
    *data = (char **) realloc(*data, *Vel * sizeof(char *));

        (*id)[*Vel-1] = (char *) malloc(ID_NUM * sizeof(char));
        (*typ)[*Vel-1] = (char *) malloc(TYP_NUM * sizeof(char));
        (*nazov)[*Vel-1] = (char *) malloc(NAZOV_NUM * sizeof(char));
        (*name)[*Vel-1] = (char *) malloc(MENO_NUM * sizeof(char));
        (*data)[*Vel-1] = (char *) malloc(DATE_NUM * sizeof(char));

        strcpy((*id)[*Vel-1], ID);
        strcpy((*typ)[*Vel-1], TYP);
        strcpy((*nazov)[*Vel-1], NAZOV);
        strcpy((*name)[*Vel-1], NAME);
        strcpy((*data)[*Vel-1], DATE);

    printf("\nZaznam sa podarilo pridat!\n");
}

void n(FILE *myfile, char ***id, char ***nazov, char ***name, char ***data,char ***typ,int *Vel) {
    rewind(myfile);
    if (myfile == NULL) {
        printf("Neotvoreny subor.\n");
        return;
    }

    for (int i = 0; i < *Vel; i++) {
        free((*id)[i]);
        free((*typ)[i]);
        free((*nazov)[i]);
        free((*name)[i]);
        free((*data)[i]);
    }
    free(*id);
    free(*typ);
    free(*nazov);
    free(*name);
    free(*data);

    char line[100];
    int count=0;
    while (fgets(line, sizeof(line), myfile)) {
        if (strlen(line) > 1) {
            count++;
        }
    }
    rewind(myfile);
    int N=count/4;

    *id = (char **) malloc(N * sizeof(char *));
    *typ = (char **) malloc(N * sizeof(char *));
    *nazov = (char **) malloc(N * sizeof(char *));
    *name = (char **) malloc(N * sizeof(char *));
    *data = (char **) malloc(N * sizeof(char *));

    for (int i = 0; i < N; i++) {
        (*id)[i] = (char *) malloc(ID_NUM * sizeof(char));
        (*typ)[i] = (char *) malloc(TYP_NUM * sizeof(char));
        (*nazov)[i] = (char *) malloc(NAZOV_NUM * sizeof(char));
        (*name)[i] = (char *) malloc(MENO_NUM * sizeof(char));
        (*data)[i] = (char *) malloc(DATE_NUM * sizeof(char));
    }
    char ID[11];
    char Id[9];
    char TYP[3];
    char NAZOV[150];
    char NAME[300];
    char DATE[13];

    int z=0;
    while (!feof(myfile)) {

        fscanf(myfile,"%[^\n]\n %[^\n]\n %[^\n]\n %[0-9]\n",ID, NAZOV, NAME, DATE);
        sscanf(ID,"%[^0-9]%[0-9]",TYP,Id);
        if(z<N){
            strcpy((*id)[z], Id);
            strcpy((*typ)[z], TYP);
            strcpy((*nazov)[z], NAZOV);
            strcpy((*name)[z], NAME);
            strcpy((*data)[z], DATE);
            z++;
        }
    }
    *Vel = N;
/*
    for (int i = 0; i < *Vel; i++) {
       // printf("typ[%d]: %s\n", i, (*typ)[i]);
       // printf("id[%d]: %s\n", i, (*id)[i]);
      //  printf("nazov[%d]: %s\n", i, (*nazov)[i]);
      //  printf("name[%d]: %s\n", i, (*name)[i]);
        printf("data[%d]: %s\n", i, (*data)[i]);
    }*/
    printf("Nacitane data.\n");
}

void s(char **id, char **nazov, char **name, char **data,char **typ,int Vel){
    if(id==NULL || nazov==NULL || name==NULL || data==NULL || typ==NULL){
        printf("Polia nie su vytvorene!\n");
        return;
    }
    char Htyp[3];
    char Hdata[13];
    char Name[100];
    char Data[100];

    printf("Zadajte DATUM:");
    scanf("%s",Hdata);
    printf("Zadajte TYP:");
    scanf("%s",Htyp);

    int result1,result2;
    for(int i=0;i<Vel;i++) {
        int len = strlen(data[i]);

        result1 = strncmp(Hdata, data[i], 8);
        result2 = strcmp(Htyp, typ[i]);

        if (result1 == 0 && result2 == 0) {
            sscanf(name[i], "%[^#]", Name);
            strncpy(Data, data[i] + len - 4, 4);
            printf("%s     %s           %s\n", Data, Name, nazov[i]);
        }
    }
    if (result1 != 0 && result2 != 0) {
        printf("Pre dany vstup neexistuju zaznamy!\n");
    }
}

void w(char **id,char **nazov,char **name,char **data,char **typ,int Vel,char ***MENA,int *VelM){
    if(id==NULL || nazov==NULL || name==NULL || data==NULL || typ==NULL){
        printf("Polia nie su vytvorene!\n");
        return;
    }

    if(*VelM>0){
        for (int i = 0; i < *VelM; i++) {
            free((*MENA)[i]);
        }
        free(*MENA);
    }

    int buff = 0;
    char **names = (char **) malloc(Vel * sizeof(char *));

    for (int i = 0; i < Vel; i++) {
        char *rest = name[i];
        char *token = strtok_r(rest, "#", &rest);

        while (token) {
            if (strcmp(token, "A") == 0 || strcmp(token, "K") == 0) {
                token = strtok_r(rest, "#", &rest);
                continue;
            }
            char *Name = strdup(token);
            names[buff] = (char *) malloc(strlen(Name) * sizeof(char));
            strcpy(names[buff], Name);
            buff++;
          //  printf("%s\n", Name);
            token = strtok_r(rest, "#", &rest);
        }
    }
    *VelM = buff;
    *MENA = (char **) malloc(*VelM * sizeof(char *));
    for (int i = 0; i < *VelM; i++) {
        (*MENA)[i] = (char *) malloc(strlen(names[i]) * sizeof(char));
        strcpy((*MENA)[i], names[i]);
        strupr((*MENA)[i]);
    }
    for (int i = 0; i < *VelM; i++) {
        printf("%s\n", (*MENA)[i]);
    }
}

void h(char **id,char **nazov,char **name,char **data,char **typ,int Vel){
    if(id==NULL || nazov==NULL || name==NULL || data==NULL || typ==NULL){
        printf("Polia nie su vytvorene!\n");
        return;
    }
    printf("--hodina--      UP  UD  PP  PD\n");

    int UP;
    int UD;
    int PP;
    int PD;

    for(int i=8;i<24;i+=2){

        UP=0;
        UD=0;
        PP=0;
        PD=0;

        for ( int l = 0; l < Vel; l++ ) {
            if ( ((int)data[l][8] - 48) * 10 + ((int)data[l][9] - 48) >= i && ((int)data[l][8] - 48) * 10 + ((int)data[l][9] - 48) < i + 2 ) {
                if ( typ[l][0] == 'U' ) {
                    if ( typ[l][1] == 'P' ) {
                        UP++;
                    }
                    else {
                        UD++;
                    }
                }
                else {
                    if ( typ[l][1] == 'P' ) {
                            PP++;

                    }else {
                        PD++;
                    }
                }
            }
        }

        if ( i < 10 ) {
            printf("0");
        }
        printf("%d:00-%d:59     ", i, i+1);
        if ( i == 8 ) {
            printf(" ");
        }
        printf("%d   %d   %d   %d\n", UP, UD, PP, PD);
    }
}

void z(char **id, char **nazov, char **name, char **data, char **typ, int *Vel) {
    if (id == NULL || nazov == NULL || name == NULL || data == NULL || typ == NULL) {
        printf("Polia nie su vytvorene!\n");
        return;
    }

    char Nazov[150];
    int result, count = 0;
    printf("Zadaite nazov prispevku: ");
    scanf("\n%[^\n]", Nazov);

    char **BUFFid = NULL, **BUFFnazov = NULL, **BUFFname = NULL, **BUFFdata = NULL, **BUFFtyp = NULL;

    BUFFid = (char **) malloc(*Vel * sizeof(char *));
    BUFFtyp = (char **) malloc(*Vel * sizeof(char *));
    BUFFnazov = (char **) malloc(*Vel * sizeof(char *));
    BUFFname = (char **) malloc(*Vel * sizeof(char *));
    BUFFdata = (char **) malloc(*Vel * sizeof(char *));

    for (int i = 0; i < *Vel; i++) {
        BUFFid[i] = (char *) malloc(ID_NUM * sizeof(char));
        BUFFtyp[i] = (char *) malloc(TYP_NUM * sizeof(char));
        BUFFnazov[i] = (char *) malloc(NAZOV_NUM * sizeof(char));
        BUFFname[i] = (char *) malloc(MENO_NUM * sizeof(char));
        BUFFdata[i] = (char *) malloc(DATE_NUM * sizeof(char));
    }
    int z=0;
    for (int i = 0; i < *Vel; i++) {
        result = strcmp(Nazov, nazov[i]);

        if (result == 0) {
           /* BUFFid[i] = "";
            BUFFtyp[i] = "";
            BUFFnazov[i] = "";
            BUFFname[i] = "";
            BUFFdata[i] = "";*/
            count++;
        } else {
            strcpy(BUFFid[z], id[i]);
            strcpy(BUFFtyp[z], typ[i]);
            strcpy(BUFFnazov[z], nazov[i]);
            strcpy(BUFFname[z], name[i]);
            strcpy(BUFFdata[z], data[i]);
            z++;
        }
    }

    for (int i = 0; i < z; i++) {
        strcpy(id[i], BUFFid[i]);
        strcpy(typ[i], BUFFtyp[i]);
        strcpy(nazov[i], BUFFnazov[i]);
        strcpy(name[i], BUFFname[i]);
        strcpy(data[i], BUFFdata[i]);
    }

    for (int i = 0; i < *Vel; i++) {
        free(BUFFid[i]);
        free(BUFFtyp[i]);
        free(BUFFnazov[i]);
        free(BUFFname[i]);
        free(BUFFdata[i]);
    }
    free(BUFFid);
    free(BUFFtyp);
    free(BUFFnazov);
    free(BUFFname);
    free(BUFFdata);

    id = (char **) realloc(id, (*Vel - count) * sizeof(char *));
    typ = (char **) realloc(typ, (*Vel - count) * sizeof(char *));
    nazov = (char **) realloc(nazov, (*Vel - count) * sizeof(char *));
    name = (char **) realloc(name, (*Vel - count) * sizeof(char *));
    data = (char **) realloc(data, (*Vel - count) * sizeof(char *));

    for (int i = 0; i < *Vel - count; i++) {
        id[i] = (char *) realloc(id[i], ID_NUM * sizeof(char));
        typ[i] = (char *) realloc(typ[i], TYP_NUM * sizeof(char));
        nazov[i] = (char *) realloc(nazov[i], NAZOV_NUM * sizeof(char));
        name[i] = (char *) realloc(name[i], MENO_NUM * sizeof(char));
        data[i] = (char *) realloc(data[i], DATE_NUM * sizeof(char));
    }
    /*for (int i = 0; i < Vel - count; i++) {
        printf("%s", typ[i]);
        printf("%s\n", id[i]);
        printf("%s\n", nazov[i]);
        printf("%s\n", name[i]);
        printf("%s\n", data[i]);
        printf("\n");
    }*/
    printf("Vymazalo sa: %d zaznamov!\n",count);
    *Vel=*Vel-count;
}

void d(char*** id, char*** nazov, char*** name, char*** data, char*** typ, int Vel) {
    for (int i = 0; i < Vel; i++) {
        free((*id)[i]);
        free((*nazov)[i]);
        free((*name)[i]);
        free((*data)[i]);
        free((*typ)[i]);
    }
    if ( Vel != 0 ) {
        free(*id);
        free(*nazov);
        free(*name);
        free(*data);
        free(*typ);
    }
    *id = NULL;
    *nazov = NULL;
    *name = NULL;
    *data = NULL;
    *typ = NULL;
}

void k(char ***id,char ***nazov,char ***name,char ***data,char ***typ,int Vel,char ***MENA,int VelM){

    for (int i = 0; i < Vel; i++) {
        free((*id)[i]);
        free((*typ)[i]);
        free((*nazov)[i]);
        free((*name)[i]);
        free((*data)[i]);
    }
    if ( Vel != 0 ) {
        free(*id);
        free(*typ);
        free(*nazov);
        free(*name);
        free(*data);
    }
    *id = NULL;
    *nazov = NULL;
    *name = NULL;
    *data = NULL;
    *typ = NULL;

    for (int i = 0; i < VelM; i++) {
        free((*MENA)[i]);
    }
    if ( VelM != 0 ) {
        free(*MENA);
    }
    *MENA = NULL;
}

void error(){
    printf("Zadali ste nemoznu moznost!(Len v,p,n,s,w,h,z,d,k)\n");
}