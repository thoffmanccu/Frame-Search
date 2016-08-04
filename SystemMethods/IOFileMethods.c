//
// Created by Ebon Moore-Martin on 6/29/2016.
// This file will serve to contain all created methods/implementations of IO type
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IOFileMethods.h"

#define MAX_PATH_A 256

/*
 * all input methods
 */



    /*
     * reads the file and inserts data into the matrices array
     * File *fopen( const char * filename, const char * mode); this will open the file
     * int fclose( FILE *fp ); to close the file when done reading returns 0 if successful
     * int fget( FILE *fp);
     */
    void readInMatrix (struct Matrices* matrices, int a)
    {

        int i = a; // will be passed into the function but the current position in the matrices struct
        int j;     // the temp for dimensions for the for loop when reading the top half of the matrix
        int index =0; // current position in the matrix

        printf("%d\n", i);


        //int testDimensions[2];
        char *path = malloc (MAX_PATH_A);
        if (path == NULL)       //checking to see if you have the memory available
        {
            printf("No memory\n");
            exit(0);
        }

        printf("path to file\n");

        fgets(path, MAX_PATH_A, stdin);

        if ((strlen(path)>0) && (path[strlen (path) - 1] == '\n'));
        {
            path[strlen(path)-1] = '\0';
        }

        printf("%s\n", path);

        FILE *fp;
        fp = fopen(path, "r");
        /*while ((c=getc(fp)) !=EOF)
        {
            printf("%c", c);
        }
         */


        matrices[i].Dimensions[0] = getc(fp) - 48;
        fseek(fp, 1 , SEEK_CUR);
        matrices[i].Dimensions[1] = getc(fp) - 48;
        fseek(fp, 1, SEEK_CUR);
        /*
         * call newLineRemover because in c when reading from a file a new line character reads as a normal character and
         * is not skipped over like in java it returns a 10 for new line and must be consumed to move on to the next line
         * of data
         */
        newLineRemover(fp);
        matrices[i].firstNum = getc(fp) - 48;

        printf("Dimensions of your matrix are R:%d C:%d", matrices[i].Dimensions[0], matrices[i].Dimensions[1]);







        /*
         * now that the necessary information has been stored to read in the rest of the matrix I will begin reading in the
         * top half of the matrix depending on whether the diagonal axis in the matrix is either positive or negative.
         *
         *                       i.e
         *                              positive upward diagonal of ones
         *                                      [0 1 0 1]           matrices[i].firstNum = 0
         *                                      [0 1 1 0]
         *                                      [0 1 1 0]
         *                                      [1 0 1 0]
         *
         *
         *
         *                              negative downward diagonal of ones
         *                                      [1 0 1 0]           matrices[i].firstNum = 1
         *                                      [0 1 1 0]
         *                                      [1 0 1 0]
         *                                      [1 0 0 1]
         */
        //playing with pointers
        int *P = &matrices[i].Dimensions[1]; // p is now a pointer to the number of columns in the matrix
        j = *P - 1; // setting j to the number of columns in the matrix for the FOR LOOP
        int n = *P; // number of columns
        int b = 1; // what i'm using to subtract get total times read just a sequence n-1 + n-2 + n-3 +...... n-n
        int TR = n - b; // number of characters read each iteration
        int *P1 = &TR;
        int buffer = 0;
        fseek(fp, -1, SEEK_CUR);
        /*
         * number of characters to skip each time a line is being read through i.e for a 3 by 3 matrix since I have already
         * taken in the first number just to determine which way the diagonal of 1s is(either up or down) the number itself
         * is not important to store so I skip over it to get either the top half of the diagonal or the bottom half.
         */
        int Skips = 1;

        // downward diagonal of ones
        if (matrices[i].firstNum == 1)
        {

            for (j; j>0; j--)
            {
                int r = *P1;
                printf("\n%d", r);
                fseek(fp, Skips, SEEK_CUR);
                for (r; r > 0; r--)
                {
                    matrices[i].Matrix[index] = getc(fp)-48;
                    index++;
                }
                a++;
                Skips++;
                TR--;
                newLineRemover(fp);
            }


        }
            // upward diagonal of ones
        else if (matrices[i].firstNum == 0)
        {
            for (j; j>0; j--)
            {
                int r = *P1;
                printf("\n%d", r);

                for (r; r > 0; r--)
                {
                    matrices[i].Matrix[index] = getc(fp)-48;
                    index++;
                }
                a++;
                Skips++;
                TR--;
                fseek(fp, Skips, SEEK_CUR);
                newLineRemover(fp);

            }


        }
            // invalid matrices entered tier 1 error checking
        else
        {
            printf("Invalid Matrices now returning to main menu.....");
            exit(0);

        }





        //testing
        printf("\nJ:%d\nN:%d\nA:%d\nTR:%d\nIndex:%d\n", j, n, a, TR, index );
        int q;
        for (q = 0; q < index; q++)
        {
            printf("\n%d", matrices[i].Matrix[q]);
        }





        //test();
        fclose(fp);
        free (path); //once freed path no longer holds anything
        exit(0);


    }

void newLineRemover(FILE *fp)
{
    char buff;
    buff = getc(fp);
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


