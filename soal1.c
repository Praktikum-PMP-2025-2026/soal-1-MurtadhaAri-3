#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
}Arsip;

int kompare (const void*a, const void *b){
    Arsip *x = (Arsip*)a;
    Arsip *y = (Arsip*)b;
    int c = strcmp (x->kategori, y ->kategori);
    if (c != 0) return c;
    if ( x->tahun != y->tahun) return (x ->tahun - y ->tahun);
    if (x ->nilai != y->nilai) return (y->nilai - x->nilai);
    return strcmp (x->nama, y->nama);
}

int main() {
    int N;
    // Melakukan memory allocation
    if(scanf("%d", &N) != 1) return 0;
    // Arsip * = (Arsip *)malloc(N * sizeof(Arsip));
    Arsip array1[N];
    for(int i = 0;i<N;i++){
        scanf("%s %s %d %d", array1[i].nama, array1[i].kategori, &array1[i].tahun, &array1[i].nilai);
    }
    // inisiasi kategori
    // buat sorting
    qsort(array1,N,sizeof(Arsip),kompare);

    for(int i = 0; i<N;i++){
        printf("%s %s %d %d", array1[i].nama, array1[i].kategori, array1[i].tahun, array1[i].nilai);
        printf("\n");
    }


    return 0;
    
}
