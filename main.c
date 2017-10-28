/**
 Tugas Data Structure

 @author : Verri Andriawan <verri [at] tiduronline.com>
 @kelas  : 22
 @NIM    : 14111036
 @date   : 27 October 2017 

 Universitas Mercubuana Yogyakarta
------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include "nasabah.h"

void questionPrompt(char *cp) {
    printf("Menu Utama 'Data Nasabah'\n");
    printf("1. Enqueue Data\n");
    printf("2. Dequeue Data\n");
    printf("3. Display Data\n");
    printf("Esc. Exit\n");
    printf("Pilih : ");

    //*cp = 0x00; // reset buffer
    fgets(cp, 4, stdin);
}

int main() {
    char ipt; // read input from user
	Queue queue;
	Nasabah nasabah;
    initQueue(&queue);

    system("clear");
    do {
        questionPrompt(&ipt);
        switch(ipt) {

            // Input Data Nasabah
            // -----------------------
            case '1':
                if(isFull(&queue)) {
                    system("clear");
                    printf("\n-------------------------------\n");
                    printf("Database is full\n");
                    printf("-------------------------------\n\n");
                } else {
                    NasabahQueue(&queue, &nasabah);
                    system("clear");
                }
            break;


            // Delete Data New
            // -----------------------
            case '2': 
                system("clear");
                printf("\n-------------------------------\n");
                NasabahDequeue(&queue);
                printf("-------------------------------\n\n");
            break;


            // Display Data
            // -----------------------
            case '3': 
                system("clear");
                printf("\n-------------------------------\n");
                DisplayNasabah(&queue);
                printf("-------------------------------\n\n");
            break;
        }

        

    } while ( (int)ipt != 27 ); // Escape Code

}