#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum();
int who();
int best();
int gender();
int region();
int year();
int average();
int over();
int change();
int newstudent();
int delstudent();
int end();
int error();

int main() {
    while (1) {
        char c;
        printf("Zadajte prikaz:");
        scanf("%s", &c);
        getchar();
        switch (c) {
            case 's':
                sum();
                break;
            case 'w':
                who();
                break;
            case 'b':
                best();
                break;
            case 'g':
                gender();
                break;
            case 'r':
                region();
                break;
            case 'y':
                year();
                break;
            case 'a':
                average();
                break;
            case 'o':
                over();
                break;
            case 'c':
                change();
                break;
            case 'n':
                newstudent();
                break;
            case 'd':
                delstudent();
                break;
            case 'x':
                end();
                return 0;
            default:
                error();
                break;
        }
    }
}
int sum() {
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};

    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    if (myfile == NULL){
        printf("Subor nie je mozne precitat.\n");
    } else {
        while (!feof(myfile)) {
            fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
            sscanf(born, "%[^/]", born);
            printf("\n");
            printf("%s, nar. %s, %s, Kraj: %s \n", name, born, strcmp(sex, "m") ? "zena" : "muz", area);
            //printf("%s, nar. %s, %s, Kraj: %s \n",name, born,sex,area);
            printf("Vysledky testov: %s \n", test);
            printf("\n");
        }
    }
    fclose(myfile);
    return 0;
}

