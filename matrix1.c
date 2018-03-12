#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void
get_walltime (double *wct)
{
  struct timeval tp;
  gettimeofday (&tp, NULL);
  *wct = (double) (tp.tv_sec + tp.tv_usec / 1000000.0);
}


int
main (int argc, const char *argv[])
{

  double *Array;
  double start, end;		                                        //time starts, time ends
  int Fill = 0;

  Array = (double *) malloc (NROWS * NCOLS * sizeof (double));

  if (Array == NULL)                                                // error checking
    {
      printf ("Error! memory not allocated.");
      exit (0);
    }

  for (int i = 0; i < NROWS * NCOLS; i++)                           //arxikopoihsh pinaka
    {
      Array[i] = 0.0;
    }

  get_walltime (&start);                                            //3ekinaw na upologizw ton xrono

  for (int i = 0; i < NROWS; i++)
    {
      for (int j = 0; j < NCOLS; j++)
	    {                                                       // kata grami
	        Fill += Array[j*NCOLS + i];                         // apifigh skip kapoiou loop apo ton metaglwtisth 
    	}
    }

  get_walltime (&end);                                              //stamataw na upologizw ton xrono
  
  double tim = ((double) end - start);  

  free (Array);
  printf ("%f Time Elapsed", tim);                                                                   //results
  printf ("\n");
  printf ("%f Megacces/sec",(2.0 * NROWS * NCOLS) / ((end - start) * 1000000));                //prospelaseis to deuterolepto
  printf ("\n");
  printf ("%d", Fill);                                                                       // to tipwnw gia na min to paralipsei o compiler
  
  return 0;
}
