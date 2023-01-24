#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    printf("Enter the input string: ");
    scanf("%s", input_string);
    int state = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        if (state == 0 && input_string[i] == '0') {
            state = 1;
        } else if (state == 1 && input_string[i] == '0') {
            state = 1;
        } else if (state == 1 && input_string[i] == '1') {
            state = 2;
        } else {
            state = 3;
        }
    }
    if (state == 2) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
return 0;
}
