//
//  Menu.cpp
//  TP_MOD10_1301210575
//
//  Created by LBN on 31/12/22.
//

#include "Header.h"


int createMenuUser(){
    int angka;
    cout << "========================================" << endl;
    cout << "|         Daftar Menu Aplikasi         |" << endl;
    cout << "|======================================|" << endl;
    cout << "|                                      |" << endl;
    cout << "| 1. Tambah Department                 |" << endl;
    cout << "| 2. Tambah Pegawai                    |" << endl;
    cout << "| 3. Cari Pegawai / Department         |" << endl;
    cout << "| 4. Show All                          |" << endl;
    cout << "| 5. Jumlah Data                       |" << endl;
    cout << "| 6. FindMax / FindMin                 |" << endl;
    cout << "| 7. Hapus Data                        |" << endl;
    cout << "| 0. Exit                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    cin >> angka;
    cout << endl;
    return angka;
}

void showAll(listDepartment LD){
    if(firstDepartment(LD) == nil) {
        cout << "Department kamu masih kosong.." << endl;
        cout << endl;
        return;
    }
    int i = 1;
    adrDepartment D = firstDepartment(LD);
    while(D != nil) {
        cout << "======== DATA DEPARTMENT ========" << endl;
        cout << "Department Ke-" << i << endl;
        cout << "Nama Department: " << infoDepartment(D).nama << endl;
        cout << "Kode Department: " << infoDepartment(D).kode << endl;
        cout << endl;
        int j = 1;
        adrPegawai P = pegawai(D);
        while(P != nil) {
            cout << "======== DATA PEGAWAI ========" << endl;
            cout << "Pegawai Ke-" << j << endl;
            cout << "ID Pegawai: " << infoPegawai(P).idPegawai << endl;
            cout << "Nama Pegawai: " << infoPegawai(P).nama << endl;
            cout << "Umur Pegawai: " << infoPegawai(P).umur << endl;
            cout << endl;
            j++;
            P = nextPegawai(P);
        }
        i++;
        D = nextDepartment(D);
    }
}
void backMenu(int &N){
    cout << "|======================================|" << endl;
    cout << "|      Kembali Ke Halaman Utama?       |" << endl;
    cout << "|======================================|" << endl;
    cout << "| 1. Yes                               |" << endl;
    cout << "| 0. Exit                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    int ANS;
    cout << "Masukan Menu: ";
    cin >> ANS;
    cout << endl;
    if(ANS == 1) {
        N = createMenuUser();
    } else if(ANS == 0) {
        N = 0;
    } else {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Menu Tidak Ditemukan.." << endl;
    }
}

void searchMenuList(listDepartment LD, listPegawai LP){
    int option;
    cout << "|======================================|" << endl;
    cout << "|       List yang ingin dicari         |" << endl;
    cout << "|======================================|" << endl;
    cout << "| 1. Department By Kode                |" << endl;
    cout << "| 2. Pegawai By Name                   |" << endl;
    cout << "| 0. Back                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    cin >> option;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Wah input kamu bukan angka nih.." << endl;
        cout << endl;
        return;
    }
    switch (option) {
        case 1: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            string kode;
            cout << "Masukkan kode: ";
            cin >> kode;
            cout << endl;
            adrDepartment D = searchDepartmentAdr(LD, kode);
            if(D == nil) {
                cout << "Department tidak ditemukan.." << endl;
                cout << endl;
                return;
            } else {
                showDepartmentByAdr(D);
                return;
            }
            break;
        }
        case 2: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            string nama;
            cout << "Masukkan nama pegawai: ";
            cin >> nama;
            cout << endl;
            multipleAdr Y = searchPegawaiOnDepartment(LD, nama);
            if(Y.P == nil) {
                cout << "Pegawai tidak ditemukan.." << endl;
                cout << endl;
                return;
            } else {
                showDepartmentByAdr(Y.D);
                showPegawaiByAdr(Y.P);
                return;
            }
            break;
        }
        case 0: {
            return;
            break;
        }
        default: {
            exit(0);
            break;
        }
    }
    
};
void deleteMenuList(listDepartment &LD) {
    int option;
    cout << "|======================================|" << endl;
    cout << "|    Jumlah yang ingin kamu lihat      |" << endl;
    cout << "|======================================|" << endl;
    cout << "| 1. Delete Department By Kode         |" << endl;
    cout << "| 2. Delete Pegawai By Name            |" << endl;
    cout << "| 0. Exit                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    cin >> option;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Wah input kamu bukan angka nih.." << endl;
        cout << endl;
        return;
    }
    switch (option) {
        case 1: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            string kode;
            cout << "Masukkan kode: ";
            cin >> kode;
            cout << endl;
            adrDepartment D = searchDepartmentAdr(LD, kode);
            if(D == nil) {
                cout << "Department tidak ditemukan.." << endl;
                cout << endl;
                return;
            } else {
                deleteDepartment(LD, D);
                cout << "===== DATA BERHASIL DIHAPUS =====" << endl;
                cout << "Nama Department: " << infoDepartment(D).nama << endl;
                cout << "Kode Department: " << infoDepartment(D).kode << endl;
                cout << endl;
                return;
            }
            break;
        }
        case 2: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            string nama;
            cout << "Masukkan nama pegawai: ";
            cin >> nama;
            cout << endl;
            multipleAdr Y = searchPegawaiOnDepartment(LD, nama);
            if(Y.P == nil) {
                cout << "Pegawai tidak ditemukan.." << endl;
                cout << endl;
                return;
            } else {
                deletePegawai(LD, Y.D, Y.P);
                cout << "===== DATA BERHASIL DIHAPUS =====" << endl;
                cout << "ID Pegawai: " << infoPegawai(Y.P).idPegawai << endl;
                cout << "Nama: " << infoPegawai(Y.P).nama << endl;
                cout << "Umur: " << infoPegawai(Y.P).umur << endl;
                cout << endl;
                return;
            }
            break;
        }
        case 0: {
            return;
            break;
        }
        default: {
            exit(0);
            break;
        }
    }
};

