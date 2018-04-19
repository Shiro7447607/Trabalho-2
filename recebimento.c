/*
Alunos-Matrícula:
 Marcos Nery Borges Junior - 17/0017885
 Matheus Salles Blanco - 16/0138400
 Gabriel Braga Mendes - 15/0126077
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int** receber(char arquivo[]);

int main () {
        


   // printf("%d %d\n",row,column);
    //printf("%d",imagem[row-2][1024]);
   // printf("%d ",imagem[1024][1024]);
          
   //char nome[] = "grass_01.txt";
   int **imagem;
   imagem = receber("grass_01.txt");
   printf("%d ",imagem[1024][1024]);
 
 
    
    
   return 0;
}

int** receber (char arquivo[]){
    
    int** imagem;
    
    
    FILE *fp;
    if((fp=fopen(arquivo, "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    int n,i;
    char c;
    
    
    
    if((imagem = (int**)malloc(1*sizeof(int*)))==NULL){
        
            printf("Erro na alocacao");
            exit(1);
        }
    
    
    if((imagem[0] = (int*)malloc(1*sizeof(int)))==NULL){
         
           printf("Erro na alocacao"); 
           exit(1);
        }
    
    
    
    
   // int * ar;
    //ar = (int*)malloc(1*sizeof(int));
    int row =0;
    int column =0;
    int count = 0;
    int aux =0;
    
    while(!feof(fp)){
    
        fscanf(fp,"%d%c",&n,&c);
        
        imagem[row][column] = n;
        aux++;
        
        if(c=='\n'){
            
            
            row++;
            if((imagem = (int**)realloc(imagem,(row+1)*sizeof(int*)))==NULL){
                
                  printf("Erro na alocacao"); 
                  exit(1);
                
                }
            if((imagem[row] = (int*)malloc(1*sizeof(int)))==NULL){
                
                    printf("Erro na alocacao");
                    exit(1);
                }
            column=0;
            aux=0;
            continue;
        }
        //count++;
        //imagem[row] = (int*)realloc(imagem[row],(column+1)*sizeof(int));
        //imagem[row][column]=n;
        
        column++;
        if((imagem[row] = (int*)realloc(imagem[row],(column+1)*sizeof(int)))==NULL){
            
                printf("Erro na alocacao");
                exit(1);
              
            }
    
        
    }
    
    return imagem;
}