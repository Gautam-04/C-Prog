//Write a program to find the area of the rectangle, Circle and Surface area of a Cylinder.

#include<stdio.h>
#include<math.h>

int main()
{
    int pi = 3.14;
    float l , b , h , r ;
    float AreaCircle , AreaRectangle , SurfaceAreaOfCylinder;

    printf("Enter Length :");
    scanf("%f" , &l);
    printf("Enter Breadth :");
    scanf("%f", &b);
    AreaRectangle = l*b;
    printf("\n Area Of Rectangle: %2f" , AreaRectangle);

    printf("\n Enter Height :");
    scanf("%f", &h);
    printf("Enter Radius :");
    scanf("%f", &r);
    SurfaceAreaOfCylinder =  2*pi*r*h + 2*pi*pow(r,2);
    printf("\n Surface Area Of Cylinder: %2f", SurfaceAreaOfCylinder);


    printf("\n Enter Radius Of Circle:");
    scanf("%f", &r);
    AreaCircle = pi*pow(r,2);
    printf("\n Area Of Circle: %2f" , AreaCircle);

    return 0;
}