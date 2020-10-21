#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input.h"

double integral(char *polynom, double lower, double upper, double step, char *rule);
double midpoint(char *polynom, double lower, double upper, double step);
double rectangle(char *polynom, double lower, double upper, double step);
double simpson(char *polynom, double lower, double upper, double step);
double trapezoid(char *polynom, double lower, double upper, double step);
double calculate(char *, double);
double pover(double x, double y);

int main(int argc, char** argv){
    if( argc != 6 ){
        printf("Eksik argüman!\n");
        return 0;
    }

    // definition
    double lower, upper, step;
    char *polynom, *rule;
    polynom = argv[1];
    lower = atoi( argv[2] );
    upper = atoi( argv[3] );
    step  = atoi( argv[4] );
    rule    = argv[5];

    //printf("Up: %lf Lo: %lf\n", upper, lower);
    double result = integral(polynom, lower, upper, step, rule);

    printf("Sonuç: %lf\n", result);    
}

double integral(char *polynom, double lower, double upper, double step, char *rule){
    char ch = rule[0];
    switch (ch){
        case 'M':
        case 'm':
            return midpoint(polynom, lower, upper, step);
            break;
        case 'R':
        case 'r':
            return rectangle(polynom, lower, upper, step);        
            break;
        case 'S':
        case 's':
            return simpson(polynom, lower, upper, step);        
            break;
        case 'T':
        case 't':
            return trapezoid(polynom, lower, upper, step);        
            break;
    }
}

double midpoint(char *polynom, double lower, double upper, double step){
    double result = 0.0;
    double stepSize = (upper-lower)/step;
    double curLower, curUpper;
    for(int i=0; i<step; i++){
        curUpper = lower + (i+1)*stepSize;
        curLower = lower + i*stepSize;
        result += (curUpper-curLower) * calculate(polynom, (curLower+curUpper)/2  );
    }
    return result;
}

double rectangle(char *polynom, double lower, double upper, double step){
    double result = 0.0;
    double stepSize = (upper-lower)/step;
    double curLower, curUpper;
    for(int i=0; i<step; i++){
        curUpper = lower + (i+1)*stepSize;
        curLower = lower + i*stepSize;
        result += calculate(polynom, curLower) * (curUpper - curLower);
    }
    return result;
}

double simpson(char *polynom, double lower, double upper, double step){
    double result = 0.0;
    double stepSize = (upper-lower)/step;
    double curLower, curUpper;
    for(int i=0; i<step; i++){
        curUpper = lower + (i+1)*stepSize;
        curLower = lower + i*stepSize;
        result += ((curUpper - curLower)/6) * ( calculate(polynom, curLower) + 4*calculate(polynom, (curUpper+curLower)/2) + calculate(polynom, curUpper) );
    }
    return result;
}

double trapezoid(char *polynom, double lower, double upper, double step){
    double result = 0.0;
    double stepSize = (upper-lower)/step;
    double curLower, curUpper;
    for(int i=0;i<step; i++){
        curUpper = lower + (i+1)*stepSize;
        curLower = lower + i*stepSize;
        result += ( ( curUpper - curLower ) / 2 ) * ( calculate(polynom, curLower) + calculate(polynom, curUpper) );
    }
    
    return result;
}

double calculate(char *polynom, double value){     //Bu bizim integral için fonksiyon için parçalara ayırma fonksiyonumuz
    char *iter = polynom;
    double coef;
    double power;
    double result = 0.0;
    
    while(*iter != '\0'){
        if(*iter == '^'){
            coef = *(iter-2) - '0';
            power = *(iter+1) - '0';
            if( *(iter-3) == '-')
                result -= ( coef * pover(value, power) );
            else
                result += ( coef * pover(value, power) );
        }
        iter++;
    }
    return result;
}

double pover(double x, double y){   //pow fonksiyonu çalışmadığı için yeniden kendim yazdım.
    if(y == 0)
        return 1;
    else if( y == 1)
        return x;
    else {
        double multiplier = x;
        while(y>1){
            x *= multiplier;
            y--;
        }
    }
    return x;
}