int who() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");

    char *name;
    name= calloc(100,sizeof (char));
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    char scaname[100];
    int result;
    char surname[100];
    int q;

    printf("Zadajte meno a priezvisko studenta:");
    scanf("%[a-zA-Z- ]",scaname);
    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(born, "%[^/]", born);
        int pos=0;
        for(q=0;q<100;q++){
            if(name[q]==' '){
                pos=q;
            }else if(name[q]==0){
                break;
            }
        }
        for(q=pos;q<100;q++){
           surname[q-pos-1]=name[q];
           if(name[q]==0){
               break;
           }
        }
        result = strcmp(scaname, surname);
        if (result==0)
            break;
    }
    float test_float[6];
    sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3], &test_float[4], &test_float[5]);
    float test_beast_score = test_float[0];
    int i;
    for(i=1; i < 6; i++) {
        if (test_beast_score < test_float[i]) {
            test_beast_score = test_float[i];
        }
    }
    float test_horshi_score = test_float[0];
    int j;
    for(j=1; j < 6; j++) {
        if (test_horshi_score > test_float[j]) {
            test_horshi_score = test_float[j];
        }
    }
    float aver_test = (test_float[0]+test_float[1]+test_float[2]+test_float[3]+test_float[4]+test_float[5])/6 ;
    printf("\n");
    printf("%s\n", name);
    printf("nar. %s, %s\n", born, strcmp(sex, "m") ? "zena" : "muz");
    printf("Kraj: %s \n", area);
    printf("\n");
    printf("Vysledky testov: %s \n", test);
    printf("\n");
    printf("Najlepsi test: %.2f   \n",test_beast_score );
    printf("Najhorsi test: %.2f   \n",test_horshi_score );
    printf("Priemerny test: %.2f \n",aver_test);
    printf("\n");
    fclose(myfile);
    return 0;
}
int best() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[1000] = {0};
    char sex[1000] = {0};
    char born[1000] = {0};
    char area[1000] = {0};
    float test[6];
    char bestestname[100];
    float btest;
    int index;
    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%f;%f;%f;%f;%f;%f", name, sex, born, area, &test[0],&test[1],&test[2],&test[3],&test[4],&test[5]);
        sscanf(born, "%[^/]", born);
        int i;
        for(i=0;i<6;i++){
            if (btest < test[i]){
                btest = test[i];
                index = i+1;
                strcpy(bestestname,name);
            }
        }
    }
    printf("Najlepsi test: %.2f   \n", btest);
    printf("Student: %s\n", bestestname);
    printf("Cislo testu: %d\n", index);
    fclose(myfile);
    return 0;
}
int gender() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char scangender[100] = {0};
    char test[100] = {0};
    float test_float[6];
    int index;
    float btest;
    int result;
    printf("Zadajte gender studenta (m/f):");
    scanf("%s",scangender);

    float btestALL;
    int indexALL=0;
    char nameALL[100];
    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);

        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3],&test_float[4], &test_float[5]);
        int i;
        for(i=0;i<6;i++){
            if (btest < test_float[i]){
                btest = test_float[i];
                index = i+1;
            }
        }
        result = strcmp(scangender, sex);
        if (result == 0){
            for(i=0;i<6;i++){
                if (btestALL < btest){
                    btestALL = btest;
                    indexALL = index;
                    strcpy(nameALL,name);
                }
            }
        }
    }
    printf("Najlepsi test: %.2f\n", btestALL);
    printf("Student: %s\n", nameALL);
    printf("Cislo testu: %d\n", indexALL);
    fclose(myfile);
    return 0;
}
int region() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    float test_float[6];
    int index;
    int indexB;
    float btestB=0;
    char nameB[100];

    int indexC,indexD,indexE,indexH,indexG,indexL,indexA;
    char nameC[100],nameD[100],nameE[100],nameH[100],nameG[100],nameL[100],nameA[100];
    float btestC=0,btestD=0,btestE=0,btestH=0,btestG=0,btestL=0,btestA=0;
    float btest;
    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(born, "%[^/]", born);
        btest=0;

        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3],&test_float[4], &test_float[5]);
        int i;
        for(i=0;i<6;i++){
            if (btest < test_float[i]){
                btest = test_float[i];
                index = i+1;
            }
        }
        if(strcmp(area, "bratislavsky") == 0){
            if (btestB < btest){
                btestB=btest;
                indexB = index;
                strcpy(nameB,name);
            }
        }
        if(strcmp(area, "trnavsky") == 0){
            if (btestA < btest){
                btestA=btest;
                indexA = index;
                strcpy(nameA,name);
            }
        }
        if(strcmp(area, "trenciansky") == 0){
            if (btestC < btest){
                btestC=btest;
                indexC = index;
                strcpy(nameC,name);
            }
        }
        if(strcmp(area, "kosicky") == 0){
            if (btestD < btest){
                btestD=btest;
                indexD = index;
                strcpy(nameD,name);
            }
        }
        if(strcmp(area, "nitriansky") == 0){
            if (btestE < btest){
                btestE=btest;
                indexE = index;
                strcpy(nameE,name);
            }
        }
        if(strcmp(area, "zilinsky") == 0){
            if (btestH < btest){
                btestH=btest;
                indexH = index;
                strcpy(nameH,name);
            }
        }
        if(strcmp(area, "banskobystricky") == 0){
            if (btestG < btest){
                btestG=btest;
                indexG = index;
                strcpy(nameG,name);
            }
        }
        if(strcmp(area, "presovsky") == 0){
            if (btestL < btest){
                btestL=btest;
                indexL = index;
                strcpy(nameL,name);
            }
        }
    }
    printf("\n");
    printf("Kraj: bratislavsky\n");
    printf("Najlepsi test %.2f\n",btestB);
    printf("Student: %s\n",nameB);
    printf("Cislo testu: %d\n",indexB);
    printf("\n");

    printf("Kraj: trnavsky\n");
    printf("Najlepsi test %.2f\n",btestA);
    printf("Student: %s\n",nameA);
    printf("Cislo testu: %d\n",indexA);
    printf("\n");

    printf("Kraj: trenciansky\n");
    printf("Najlepsi test %.2f\n",btestC);
    printf("Student: %s\n",nameC);
    printf("Cislo testu: %d\n",indexC);
    printf("\n");

    printf("Kraj: nitriansky\n");
    printf("Najlepsi test %.2f\n",btestE);
    printf("Student: %s\n",nameE);
    printf("Cislo testu: %d\n",indexE);
    printf("\n");

    printf("Kraj: zilinsky\n");
    printf("Najlepsi test %.2f\n",btestH);
    printf("Student: %s\n",nameH);
    printf("Cislo testu: %d\n",indexH);
    printf("\n");

    printf("Kraj: banskobystricky\n");
    printf("Najlepsi test %.2f\n",btestG);
    printf("Student: %s\n",nameG);
    printf("Cislo testu: %d\n",indexG);
    printf("\n");

    printf("Kraj: presovsky\n");
    printf("Najlepsi test %.2f\n",btestL);
    printf("Student: %s\n",nameL);
    printf("Cislo testu: %d\n",indexL);
    printf("\n");

    printf("Kraj: kosicky\n");
    printf("Najlepsi test %.2f\n",btestD);
    printf("Student: %s\n",nameD);
    printf("Cislo testu: %d\n",indexD);
    printf("\n");

    fclose(myfile);
    return 0;
}
int year() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    float test_float[6];
    int index;
    float btest;
    float btestALL;
    int indexALL=0;
    char nameALL[100];
    int yearall=0;
    double val;
    int scanyear;
    printf("Zadajte rok narodenia studenta:");
    scanf("%d",&scanyear);

    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(born, "%[^/]", born);

        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3],&test_float[4], &test_float[5]);
        int i;
        for(i=0;i<6;i++){
            if (btest < test_float[i]){
                btest = test_float[i];
                index = i+1;
            }
        }
        val = atof(born);
        if(val>scanyear){
            for(i=0;i<6;i++){
                if (btestALL < btest){
                    btestALL = btest;
                    indexALL = index;
                    yearall = (int)(val);
                    strcpy(nameALL,name);
                }
            }
        }
        }
    printf("%s \n", nameALL);
    printf("nar. %d \n", yearall);
    printf("Najlepsi test: %.2f\n", btestALL);
    printf("Cislo testu: %d\n", indexALL);

    fclose(myfile);
    return 0;
}
int average() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};

    char bestestname[100];
    float aver_testBest = 0;
    float aver_test;
    float test_float[6];

    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(born, "%[^/]", born);
        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3], &test_float[4], &test_float[5]);
        aver_test = (test_float[0]+test_float[1]+test_float[2]+test_float[3]+test_float[4]+test_float[5])/6 ;
        printf("%s - ", name);
        printf("%.2f", aver_test);

        if (aver_testBest < aver_test){
            aver_testBest = aver_test;
            strcpy(bestestname,name);
        }
    }
    printf("\n");
    printf("Najlepsie:");
    printf("%s - ", bestestname);
    printf("%.2f\n", aver_testBest);
    fclose(myfile);
    return 0;
}
int over() {
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    float test_float[6];
    int index;
    float scantest;
    printf("Zadajte vas test:");
    scanf("%f",&scantest);
    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(born, "%[^/]", born);
        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3],&test_float[4], &test_float[5]);
        printf("%s",name);
        int numb=0;
        int i;
        for(i=0;i<6;i++) {
            if (test_float[i] >= scantest) {
                numb++;
            }
        }
        printf(" - %d test",numb);
        if(numb==5 || numb==6){
            printf("ov,");
        }
        if(numb==1){
            printf(",");
        }
        if(numb==2 || numb==3 || numb==4){
            printf("y,");
        }
        for(i=0;i<6;i++) {
            if (test_float[i] >= scantest) {
                index=i+1;
                printf(" %d (%.2f)",index,test_float[i]);
            }
        }
        printf("\n");
    }
    fclose(myfile);
    return 0;}

