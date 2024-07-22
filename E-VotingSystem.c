#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int control();

int main() {
    printf("*\n");
    printf("WELCOME TO VOTING SYSTEM USING C\n");
    printf("*\n");
    control();    
    return 0;
}

int control() {
    char name[50];
    int pass;
    printf("-------------------WELCOME TO CONTROL MODULE-------------------\n");
    printf("PLEASE ENTER THE NAME OF THE ELECTION: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < 50 && name[i] != '\0'; i++) {
        if (name[i] > 96) {
            name[i] = name[i] - 32;
        }
    }
    printf("THE NAME OF THE ELECTION IS %s\n", name);
    printf("PLEASE ENTER A 6 DIGIT PASSWORD: ");
    scanf("%d", &pass);
    system("cls");
    printf("PLEASE ENTER NUMBER OF CANDIDATES: ");
    int z;
    scanf("%d", &z);
    int i = 1;
    while (i) {
        if (z <= 0 || z > 16) {
            i = 1;
            printf("PLEASE ENTER A VALID VALUE\n");
            printf("PLEASE ENTER NUMBER OF CANDIDATES: ");
            scanf("%d", &z);
        } else {
            printf("YOU HAVE ENTERED %d CANDIDATES. \nPLEASE ENTER 0 TO CONFIRM OR 1 TO RE-ENTER: ", z);
            scanf("%d", &i);
        }
    }
    char cn[z+2][35];
    for (int j = 1; j < z + 1; j++) {
        printf("ENTER THE NAME OF CANDIDATE %d: ", j);
        scanf(" %[^\n]s", cn[j]);
        printf("\n");
        for (int k = 0; k < 35 && cn[j][k] != '\0'; k++) {
            if (cn[j][k] > 96) {
                cn[j][k] = cn[j][k] - 32;
            }
        }
        printf("YOU HAVE ENTERED THE NAME FOR CANDIDATE %d AS %s \nPRESS 0 TO CONFIRM OR 1 TO RE-ENTER: ", j, cn[j]);
        scanf("%d", &i);
        if (i) {
            j--;
        }
    }
    system("cls");
    printf("THE FINAL CANDIDATES LIST IS PRINTED BELOW\n");
    for (int j = 1; j < z + 1; j++) {
        printf("%d. %s \n", j, cn[j]);
    }
    int v;
    printf("ENTER NUMBER OF VOTERS: ");
    scanf("%d", &v);
    int p[z + 1];
    for (int j = 0; j <= z; j++) {
        p[j] = 0;
    }
    printf("VOTING STARTS NOW\n");
    system("cls");
    for (i = 1; i <= v; i++) {
        int t;
        printf("-----------------------------------------\n");
        printf("%s\n", name);
        printf("-----------------------------------------\n");
        printf("DEAR VOTER %d PLEASE SELECT A CANDIDATE\n", i);
        for (int j = 1; j < z + 1; j++) {
            printf("%d. %s \n", j, cn[j]);
        }
        printf("%d. NOTA\n", z + 1);
        printf("-----------------------------------------\n");
        printf("PLEASE ENTER YOUR CANDIDATE OF YOUR WISH: ");
        scanf("%d", &t);
        int m = 1;
        while (m) {
            if (t == 0 || t > z + 1 || t < 0) {
                printf("PLEASE ENTER A VALID VALUE\n");
                printf("-----------------------------------------\n");
                printf("PLEASE ENTER YOUR CANDIDATE OF YOUR WISH: ");
                scanf("%d", &t);
            } else {
                int w = 0;
                printf("YOU HAVE SELECTED TO CAST YOUR VOTE FOR THIS PARTICULAR CANDIDATE:\n");
                printf("--------------------------------------------------------\n");
                printf("%d. %s \n", t, cn[t]);
                printf("--------------------------------------------------------\n");
                printf("PLEASE ENTER 0 TO PROCEED OR 1 TO RE-SELECT YOUR VOTE: ");
                scanf("%d", &w);
                if (w == 1) {
                    m = 0;
                    i--;
                    system("cls");
                } else if (w == 0) {
                    m = 0;
                    system("cls");
                    p[t]++;
                }
            }
        }
        system("cls");
    }
    printf("PLEASE ENTER THE PASSWORD TO ENTER INTO CONTROL MODULE: ");
    int ent;
    scanf("%d", &ent);
    int m = 1;
    while (m) {
        if (ent == pass) {
            printf("THE RESULTS ARE GIVEN BELOW\n");
            for (int i = 1; i <= z; i++) {
                printf("%d. %-35s %d VOTES\n", i, cn[i], p[i]);
            }
            m = 0;
        }
    }
    int max = p[1];
    int maxv = 1;
    for (i = 1; i <= z; i++) {
        if (p[i] > max) {
            maxv = i;
        }
    }
    printf("----------------------------------------------------------\n");
    printf("THE WINNER IS \n %-35s %d VOTES\n", cn[maxv], p[maxv]);
    printf("----------------------------------------------------------\n");
    
    return 0;
}
