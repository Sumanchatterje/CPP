#include <stdio.h>

int main() {
    char str[100];
    int v = 0, con = 0, len = 0, spec = 0;
    printf("Enter text: \n");
    gets(str);
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
                v++;
                break;
            case ' ':case '\n':case '\t':
                spec++;
                break;
            default:
                con++;
                break;
        }
    }
    printf("Number of vowels: %d\n", v);
    con = len - v - spec;
    printf("Number of consonants: %d\n", con);

    return 0;
}