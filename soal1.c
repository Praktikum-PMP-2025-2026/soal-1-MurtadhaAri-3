#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Arsip
{
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
};

int main() {
    int N;
    // Melakukan memory allocation
    if(scanf("%d", &N) != 1) return 0;
    // Arsip * = (Arsip *)malloc(N * sizeof(Arsip));
    struct Arsip array1[N];
    for(int i = 0;i<N;i++){
        scanf("%s %s %d %d", array1[i].nama, array1[i].kategori, &array1[i].tahun, &array1[i].nilai);
    }
    // inisiasi kategori
    // buat sorting
    for(int i = 0; i<N;i++){
        for(int j = 0; j<N-1;j++){
            int flag = 0;
            // Membandingkan kategori, kalo misal indeks j > j+1 saat 0, maka dia berubah dan nandain flag = 1
            if (strcmp(array1[j].kategori, array1[j+1].kategori) >0)
            {
                flag = 1;
            }
            else if(strcmp(array1[j].kategori, array1[j+1].kategori)==0){
                if(array1[j].tahun > array1[j+1].tahun){
                    flag = 1;
                }
                else if(array1[j].tahun == array1[j+1].tahun){
                    if(array1[j].nilai < array1[j+1].nilai){
                        flag = 1;
                    }
                    else if (array1[j].nilai == array1[j+1].nilai)
                    {
                        if(strcmp(array1[j].nama, array1[j+1].nama)){
                            flag = 1;
                        }
                    }
                    
                }
            }
            
            if(flag == 1){
                struct Arsip temp = array1[j];
                array1[j] = array1[j+1];
                array1[j+1] = temp;
            }
            // else if([j].tahun == [j+1].tahun){
            //     if([j].nilai < [j+1].nilai){
            //         flag = 1;
            //     }
            // }

            
        }
    }

    for(int i = 0; i<N;i++){
        printf("%s %s %d %d", array1[i].nama, array1[i].kategori, array1[i].tahun, array1[i].nilai);
        printf("\n");
    }


    return 0;
    
}
