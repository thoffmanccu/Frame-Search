//
// Created by Ebon Moore-Martin on 6/8/2016.
//

#include "Main.h"
#include <stdio.h>
#include "../Menu/Menu.h"

int main(void)
{

    /*
     * need array of arrays declared here
     * other arrays used such as dimensions[] and matrix[] should be declared here these will be temp arrays to be fed into the array of arrays
     * dynamically creating array probably will do a for loop to re create the array each time for now till I find another solution
     */

    int length = 1000;     //length of matrices array
    int i = -1;
    struct Matrices matrices[length];  //main struct to store all things in

    matrices->matrixNumber=0;
    menu(&matrices[0], &i);




}
