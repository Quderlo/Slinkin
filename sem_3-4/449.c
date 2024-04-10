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
} triangle;

<<<<<<< HEAD
=======

>>>>>>> aa33b0890b06b842893f0b210b745b226718fed6

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
	double side12 = lenght_of_side(t.p1, t.p2);
    double side23 = lenght_of_side(t.p2, t.p3);
    double side13 = lenght_of_side(t.p1, t.p3);
    
    t.square = square_of_triangle(side12, side23, side13);
    
    return t;
}


// Если точка внутреннего треугольника находится на одной стороне с
// третьей точкой внешнего треуголника функция вернёт 1 иначе 0
int check_point_side(point p1, point p2, point p3, point p4){
	double a = p1.y - p2.y;
	double b = p2.x - p1.x;
	double c = p1.x * (p1.y - p2.y) + p1.y * (p2.x - p1.x);
	
	if ((a * p3.x + b * p3.y + c) * (a * p4.x + b * p4.y + c) >= 0)
		return 1;
	
	return 0;
}


int check_all_points_by_half_plane(triangle t1, triangle t2) {
	int xy1 = check_point_side(t2.p1, t2.p2, t2.p3, t1.p1);
	int xy2 = check_point_side(t2.p1, t2.p2, t2.p3, t1.p2);
	int xy3 = check_point_side(t2.p1, t2.p2, t2.p3, t1.p3);
	
	int xy4 = check_point_side(t2.p2, t2.p3, t2.p1, t1.p1);
	int xy5 = check_point_side(t2.p2, t2.p3, t2.p1, t1.p2);
	int xy6 = check_point_side(t2.p2, t2.p3, t2.p1, t1.p3);
	
	int xy7 = check_point_side(t2.p1, t2.p3, t2.p2, t1.p1);
	int xy8 = check_point_side(t2.p1, t2.p3, t2.p2, t1.p2);
	int xy9 = check_point_side(t2.p1, t2.p3, t2.p2, t1.p3);
	
	if (xy1 && xy2 && xy3 && xy4 && xy5 && xy6 && xy7 && xy8 && xy9)
		return 1;
		
	return 0;
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
	
	if (fabs(t.square - (s1 + s2 + s3)) < 0.000001) {
		return 1;
	}
		
	return 0;
}

int check_all_points_by_square(triangle t1, triangle t2) {
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
/*
	printf("Write coordinates for first inner triangle (x1 y1 x2 y2 x3 y3): ");
	scanf("%lf %lf %lf %lf %lf %lf", &triangle1.p1.x, &triangle1.p1.y, 
	&triangle1.p2.x, &triangle1.p2.y, &triangle1.p3.x, &triangle1.p3.y);

	printf("Write coordinates for second triangle (x1 y1 x2 y2 x3 y3): ");
	scanf("%lf %lf %lf %lf %lf %lf", &triangle2.p1.x, &triangle2.p1.y, 
	&triangle2.p2.x, &triangle2.p2.y, &triangle2.p3.x, &triangle2.p3.y);
*/	

	//Тест
	triangle1.p1.x = 0.5, triangle1.p1.y = 0/5;
	triangle1.p2.x = 1, triangle1.p2.y = 0;
	triangle1.p3.x = 1.5, triangle1.p3.y = 0.5;
	
	triangle2.p1.x = 0, triangle2.p1.y = 0;
	triangle2.p2.x = 1, triangle2.p2.y = 1;
	triangle2.p3.x = 2, triangle2.p3.y = 0;	
	
	triangle1 = get_sides_and_square(triangle1);
	triangle2 = get_sides_and_square(triangle2);
	
	
	if (check_all_points_by_square(triangle1, triangle2)) {
		printf("Result: square = %lf\n", triangle2.square - triangle1.square);
	}
	else {
		printf("The triangles intersect\n");
	}
	
	if (check_all_points_by_half_plane(triangle1, triangle2)) {
		printf("Result: square = %lf\n", triangle2.square - triangle1.square);
	}
	else {
		printf("The triangles intersect\n");
	}
	
	
    return 0;
}
