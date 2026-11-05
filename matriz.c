#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int fila;
    int col;
    float valor;
}ElementoEsparso;

int main () {
    FILE *matA;
    FILE *matB;
    srand(time(NULL));
    int M,N,P;
    int min_dim=0,max_dim=1000;
    
    M=min_dim+rand()%(max_dim-min_dim+1);
    N=min_dim+rand()%(max_dim-min_dim+1);
    P=min_dim+rand()%(max_dim-min_dim+1);
    
    int nro_elementosA=(M*N)/20;
    int nro_elementosB=(N*P)/20;
    
    matA=fopen("matriz_a.txt","w");
    matB=fopen("matriz_b.txt","w");
    
    if (matA==NULL || matB==NULL) {
        printf("Uno de los dos archivos no se pudo crear.");
        return -1;
    }
    
    fprintf(matA,"%d %d\n",M,N);
    fprintf(matB,"%d %d\n",N,P);
    
    int contA=nro_elementosA;
    int contB=nro_elementosB;
    int i,j;
    float num;
    
    printf("Escribiendo en la matriz A\n");
    while (contA>0) {
        i=rand()%M;
        j=rand()%N;
        num=((float)(rand()/100));
        fprintf(matA,"%.2f %d %d\n",num,i,j);
        contA--;
    }
    
    printf("Escribiendo en la matriz B\n");
    while (contB>0) {
        i=rand()%N;
        j=rand()%P;
        num=((float)(rand()/100));
        fprintf(matB,"%.2f %d %d\n",num,i,j);
        contB--;
    }
    
    fclose(matA);
    fclose(matB);
    
    ElementoEsparso e;
    
    
    return 0;
}