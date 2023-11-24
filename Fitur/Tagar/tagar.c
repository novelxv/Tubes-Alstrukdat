#include "tagar.h"
#include "../../ADT/MapDin/mapdin.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/Boolean/boolean.h"
#include "../Global/global.h"

void cariKicauan(Word tagar){
    int key = hash(tagar, CAP_MAPDIN(globalMapTagarKicauan));
    boolean isFound = false;
    int idx = key;
    if(compareWord(ELMT_MAP_TAGAR(globalMapTagarKicauan,idx),tagar)){
        isFound = true;
    }else{
        do{
            idx = (idx+1)%CAP_MAPDIN(globalMapTagarKicauan);
            if(compareWord(ELMT_MAP_TAGAR(globalMapTagarKicauan,idx),tagar)){
                isFound = true;
            }
        }while (!isFound || idx == key);
    }

    if(!isFound){
        printf("Tidak ditemukan kicauan dengan tagar ");
        printWord(tagar);
        printf("\n\n");
    }else{
        printf("PASS2E\n");
        printWord(ELMT_MAP_TAGAR(globalMapTagarKicauan,idx));
        printf("\nIDKICAU: %d\n",(ELMT_MAP_VALUE(globalMapTagarKicauan,idx)->address_kicauan->id));
        printWord(BUFFER_MAP(globalMapTagarKicauan)[idx].value->address_kicauan->text);
        printf("\nPASS3\n");
        printWord(BUFFER_MAP(globalMapTagarKicauan)[idx].value->address_kicauan->tagar);
        printf("\nKEYY:%d\n",(BUFFER_MAP(globalMapTagarKicauan)[idx].mapKey));
        displayKicauanTagar(ELMT_MAP_VALUE(globalMapTagarKicauan,idx));
    }
    printf("PASS2END\n");
    
}

void displayKicauanTagar(AddressNodeMap l){
    AddressNodeMap p = l;
    while (p!=NULL)
    {
        Kicauan k = *(INFO_VAL_MAP(p));
        printf("| ");
        printWord(ADDR_AKUN_KICAUAN(k)->username);
        printf("\n");
        printf("| ");
        DisplayDateTime(WAKTU(k));
        printf("\n");
        printf("| ");
        printWord(TEXT_KICAU(k));
        printf("\n");
        printf("| ");
        printWord(TAGAR(k));
        printf("\n");
        printf("| Disukai : %d", JUMLAH_LIKE(k));
        printf("\n");
        printf("\n");
        p = NEXT_VAL_MAP(p);
    }
    
}