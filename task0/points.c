#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "points.h"

// Функція для генерації випадкових чисел у заданому діапазоні
double random_double(double min, double max) {
    return min + (double)rand() / ((double)RAND_MAX / (max - min));
}

// Створення масиву точок з випадковими координатами та масою
Point* create_points(int n) {
    Point* points = (Point*)malloc(n * sizeof(Point));
    if (!points) {
        printf("Помилка виділення пам'яті\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        points[i].x = random_double(0.0, 100.0);  // Генерація координати x
        points[i].y = random_double(0.0, 100.0);  // Генерація координати y
        points[i].z = random_double(0.0, 100.0);  // Генерація координати z
        points[i].mass = random_double(1.0, 10.0); // Генерація маси
        printf("Точка %d: координати (%.2lf, %.2lf, %.2lf), маса %.2lf\n", 
               i + 1, points[i].x, points[i].y, points[i].z, points[i].mass);
    }
    return points;
}

// Звільнення пам'яті для масиву точок
void free_points(Point* points) {
    free(points);
}

// Знаходження точки з найменшою масою
int find_min_mass_point(Point* points, int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].mass < points[min_index].mass) {
            min_index = i;
        }
    }
    return min_index;
}

// Знаходження найближчої точки
int find_nearest_point(Point* points, int n, int index) {
    int nearest_index = -1;
    double min_distance = -1;
    for (int i = 0; i < n; i++) {
        if (i == index) continue;
        double distance = sqrt(pow(points[i].x - points[index].x, 2) +
                               pow(points[i].y - points[index].y, 2) +
                               pow(points[i].z - points[index].z, 2));
        if (nearest_index == -1 || distance < min_distance) {
            nearest_index = i;
            min_distance = distance;
        }
    }
    return nearest_index;
}

// Обробка точок, поки не залишиться одна
void process_points(Point* points, int n) {
    while (n > 1) {
        int min_mass_index = find_min_mass_point(points, n);
        int nearest_index = find_nearest_point(points, n, min_mass_index);
        
        // Передаємо масу
        points[nearest_index].mass += points[min_mass_index].mass;

        // Виведення інформації про передачу маси
        printf("Точка з масою %.2lf на координатах (%.2lf, %.2lf, %.2lf) передає масу %.2lf до точки з масою %.2lf на координатах (%.2lf, %.2lf, %.2lf)\n",
               points[min_mass_index].mass, 
               points[min_mass_index].x, points[min_mass_index].y, points[min_mass_index].z,
               points[min_mass_index].mass,
               points[nearest_index].mass,
               points[nearest_index].x, points[nearest_index].y, points[nearest_index].z);

        // Видаляємо точку з найменшою масою
        for (int i = min_mass_index; i < n - 1; i++) {
            points[i] = points[i + 1];
        }
        n--;
    }

    printf("Залишилася одна точка з координатами: (%.2lf, %.2lf, %.2lf) і масою %.2lf\n",
           points[0].x, points[0].y, points[0].z, points[0].mass);
}
