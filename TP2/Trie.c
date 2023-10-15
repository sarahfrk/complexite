#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//************************* Algo 1 - Tris par selection *******************************************************************************
//on cherche le min a droite
void Tri_par_selection(int *Tab, int n){
    int i, min, j, temp, cmpt=0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
        	if(Tab[j] < Tab[min]){
        		cmpt++;
        		min = j;
                temp = Tab[i];
                Tab[i] =Tab[min];
                Tab[min] = temp;
                min = i;
			}

        }
    }
    printf("\t%d\t",cmpt);
}

//************************* Algo 2 - par insertion *******************************************************************************
//parcourir 2 tab: tab trie et l'autre non
void tri_insertion(int *T, int n)
{
	int i, k, c, p, cmpt=0;
	for(i=1; i < n; i++)
	{
		c = T[i];
		p = 0;
		while (T[p] < c){
		    // on cherche la position p que l' on va affecter � l'�l�ment
		    cmpt++;
	        p++;
		}
		for (k=i-1; k>=p; k--){
			// on d�cale les nombres
	    	T[k+1] = T[k];
		}
		// on �crit l'�l�ment
		T[p] = c ;
   }
   printf("\t%d\t",cmpt);
}


//************************* Algo 3 - Tris par bulle *******************************************************************************
//comparaison 2 a 2 consecutif
void tri_bulle(int *T,int n)
{
	int flag, i, c, cmpt=0;
    flag=1;
    while (flag)
    {
    	//tant qu'on modifie le tableau
        flag=0; i=0;
        while (i<n-1)
        {
        	if(T[i]>T[i+1])
        	{ //si �l�ment est sup�rieur au suivant on �change les deux nombres
        	    cmpt++;
                c=T[i];
                T[i]=T[i+1];
                T[i+1]=c;
                flag=1;
			}
			i++;
		}
	}
	printf("\t%d\t",cmpt);
}



//************************* Algo 4 - Tris rapide *******************************************************************************
//choisir un pivot : plus petit de pivot a G
void changer(int *T, int i, int j)
{
    int echange;
    echange=T[i];
    T[i]=T[j];
    T[j]=echange;
}
int partition(int*tableau, int deb, int fin)
{
	int compt=deb;
	int pivot=tableau[deb];
	int i;
	for(i=deb+1;i<=fin;i++){
		if(tableau[i]<pivot){
			compt++;
            changer (tableau, compt, i);
		}
	}
	changer (tableau, compt, deb) ;
    return (compt) ;
}

int tri_rapide_bis(int *tableau,int debut,int fin)
{ 
    int pivot = 0;
	if (debut<fin){
		pivot=partition(tableau, debut, fin);
        tri_rapide_bis(tableau, debut, pivot-1);
        tri_rapide_bis (tableau, pivot+1, fin);
	}
	return pivot;
	
}
void tri_rapide(int *tableau,int n)
{
	int cmpt = tri_rapide_bis(tableau,0,n-1);
	printf("\t%d\t",cmpt);
}


//*************************** Algo 5 - Tris par fusion *******************************************************************************
//dichotomique on divise le tab en 2, on tri chaqu'un d'entre eux apr on fusionne
int triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}

    int m = (i + j) / 2;

    triFusion(i, m, tab, tmp); //trier la moiti� gauche r�cursivement
    triFusion(m + 1, j, tab, tmp); //trier la moiti� droite r�cursivement
    int pg = i; //pg pointe au d�but du sous-tableau de gauche
    int pd = m + 1; //pd pointe au d�but du sous-tableau de droite
    int c; //compteur
// on boucle de i � j pour remplir chaque �l�ment du tableau final fusionn�
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            cmpt++;
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            cmpt++;
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un �l�ment plus petit
            cmpt++;
            tmp[c] = tab[pg];
            pg++;
        }else { //le pointeur du sous-tableau de droite pointe vers un �l�ment plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) { //copier les �l�ments de tmp[] � tab[]
        tab[c] = tmp[c];
    }
    return cmpt;
}

