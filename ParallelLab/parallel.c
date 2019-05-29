//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Prithvi Kannan
 * UCLA ID : 405110096
 * Email : prithvi.kannan@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_par(long *old, long *new) {
  int i, j, k;
  int u, v, w;
  int tempi, tempj, tempk;
  long compute_it;
  long aggregate=1.0;
  int temp = 0;
  
//#pragma omp parallel num_threads(4) private(i,j,k,u,v,w, tempi, tempj, tempk,compute_it, temp)
  for (i=1; i<DIM-1; i++) {
    tempi = i*DIM*DIM;
    for (j=1; j<DIM-1; j++) {
      tempj = tempi + j*DIM;
      for (k=1; k<DIM-1; k++) {
        tempk = tempj + k;
        temp = 0;
        compute_it = old[tempj+k] * we_need_the_func();
        //#pragma omp single nowait        
        aggregate+= compute_it / gimmie_the_func();
        //#pragma omp for nowait reduction(+:temp)
        for (u=-1; u<=1; u++) {
          for (v=-1; v<=1; v++) {
            for (w=-1; w<=1; w++) {
               temp+=old[(i+u)*DIM*DIM+(j+v)*DIM+(k+w)];
            }
          }
        }

        temp/=27;
        new[tempk]=temp;
        //#pragma omp single nowait
        u=(temp/100);        
        //#pragma omp single nowait
        if (u<=0) u=0;
        //#pragma omp single nowait
        if (u>=9) u=9;
        //#pragma omp single nowait
        histogrammy[u]++;
      }
    }
  }
  printf("AGGR:%ld\n",aggregate);

}