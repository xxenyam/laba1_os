#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "points.h"

int main() {
    int n;

    // Ініціалізуємо генератор випадкових чисел на основі поточного часу
    srand(time(NULL));

    printf("Введіть кількість точок: ");
    scanf("%d", &n);

    Point* points = create_points(n);
    process_points(points, n);
    free_points(points);

    return 0;
}
