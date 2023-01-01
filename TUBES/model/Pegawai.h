//
//  Pegawai.h
//  TP_MOD10_1301210575
//
//  Created by LBN on 31/12/22.
//

#ifndef Pegawai_h
#define Pegawai_h

#include "Header.h"

#include <string>
#include <iostream>
using namespace std;

/**
 * Define helper function for pegawai list
 **/
#define firstPegawai(LP) ((LP).firstPegawai)
#define infoPegawai(P) (P)->infoPegawai
#define nextPegawai(P) (P)->nextPegawai

// Define type model of pegawai
struct pegawai {
    string nama, idPegawai;
    int umur;
};


// Define type of element
typedef struct elementPegawai *adrPegawai;

// Define type of Infotype
typedef struct pegawai infotypePegawai;

// Define element pegawai
struct elementPegawai {
    infotypePegawai infoPegawai;
    adrPegawai nextPegawai;
};


// Define list pegawai
struct listPegawai {
    adrPegawai firstPegawai;
};

#endif /* Pegawai_h */
