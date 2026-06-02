#include <stdio.h>

int main() {
    int n, i;
    float x, y;
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    float m, c; // slope and y-intercept

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x and y values for each point:\n");
    for (i = 0; i < n; i++) {
        printf("Point %d (x y): ", i + 1);
        scanf("%f %f", &x, &y);

        sum_x += x;
        sum_y += y;
        sum_xy += (x * y);
        sum_x2 += (x * x);
    }

    // Calculate slope (m)
    m = (float)(n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);

    // Calculate y-intercept (c)
    c = (float)(sum_y - m * sum_x) / n;

    printf("\nLinear Regression Equation: y = %.2fx + (%.2f)n", m, c);

    return 0;
}
