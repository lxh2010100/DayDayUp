#include <stdio.h>
#include <stdarg.h> 


double sum(double num1, double num2) {
    return num1 + num2; 
} 

int main() { 
    printf("Sum of 2, 2 is %f\n", sum(2, 2)); 
    printf("Sum of 2.0, 4.0 %f\n", sum(2.0,4.0)); 
}
