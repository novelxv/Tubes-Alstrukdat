#include <stdio.h>
#include "inisialisasi.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/ListStatikAkun/liststatikakun.h"
#include "../../ADT/DrafKicauan/drafkicauan.h"
#include "../../ADT/DateTime/datetime.h"
#include "../../ADT/Kicauan/kicauan.h"
#include "../../ADT/Balasan/balasan.h"

void tripleConcat(char *s1, char *s2, char *s3, char *result){
    int i = 0, j = 0;
    while(s1[i] != '\0'){
        result[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0'){
        result[i] = s2[j];
        i++;
        j++;
    }
    j = 0;
    while(s3[j] != '\0'){
        result[i] = s3[j];
        i++;
        j++;
    }
    result[i] = '\0';
}


void inisialisasi(){
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORD();
    ADVWORD(); // currentWord.TabWord = nama folder

    char dataPath[] = "Config/";
    char balasanPath[NMax], drafPath[NMax], kicauanPath[NMax], penggunaPath[NMax], utasPath[NMax] = "";
    tripleConcat(dataPath, currentWord.TabWord, "/balasan.config", balasanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/draf.config", drafPath);
    tripleConcat(dataPath, currentWord.TabWord, "/kicauan.config", kicauanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/pengguna.config", penggunaPath);
    tripleConcat(dataPath, currentWord.TabWord, "/utas.config", utasPath);
    int i = 0;
/*
    // Inisialisasi balasan
    printf("\n[Balasan]\n");
    freopen(balasanPath, "r", stdin);
    STARTWORD();
    banyakKicauanBerbalasan = wordToInt(currentWord); // banyak kicauan yang memiliki balasan
    printf("banyakKicauanBerbalasan: %d\n", banyakKicauanBerbalasan);
    
    for(i = 0; i < banyakKicauanBerbalasan; i++){
        ADVWORD();
        listBalasan[i].idParent = wordToInt(currentWord); // ID parent = 5

        ADVWORD();
        listBalasan[i].banyakBalasan = wordToInt(currentWord); // Memiliki 4 balasan

        int j = 0;
        for(j = 0; j < listBalasan[i].banyakBalasan; j++){
            ADVWORD();
            listBalasan[j].idParent = wordToInt(currentWord); // ID balasan = 1

            ADVWORD();
            listBalasan[j].id = wordToInt(currentWord); // ID balasan = 1

            ADVLINE();// Ini Balasan dari Node Utama, yaitu Kicauan ke-5
            listBalasan[j].text = cleanWord(currentWord);

            ADVLINE();
            listBalasan[j].nama = cleanWord(currentWord);
            
            ADVWORD();
            SetDateFromWord(&listBalasan[i].dateTime, cleanWord(currentWord));

            ADVWORD();
            SetTimeFromWord(&listBalasan[i].dateTime, cleanWord(currentWord));
        }
    }

*/
    // Inisialisasi draf
    // printf("\n[Draf]\n");
    freopen(drafPath, "r", stdin);
    STARTWORD();
    banyakDraf = wordToInt(currentWord);// 5 # Banyak draf
    for(i = 0; i < banyakDraf; i++){
        
        ADVWORD();
        listDraftkicauan[i].id = wordToInt(currentWord); // 1 # draf dengan ID ke-1
        
        ADVLINE();
        listDraftkicauan[i].text = cleanWord(currentWord); // Hehe
        
        ADVLINE();
        listDraftkicauan[i].nama = cleanWord(currentWord); // Tuan Hak

        ADVWORD();
        SetDateFromWord(&listDraftkicauan[i].dateTime, cleanWord(currentWord)); // 14/10/2023

        ADVWORD();
        SetTimeFromWord(&listDraftkicauan[i].dateTime, cleanWord(currentWord)); // 11:09:18
    }
    DebugListDraftKicauan();


 
    // Inisialisasi kicauan
    freopen(kicauanPath, "r", stdin);
    STARTWORD();
    banyakKicauan = wordToInt(currentWord); // 2 # Banyak kicauan sebanyak 2
    for(i = 0; i < banyakKicauan; i++){
        ADVWORD();
        listKicauan[i].id = wordToInt(currentWord); // 1 # ID kicauan 1

        ADVLINE();
        listKicauan[i].text = cleanWord(currentWord); // Halooo

        ADVWORD();
        listKicauan[i].likeCount = wordToInt(currentWord); // 12 # Like

        ADVLINE();
        listKicauan[i].namaPembuat = cleanWord(currentWord); // Tuan Bus

        ADVWORD();
        SetDateFromWord(&listKicauan[i].dateTime, cleanWord(currentWord)); // 14/10/2023

        ADVWORD();
        SetTimeFromWord(&listKicauan[i].dateTime, cleanWord(currentWord)); // 11:09:18
    }
    DebugListKicauan();


    // Inisialisasi pengguna
    freopen(penggunaPath, "r", stdin);
    STARTWORD();
    NEFF(listAkun) = wordToInt(currentWord); // 2 # Banyak pengguna
    for(i = 0; i < NEFF(listAkun); i++){
        CreateAkun(&CONTENT(listAkun, i));

        ADVLINE();
        CONTENT(listAkun, i).profil.nama = cleanWord(currentWord);

        ADVLINE();
        CONTENT(listAkun, i).password = cleanWord(currentWord);
        
        ADVLINE();
        CONTENT(listAkun, i).profil.bio = cleanWord(currentWord);
        
        ADVLINE();
        CONTENT(listAkun, i).profil.noHp = cleanWord(currentWord);

        ADVLINE();
        CONTENT(listAkun, i).profil.weton = cleanWord(currentWord);

        ADVLINE();
        CONTENT(listAkun, i).isPublic = jenisAkunToBoolean(cleanWord(currentWord));

        int j = 0;
        for(j = 0; j < FOTO_ROW_CAP; j++){
            int k = 0;
            for(k = 0; k < FOTO_COL_CAP; k++){
                ADVWORD();
                setColor(&(CONTENT(listAkun, i).profil.foto), j, k, currentWord.TabWord[0]);
                ADVWORD();
                setVal(&(CONTENT(listAkun, i).profil.foto), j, k, currentWord.TabWord[0]);
            }
        }
    }
    // Matriks Pertemanan

    DebugListAkun();
/*
    // Inisialisasi pengguna
    printf("\n[Utas]\n");
    freopen(utasPath, "r", stdin);
    STARTWORD();
    int banyakKicauanBerutas = wordToInt(currentWord); // 2 # Banyak kicauan yang memiliki utas
    for(i = 0; i < banyakKicauanBerutas; i++) {
        ADVWORD();
        printf("idKicauan: %d\n", wordToInt(currentWord)); // 1 # ID kicauan ke-2

        ADVWORD();
        int banyakUtas = wordToInt(currentWord); 
        printf("banyakUtas: %d\n", wordToInt(currentWord)); // 3 # memiliki 3 utas

        int j = 0;
        for(j = 0; j < banyakUtas; j++){
            ADVWORD();
            printf("idUtas: %d\n", wordToInt(currentWord)); // 1 # ID utas ke-1

            ADVLINE();
            printf("text: %s\n", cleanWord(currentWord).TabWord); // Nyonya Hil

            ADVLINE();
            printf("nama: %s\n", cleanWord(currentWord).TabWord); // Nyonya Hil

            ADVWORD();
            printf("date: %s\n", cleanWord(currentWord).TabWord); // 14/10/2023

            ADVWORD();
            printf("time: %s\n", cleanWord(currentWord).TabWord); // 11:09:18
        }
    }

*/

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}