//************************** Algo 6 - Tris par tas *******************************************************************************
//permutation entre le 1er elmt et le dernier
void echanger(int *T, int i, int j)
{
	int echange;
    //permutation pour rendre s fils inferieurs � leurs p�re
    echange=T[i];
    T[i]=T[j];
    T[j]=echange;
}

int remonter (int *T, int n, int i)
{
	int c;
	if (i==0) return;
    if (T[i]>T[i/2]){
    	c++;
    	echanger (T, i, i/2);
        //si la valeur du fils est inferieur on le remonte
        remonter (T, n, i/2);
	}
	return c;
}

int redescendre ( int *T, const int n, int i)
{
	int cmpt;
	int imax;
    //pour s'arreter et mettre la plus grande valeur a la fin
    if (2*i+1>=n) return;
    if (T[2*i+1] > T[2*i])
    imax=2*i+1; // droite indice
    else
    imax=2*i; //guauche
    if (T[imax] > T[i])
	{
		cmpt++;
		echanger (T, imax, i);
        redescendre (T, n, imax);
	}
	return cmpt;
}

int organiser(int *T, int n )
{
	int i,c;
    for(i=1;i<n; i++)
    // organiser le tableau sous forme d'arbre (tas) les peres > fils
     c = remonter (T, n, i);
    return c;
}

void Tri_Arbre(int *T, const int n )
{
	int i, cmpt=0, c=0, resultat;
     c = organiser(T, n);
    for(i=n-1 ; i>0 ; i--)
    {
    	echanger(T, 0, i);
        //1a derniere valeur va eter remplac� par a racine la plus grande
        // valeur qui se trouve au debut du tablea
        cmpt = redescendre (T, i, 0);
	}
	resultat = cmpt + c;
	printf("\t%d\t",resultat);
}







