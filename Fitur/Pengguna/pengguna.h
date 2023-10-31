/* File: pengguna.h */
/* Login dan Logout System */

#ifndef __PENGGUNA_H__
#define __PENGGUNA_H__

#include "../../ADT/MesinKata/boolean.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/StackDin/stackdin.h"
#include "../../ADT/PrioQueue/prioqueue.h"
#include "../../ADT/Profile/profile.h"

#define IDMax 20
#define BLANK ' '

/* State Pengguna */
extern boolean isLogin;

void daftar();
void masuk();
void keluar();
void tutup_program();

#endif