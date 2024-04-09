#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
} point;

typedef struct {
	point p1;
	point p2;
	point p3;
	double square;
	double side12;
	double side23;
	double side31;
} triangle;

#define EPSILON 0.000001 // Отклонение

// Длинна стороны
double lenght_of_side(point p1 , point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Площадь треугольника по Герону
double square_of_triangle(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Получение площади и сторон
triangle get_sides_and_square(triangle t) {
	t.side12 = lenght_of_side(t.p1, t.p2);
    t.side23 = lenght_of_side(t.p2, t.p3);
    t.side31 = lenght_of_side(t.p3, t.p1);
    
    t.square = square_of_triangle(t.side12, t.side23, t.side31);
    
    return t;
}


// Если сумма площадей треугольников, образованных от вершины 
// внутреннего треугольника и вершин внешнего, равна площади внешнего -
// точка находится внутри него
int point_in_triangle(point p, triangle t) {
	double s1 = square_of_triangle(lenght_of_side(p, t.p1), 
		lenght_of_side(p, t.p2), lenght_of_side(t.p1, t.p2));
		
	double s2 = square_of_triangle(lenght_of_side(p, t.p2), 
		lenght_of_side(p, t.p3), lenght_of_side(t.p2, t.p3));
		
	double s3 = square_of_triangle(lenght_of_side(p, t.p3), 
		lenght_of_side(p, t.p1), lenght_of_side(t.p1, t.p3));
	
	if (fabs(t.square - (s1 + s2 + s3)) < EPSILON) {
		return 1;
	}
		
	return 0;
}

int check_all_points(triangle t1, triangle t2) {
	int p1 = point_in_triangle(t1.p1, t2);
	int p2 = point_in_triangle(t1.p2, t2);
	int p3 = point_in_triangle(t1.p3, t2);
	
	if(p1 == p2 && p2 == p3 && p3 == 1) {
		return 1;
	}

	return 0;
}


int main() {
	triangle triangle1, triangle2;

	printf("Write coordinates for first inner triangle (x1 y1 x2 y2 x3 y3): ");
	scanf("%lf %lf %lf %lf %lf %lf", &triangle1.p1.x, &triangle1.p1.y, 
	&triangle1.p2.x, &triangle1.p2.y, &triangle1.p3.x, &triangle1.p3.y);

	printf("Write coordinates for second triangle (x1 y1 x2 y2 x3 y3): ");
	scanf("%lf %lf %lf %lf %lf %lf", &triangle2.p1.x, &triangle2.p1.y, 
	&triangle2.p2.x, &triangle2.p2.y, &triangle2.p3.x, &triangle2.p3.y);
	
/*
	triangle1.p1.x = 0.5, triangle1.p1.y = 0/5;
	triangle1.p2.x = 1, triangle1.p2.y = 0;
	triangle1.p3.x = 1.5, triangle1.p3.y = 0.5;
	
	triangle2.p1.x = 0, triangle2.p1.y = 0;
	triangle2.p2.x = 1, triangle2.p2.y = 1;
	triangle2.p3.x = 2, triangle2.p3.y = 0;
*/	
	
	triangle1 = get_sides_and_square(triangle1);
	triangle2 = get_sides_and_square(triangle2);
	
	
	if (check_all_points(triangle1, triangle2)) {
		printf("Result: square = %lf", triangle2.square - triangle1.square);
	}
	else {
		printf("The triangles intersect");
	}
	
	
    return 0;
}
