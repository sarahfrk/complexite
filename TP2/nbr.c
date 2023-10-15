#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	unsigned long long i;
	FILE* fichier=NULL;
	fichier = fopen("C:/Users/AHM/Desktop/listenbr.txt","w");
	
	for(i=1;i<=100000;i++){
		fprintf(fichier,"%llu;",i);
	}
	
//	for(i=1; i<=100000000; i++){
//		fprintf(fichier,"%llu;", 1 + rand() % 100000000);
//		
//	}
//	
	
	return 0;
}
