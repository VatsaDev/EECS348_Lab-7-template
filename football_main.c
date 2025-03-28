#include <stdio.h>
#include "football.h"

int main(int argc, char *argv[]) {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (score <= 1) {
            break;
        }

        print_combinations(score);
    }
    return 0;
}
