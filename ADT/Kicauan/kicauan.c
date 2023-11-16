#include <stdio.h>
#include "kicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../GrafTeman/grafteman.h"

int banyakKicauan;
Kicauan currentKicauan;

ListDinKicauan listDinKicauan;

void createKicauan(Kicauan *k, Word text, Word tagar){
    k = (Kicauan*) malloc(sizeof(Kicauan));
    if(k!=NULL){
        IDKICAU(*k) = listDinKicauan.nEff+1;
        setWord(&TEXT_KICAU(*k),text.TabWord);
        JUMLAH_LIKE(*k) = 0;
        setWord(&PEMBUAT(*k),Username(currentAkun).TabWord);
        SetToCurrentDateTime(&WAKTU(*k));
        setWord(&TAGAR(*k),tagar.TabWord);
        isUTAS(*k) = false;
    }
}

void printKicauan(Kicauan kicauan){
    printf("| ID = %d\n", IDKICAU(kicauan));
    printf("| ");
    // --> printWord(PEMBUAT(kicauan)); printf("\n");
    printWord(PEMBUAT(kicauan));
    printf("\n");
    printf("| ");
    // --> printDatetime(WAKTU(kicauan)); printf("\n");
    DisplayDateTime(WAKTU(kicauan));
    printf("\n");
    printf("| ");
    // --> printWord(TEXT_KICAU(kicauan)); printf("\n");
    printWord(TEXT_KICAU(kicauan));
    printf("\n");
    printf("| Disukai : %d", JUMLAH_LIKE(kicauan));
}

void kicau(){
    Word text_kicau, tagar;
    // Word input_kicauan;
    printf("Masukkan kicauan:\n");

    currentWord.Length = 0;
    currentWord = cleanWord(currentWord);
    STARTWORD();
    capCurrentWord(280);
    setWord(&text_kicau, currentWord.TabWord);

    printf("\n");

    // # Case 1 : input_kicauan hanya mengandung spasi saja
    if(text_kicau.Length == 0){
        printf("Kicauan tidak boleh kosong!");
        // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
    }
    // # Case 2 : input_kicauan valid, terima maksimal 280 character
    else{
        printf("Masukkan tagar:\n");
        currentWord.Length = 0;
        currentWord = cleanWord(currentWord);
        STARTWORD();
        setWord(&tagar, currentWord.TabWord);

        printf("\n");

        if(tagar.Length!=0){
            //Hash map
        }

        Kicauan k;
        createKicauan(&k, text_kicau, tagar);
        insertKicauan(&k);
        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        printKicauan(k);
        printf("\n");
        printf("\n");
    }
}

// void KICAUAN(){
//     int i;
//     if(isListKicauanEmpty()){
//         printf("Masih belum ada kicauan\n");
//     }else{
//         Kicauan currentKicauan;
//         for(i=NEFF_LIST_KICAUAN(listDinKicauan)-1;i>=0;i--){
//             currentKicauan = *ADDR_KICAUAN(listDinKicauan,i);
//             // if(isAkunBerteman(currentGrafTeman, akun1, akun2)){
//                 printKicauan(currentKicauan);
//                 printf("\n");
//             // }
//         }
//     }
// }

// void SUKA_KICAUAN(int id_kicau){
    // printf("\n");
    // if(!isIn(id_kicau,l_kicauan)){
    //     printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau);
    // }else if(!isAkunPublicByPengguna(getPembuatById(l_kicauan,id_kicau)) && !isBerteman(currPengguna,getPembuatById(l_kicauan,id_kicau))){
    //     printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya!")
    // }else{
    //     setLike(id_kicau, l_kicauan, 1+getLike(id_kicau, l_kicauan));
    //     printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
    //     printKicauan(getKicauan(l_kicauan,id_kicau));
    // }
    // printf("\n\n");
// }

// void UBAH_KICAUAN(int id_kicau){
//     int idxKicauan = id_kicau-1;
//     Kicauan k = *ADDR_KICAUAN(listDinKicauan,idxKicauan);
//     if(!isInListKicauan(id_kicau)){
//         printf("Tidak ditemukan kicauan dengan ID = %d!", id_kicau);
//     }else if(compareWord(Username(currentAkun),PEMBUAT(k))){ // pre-requisite: boolean isSama(Word w1, Word w2)
//         printf("Kicauan dengan ID = %d bukan milikmu!",id_kicau);
//     }else{
//         Word new_textKicauan;
//         printf("Masukkan kicauan baru:\n");
        // <--Disini nanti diminta masukan input_kicauan
        // printf("\n");
        // # Case 1 : input_kicauan hanya mengandung spasi saja

            // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");

        // # Case 2 : input_kicauan valid, terima maksimal 280 character

        // --> buat kicauan baru, masukin ke list_kicauan (ListDin)

        // Cetak pesan
//         printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
//         printKicauan(k);
//     } 
// }

void createListDinKicauan(ListDinKicauan *l, int cap){
    NEFF_LIST_KICAUAN(*l) = 0;
    CAP_LIST_KICAUAN(*l) = cap;
    CONTENTS_LIST_KICAUAN(*l) = (AddressKicauan*) malloc(cap * sizeof(AddressKicauan));
}

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2){
    int i;
    // createListDinKicauan(l2);
    for(i=0;i < NEFF_LIST_KICAUAN(*l1);i++){
        ADDR_KICAUAN(*l2,i) = ADDR_KICAUAN(*l1,i);
    }
    NEFF_LIST_KICAUAN(*l2) = NEFF_LIST_KICAUAN(*l1);
    CAP_LIST_KICAUAN(*l2) = CAP_LIST_KICAUAN(*l1);
}

void expandListKicauan(ListDinKicauan *l){
    int new_cap = 2 * CAP_LIST_KICAUAN(*l);
    ListDinKicauan lNew;
    createListDinKicauan(&lNew, new_cap);
    copyContentListKicauan(l, &lNew);
    *l = lNew;
}

boolean isFullListKicauan(ListDinKicauan l){
    return(NEFF_LIST_KICAUAN(l) == CAP_LIST_KICAUAN(l));
}

void insertKicauan(Kicauan *k){
    AddressKicauan p = k;
    if(isFullListKicauan(listDinKicauan)){
        expandListKicauan(&listDinKicauan);
    }
    int idx = NEFF_LIST_KICAUAN(listDinKicauan);
    ADDR_KICAUAN(listDinKicauan,idx) = p;
    NEFF_LIST_KICAUAN(listDinKicauan)++;
}

boolean isListKicauanEmpty(){
    return(NEFF_LIST_KICAUAN(listDinKicauan)==0);
}

boolean isInListKicauan(int idKicau){
    return(idKicau <= NEFF_LIST_KICAUAN(listDinKicauan) && idKicau >= 1);
}

void DebugListKicauan(){
    printf("======== [Debug listKicauan] ========\n");
    int i;
    for(i=0;i<banyakKicauan;i++){
        printf("[Kicauan ke-%d]\n",i+1);
        // displayKicauan(listKicauan[i]);
        printf("\n");
    }
    printf("======== [Debug listKicauan End] ========\n");
}
void displayKicauan(Kicauan kicauan){
    printf("id: %d\n", IDKICAU(kicauan));
    printf("text: %s\n", TEXT_KICAU(kicauan).TabWord);
    printf("like: %d\n", JUMLAH_LIKE(kicauan));
    printf("nama: %s\n", PEMBUAT(kicauan).TabWord);
    printf("dateTime: ");
    DisplayDateTime(WAKTU(kicauan));
}