#ifndef AKUN_H
#define AKUN_H

#include "boolean.h"
#include "../Profile/profile.h"
#include "../MesinKata/wordmachine.h"
#include "../StackDin/stackdin.h"
#include "../PrioQueue/prioqueue.h"

typedef struct akun
{
    int id;
    Profile profil;
    Word password;
    StackDin* list_daftar_kicauan;
    PrioQueue list_permintaan_pertemanan;
    boolean isPublic;
} Akun;

extern Akun currentAkun; // Global variable
extern Akun listAkun[20]; // Global variable
extern int banyakAkun;

void CreateAkun(Akun* akun);
void DisplayAkun(Akun akun);
void DebugListAkun();

boolean jenisAkunToBoolean(Word w);
Word jenisAkunToWord(boolean b);


#endif