int main(int argc, char** argv){
	int   currentNumber;
    char   *endChar;
	
	char *buffer11 = malloc(sizeof(char) * 10000);
    char *buffer12 = malloc(sizeof(char) * 10000);
    char *buffer13 = malloc(sizeof(char) * 10000);
    
    int *tableu11 = malloc(sizeof(int) * 10000);
    int *tableu12 = malloc(sizeof(int) * 10000);
    int *tableu13 = malloc(sizeof(int) * 10000);
    
    int *tmp = malloc(sizeof(int) * 10000);
    
    int i =0, j=0, k=0;

    FILE *fp11, *fp12, *fp13;  //10000
    
    clock_t t11, t12, t21, t22, t31, t32;
    double delta1,delta2,delta3;
    double resulta[3][6];
    
    
    
    printf("\nLes resultats pour la taille de 10000\n\n");
    printf("Le nombre de comparaison pour les fichiers: bon ordre, ordre inverse, al�atoires est dans l'ordre: \t\n");


            //ouverture fichier Les donn�es du tableau sont tri�es en bon ordre:
            fp11 = fopen("C:/Users/AHM/Desktop/master/S1/Complexite/TP/TP2/listebo1.txt","r");
           if(NULL == fp11)
           {
             return(1);
           }

           //une boucle qui prend chaque ligne les unes apres les autres jusqu'� la fin du fichier
           while(NULL != fgets(buffer11, 10000, fp11))
           {
            //printf("nouvelle ligne: \n");
             currentNumber = strtol(buffer11, &endChar, 10);
             tableu11[i] = currentNumber;
            //on entre dans la ligne pour reccuperer les nbr
            while(*endChar != (char) NULL)
            {
               char* ptr = endChar+1;
               currentNumber = strtol(ptr, &endChar, 10);
               i++;
               tableu11[i] = currentNumber;
            }
          }

          //ouverture fichier Les donn�es du tableau sont tri�es en ordre inverse:
           fp12 = fopen("C:/Users/AHM/Desktop/master/S1/Complexite/TP/TP2/listeio1.txt","r");
           if(NULL == fp12)
           {
             return(1);
           }

           //une boucle qui prend chaque ligne les unes apres les autres jusqu'� la fin du fichier
           while(NULL != fgets(buffer12, 10000, fp12))
           {
            //printf("nouvelle ligne: \n");
             currentNumber = strtol(buffer12, &endChar, 10);
             tableu12[j] = currentNumber;
            //on entre dans la ligne pour reccuperer les nbr
            while(*endChar != (char) NULL)
            {
               char* ptr = endChar+1;
               currentNumber = strtol(ptr, &endChar, 10);
               j++;
               tableu12[j] = currentNumber;
            }
          }


          //ouverture fichier Les donn�es du tableau ne sont pas tri�es:
            fp13 = fopen("C:/Users/AHM/Desktop/master/S1/Complexite/TP/TP2/listent1.txt","r");
           if(NULL == fp13)
           {
             return(1);
           }

           //une boucle qui prend chaque ligne les unes apres les autres jusqu'� la fin du fichier
           while(NULL != fgets(buffer13, 10000, fp13))
           {
            //printf("nouvelle ligne: \n");
             currentNumber = strtol(buffer13, &endChar, 10);
             tableu13[k] = currentNumber;
            //on entre dans la ligne pour reccuperer les nbr
            while(*endChar != (char) NULL)
            {
               char* ptr = endChar+1;
               currentNumber = strtol(ptr, &endChar, 10);
               k++;
               tableu13[k] = currentNumber;
            }
          }




          //***************************calcule du temps d'excecution de la langueur 10^4
          t11 = clock();
          // appel au fonction de tri d'un tableau
          //triFusion(0,9999,tableu11,tmp);
          Tri_Arbre(tableu11,10000);
          t12 = clock();
          delta1 = (double) (t12-t11)/CLOCKS_PER_SEC;
          //_____________________________________________________

          t21 = clock();
          // appel au fonction de tri d'un tableau
          //triFusion(0,9999,tableu12,tmp);
          Tri_Arbre(tableu12,10000);
          t22 = clock();
          delta2 = (double) (t22-t21)/CLOCKS_PER_SEC;
          //_______________________________________________________


          t31 = clock();
          // appel au fonction de tri d'un tableau
          //triFusion(0,9999,tableu13,tmp);
          Tri_Arbre(tableu13,10000);
          t32 = clock();
          delta3 = (double) (t32-t31)/CLOCKS_PER_SEC;
          //_______________________________________________________

          //L'AFFICHAGE DES RESULTATS de la langueur 10^4  ******

          printf("\n\n\t\tLE TRI PAR TAS\n\n");
          printf("****Les donnees du tableau sont triees en bon ordre****\n");
          printf("==>Le temps d'execution: (%lf)\n",delta1);
          printf("\n****Les donnees du tableau sont triees en ordre inverse****\n");
          printf("==>Le temps d'execution: (%lf\)\n\n",delta2);
          printf("****Les donnees du tableau ne sont pas triees****\n");
          printf("==>Le temps d'execution: (%lf)\n\n",delta3);


    int rps;
    printf("vous voullez afficher le tableau triee? choisisser 1 si c'est le cas.\t");
    scanf("%d",&rps);
    //l'affichage de tabkeau trie
    if(rps == 1){
    	for(i=1;i<10000;i++){
        printf("Le nombre courant = %d\n",tableu13[i]);
	}
  
  }
  free(tableu11); free(buffer11);
  free(tableu12); free(buffer12);
  free(tableu13); free(buffer13);
  free(tmp);

    
    
    
    
    
    
    
    
    
	
//	int i;
//	int tmp[6];
//    int T[6] = {23,10,50,9,12,99};
   //triFusion(0, 5, T, tmp);


//    tri_insertion(T, 6);
//
//
//    for(i=0;i<=5;i++){
//        printf("T[%d] = %d\n",i,T[i]);
//   }
	
	return 0;
}
