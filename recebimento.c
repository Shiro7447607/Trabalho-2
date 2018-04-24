/*
Alunos-Matrícula:
 Marcos Nery Borges Junior - 17/0017885
 Matheus Salles Blanco - 16/0138400
 Gabriel Braga Mendes - 15/0126077
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int** receber(char arquivo[], int *tamanho);
void montar_vet_treino(int *vet);
void preencher_vet_norm(int indice, int tipo, float *vet);
void preencher_ilbp(float *vet, int tam, int **matriz);
void criar_bin(int tam,int **matriz, int *vet, int row, int cl);
int bin_dec(int *vet);
void preencher_glcm(float *vet, int tam, int **matriz);
void calc_metr(int tam, int **matriz, float *vet, int dir);

int main () {
    


    //Processo de treinamento
    int *img, *ima,i;
    float *vm_img, *vm_ima;
    
    img = (int*)calloc(25,sizeof(int));
    
    if (img == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}
    
    ima = (int*)calloc(25,sizeof(int));
    if (ima == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}

    //Gerando 25 indices aleatorios de imagens de cada grupo
    srand(time(NULL));
    montar_vet_treino(ima);
    montar_vet_treino(img);
    
    
    //Criando e preenchendo os vetores normalizados do treinamento
    vm_img = (float*)calloc(536,sizeof(int));
    
    if (vm_img == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}
    
    vm_ima = (float*)calloc(536,sizeof(int));
    if (vm_ima == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}
    
//    for(i=0;i<25;i++){
//         
//          
//        
//        
//        }
    
    preencher_vet_norm(1,0,vm_ima);

    
    
   return 0;
}

int** receber (char arquivo[], int* tamanho){
    
    int** imagem;
    
    
    FILE *fp;
    if((fp=fopen(arquivo, "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    int n;
    char c;
    
    
    
    if((imagem = (int**)malloc(1*sizeof(int*)))==NULL){
        
            printf("Erro na alocacao");
            exit(1);
        }
    
    
    if((imagem[0] = (int*)malloc(1*sizeof(int)))==NULL){
         
           printf("Erro na alocacao"); 
           exit(1);
        }
    
    
    

    int row =0;
    int column =0;
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

        
        column++;
        if((imagem[row] = (int*)realloc(imagem[row],(column+1)*sizeof(int)))==NULL){
            
                printf("Erro na alocacao");
                exit(1);
              
            }
    
        
    }
    
    
    *tamanho = row-2;
    return imagem;
}
int bin_dec(int *vet){
    
    int i,dec=0,aux=8;
    for(i=0;i<9;i++){
        
         dec += vet[i] * pow(2,aux);
         aux--;
        
    } 
    
   return dec;
}

void montar_vet_treino(int *vet){
    
    
    int check,r,i,q=0;
    
    while(q<25){
        
        
        check = 0;
        r = (rand() % 50)+1;
        
        for(i=0;i<25;i++){
             
              if(vet[i]==r){check=1;}
            
        }
        
        if(check != 1){
             
              vet[q] = r;
              q++; 
            
        }
        
    }
    
}

void criar_bin(int tam,int **matriz, int *vet, int row, int cl){
    
 int elem[] = {matriz[row-1][cl-1],matriz[row-1][cl],matriz[row-1][cl+1],matriz[row][cl-1],matriz[row][cl],matriz[row][cl+1],matriz[row+1][cl-1],matriz[row+1][cl],matriz[row+1][cl+1]};
 float m = 0,i; 
 int bin[9],min,temp;
 for(i=0;i<9;i++){
      m += elem[i]/9.0;
     } 
  
  for(i=0;i<9;i++){
      if(elem[i]>m){bin[i]=1;}
      else{bin[i]=0;}
   }
   
   min = bin_dec(bin);
   for(i=0;i<9;i++){
      temp = bin[i];
      bin[i] = bin[8];
      bin[8] = temp;
      if(min>bin_dec(bin)){min = bin_dec(bin);}
   }
   
   vet[min] += 1;
}

void preencher_ilbp(float *vet, int tam, int **matriz){
     
      //Processo ILBP
      int i,j;
      for(i=1;i<1024;i++){
           for(j=1;j<1024;j++){
               
                 criar_bin(tam,matriz,vet,i,j);
               
               }
    }
      
    
    
}
void calc_metr(int tam, int **matriz, float *vet, int dir){
    
  int **moc,i;
  moc = (int**)calloc(1025,sizeof(int*));  
  for(i)
    
  if(dir==0){
      
      
      
      }
  else if(dir==1){}
  else if(dir==2){}
  else if(dir==3){}
  else if(dir==4){}
  else if(dir==5){}
  else if(dir==6){}
  else if(dir==7){}
  else{}
    
    
    
}
void preencher_glcm(float *vet, int tam, int **matriz){
    
    
    
    
    
    }
void preencher_vet_norm(int indice, int tipo, float *vet){
      
    char nome[15];
    int tamanho;
     //0 = grama 1= asfalto
     if(tipo ==0){
            sprintf(nome, "%s%.2d%s", "grass_",indice,".txt");
         }   
     else{
            sprintf(nome, "%s%.2d%s", "asphalt_",indice,".txt");
         }  
     
   int **imagem;
   imagem = receber(nome,&tamanho);
   
   //Processo ILBP
   
   //Precisa ser float ?
   float *vet_n; 
   vet_n = (float*)calloc(536,sizeof(float));
   if(vet_n == NULL){printf("Erro na alocacao");exit(1);}
   preencher_ilbp(vet_n,tamanho,matriz);
   //Processo GLCM
   
    

}