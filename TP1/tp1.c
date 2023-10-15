#include <stdio.h>
#include <stdlib.h>
#include <time.h>




//------------------------------Algo1-----------------------------

//****on va faire une boucle dans laquelle on va tester si le nombre n est
//divisible par 2,3...,n-1(on epargne le 1 car tout les nombre sont divisible par 1

int Algorithme1(unsigned long long nbr){
    int premier = 1;
    unsigned long long i=2;
    while((i<=nbr-1) && (premier)){
        if(nbr%i == 0)  premier = 0;
        else i++;
    }
    return premier;
}


//------------------------------Algo2-----------------------------

//****on va arreter la boucle a n/2 car si n est divisible par 2 il est aussi divisible par n/2

int Algorithme2(unsigned long long nbr){
    int premier=1;
    unsigned long long i=2;
    while(i<=floor(nbr/2) && (premier)){
        if(nbr%i==0) premier = 0;
        else i++;
    }
    return premier;
}


//------------------------------Algo3-----------------------------

//****tester si n est impair dans ce cas il faut dans la boucle tester la divisibilite de n que par les nb impair

int Algorithme3(unsigned long long nbr){
    int premier = 1;
    if((nbr!=2) &&(nbr%2 == 0)) premier = 0;
    else if(nbr!=2){
       unsigned long long i=3;
       while((i<=nbr-2) && (premier)){
           if(nbr % i ==0) premier = 0 ;
           else i=i+2;
       }
    }
    return premier;
}


//------------------------------Algo4-----------------------------

//****melange de A2 ET A3

int Algorithme4(unsigned long long nbr){
    int premier = 1;
    if((nbr!=2) &&(nbr%2 == 0)) premier = 0;
    else if(nbr!=2){
                    unsigned long long i=3;
                    while((i<=floor(nbr/2)) && (premier)){
                        if(nbr % i ==0)
                            premier = 0 ;
                         else
                            i = i+2;
                    }
                    }
       return premier;
}

//------------------------------Algo5-----------------------------

//****arreter la boucle a racine de n au lieu de n/2 car si n est divisible par x il est
//aussi divisible par n/x donc ca ne sert a rien d'aller au dela de x=n/x

int Algorithme5(unsigned long long nbr){
    int premier = 1;
    unsigned long long i = 2;
    while((i<=floor(sqrt(nbr))) && (premier)){
        if(nbr%i==0) premier = 0 ;
        else i++;
    }
    return premier;
}

//------------------------------Algo6-----------------------------

//****melange de A3 et A5

int Algorithme6(unsigned long long nbr){
    int premier = 1;
    if((nbr!=2) &&(nbr%2 == 0))
        premier = 0;
    else
        if(nbr!=2){
                unsigned long long i=3;
                while((i<=floor(sqrt(nbr))) && (premier)){
                    if(nbr%i == 0)
                        premier = 0 ;
                     else
                        i = i+2;}
        }
   return premier;
}





