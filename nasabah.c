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

void initQueue(Queue *queue) {
    queue->head = queue->tail = -1;
}


/**
 This will check that queue is empty
 return Int
-------------------------------------------- */
int isEmpty(Queue *queue) {
    if(queue->head == -1 && queue->tail == -1)
        return 1;
    return 0;
}

/**
 This will check that queue is Full
 return Int
-------------------------------------------- */
int isFull(Queue *queue) {
    int max_length = (queue->head < queue->tail && (queue->tail - queue->head) == MAX-1);
    int low_tail = (queue->head > queue->tail && (queue->head - queue->tail) == 1);

    if (max_length || low_tail)
        return 1;

    return 0;
}

/**
 This will check it just have one element inside
 return Int
-------------------------------------------- */

int isOneElement(Queue *queue) {
    if(queue->head == queue->tail && 
       queue->head!=-1)
        return 1;

    return 0;
}


/**
 Append data 'Nasabah' to our queue
 return Int
-------------------------------------------- */
int NasabahQueue(Queue *queue, Nasabah *nasabah) {
    inputData(nasabah);

    if(isEmpty(queue)) {
        queue->head = queue->tail = 0;
        queue->data[queue->tail] = *nasabah;
        return 0;
    }
    
    if(isFull(queue)) {
        printf("Database is full\n");
        return 0;
    } 

    if(queue->tail == MAX-1)
        queue->tail = 0;
    else 
        queue->tail++;

    queue->data[queue->tail] = *nasabah;
    return 0;
}


/**
 Delete data from queue
 return Int
-------------------------------------------- */
int NasabahDequeue(Queue *queue) {
    Nasabah data = queue->data[queue->head];

    if(isEmpty(queue)) {
        printf("Database is empty\n");
        return 0;
    }

    if(isOneElement(queue)) {
        initQueue(queue);

    } else {
    
        if(queue->head == MAX-1) {
            queue->head = 0;
            
        } else {
            queue->head++;
        }
    }

    printf("Data %s has been deleted \n", data.name);
    return 0;
}


/**
 Just show Nasabah Profile
-------------------------------------------- */

void showProfile(Nasabah *nasabah) {
    printf("Nama: %s\n", nasabah->name);
    printf("Phone: %s\n\n", nasabah->phone);
    printf("Alamat: %s\n\n", nasabah->address);

}


/**
 Aggregation Nasabah Profiles from Queue
 return Int
-------------------------------------------- */
void DisplayNasabah(Queue *queue) {
    if(isEmpty(queue)) {
        printf("Database is empty\n");
    } else {
        if(queue->head <= queue->tail) {
            for(int i=queue->head; i<queue->tail+1; i++) {
                printf("[+] Data: %d\n", i+1);
                showProfile(&queue->data[i]);
            }    
        }
        
    }
}


/**
 Input Data Nasabah
-------------------------------------------- */
void inputData(Nasabah *nasabah) {
    char *name, *phone, *address;

    name = (char *)malloc(sizeof(char));
    phone = (char *)malloc(sizeof(char));
    address = (char *)malloc(sizeof(char));

    printf("Tell me your name: "); scanf("%[^\n]%*c", name);
    printf("Your phone number: "); scanf("%[^\n]%*c", phone);
    printf("Alamat: "); scanf("%[^\n]%*c", address);

    nasabah->name     = name;
    nasabah->phone    = phone;
    nasabah->address  = address;
}


