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
int bin_dec(int *vet);
void criar_bin(int tam,int **matriz, float *vet, int row, int cl);
void preencher_ilbp(float *vet, int tam, int **matriz);
void calc_metr(int tam, int **matriz, float *vet, int pi,int dir);
void preencher_glcm(float *vet, int tam, int **matriz);
void normalizar_vet(int tam, float *vet);
void preencher_vet_med(int indice, int tipo, float *vet);
void executar_testes(int indice, int tipo,float *vimg, float *vima,float *ac,float *fa, float* fr);


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
    
    printf("Vetores de indice de treinamento montados\n");
    
    //Criando e preenchendo os vetores normalizados do treinamento
    vm_img = (float*)calloc(536,sizeof(int));
    
    if (vm_img == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}
    
    vm_ima = (float*)calloc(536,sizeof(int));
    if (vm_ima == NULL){printf("Alocacao falhou. Finalizado.\n");exit(1);}
    
    printf("Vetores de media alocados\n");
    
    for(i=0;i<25;i++){
        
        preencher_vet_med(img[i],0,vm_img);
        
        }
        
    printf("Vetor de medias normalizadas do tipo grama preenchido\n");
    for(i=0;i<25;i++){
        
        preencher_vet_med(ima[i],1,vm_ima);
        
        }
    printf("Vetor de medias normalizadas do tipo asfalto preenchido\n");

        
    //Criando o vetor indice de testes
    
    int it_img[25],it_ima[25],j,check=0,iaux=0;
    
    for(i=1;i<=50;i++){
           
             for(j=0;j<25;j++){
                  
                  if(img[j] == i){check=1;}
                 
                 }
            if(check==0){
                   it_img[iaux] = i;
                   iaux++;
                }
         check = 0;
           
    }
        printf("Vetor de indices de teste do tipo grama preenchido\n");

    check = 0,iaux=0;
    for(i=1;i<=50;i++){
           
             for(j=0;j<25;j++){
                  
                  if(ima[j] == i){check=1;}
                 
                 }
            if(check==0){
                   it_ima[iaux] = i;
                   iaux++;
                }
        check = 0;
    }
        
       printf("Vetor de indices de teste do tipo asfalto preenchido\n");

 
    float ac=0,fa=0,fr=0;
    
    
    
    for(i=0;i<25;i++){
        
        executar_testes(it_img[i],0,vm_img,vm_ima,&ac,&fa,&fr);
        
    }
    
    printf("Testes com o grupo de imagens do tipo grama finalizados\n");
        
    for(i=0;i<25;i++){
        
        executar_testes(it_ima[i],1,vm_img,vm_ima,&ac,&fa,&fr);
        
    }
   printf("Testes com o grupo de imagens do tipo asfalto finalizados\n");
    
  ac = (ac/50.0)*100;
  fa = (fa/50.0)*100;
  fr = (fr/50.0)*100;
        
  printf("Taxa de acerto: %.2f %% \nTaxa de falsa aceitacao: %.2f %% \nTaxa de falsa rejeicao: %.2f %% \n",ac,fa,fr);      
        
  printf("\nGrupo grama utilizado:\n");
  
  for(i = 0;i<25;i++)
      printf("%d ",img[i]);
 printf("\nGrupo asfalto utilizado:\n");

  for(i = 0;i<25;i++)
      printf("%d ",ima[i]);
  printf("\nGrupo grama utilizado:\n");

  for(i = 0;i<25;i++)
    printf("%d ",it_img[i]);
  printf("\nGrupo asfalto utilizado:\n");

  for(i = 0;i<25;i++)
    printf("%d ",it_ima[i]);

  
  
  free(img);
  free(ima);
  free(vm_ima);
  free(vm_img);  

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
    
    
    *tamanho = row-1;
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

