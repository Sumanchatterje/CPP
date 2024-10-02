#include <stdio.h>

int main() {
    int math, eng, comp, dsa, eng, mgrade, egrade, cgrade, dgrade, engrade;
    printf("Enter marks of subjects as maths, eng, computer, dsa, english: ");
    scanf("%d %d %d %d %d", &math, &eng, &comp, &dsa, &eng);
    mgrade = ((math / 10) + 1) * 4;
    egrade = ((eng / 10) + 1) * 4;
    cgrade = ((comp / 10) + 1) * 4;
    dgrade = ((dsa / 10) + 1) * 4;
    engrade = ((eng / 10) + 1) * 4;
    float avg = (float) (mgrade + egrade + cgrade + dgrade + engrade) / 15;
    printf("Your SGPA is: %f\n", avg);
    return 0;
}