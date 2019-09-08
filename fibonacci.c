#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long unsigned int fiboRec( long unsigned int );
long unsigned int fiboIter( long unsigned int );
void salvaDados( char*, double, int );
void limpaArquivo( char* );

int main( void ){
    int i;
    long int inicio, fim;
    long unsigned int num, resultado;
    double dado;
    char *arquivoRec = "recursiva.csv", *arquivoIte = "iterativa.csv";

    limpaArquivo(arquivoRec);
    limpaArquivo(arquivoIte);

    for( i = 0; i < 10000; i++ ){
    }


    for( i = 1; i <= 55; i++){
        inicio = clock();
        resultado = fiboRec(i);
        fim = clock();

        dado = (double)(fim - inicio)/CLOCKS_PER_SEC;
        salvaDados( arquivoRec, dado, i );


        inicio = clock();
        resultado = fiboIter(i);
        fim = clock();

        dado = (double)(fim - inicio)/CLOCKS_PER_SEC;
        salvaDados( arquivoIte, dado, i );
    }

    return 0;
}


long unsigned int fiboRec( long unsigned int num ){
    if ( num == 1 || num == 2 ){
        return 1;
    }

    return fiboRec(num-1) + fiboRec(num-2);
}


long unsigned int fiboIter( long unsigned num ){
    long unsigned int fibo1 = 1, fibo2 = 1;
    int i;

    for( i = 2; i < num; i++){
        fibo1 += fibo2;
        fibo2 = fibo1 - fibo2;
    }

    return fibo1;
}


void salvaDados( char* nome, double dado, int num ){
    FILE *dados;

    dados = fopen(nome, "a");

    if( dados == NULL ){
        printf("Não foi possível abrir o arquivo.\n");
        exit(1);
    }

    fprintf(dados, "%f, %d\n", dado, num);

    fclose(dados);
}


void limpaArquivo( char* nome ){
    FILE *dados;

    dados = fopen(nome, "w");

    fclose(dados);
}