/* File: pengguna.h */
/* Login dan Logout System */

#ifndef __PENGGUNA_H__
#define __PENGGUNA_H__

#include "../../ADT/Boolean/boolean.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/StackDin/stackdin.h"
#include "../../ADT/DaftarPermintaan/daftarpermintaan.h"
#include "../../ADT/Profile/profile.h"

#define BLANK ' '

/* State Pengguna */
extern boolean isLogin;
extern Word currentPengguna;

void daftar();
void masuk();
void keluar();
void tutup_program();

#endif