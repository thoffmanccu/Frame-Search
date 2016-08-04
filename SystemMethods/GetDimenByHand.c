//
// Created by Ebon Moore-Martin on 6/8/2016.
//

#include "GetDimenByHand.h"
#include <stdio.h>
#include "../MainProgram/Main.h"


void GetDimen(struct Matrices *matrices, int i)
{
    int R1;     // int for number of rows within first matrix
    //int R2;     // int for number of rows within second matrix ----- unused will be deleted in next version
    int C1;     // int for number of columns withing first matrix
    //int C2;     // int for number of columns withing second matrix ----- unused will be deleted in next version
    //int D[2];      // int array for actual dimensions ----- unused will be deleted in next version
    int check = 0;
    int check2 = 0;
    char ans;


    printf("%dA's value is : " , i);

    while (check == 0)
    {

        printf("please enter demensions of your your matrix\n");

        //getting number of rows and columns for the matrix
        printf("number of rows = \n");
        scanf("%d", &R1);
        printf("number of columns = \n");
        scanf("%d", &C1);

        matrices[i].Dimensions[0] = R1;
        matrices[i].Dimensions[1] = C1;

        //matrices->Dimensions[0] = R1; //pointer to the number of rows
        //matrices->Dimensions[1] = C1; // pointer to the number of columns

        //printf("testing number of rows = %d", R1);
        //printf("\ntesting number of columns = %d", C1);
        printf("Demensions of your matrix are: %d", R1);
        printf("x%d", C1);

        //not working for some reason
        /*
         * update in c the scanf does not account for white space a couple options are to
         * scanf(" %c", &ans);
         * or before the scanf clear the buffer with fflush(stdin);
         * I will be using fflush(stdin); cause it looks cooler
         * ---Fixed will remove extra comments in next version
         */
        printf("\nare these demensions correct? (enter Y for yes N for no)");
        fflush(stdin);                                                                            //ans = getchar(); ----- unused will be deleted in next version
        scanf("%c", &ans); //maybe not the right %_ for char or chars are handled weirdly

                                                                                                  //printf("%c", ans); ----- unused testing will be deleted in next version
        while(check2 != 1)
        {
            if (ans == 'Y') {
                check = 1;
                check2 = 1;
            }
            else if (ans == 'N') {
                check = 0;
                check2 =1;
            }
            else {
                printf("please enter valid answer");
                printf("are these demensions correct? (enter Y for yes N for no)");
                fflush(stdin);
                scanf("%c", &ans);

                //check = 1;
            }
        }

    }
                     // return D doesn't work can't return arrays must find a way around this problem   ----- unused will be deleted in next version


 /*   //code to get dimensions from the user and pass them back to the menu program by utilizing pointers

    printf("\nplease enter demensions of your matrix\n");
    printf("number of rows = \n");
    scanf("%d", &R1); //scans keyboard for an int representing the number of rows for the matrix
    printf("number of columns = \n");
    scanf("%d", &C1); //scans keyboard for an int representing the number of columns for the matrix

    printf("Demensions of the matrix is: %d", R1);
    printf("x%d", C1);

    *pR = R1; // setting a pointer to the number of rows just read in
    *pC = C1; // setting a pointer to the number of columns just read in
   */
}