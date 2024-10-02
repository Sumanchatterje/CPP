#include <stdio.h>

int main() {
    int rollNumbers[] = {101, 119, 120, 131, 145, 164, 178};
    int n = sizeof(rollNumbers) / sizeof(rollNumbers[0]);
    int targetRollNumber = 164;
    int isPresent = 0;

    for (int i = 0; i < n; i++) {
        if (rollNumbers[i] == targetRollNumber) {
            isPresent = 1;
            break;
        }
    }

    if (isPresent) {
        printf("Roll number 164 is present.\n");
    } else {
        printf("Roll number 164 is not present.\n");
    }

    return 0;
}