#ifndef POINTS_H
#define POINTS_H

typedef struct {
    double x, y, z;  // координати точки
    double mass;     // маса точки
} Point;

Point* create_points(int n);  // створення точок
void free_points(Point* points);  // звільнення пам'яті
int find_min_mass_point(Point* points, int n);  // знаходження точки з найменшою масою
int find_nearest_point(Point* points, int n, int index);  // знаходження найближчої точки
void process_points(Point* points, int n);  // обробка точок

#endif