void criar_bin(int tam,int **matriz, float *vet, int row, int cl){
    
 int elem[] = {matriz[row-1][cl-1],matriz[row-1][cl],matriz[row-1][cl+1],matriz[row][cl-1],matriz[row][cl],matriz[row][cl+1],matriz[row+1][cl-1],matriz[row+1][cl],matriz[row+1][cl+1]};
 float m = 0;
 int i; 
 int bin[9],min,temp,temp2,z;
 for(i=0;i<9;i++){
      m += elem[i]/9.0;
     } 
  
  for(i=0;i<9;i++){
      if(elem[i]>m){bin[i]=1;}
      else{bin[i]=0;}
   }
   
   min = bin_dec(bin);
   for(i=0;i<9;i++){
      temp = bin[0];
      bin[0] = bin[8];
      for(z=1;z<9;z++){
          temp2 = bin[z];
          bin[z] = temp;
          temp = temp2;
      }
      
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
void calc_metr(int tam, int **matriz, float *vet, int pi,int dir){
    
  int **mgl,i,j;
  mgl = (int**)calloc(256,sizeof(int*));
  for(i=0;i<256;i++){
      
        *(mgl+i) = calloc(256,sizeof(int));
      }
  
  
  switch(dir){
    
       case 0:
         
          for(i=0;i<1025;i++){
             for(j=1;j<1025;j++){
              
                    mgl[matriz[i][j-1]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 1:
          for(i=1;i<1025;i++){
             for(j=0;j<1025;j++){
              
                    mgl[matriz[i-1][j]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 2:
          for(i=0;i<1025;i++){
             for(j=0;j<1024;j++){
              
                    mgl[matriz[i][j+1]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 3:
          for(i=0;i<1024;i++){
             for(j=0;j<1025;j++){
              
                    mgl[matriz[i+1][j]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 4:
          for(i=1;i<1025;i++){
             for(j=0;j<1024;j++){
              
                    mgl[matriz[i-1][j+1]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 5:
          for(i=0;i<1024;i++){
             for(j=0;j<1024;j++){
              
                    mgl[matriz[i+1][j+1]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 6:
          for(i=0;i<1024;i++){
             for(j=1;j<1025;j++){
              
                    mgl[matriz[i+1][j-1]][matriz[i][j]]++;
                            
             }
          }
          break;
        case 7:
          for(i=1;i<1025;i++){
             for(j=1;j<1025;j++){
              
                    mgl[matriz[i-1][j-1]][matriz[i][j]]++;
                            
             }
          }
          break;
      
      
      
    }
    
    
    float contr=0,ener=0,hom=0;
    
    for(i=0;i<256;i++){
        for(j=0;j<256;j++){
        
            ener += pow(mgl[i][j],2);
            contr += pow(i-j,2) * mgl[i][j];
            hom += mgl[i][j]/(1+sqrt(pow(i-j,2)));
        }
        
    }
  
   vet[pi] = contr;
   vet[pi+1] = ener;
   vet[pi+2] = hom; 
   
   for(i=0;i<256;i++){
       
        free(mgl[i]);
       
       }
       free(mgl);

}
void preencher_glcm(float *vet, int tam, int **matriz){
    
  int i,pi=512;
  for(i=0;i<8;i++){
     
     calc_metr(tam,matriz,vet,pi,i);
     pi += 3;
  }
    
}

void normalizar_vet(int tam, float* vet){
    
   int min = vet[0],i,max=vet[0];
   for(i=1;i<tam;i++){
          if(vet[i]>max){max=vet[i];}
          if(vet[i]<min){min=vet[i];}
       }
    for(i=0;i<tam;i++){
        
         vet[i] = (vet[i] - min)/(float)(max-min);
        
        }
    
}
void preencher_vet_med(int indice, int tipo, float *vet){
      
    char nome[15];
    int tamanho;
     //0 = grama 1= asfalto
     if(tipo ==0){
            sprintf(nome, "%s%.2d%s", "DataSet\\grass\\grass_",indice,".txt");
         }   
     else{
            sprintf(nome, "%s%.2d%s", "DataSet\\asphalt\\asphalt_",indice,".txt");
         }  
     
   int **imagem;
   imagem = receber(nome,&tamanho);
   
   //Processo ILBP
   
   //Precisa ser float ?
   printf("Imagem atual recebida\n");
   
   float *vet_n;
   int i; 
   vet_n = (float*)calloc(536,sizeof(float));
   if(vet_n == NULL){printf("Erro na alocacao");exit(1);}
   preencher_ilbp(vet_n,tamanho,imagem);
   printf("Fim do processo ilbp\n");
   //Processo GLCM
   preencher_glcm(vet_n,tamanho,imagem);
   printf("Fim do processo glcm\n");
     
   normalizar_vet(536,vet_n);
   printf("Fim da normalizacao\n");
   for(i=0;i<536;i++){
       
         vet[i] += (vet_n[i]/25.0);
       
    }
    printf("Fim do calculo da media na imagem atual\n--------------------\n");
   
   for(i=0;i<tamanho;i++){
       
        free(imagem[i]);
       
       }
       
       free(imagem);
      free(vet_n);
}
void executar_testes(int indice, int tipo, float *vimg, float *vima,float *ac,float *fa, float* fr){
      
    char nome[15];
    int tamanho;
     //0 = grama 1= asfalto
     if(tipo ==0){
            sprintf(nome, "%s%.2d%s", "DataSet\\grass\\grass_",indice,".txt");
         }   
     else{
            sprintf(nome, "%s%.2d%s", "DataSet\\asphalt\\asphalt_",indice,".txt");
         }  
     
   int **imagem;
   imagem = receber(nome,&tamanho);
   
   //Processo ILBP
   
   //Precisa ser float ?
   printf("Imagem atual recebida\n");
   
   float *vet_n; 
   vet_n = (float*)calloc(536,sizeof(float));
   if(vet_n == NULL){printf("Erro na alocacao");exit(1);}
   preencher_ilbp(vet_n,tamanho,imagem);
   //Processo GLCM
   preencher_glcm(vet_n,tamanho,imagem);
   
   printf("Processos ILBP e GLCM finalizados\n");
   
    normalizar_vet(536,vet_n);
        
    printf("Normalizacao do vetor atual concluida\n");
    float deg = 0;
    float dea = 0;      
    int i;
    for(i=0;i<536;i++){
        
        deg += pow((vet_n[i]-vimg[i]),2);
        dea += pow((vet_n[i]-vima[i]),2);
        
     }
     
     deg = sqrt(deg);
     dea = sqrt(dea);
     printf("Calculo das distancias euclidianas concluido\n");
     
   if(deg<dea && tipo==0){*ac += 1;}  
   else if(deg>dea && tipo==1){*ac += 1;}  
   else if(deg<dea && tipo==1){*fa += 1;}  
   else if(deg>dea && tipo==0){*fr += 1;}  
   printf("Comparacao atual concluida\n--------------------\n");
   
   for(i=0;i<tamanho;i++){
       
        free(imagem[i]);
       
       }
       
       free(imagem);
      free(vet_n);
}