/* File: profile.c */
/* ADT Profile yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil dari pengguna */

#include <stdio.h>
#include "profile.h"

/* *** PROTOTYPE *** */
/* *** PEMBUATAN DENGAN NILAI DEFAULT *** */
void CreateProfil(Profile *P){
    /* Mambuat profil kosong dengan nilai-nilai default */
    setWord(&Bio(*P), "");
    queueLinked_CreateQueue(&NomorHP(*P));
    setWord(&Weton(*P), "");
    JenisAkun(*P) = true;
    CreateFotoProfil(&Foto(*P));
}

/* *** PEMERIKSAAN NILAI *** */
boolean isWetonValid(Word weton){
    /* Memeriksa apakah weton valid */
    // Konversi semua huruf ke huruf kecil
    Word weton_kecil = weton;
    for (int i = 0; i < weton.Length; i++){
        if (weton_kecil.TabWord[i] >= 'A' && weton_kecil.TabWord[i] <= 'Z'){
            weton_kecil.TabWord[i] += ('a' - 'A');
        }
    }
    return (compareWord(weton_kecil, stringToWord("pahing")) ||
            compareWord(weton_kecil, stringToWord("kliwon")) ||
            compareWord(weton_kecil, stringToWord("wage")) ||
            compareWord(weton_kecil, stringToWord("pon")) ||
            compareWord(weton_kecil, stringToWord("legi")) ||
            compareWord(weton, stringToWord("")));
}

boolean isNomorHPValid(QueueLinked nomor_hp){
    /* Memeriksa apakah nomor HP valid */
    queueAddress p = ADDR_HEAD(nomor_hp);
    while (p != NIL){
        if (!(INFO(p) >= '0' && INFO(p) <= '9')){
            return false;
        }
        p = NEXT(p);
    }
    return true;
}

boolean isAkunPrivat(Profile P){
    /* Memeriksa apakah jenis akun privat */
    return (!JenisAkun(P));
}

boolean isAkunPublik(Profile P){
    /* Memeriksa apakah jenis akun publik */
    return (JenisAkun(P));
}

/* *** PENGUBAHAN NILAI *** */
void changeBio(Profile *P, Word w){
    /* Mengubah bio berdasarkan masukan pengguna */
    if (w.Length > 135){
        printf("\nPanjang bio melebihi batas maksimum. Karakter ke 136 dan seterusnya akan dihapus.\n");
    }
    capWord(w, 135);
    Bio(*P) = w;
}

void changeNomorHP(Profile *P, QueueLinked q){
    /* Mengubah nomor HP berdasarkan masukan pengguna */
    NomorHP(*P) = q;
}

void changeWeton(Profile *P, Word w){
    /* Mengubah weton berdasarkan masukan pengguna */
    Weton(*P) = w;
}

void changeJenisAkun(Profile *P){
    /* Mengubah jenis akun pengguna */
    if (JenisAkun(*P)){
        JenisAkun(*P) = false;
    }
    else{
        JenisAkun(*P) = true;
    }
}

/* *** PENAMPILAN NILAI *** */
void displayProfil(Profile P, Word username){
    /* Menampilkan profil pengguna dengan username "username" kecuali bagian foto profil */
    printf("\n| Nama: ");
    printWord(username);
    printf("\n| Bio Akun: ");
    printWord(Bio(P));
    printf("\n| No HP: ");
    queueLinked_DisplayQueue(NomorHP(P));
    printf("\n| Weton: ");
    printWord(Weton(P));
}

void lihatProfil(Profile P, Word username){
    /* Menampilkan profil pengguna dengan username "username" */
    printf("\n| Nama: ");
    printWord(username);
    printf("\n| Bio Akun: ");
    printWord(Bio(P));
    printf("\n| No HP: ");
    queueLinked_DisplayQueue(NomorHP(P));
    printf("\n| Weton: ");
    printWord(Weton(P));
    printf("\n\nFoto profil akun ");
    printWord(username);
    printf("\n");
    displayFotoProfil(Foto(P));
}