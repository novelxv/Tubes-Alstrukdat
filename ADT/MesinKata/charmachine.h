/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_MACHINE_H__
#define __CHAR_MACHINE_H__

#include "../Boolean/boolean.h"

#define MARK ';'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void STARTFILEREADER(char path[]);
/* Pita direset untuk handle fopen file. */

void STARTFILEWRITER(char path[]);
/* Pita direset untuk handle fopen file. */

// Tulis char ke file
void WRITECHAR(char c);

// Tulis new line ke file
void WRITENL();
#endif