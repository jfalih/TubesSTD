//
//  Department.h
//  TP_MOD10_1301210575
//
//  Created by LBN on 31/12/22.
//

#ifndef Department_h
#define Department_h

#include "Header.h"

/**
 * Define helper function for department list
 **/
#define firstDepartment(LD) ((LD).firstDepartment)
#define infoDepartment(D) (D)->infoDepartment
#define pegawai(D) (D)->pegawai
#define nextDepartment(D) (D)->nextDepartment

// Define model for department
struct department {
    string nama, kode;
};

// Define struct helper for type
typedef struct elementDepartment *adrDepartment;
typedef struct department infotypeDepartment;


// Define struct of elementDepartment
struct elementDepartment {
    infotypeDepartment infoDepartment;
    adrPegawai pegawai;
    adrDepartment nextDepartment;
};

// Define list of department
struct listDepartment {
    adrDepartment firstDepartment;
};

struct multipleAdr {
    adrPegawai P;
    adrDepartment D;
};

#endif /* Department_h */