void minMaxMenuList(listDepartment LD) {
    int option;
    cout << "|======================================|" << endl;
    cout << "|    Jumlah yang ingin kamu lihat      |" << endl;
    cout << "|======================================|" << endl;
    cout << "| 1. Maximum                           |" << endl;
    cout << "| 2. Minimum                           |" << endl;
    cout << "| 0. Exit                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    cin >> option;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Wah input kamu bukan angka nih.." << endl;
        cout << endl;
        return;
    }
    switch (option) {
        case 1: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            int maximum, count;
            maximum = 0;
            adrDepartment DMax = firstDepartment(LD);
            adrDepartment D = firstDepartment(LD);
            while(D != nil){
                adrPegawai P = pegawai(D);
                count = 0;
                while(P != nil){
                    count++;
                    P = nextPegawai(P);
                }
                if(maximum < count) {
                    maximum = count;
                    DMax = D;
                }
                D = nextDepartment(D);
            }
            showDepartmentByAdr(DMax);
            cout << "Maximum Pegawai Pada Department: " << maximum << endl;
            break;
        }
        case 2: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            int minimum, count;
            adrDepartment DMin = firstDepartment(LD);
            adrDepartment D = firstDepartment(LD);
            minimum = 1000000000;
            while(D != nil){
                adrPegawai P = pegawai(D);
                count = 0;
                while(P != nil){
                    count++;
                    P = nextPegawai(P);
                }
                if(minimum > count) {
                    minimum = count;
                    DMin = D;
                }
                D = nextDepartment(D);
            }
            showDepartmentByAdr(DMin);
            cout << "Minimum Pegawai Pada Department: " << minimum << endl;
            break;
        }
        case 0: {
            return;
            break;
        }
        default: {
            exit(0);
            break;
        }
    }
}
void countMenuList(listDepartment LD) {
    int option;
    cout << "|======================================|" << endl;
    cout << "|    Jumlah yang ingin kamu lihat      |" << endl;
    cout << "|======================================|" << endl;
    cout << "| 1. Department                        |" << endl;
    cout << "| 2. Pegawai                           |" << endl;
    cout << "| 3. Pegawai By Department             |" << endl;
    cout << "| 0. Exit                              |" << endl;
    cout << "|______________________________________|" << endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    cin >> option;
    cout << endl;
    if(cin.fail()) {
        cin.clear(); //YOU MUST CLEAR THE ERROR STATE
        cin.ignore();
        cout << "Wah input kamu bukan angka nih.." << endl;
        cout << endl;
        return;
    }
    switch (option) {
        case 1: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            int jumlah = 0;
            adrDepartment D = firstDepartment(LD);
            while(D != nil){
                jumlah++;
                D = nextDepartment(D);
            }
            cout << "Total jumlah department: " << jumlah << endl;
            break;
        }
        case 2: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            int jumlah = countPegawai(LD);
            cout << "Total jumlah pegawai: " << jumlah << endl;
            break;
        }
        case 3: {
            if(firstDepartment(LD) == nil) {
                cin.clear(); //YOU MUST CLEAR THE ERROR STATE
                cin.ignore();
                cout << "Departement masih kosong.." << endl;
                cout << endl;
                return;
            }
            string kode;
            cout << "Masukkan kode department: ";
            cin >> kode;
            cout << endl;
            int jumlah = countPegawaiByDepartment(LD, kode);
            cout << "Total jumlah pegawai: " << jumlah << endl;
            break;
        }
        case 0: {
            return;
            break;
        }
        default: {
            exit(0);
            break;
        }
    }
}
