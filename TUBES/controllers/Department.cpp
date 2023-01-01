//
//  Department.cpp
//  TP_MOD10_1301210575
//
//  Created by LBN on 31/12/22.
//

#include "Header.h"

void createListDepartment(listDepartment &LD){
    firstDepartment(LD) = nil;
}

void insertLastDepartment(listDepartment &LD, adrDepartment D){
    adrDepartment ND;
    nextDepartment(D) = nil;
    if(firstDepartment(LD) == nil) {
        firstDepartment(LD) = D;
    } else if(nextDepartment(firstDepartment(LD)) == nil) {
        nextDepartment(firstDepartment(LD)) = D;
    } else {
        ND = firstDepartment(LD);
        while(nextDepartment(ND) != nil) {
            ND = nextDepartment(ND);
        }
        nextDepartment(ND) = D;
    }
}

adrDepartment createElementDepartment(department D){
    adrDepartment AD = new elementDepartment;
    infoDepartment(AD) = D;
    nextDepartment(AD) = nil;
    return AD;
}

void createNDepartment(listDepartment &LD){
    department D;
    adrDepartment AD, SD;
    int N;
    int i = 0;
    cout << "Masukkan Jumlah Department: ";
    cin >> N;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Wah input kamu bukan angka nih.." << endl;
        cout << endl;
    }
    while(i < N){
        cout << "Input Department ke-" << i + 1 << endl;
        cout << "Nama Department: ";
        cin >> D.nama;
        cout << "Kode Department: ";
        cin >> D.kode;
        cout << endl;
        SD = searchDepartmentAdr(LD, D.kode);
        if(SD != nil) {
            // Print any message
            cout << "Kesalahan department sudah pernah diinput.." << endl;
            cout << endl;
            return;
        }
        AD = createElementDepartment(D);
        insertLastDepartment(LD, AD);
        i++;
    }
}
    
adrDepartment searchDepartmentAdr(listDepartment LD, string kode) {
        adrDepartment D = firstDepartment(LD);
        while(D != nil){
            if(infoDepartment(D).kode == kode) {
                return D;
            }
            D = nextDepartment(D);
        }
        return nil;
}

void showDepartmentByAdr(adrDepartment D){
    cout << "==== DATA DEPARTMENT ====" << endl;
    cout << "Nama Department: " << infoDepartment(D).nama << endl;
    cout << "Kode Department: " << infoDepartment(D).kode << endl;
    cout << endl;
}

multipleAdr searchPegawaiOnDepartment(listDepartment LD, string nama){
    multipleAdr Y;
    adrPegawai P;
    adrDepartment D = firstDepartment(LD);
    while(D != nil){
        P = pegawai(D);
        while(P != nil) {
            if(infoPegawai(P).nama == nama) {
                Y.P = P;
                Y.D = D;
                return Y;
            }
            P = nextPegawai(P);
        }
        D = nextDepartment(D);
    }
    Y.P = nil;
    Y.D = nil;
    return Y;
}

void deleteDepartment(listDepartment &LD, adrDepartment &D){
    if(nextDepartment(firstDepartment(LD)) == nil) {
        D = firstDepartment(LD);
        firstDepartment(LD) = nil;
    } else {
        adrDepartment AD = firstDepartment(LD);
        while(nextDepartment(AD) != D) {
            AD = nextDepartment(AD);
        }
        nextDepartment(AD) = nextDepartment(D);
        nextDepartment(D) = nil;
    }
}
