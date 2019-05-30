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
  int tempi, tempj, tempk, tempu, tempv;
  long compute_it, compute_it1;
  long aggregate=1.0;
  int temp = 0;
  int ii,jj,kk;
  int SIZE = DIM-1;
  int index;
  int BLOCK = 8;

  #pragma omp parallel for private (jj,kk,i,j,k,u,v,w,index,compute_it1,tempi, tempj, tempu, tempv) reduction (+: aggregate)
  for (ii = 1; ii < SIZE; ii+= BLOCK) {
    for (jj = 1; jj < SIZE; jj+= BLOCK) {
      for (kk = 1; kk < SIZE; kk+= BLOCK) {
        int iiSize = ii+BLOCK;
        for (i=ii; (i<iiSize && i<SIZE); i++) {
          tempi = i*DIM*DIM;
          int jjSize = jj+BLOCK;
          for (j=jj; (j<jjSize && j<SIZE); j++) {
            tempj = tempi + j*DIM;  
            int kkSize = kk+BLOCK;
            for (k=kk; (k<kkSize && k<SIZE); k++) {
              index = tempj + k;
              //index = i*DIM*DIM + j*DIM + k;
              new[index] = 0;
              compute_it1=old[index] * we_need_the_func();
              aggregate += compute_it1 / gimmie_the_func();
              for (u=-1; u<=1; u++) {
                tempu = (i+u)*DIM*DIM;
                for (v=-1; v<=1; v++) {
                  tempv = (j+v)*DIM;
                  for (w=-1; w<=1; w++) {
                    temp+=old[tempu+tempv+(k+w)];
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  printf("AGGR:%ld\n",aggregate);

  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        u=(new[i*DIM*DIM+j*DIM+k]/100);
        if (u<=0) u=0;
        if (u>=9) u=9;
        histogrammy[u]++;
      }
    }
  }
  
// //#pragma omp parallel num_threads(4) private(i,j,k,u,v,w, tempi, tempj, tempk,compute_it)
//   for (i=1; i<DIM-1; i++) {
//     tempi = i*DIM*DIM;
//     for (j=1; j<DIM-1; j++) {
//       tempj = tempi + j*DIM;
//       for (k=1; k<DIM-1; k++) {
//         temp = 0;
//         tempk = tempj + k;
//         //#pragma omp for nowait reduction(+:temp)
//         for (u=-1; u<=1; u++) {
//           for (v=-1; v<=1; v++) {
//             for (w=-1; w<=1; w++) {
//                temp+=old[(i+u)*DIM*DIM+(j+v)*DIM+(k+w)];
//             }
//           }
//         }

//         temp/=27;
//         new[tempk]=temp;
//         //#pragma omp single nowait
//         u=(temp/100);        
//         //#pragma omp single nowait
//         if (u<=0) u=0;
//         //#pragma omp single nowait
//         if (u>=9) u=9;
//         //#pragma omp single nowait
//         histogrammy[u]++;
//       }
//     }
//   }

// }

}