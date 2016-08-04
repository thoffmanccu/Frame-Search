//
// Created by Ebon Moore-Martin 6/8/2016.
//

#include "../Menu/Menu.h"
#include "../SystemMethods/GetDimenByHand.h"
#include "../SystemMethods/GetMatrixByHand.h"
#include "../SystemMethods/IOFileMethods.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 256

/*
 * when you have multiple folders must do ../fileName/File.c
 * Now to change menu to allow users to read in previous data from a file or to start from scratch on a new file
 */


void menu(struct Matrices* matrices, int* i)
{
    int option; // int value for the menu driven program used to move through the differnt part
    int Dimensions[2]; //dimension to be used when entering an array
    int a = *i;
    char user[MAX_NAME_LENGTH]; // read in value for the to determine new or old user
    int menuCheck1 = 0; // the check to leave the first part of the menu continues to next menu when value = 1
    //char new[256] = "new";
    //char existing[256] = "existing";
    bool status;
    //char *path = malloc(128+1);

    //menu selection 1
    /*
     * determines if the user is a new or old user
     * then either creates new file for matrices to be stored in or reads in existing matrices
     */
       printf("\nWelcome to matricies v0.1\n");
       printf("\nAre you an existing user or new user?(type new or existing)\n");
       fflush(stdin);
       fflush(stdout);
       //scanf("%s", user);
       fgets(user, sizeof(user), stdin);  //-------- works and is safer than scan f for arbitrary strings

       // all testing will be removed in next version
       //printf("\n%s", user);
       //printf("\n%s", new);
       //printf("\n%d", menuCheck1);
    /*
     * when using strncmp it returns 0 if they are equal without the condition for checking strings
     * strncmp takes in three parameters the first string, the second string, and the number of characters to check
     */
  while (menuCheck1 != 1)
  {
      if (strncmp(user, "new", 3) == 0) {
          menuCheck1 = 1;
          status = 1; // 1 for new users

          printf("\nplease enter the location where you wish to store the output file");
          //printf("new works");
      }
      else if (strncmp(user, "existing", 8) == 0) {
          menuCheck1 = 1;
          status = 0; // 0 for old users
          //printf("\n%d", status); -------------------- testing will be removed in next version
          printf("\nplease enter the location of the existing matrix file");
          //printf("existing works");
      }
      else {
          printf("\nPlease enter in a valid answer");
          fflush(stdin);
          fgets(user, sizeof(user), stdin);
      }
  }


    //printf("\n%d", menuCheck1);
    //menu selection 2
    /*
     * preforms actual operations on matrices
     * option 1: adds a matrix by hand to the array
     * option 2: reads in a matrix or matrices from a file
     * option 3: to be added at a later time
     * option 4: quits
     *
     * additional options to be added once all matrix input and output functionality is finished
     */

  do {

       printf("\nWelcome please choose an option\n");

       printf("1: Enter in a matrix by hand\n");
       printf("2: Read matricies from a file\n");
       printf("3: Perform operations on current matrices\n");
       printf("4: Quit\n");
       scanf("%d", &option);

     switch (option) {
        case 1 :
           printf("You have chose to enter a matrix by hand\n");
             a++; //increment to reach the next struct
             GetDimen(matrices, a);
             EnterMatrixbh(matrices, a);  //to make changes do not put *matrices just pass it matrices
             break;
        case 2 :
           printf("You have chose to read in a matrix/matricies from a file\n");


             fflush(stdin);
             //path = "D:\\College Documents\\HoffmanResearch\\IOTestFolders\\matrixReadInTest1.txt";
             //scanf("%s", path);


             readInMatrix(matrices, a);

             //function to read in from file
             break;

         case 3 :
             printf("You have chosen to perform operations on your matrices here is a list of all matrices entered please select one by its index");
                break;




        case 4 :
           printf("Goodbye");
             option = 9;
             break;

     }


  } while (option != 9);




}
