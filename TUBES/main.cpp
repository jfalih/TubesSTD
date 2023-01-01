//
//  main.cpp
//  TP_MOD8_1301210575_IF4507
//
//  Created by LBN on 28/11/22.
//

#include "Header.h"

void checkMenu(int &N, listDepartment &LD, listPegawai &LP) {
    switch (N) {
        case 1:
            createNDepartment(LD);
            backMenu(N);
            break;
        case 2:
            createNPegawai(LP, LD);
            backMenu(N);
            break;
        case 3:
            searchMenuList(LD, LP);
            backMenu(N);
            break;
        case 4:
            showAll(LD);
            backMenu(N);
            break;
        case 5:
            countMenuList(LD);
            backMenu(N);
            break;
        case 6:
            minMaxMenuList(LD);
            backMenu(N);
            break;
        case 7:
            deleteMenuList(LD);
            backMenu(N);
            break;
        default:
            exit(0);
            break;
    }
}

int main() {
    int input;
    // Define type of list
    listDepartment LD;
    listPegawai LP;
    
    // Define createList function for all list;
    createListDepartment(LD);
    createListPegawai(LP);
    input = createMenuUser();
    
    while(input != 0) {
        checkMenu(input, LD, LP);
    }
}
