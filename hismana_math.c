/*
Slope, Midpoint, Intercepts, Distance Solver by Nikko Gabriel J Hismaña
-Input: asks user to input coordinates (X1,Y1), (X2,Y2)
-Output: Slope, Midpoint, Distance, yint, xInt
*/

#include <stdio.h>
#include <math.h>

struct Coordinate {
    double x;
    double y;
};

int main(){

    //DECLARE VARIABLES
    double slope, midpointX, midpointY, distance, yIntercept, xIntercept;
    int i;

    //COORDINATE STRUCTS AND USER INPUT
    struct Coordinate point[2];

    for (i = 0; i<2; i++){
        printf("Enter X Coordinate of Point %d: ",i+1);
        scanf("%lf", &point[i].x);
        printf("Enter Y Coordinate of Point %d: ",i+1);
        scanf("%lf", &point[i].y);
    }

    //COMPUTATIONS
    slope = (point[0].y-point[1].y)/(point[0].x-point[1].x);
    midpointX = (point[0].x + point[1].x)/2;
    midpointY = (point[0].y + point[1].y)/2;
    distance = sqrt( pow((point[0].x - point[1].x),2) + pow((point[0].y - point[1].y),2) );
    yIntercept = point[0].y - slope*(point[0].x) ;
    xIntercept = -yIntercept/slope;

    //PRINT OUTPUT (as specified in instructions)
    printf("\n\nOUTPUT:\n");
    printf("Slope = %.2f\n", slope);
    printf("Midpoint = (%.2f, %.2f)\n", midpointX, midpointY);
    printf("Distance = %.2f\n", distance);
    printf("yIntercept = %.2f\n", yIntercept );
    printf("xIntercept = %.2f\n", xIntercept );

    //prevent window from closing as soon as wordcount results are printed
    //used system("pause") since getc()/getchar() not working
    system("pause"); 
    return 0;
}