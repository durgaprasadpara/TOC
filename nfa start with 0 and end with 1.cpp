#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int is_accepting_state(char* string) {
    int length = strlen(string);
    if (string[0] == '0' && string[length - 1] == '1') {
        return 1;
    }
    return 0;
}

int main() {
    char input_string[MAX_LENGTH];
    printf("Enter a string to check: ");
    scanf("%s", input_string);
    if (is_accepting_state(input_string)) {
        printf("Accept\n");
    } else {
        printf("Reject\n");
    }
    return 0;
}
