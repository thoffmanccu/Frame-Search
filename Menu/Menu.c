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
       printf("\nWelcome to matricies v0.15\n");
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



         //case 3 :
           //printf("You have chose to perform operations on matricies\n");
           //  printf("Which operation you would like to perform");
           //  printf("\nnot available in this version still in development");
             //function for operations
            /*
             * 0 PLAYSTATION 3 TO ADD FULL GAME COLLECTION
             * 1 SEXBOX LOL WHO PLAYS THIS SHIT
             * 2 PC MASTERRACE GOD MODE SUPER SALT 3
             * 4 PLAYSTATION 4 SONY GODS
             *
             */

           /* srand(time(NULL));
             int a = rand() % 3;
             int exit = 0;
             int gamemode;
             printf("random number is: %d" , a);
             //printf("\n 0 for playstation\n 1 for xbox one\n 2 for PC MasterRace");
                switch (a)
                {
                    case 0 :
                        printf("\nYour console of choice is Playstaion 3");
                        int b = rand() % 3;
                        if (b == 0)
                        {
                            printf("  you are going to play Uncharted");
                        }
                        else if (b == 1)
                        {
                            printf(" you are going to play Jak and Daxster");
                        }
                        else if (b == 2)
                        {
                            printf(" you are going to play Grand Turismo");
                        }
                        else
                        {
                            printf("\nsomething went wrong in the if else comparison statement fuck c");
                        }
                        break;

                    case 1 :
                        exit = 1;
                        printf("\nYour console of choice is SeXbox");
                        printf(" you are playing halo for a game");
                        break;

                    case 2 :
                        printf("\n Your console of choice is PC Master Race");
                        int c = rand() % 5;
                        if (c == 0)
                        {
                            printf("\nyou are playing Batman");
                        }
                        else if (c == 1)
                        {
                          printf("\nyou are playing Dishonored");
                        }
                        else if ( c == 2)
                        {
                            printf(" you are playing Dark Souls 3");
                        }
                        else if ( c == 3 )
                        {
                            printf(" you are playing Battle Field 4");
                            gamemode = rand() % 3;
                            exit = 1;
                            if (gamemode == 0)
                            {
                                printf("\n you are playing hardcore for a game");
                            }
                            else if (gamemode == 1)
                            {
                                printf("\n you are playing normal conquest for a game");
                            }
                            else if (gamemode == 2)
                            {
                                printf("\n you are playing rush for a game");
                            }



                        }
                        else if ( c == 4)
                        {
                            printf(" you are about to be enveloped in salt prepare thy anus cause you are playing paragon");
                             gamemode = rand() % 2;
                            exit = 1;
                            if (gamemode == 0)
                            {
                                printf("\n you must take on the world and play PVP get the big salt you will need it");
                            }
                            else if (gamemode == 1)
                            {
                                printf("\n you must be a pussy and play CO-OP YOU ARE A BITCH");
                            }
                            else
                            {
                                printf("you fucked up somehow good luck finding where");
                            }


                        }
                        else
                        {
                            printf("\n something went wrong you fucked up go kill yourself");
                        }
                        break;


                }
             if (exit == 0)
             {
                 int randTime1 = rand() % 31;
                 printf("\n you will be playing for %d minutes good luck", randTime1);
             }
             break; */

        case 4 :
           printf("Goodbye");
             option = 9;
             break;

     }


  } while (option != 9);




}