int change() {
    char scaname[100];
    int scanindex;
    float scantest;

    printf("Zadajte priezvisko studenta:");
    scanf("%s",scaname);
    printf("Zadajte poradove cislo testu:");
    scanf("%d",&scanindex);
    printf("Zadajte novy vysledok testu:");
    scanf("%f",&scantest);

    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    float test_float[6];
    char surname[100];
    int q;
    char ch;
    FILE *myfile;
    myfile = fopen("files/studenti.csv", "r");
    FILE *fileBUFF;
    fileBUFF = fopen("files/buffer.txt","w");

    while (!feof(myfile)) {
        fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
        sscanf(test, "%f;%f;%f;%f;%f;%f", &test_float[0], &test_float[1], &test_float[2], &test_float[3],&test_float[4], &test_float[5]);

        int pos = 0;
        for (q = 0; q < 100; q++) {
            if (name[q] == ' ') {
                pos = q;
            } else if (name[q] == 0) {
                break;
            }
        }
        for (q = pos; q < 100; q++) {
            surname[q - pos - 1] = name[q];
            if (name[q] == 0) {
                break;
            }
        }
        int result;
        result = strcmp(scaname, surname);
        if (result == 0) {
            test_float[scanindex - 1] = scantest;
        }
        fprintf(fileBUFF, "%s;%s;%s;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", name, sex, born, area, test_float[0],
                test_float[1], test_float[2], test_float[3], test_float[4], test_float[5]);
    }
    fclose(fileBUFF);
    fclose(myfile);
    myfile = fopen("files/studenti.csv", "w");
    fileBUFF = fopen("files/buffer.txt","r");
    while ((ch = fgetc(fileBUFF)) != EOF)
        fputc(ch, myfile);

    fclose(fileBUFF);
    remove("fileBUFF");
    fclose(myfile);
    myfile = fopen("files/studenti.csv", "r");

    if (myfile == NULL){
        printf("Subor nie je mozne precitat.\n");
    } else {
        while (!feof(myfile)) {
            fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
            sscanf(born, "%[^/]", born);

            printf("\n");
            printf("%s, nar. %s, %s, Kraj: %s \n", name, born, strcmp(sex, "m") ? "zena" : "muz", area);
            printf("Vysledky testov: %s \n", test);
            printf("\n");
        }
    }
    fclose(myfile);
    return 0;
}
int newstudent() {
    char name[100] = {0};
    char sex[100] = {0};
    char born[100] = {0};
    char area[100] = {0};
    char test[100] = {0};
    char NEWname[100] = {0};
    char NEWsex[100] = {0};
    char NEWborn[100] = {0};
    char NEWarea[100] = {0};
    char NEWtest[100] = {0};

    FILE *myfile;
    myfile = fopen("files/studenti.csv", "a");
    if (myfile == NULL) {
        printf("Subor nie je mozne precitat.\n");
    } else {
        fprintf(myfile, "\n");
        printf("Zadajte krstne meno a priezvisko studenta:");
        scanf("%[a-zA-Z- ]", NEWname);
        printf("Zadajte svoje pohlavie (m/f):");
        scanf("%s", NEWsex);
        printf("Zadajte datum narodenia vo formate (YYYY/MM/DD):");
        scanf("%s", NEWborn);
        printf("Zadajte oblast bydliska:");
        scanf("%s", NEWarea);
        printf("Zadajte poslednych 6 testov vo formate (test1;test2;...;test6):");
        scanf("%s", NEWtest);
        fprintf(myfile, "%s;%s;%s;%s;%s", NEWname, NEWsex, NEWborn, NEWarea, NEWtest);
        fclose(myfile);

        myfile = fopen("files/studenti.csv", "r");

        while (!feof(myfile)) {
            fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
            sscanf(born, "%[^/]",born);

            printf("\n");
            printf("%s, nar. %s, %s, Kraj: %s \n", name, born, strcmp(sex, "m") ? "zena" : "muz", area);
            printf("Vysledky testov: %s \n", test);
            printf("\n");
        }
    }
        fclose(myfile);
        return 0;
    }
    int delstudent() {
        char delname[100] = {0};
        printf("Zadajte priezvisko studenta:");
        scanf("%s", delname);
        char name[100] = {0};
        char sex[100] = {0};
        char born[100] = {0};
        char area[100] = {0};
        char test[100] = {0};
        char surname[100];
        char namee[100] = {0};
        int q;
        char ch[300];
        int str;
        FILE *myfile;
        myfile = fopen("files/studenti.csv", "r");
        FILE *fileBUFF;
        fileBUFF = fopen("files/buffer.txt","w");

        while (!feof(myfile)) {
            fscanf(myfile, "%[^;];%[^;];%[0-9/ ];%[^;];%[0-9.; ]", name, sex, born, area, test);
            getc(myfile);
            int pos = 0;
            for (q = 0; q < 100; q++) {
                if (name[q] == ' ') {
                    pos = q;
                } else if (name[q] == 0) {
                    break;
                }
            }
            for (q = pos; q < 100; q++) {
                surname[q - pos - 1] = name[q];
                if (name[q] == 0) {
                    break;
                }
            }
            int result;
            result = strcmp(delname, surname);
            if (result!=0) {
                fprintf(fileBUFF, "%s;%s;%s;%s;%s\n", name, sex, born, area, test);
                str++;
                } else if (result==0){
                strcpy(namee,name);
            }
        }
            fclose(fileBUFF);
            fclose(myfile);
            myfile = fopen("files/studenti.csv", "w");
            fileBUFF = fopen("files/buffer.txt","r");

            while (str!=0){
                fgets(ch, 300, fileBUFF);
                if(str==1){
                    ch[strlen(ch)-1]='\0';
                }
                fprintf(myfile,"%s",ch);
                str--;
            }

            printf("Student s menom  '%s' vymazany.\n",namee);
        fclose(fileBUFF);
        remove("fileBUFF");
        fclose(myfile);
        return 0;
    }
    int end() {
        printf("Koniec operacii\n");
        return 0;
    }
    int error() {
        printf("Zadali ste nemoznu moznost!(Len s,w,b,g,r,y,a,o,c,n,d,x)\n");
        return 0;
    }