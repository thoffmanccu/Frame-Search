//
// Created by Ebon Moore-Martin on 6/8/2016.
//

#ifndef MATRICIESHOFFMANPROJECTV0_1_MAIN_C_H
#define MATRICIESHOFFMANPROJECTV0_1_MAIN_C_H

/*
 * can only have one flexible array in a struct and it must be the last member listed order matters here for some reason
 */
struct Matrices
{
    int matrixNumber;  //what matrix it is based on position when entered like matrix 1, 2 , 4, ect..
    int Dimensions[2];  // Dimensions of said matrix
    int firstNum; //the first number of the matrix so I know which way the diagonal is either up or down for reconstruction later for output
    int Matrix[];      // Matrix itself well half of it uses dimension to duplicate second half when printing to screen/file
};

#endif //MATRICIESHOFFMANPROJECTV0_1_MAIN_C_H
