//
// Created by Ebon Moore-Martin on 6/29/2016.
// This file will serve to contain all created methods/implementations of IO type
//

#include <stdio.h>
#include <stdlib.h>
#include "IOFileMethods.h"

/*
 * all input methods
 */



    /*
     * reads the file and inserts data into the matrices array
     * File *fopen( const char * filename, const char * mode); this will open the file
     * int fclose( FILE *fp ); to close the file when done reading returns 0 if successful
     * int fget( FILE *fp);
     */
    void getMatrix (struct Matrices* matrices, int a, char path[])
    {
        printf("\nhas entered getMatrix function");
        char tmp[20]; //technically a string now so use %s

        FILE *input = fopen("C:\\User\\Red Dragon Emperor\\Desktop\\inTest.txt", "r");

        //FILE *input = fopen("D:\\College Documents\\HoffmanResearch\\IOTestFolders\\matrixReadInTest1.txt", "r");
        free(path);

        if (input == NULL)
        {
            perror("Error"); //actually will print out error
        }

        fscanf(input, "%s", tmp);
        printf("\n%c", tmp[0]);  // now that I'm pulling specific characters it needs to be a %c
        int dim = (int)tmp[0] - 48;   //ascii stars at 48 so to get the number you want you need to subtract 48
        printf("\n%d", dim);




    }

  void listAllMatrices (struct Matrices* matrices)
  {
      int i;
      int j;

     /* for (i = 0; i <= sizeof(matrices); i++)
      {
          for (j = 0; j <= sizeof(matrices[i].Matrix); j++)
          {

          }
      }
      */

  }


/*
 * all output methods
 */


