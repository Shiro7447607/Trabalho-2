/*
Alunos-Matrícula:
 Marcos Nery Borges Junior - 17/0017885
 Matheus Salles Blanco - 16/0138400
 Gabriel Braga Mendes - 15/0126077
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
        
    FILE *fp;
    if((fp=fopen("asphalt_01.txt", "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    int n,i;
    char c;
    int **myarr;
    myarr = (int**)malloc(1*sizeof(int*));
    myarr[0] = (int*)malloc(1*sizeof(int));
    
   // int * ar;
    //ar = (int*)malloc(1*sizeof(int));
    int row =0;
    int column =0;
    int count = 0;
    int aux =0;
    
    while(!feof(fp)){
    
        fscanf(fp,"%d%c",&n,&c);
        
        myarr[row][column] = n;
        aux++;
        
        if(c=='\n'){
            
            
            row++;
            myarr = (int**)realloc(myarr,(row+1)*sizeof(int*));
            myarr[row] = (int*)malloc(1*sizeof(int));
            column=0;
            aux=0;
            continue;
        }
        //count++;
        //myarr[row] = (int*)realloc(myarr[row],(column+1)*sizeof(int));
        //myarr[row][column]=n;
        
        column++;
        myarr[row] = (int*)realloc(myarr[row],(column+1)*sizeof(int));
    
        
    }
    

   // printf("%d %d\n",row,column);
    //printf("%d",myarr[row-2][1024]);
    printf("%d ",myarr[1024][1024]);
        
 
    
    
   return 0;
}