#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    float amount;
    printf("Enter in dollars: ");
    scanf("%f", &amount);
    int pennies = 100 * amount;
    printf("Dollars converted to pennies are %d", pennies);
    return 0;
}