int main()
{

    //DECLARATION DE 2 FICHIERS POUR LES RESULTATS
    FILE* fichier=NULL;
    FILE* fichierQst3=NULL;


    int nbrfois;


    //DECLARATIN DES TABLEAUX
    //QST1----
    unsigned long long Tab1[] = {8768477 ,20910101 ,65229067 , 501027419, 716786933,4617403429, 5544625589, 12469345529, 46885138957, 180327126037 };
    //QST2----
    unsigned long long Tab2[] = {105989621,133329107,135741521,177112589,277151089,324784529,378535273,379866931,469498597,508145639,509305891,644920949, 653273063,666183283,698207291,698779387,778377773,836627747,964521797,987952681};
    //QST3----
    unsigned long long Tab3[] = {7474387, 8768477, 20910101, 65229067, 501027419 };

    //CALCULE DES TAILLES DES 3 TABLEAUX
    int j=0;
    int taille1 = sizeof(Tab1)/sizeof(Tab1[0]);
    int taille2 = sizeof(Tab2)/sizeof(Tab2[0]);
    int taille3 = sizeof(Tab3)/sizeof(Tab3[0]);

    double Moyenne[20];
    double moy;



    //DECLARATION DES VARIABLES DE MESURE DU TEMPS
    clock_t t1,t2;
    double delta;
    float reel;

    int choix;
    printf("\n Choisissez votre chiffre:\n1 ->Pour s'executer la qst1 et qst2.\n2 ->Pour s'executer la qst3 50 fois.\n");
    printf("\nMon choix est:");
    scanf("%d",&choix);
    switch(choix){
    case 1:
        //CREATION DU FICHIER QUI VA STOCKER LES RESULTATS DE LA QST 1 ET 2
        fichier = fopen("C:/Users/AHM/Desktop/TempPrem12.txt","w");
                    //--------------------------QST1
            printf("---------------------------QST 1--------------------------------\n\n");
            printf("\t\t ALGORITHME 1\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme1(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D4EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n");

                //--------------------------ALGO2-----------------------------------
            printf("\n\t\t ALGORITHME 2\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme2(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D4EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n");

                //--------------------------ALGO3-----------------------------------
            printf("\n \t\t ALGORITHME 3\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme3(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D'EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n");


                //--------------------------ALGO4-----------------------------------
            printf("\n \t\t ALGORITHME 4\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme4(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D4EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n");

               //--------------------------ALGO5-----------------------------------
            printf("\n \t\t ALGORITHME 5\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme5(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D4EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n");

               //--------------------------ALGO6-----------------------------------
            printf("\n \t\t ALGORITHME 6\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille1;j++){

                    //1ERE VAR DE TEMPS
                    t1 = clock();

                    //APPEL AU FONCTION
                    int test=Algorithme6(Tab1[j]);

                    //AFFICHAGE (PREMIER OU NON)
                    if(test == 0){
                        printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab1[j]);
                    }else{
                        printf("*************** Le nombre ( %llu ) est premier.\n",Tab1[j]);
                    }

                    //2EME VAR DE TEMPS
                    t2 = clock();

                    //LA MOYENNE DE TEMPS D4EXECUTION
                    delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                    reel = (float)delta;

                    //AFFICHAGE DU TEMPS D'EXECUTION
                    printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab1[j],delta);

                    //SAISIE DANS LE FICHIER
                    fprintf(fichier,"%lf,",delta);
                }
                fprintf(fichier,"\n\n\n");



                                //--------------------------QST2
                printf("\n---------------------------QST 2--------------------------------\n\n");
                printf("\t\t ALGORITHME 1\n");
                    //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme1(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n");

                   printf("\n\t\t ALGORITHME 2\n");
                   //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme2(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n");

                 printf("\n\t\t ALGORITHME 3");
                    //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme3(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n");

                    printf("\n\t\t ALGORITHME 4\n");

                    //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme4(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n");

                    printf("\n\t\t ALGORITHME 5\n");

                    //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme5(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n");


                    printf("\n\t\t ALGORITHME 6\n");

                    //BOUCLE DE PARCOUR D'UN TABLEAU
                    for(j=0;j<taille2;j++){

                        //1ERE VAR DE TEMPS
                        t1 = clock();

                        //APPEL AU FONCTION
                        int test=Algorithme6(Tab2[j]);

                        //AFFICHAGE (PREMIER OU NON)
                        if(test == 0){
                            printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab2[j]);
                        }else{
                            printf("*************** Le nombre ( %llu ) est premier.\n",Tab2[j]);
                        }

                        //2EME VAR DE TEMPS
                        t2 = clock();

                        //LA MOYENNE DE TEMPS D4EXECUTION
                        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                        reel = (float)delta;

                        //AFFICHAGE DU TEMPS D'EXECUTION
                        printf("*************** Le temps d'execution de (%llu) est: ( %lf )\n\n",Tab2[j],delta);

                        //SAISIE DANS LE FICHIER
                        fprintf(fichier,"%lf,",delta);
                    }
                    fprintf(fichier,"\n\n\n");

                    fclose(fichier);


        break;
    case 2:

                      //--------------------------QST3
                //CREATION DU FICHIER QUI VA STOCKER LES RESULTATS DE LA QST 3
                fichierQst3 = fopen("C:/Users/AHM/Desktop/TempPrem3.txt","w");

                printf("---------------------------QST 3--------------------------------\n\n");
                printf("\t\t ALGORITHME 1\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme1(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");

                                printf("\t\t ALGORITHME 2\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme2(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");

                                printf("\t\t ALGORITHME 3\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme3(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");

                                printf("\t\t ALGORITHME 4\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme4(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");

                                printf("\t\t ALGORITHME 5\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme5(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");

                                printf("\t\t ALGORITHME 6\n");
                //BOUCLE DE PARCOUR D'UN TABLEAU
                for(j=0;j<taille3;j++){
                        for(nbrfois=0;nbrfois<50;nbrfois++){
                            //1ERE VAR DE TEMPS
                            t1 = clock();

                            //APPEL AU FONCTION
                            int test=Algorithme6(Tab3[j]);

                            //AFFICHAGE (PREMIER OU NON)
                            if(test == 0){
                                printf("*************** Le nombre ( %llu ) n'est pas premier!\n",Tab3[j]);
                            }else{
                                printf("*************** Le nombre ( %llu ) est premier.\n",Tab3[j]);
                            }

                            //2EME VAR DE TEMPS
                            t2 = clock();

                            //LA MOYENNE DE TEMPS D4EXECUTION
                            delta = (double)(t2-t1)/CLOCKS_PER_SEC;
                            reel = (float)delta;
                            Moyenne[j] = delta;
                        }
                        int t;
                        for(t=0;t<taille3;t++){
                             moy = (moy + Moyenne[t])/50;
                        }
                        printf("La moyenne du temps d'execution de %llu est %lf\n\n",Tab3[j],moy);
                        fprintf(fichierQst3,"%lf,",moy);

                        }
                fprintf(fichierQst3,"\n");






            fclose(fichierQst3);
        break;
    default:
        printf("\nErreur! Choix n'existe pas.\n\n");
    }




















    return 0;
}

