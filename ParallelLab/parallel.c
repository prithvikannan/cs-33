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
    long u = 0;
    long u_0, u_1, u_2, u_3, u_4, u_5 ,u_6, u_7, u_8, u_9 = 0;
    long tempSum = 0;
    const long DIM_2 = DIM * DIM;
    long compute_it;
    long aggregate = 1.0;
    long address = 0;
    long tempAddress = 0;

    #pragma omp parallel for private(j,k,address, compute_it, tempAddress, u) reduction(+: aggregate) reduction(+:tempSum)\
    reduction(+:u_0) reduction(+:u_1) reduction(+:u_2) reduction(+:u_3) reduction(+:u_4) reduction(+:u_5) reduction(+:u_6) reduction(+:u_7) reduction(+:u_8) reduction(+:u_9)
    for (i=1; i<DIM-1; i++) {
        for (j=1; j<DIM-1; j++) {
            for (k=1; k<DIM-1; k++) {
                address = i * DIM_2 + j * DIM + k;
                compute_it = old[address] * we_need_the_func();
                aggregate += compute_it / gimmie_the_func();
                tempSum = 0;

                tempAddress = address - DIM_2;

                tempAddress -= DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];


                tempAddress = address;

                tempAddress -= DIM;

                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];


                tempAddress = address + DIM_2;

                tempAddress -= DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempAddress += DIM;
                tempSum += old[tempAddress-1];
                tempSum += old[tempAddress];
                tempSum += old[tempAddress+1];

                tempSum /= 27;
                new[address] = tempSum;
                u = (tempSum/100);
                if (u<=0) u_0++;
                if (u==1) u_1++;
                if (u==2) u_2++;
                if (u==3) u_3++;
                if (u==4) u_4++;
                if (u==5) u_5++;
                if (u==6) u_6++;
                if (u==7) u_7++;
                if (u==8) u_8++;
                if (u>=9) u_9++;
            }
        }
    }
  
    printf("AGGR:%ld\n",aggregate);

    histogrammy[0] = u_0;
    histogrammy[1] = u_1;
    histogrammy[2] = u_2;
    histogrammy[3] = u_3;
    histogrammy[4] = u_4;
    histogrammy[5] = u_5;
    histogrammy[6] = u_6;
    histogrammy[7] = u_7;
    histogrammy[8] = u_8;
    histogrammy[9] = u_9;

}

