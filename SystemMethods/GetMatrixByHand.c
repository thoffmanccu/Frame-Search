//
// Created by Ebon Moore-Martin on 6/9/2016.
//

#include <stdio.h>
#include "GetMatrixByHand.h"
#include "../MainProgram/Main.h"


/*
 * This method will be passed a pointer from the main array to where the next array will be stored
 * then read in the array using scanf
 */

void EnterMatrixbh(struct Matrices* matrices, int i)

{

    int j=0;




   printf("%dA's value is : " , i);

    printf("\nPlease enter top half of matrix 1 digit at a time\n");

    //matrices->Matrix[i] = 56;           //short hand for (*matrices).Matrix[i]=56;
    scanf("%d", &matrices[i].firstNum);
    j++;


    //J will start at 1 to pick up either top half or bottom half depending on which way the main diagonal of ones is facing in the matrix
    for(j; j<matrices[i].Dimensions[1]; j++)
    {
        scanf("%d", &matrices[i].Matrix[j]);
        //printf("%d", matrices[i].Matrix[j]); //only gets & sign because of the scan f and print f for normal assignments just use matrices[a].Matrix[j];
    }


    /*
     * side not & when used with printing will give a pointer to the location so the address to get the actual value leave it without the & sign
     */



}
