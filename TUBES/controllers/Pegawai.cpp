//
//  Pegawai.cpp
//  TP_MOD10_1301210575
//
//  Created by LBN on 31/12/22.
//

#include "Header.h"

void createListPegawai(listPegawai &LP) {
    firstPegawai(LP) = nil;
}

void connectDepartmentWithPegawai(adrPegawai P, listDepartment &LD, string code) {
    adrDepartment D = searchDepartmentAdr(LD, code);
    if(pegawai(D) == nil) {
        pegawai(D) = P;
    } else if(nextPegawai(pegawai(D)) == nil) {
        nextPegawai(pegawai(D)) = P;
    } else {
        adrPegawai AP = pegawai(D);
        while(nextPegawai(AP) != nil) {
            AP = nextPegawai(AP);
        }
        nextPegawai(AP) = P;
    }
}

adrPegawai createElementPegawai(pegawai P){
    adrPegawai AP = new elementPegawai;
    infoPegawai(AP) = P;
    nextPegawai(AP) = nil;
    return AP;
}


void insertLastPegawai(listPegawai &LP, adrPegawai P){
    if(firstPegawai(LP) == nil) {
        firstPegawai(LP) = P;
        nextPegawai(firstPegawai(LP)) = nil;
    } else if(nextPegawai(firstPegawai(LP)) == nil) {
        nextPegawai(firstPegawai(LP)) = P;
        nextPegawai(nextPegawai(firstPegawai(LP))) = nil;
    } else {
        adrPegawai NP;
        NP = firstPegawai(LP);
        while(nextPegawai(NP) != nil) {
            NP = nextPegawai(NP);
        }
        nextPegawai(NP) = P;
        nextPegawai(nextPegawai(NP)) = nil;
    }
}

void createNPegawai(listPegawai &LP, listDepartment LD){
    pegawai P;
    adrPegawai AP;
    int N;
    int i = 0;
    cout << "Masukkan Jumlah Pegawai: ";
    cin >> N;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Input kamu bukan angka nih.." << endl;
        cout << endl;
    } else if(firstDepartment(LD) == nil) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Department masih kosong, isi terlebih dahulu." << endl;
        cout << endl;
        return;
    }
    while(i < N){
        string kode;
        cout << "Input data pegawai ke-" << i + 1 << endl;
        cout << "Nama Pegawai: ";
        cin >> P.nama;
        cout << "ID Pegawai: ";
        cin >> P.idPegawai;
        cout << "Umur: ";
        cin >> P.umur;
        cout << "Kode Department: ";
        cin >> kode;
        cout << endl;
        adrDepartment SD = searchDepartmentAdr(LD, kode);
        if(SD == nil) {
            cin.clear(); //YOU MUST CLEAR THE ERROR STATE
            cin.ignore();
            cout << "User tidak terinput, Kode department Tidak Ditemukan!!!" << endl;
            cout << "Silahkan input department dahulu, lalu input user kembali.." << endl;
            cout << endl;
            return;
        };
        AP = createElementPegawai(P);
        connectDepartmentWithPegawai(AP, LD, kode);
        i++;
    }
}

adrPegawai searchPegawaiByName(listPegawai LP, string nama) {
    adrPegawai P = firstPegawai(LP);
    while(P != nil){
        if(infoPegawai(P).nama == nama) {
            return P;
        }
        P = nextPegawai(P);
    }
    return nil;
}

int countPegawai(listDepartment LD){
    int count = 0;
    adrDepartment D = firstDepartment(LD);
    while(D != nil) {
        adrPegawai P = pegawai(D);
        while(P != nil){
            count++;
            P = nextPegawai(P);
        }
        D = nextDepartment(D);
    }
    return count;
}
int countPegawaiByDepartment(listDepartment LD, string kode) {
    int count = 0;
    adrDepartment D = searchDepartmentAdr(LD, kode);
    if(D == nil) {
        cout << "Department tidak ditemukan" << endl;
        return 0;
    }
    adrPegawai P = pegawai(D);
    while(P != nil) {
        count++;
        P = nextPegawai(P);
    }
    return count;
}
void showPegawaiByAdr(adrPegawai P){
    cout << "==== DATA PEGAWAI ====" << endl;
    cout << "Nama: " << infoPegawai(P).nama << endl;
    cout << "Umur: " << infoPegawai(P).umur << endl;
    cout << "ID Pegawai: " << infoPegawai(P).idPegawai << endl;
    cout << endl;
}

void deletePegawai(listDepartment &LD, adrDepartment &D, adrPegawai &P){
    if(nextPegawai(pegawai(D)) == nil) {
        P = pegawai(D);
        pegawai(D) = nil;
    } else {
        adrPegawai HP = pegawai(D);
        while(nextPegawai(HP) != P) {
            HP = nextPegawai(HP);
        }
        nextPegawai(HP) = nextPegawai(P);
        nextPegawai(P) = nil;
    }
}
