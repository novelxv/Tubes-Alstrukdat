/* File: queue.c */
/* *** Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik *** */

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void queue_CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean queue_isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean queue_isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return ((IDX_TAIL(q) == IDX_HEAD(q) - 1) || (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1));
}

int queue_length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (queue_isEmpty(q)){
        return 0;
    }
    else if (IDX_HEAD(q) <= IDX_TAIL(q)){
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    else{
        return (CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
    }
}

/* *** Primitif Add/Delete *** */
void queue_enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (queue_isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        if (IDX_TAIL(*q) == CAPACITY - 1){
            IDX_TAIL(*q) = 0;
        }
        else{
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void queue_dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        if (IDX_HEAD(*q) == CAPACITY - 1){
            IDX_HEAD(*q) = 0;
        }
        else{
            IDX_HEAD(*q)++;
        }
    }
}

/* *** Display Queue *** */
void queue_displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (queue_isEmpty(q)){
        printf("[]\n");
    }
    else{
        int i, j;
        if (IDX_TAIL(q) < IDX_HEAD(q)){
            printf("[");
            for (i = IDX_HEAD(q); i < CAPACITY; i++){
                printf("%d,", q.buffer[i]);
            }
            for (j = 0; j <= IDX_TAIL(q); j++){
                if (j < IDX_TAIL(q)){
                    printf("%d,", q.buffer[j]);
                }else{
                    printf("%d]\n", q.buffer[j]);
                }
            }
        }
        else{
            printf("[");
            for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
                if (i < IDX_TAIL(q)){
                    printf("%d,", q.buffer[i]);
                }else{
                    printf("%d]\n", q.buffer[i]);
                }
            }
        }
    }
}