//
//  Header.h
//  TP_MOD10_1301210575
//
//  Created by LBN on 05/12/22.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>

using namespace std;


// Define model of project
#include "./model/Pegawai.h"
#include "./model/Department.h"

// Define helper for nil
#define nil NULL

// Pegawai
void createListPegawai(listPegawai &LP);
void createNPegawai(listPegawai &LP, listDepartment LD);
void insertLastPegawai(listPegawai &LP, adrPegawai P);
adrPegawai searchPegawaiByName(listPegawai LP, string nama);
void connectDepartmentWithPegawai(adrPegawai P, listDepartment &LD, string code);
void showPegawaiByAdr(adrPegawai P);
int countPegawai(listDepartment LD);
int countPegawaiByDepartment(listDepartment LD, string kode);
void deletePegawai(listDepartment &LD, adrDepartment &D, adrPegawai &P);

// Department
void createListDepartment(listDepartment &LD);
void inserLastDeparment(listDepartment &LD, adrDepartment D);
void createNDepartment(listDepartment &LD);
adrDepartment searchDepartmentAdr(listDepartment LD, string kode);
void showDepartmentByAdr(adrDepartment D);
multipleAdr searchPegawaiOnDepartment(listDepartment LD, string nama);
void deleteDepartment(listDepartment &LD, adrDepartment &D);

// Menu
void backMenu(int &N);
int createMenuUser();
void searchMenuList(listDepartment LD, listPegawai LP);
void showAll(listDepartment LD);
void countMenuList(listDepartment LD);
void minMaxMenuList(listDepartment LD);
void deleteMenuList(listDepartment &LD);
#endif /* Header_h */
