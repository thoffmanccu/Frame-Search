//
// Created by Ebon Moore-Martin on 6/29/2016.
//

#include "../MainProgram/Main.h"
#include <stdio.h>

#ifndef MATRICIESHOFFMANPROJECTV0_1_IOFILEMETHODS_H
#define MATRICIESHOFFMANPROJECTV0_1_IOFILEMETHODS_H

void readInMatrix(struct Matrices* matrices, int a);

void newLineRemover(FILE* fp);

void listAllMatrices(struct Matrices* matrices);

#endif //MATRICIESHOFFMANPROJECTV0_1_IOFILEMETHODS_H
