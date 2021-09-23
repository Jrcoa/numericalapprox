///
/// file: approximator.c
/// author: joseph casale
///

#include <stdio.h>
#include <stdlib.h>
#include "incrementor.h"

#define DT 0.001 //timestep
#define K 10 //spring constant
#define M 2 //mass

/**
 * Function for a single discretized step of X for mass-spring system.
 * @param Xn current x (position)
 * @param Vn current v (velocity)
 * @returns Xn+1
 */

double stepX( double Xn,  double Vn){
    return Xn + DT*Vn;
}


/**
 * Function for a single discretized step of V for mass-spring system.
 * @param Vn current V (velocity)
 * @param Xn current X (position)
 * @returns Vn+1
 */

double stepV( double Vn,  double Xn){
    return Vn - (K*Xn *DT)/M;
}

int main(int argc, char** argv){
    if(argc <= 1){
        printf("Usage: ./approx [seconds to approx]");
        return 1;
    }
    long time = atol(argv[1]); //time input
    long steps = time/DT;

    //Arrays to hold history
    double *Vn = malloc(sizeof( double)*steps);
    double *Xn = malloc(sizeof( double)*steps);

    //Initial conditions
    *Vn = 0;
    *Xn = 5.0;

    FILE *f = fopen("data.dat", "w+");
    for(int i = 0; i < steps; i++){
        increment(Vn, Xn, stepV);
        increment(Xn, Vn, stepX);

        //put into the data file to later be plotted
        fprintf(f, "%f\t%f\n", i * DT, *Xn);
        Xn++;
        Vn++;
    }
    //Move back to the start of the pointers
    Vn -= steps;
    Xn -= steps;

    //plot data
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set xrange [0:%ld]\n", time);
    fprintf(gnuplotPipe, "set yrange [-6:6]\n");
    fprintf(gnuplotPipe, "plot \"data.dat\"\n");
    fflush(gnuplotPipe);

    return 0;
}
