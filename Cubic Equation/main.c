#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main()
{
    float a, b, c;
    char a_n[39];
    char b_n[39];
    char c_n[39];
    float y, p, q, d, u, v ;

    printf("Cubic equation: x3 + ax2 + bx + c = 0\n");
    printf("Enter a: ");
    fgets(a_n, 38, stdin);
    a = atof(a_n);
   

    printf("Enter b: ");
    fgets(b_n, 38, stdin);
    b = atof(b_n);
   

    printf("Enter c: ");
    fgets(c_n, 38, stdin);
    c = atof(c_n);
    if (a == 0 && b == 0 && c == 0){
        printf("x = 0");
        getch();
        exit(-1);
        
    }
    

    p = b - (a*a)/3;

    q = (2*a*a*a/27) - (a*b)/3 + (c);

    d = (p*p*p/27) + (q*q/4);



    if (d > 0){
        float y1;
        float complex y2, y3;
        float x1;
        float complex x2, x3;

        y = -q/2 + sqrt(d);
        u = (y>0) ? (pow(y,1/3.)) : (pow(fabs(y), 1/3.)*(-1));
        v = -p/(3*u);

        y1 = u + v;
        y2 = (u+v)/(-2) + I*(sqrt(3)*(u-v))/2;
        y3 = (u+v)/(-2) - I*(sqrt(3)*(u-v))/2;

        x1 = y1 - a/3;
        x2 = y2 - a/3;
        x3 = y3 - a/3;

        printf("\n x1: %f", x1);
        printf("\n x2: %f + %fi", creal(x2), cimag(x2));
        printf("\n x3: %f + %fi", creal(x3), cimag(x3));
        getch();

    }

    else if(d == 0){
        float y1, y2;
        float x1, x2;

        y1 = 3*q/p;
        y2 = -3*q/(2*p);
        x1 = y1 - a/3;
        x2 = y2 - a/3;

        printf("\n x1: %f", x1);
        printf("\n x2: %f", x2);
        printf("\n x3: %f", x2);
        getch();


    }

    else if (d < 0 && (p*p*p/(-27)) >= 0 ){
        float y1, y2, y3;
        float x1, x2, x3;
        float r = sqrt(p*p*p/(-27));
        float ph = acos(-q/(2*r));

        y1 = 2*fabs(pow(r, 1/3.))* cos(ph/3);
        y2 = 2*fabs(pow(r, 1/3.))* cos((ph+2*M_PI)/3);
        y3 = 2*fabs(pow(r, 1/3.))* cos((ph +4*M_PI)/3);

        x1 = y1 - a/3;
        x2 = y2 - a/3;
        x3 = y3 - a/3;

        printf("\n x1: %f", x1);
        printf("\n x2: %f", x2);
        printf("\n x3: %f", x3);
        getch();
    }
    return 0;




}
