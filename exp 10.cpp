#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100

int epsilon[MAX_STATES][MAX_STATES]; 
int closure[MAX_STATES][MAX_STATES];
int num_states; 

void find_closure(int state) {
    closure[state][state] = 1; 

    int stack[MAX_STATES], top = 0;
    stack[top++] = state;

    while (top > 0) {
        int current = stack[--top];
        for (int i = 0; i < num_states; i++) {
            if (epsilon[current][i] && !closure[state][i]) {
                closure[state][i] = 1;
                stack[top++] = i;
            }
        }
    }
}

int main() {
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &num_states);

    printf("Enter the transition matrix for epsilon moves (1 for epsilon move, 0 otherwise):\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            scanf("%d", &epsilon[i][j]);
        }
    }

    for (int i = 0; i < num_states; i++) {
        find_closure(i);
    }

    printf("Epsilon closure for each state:\n");
    for (int i = 0; i < num_states; i++) {
        printf("State %d: {", i);
        for (int j = 0; j < num_states; j++) {
            if (closure[i][j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}
