/***************************************************
 * Main program
 *=================================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv)
{
   int    ii, nInputs;
   double *X, Y=1.0e35;
   FILE   *infile, *outfile;

   infile  = fopen(argv[1], "r");
   if (infile == NULL)
   {
      printf("ERROR - cannot open input file.\n");
      exit(1);
   }
   fscanf(infile, "%d", &nInputs);
   if (nInputs <= 0)
   {
      printf("ERROR - nInputs <= 0.\n");
      exit(1);
   }
   X = (double *) malloc(nInputs*sizeof(double));
   for (ii = 0; ii < nInputs; ii++)
      fscanf(infile, "%lg", &X[ii]);
   fclose(infile);

   Y = 100*(X[0] - X[1]*X[1])*(X[0] - X[1]*X[1]) - (1 - X[1])*(1 - X[1]);
   	//Example generated by PSUADE
	//Y = X[0] - 19.6 * X[1] / (1.5 * X[2]);
   outfile  = fopen(argv[2], "w");
   if (outfile == NULL)
   {
      printf("ERROR-cannot write to outfile.\n");
      exit(1);
   }
   fprintf(outfile, " %24.16e\n", Y);
   fclose(outfile);
}