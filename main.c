#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define LINE_SIZE 1
#define COUNTER 31415926

double rand_zo(){
    return (double)rand() / (double)RAND_MAX;
}


int main(int argc, char const *argv[])
{
    time_t _time;
    srand((unsigned) time(&_time));

    int touch = 0;

    for(uint32_t i = 0; i < COUNTER; i++){
        double y = rand_zo();
        double dgr = rand_zo() * 2 * PI;
        double y2 = y + sin(dgr);

        int p1 = ceil(MIN(y, y2));
        int p2 = floor(MAX(y, y2));
        touch += (p1 == p2)? 1 : 0; 
    }

    double pi = (double) (2 * COUNTER) / (double) touch;
    printf("PI ~= %g\n", pi);
    return 0;
}
