#include "football.h"
#include <stdio.h>

/**
 * @brief Return the number of possible combinations to add up to `points`
 *
 * @param points
 * @return int
 */
int count_combinations(int points) {
    int count = 0;
    for (int td2 = 0; td2 * 8 <= points; ++td2) {
        for (int td1 = 0; td2 * 8 + td1 * 7 <= points; ++td1) {
            for (int td = 0; td2 * 8 + td1 * 7 + td * 6 <= points; ++td) {
                for (int fg = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= points; ++fg) {
                    int remaining_points = points - (td2 * 8 + td1 * 7 + td * 6 + fg * 3);
                    if (remaining_points % 2 == 0) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

/**
 * @brief Print a formatted table of all possible combinations that add up to
 * `points`
 *
 * @param points
 */
void print_combinations(int points) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", points);
    for (int td2 = 0; td2 * 8 <= points; ++td2) {
        for (int td1 = 0; td2 * 8 + td1 * 7 <= points; ++td1) {
            for (int td = 0; td2 * 8 + td1 * 7 + td * 6 <= points; ++td) {
                for (int fg = 0; td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= points; ++fg) {
                    int remaining_points = points - (td2 * 8 + td1 * 7 + td * 6 + fg * 3);
                    if (remaining_points % 2 == 0 && remaining_points >= 0) {
                        int s = remaining_points / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, s);
                    }
                }
            }
        }
    }
}
