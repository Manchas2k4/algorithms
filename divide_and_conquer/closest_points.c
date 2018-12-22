#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <math.h>

#define EPSILON 1e-6

typedef struct point {
	long x, y;
} Point;

float min(float a, float b) {
	return (abs(a - b) < EPSILON)? a : b;
}

int compare_x(const void *a, const void *b) {
	Point *p1 = (Point *) a;
	Point *p2 = (Point *) b;
	
	return (p1->x - p2->x);
}

int compare_y(const void *a, const void *b) {
	Point *p1 = (Point *) a;
	Point *p2 = (Point *) b;
	
	return (p1->y - p2->y);
}

float distance(Point p1, Point p2) {
	return sqrt( ((p1.x - p2.x) * (p1.x - p2.x)) +
				 ((p1.y - p2.y) * (p1.y - p2.y)) );
}

double brute_force(Point p[], int n) {
	float min = FLT_MAX;
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = (i + 1); j < n; j++) {
			if (distance(p[i], p[j]) < min) {
				min = distance(p[i], p[j]);
			}
		}
	}
	return min;
}

float strip_closest(Point strip[], int n, float d) {
	float min = d;
	int i, j;
	
	qsort(strip, n, sizeof(Point), compare_y);
	
	for (i = 0; i < n; i++) {
		for (j = (i + 1); j < n && (strip[j].y - strip[i].y) < min; j++) {
			if (distance(strip[i], strip[j]) < min) {
				min = distance(strip[i], strip[j]);
			}
		}
	}
	return min;
}

float closest_pair_rec(Point Px[], Point Py[], int n) {
	if (n <= 3) {
		return brute_force(Px, n);
	}
	
	int mid = n / 2;
	Point midPoint = Px[mid];
	
	Point Pyl[mid + 1];
	Point Pyr[n - mid - 1];
	int left = 0, right = 0, i;
	for (i = 0; i < n; i++) {
		if (Py[i].x <= midPoint.x) {
			Pyl[left++] = Py[i];
		} else {
			Pyr[right++] = Py[i];
		}
	}
	
	float dleft = closest_pair_rec(Px, Pyl, mid);
	float dright = closest_pair_rec(Px, Pyr, n - mid);
	float d = min(dleft, dright);
	
	Point strip[n];
	int j = 0;
	for (i = 0; i < n; i++) {
		if (abs(Py[i].x - midPoint.x) < d) {
			strip[j++] = Py[i];
		}
	}
	
	return min(d, strip_closest(strip, j, d));
}

float closest_pair(Point P[], int n) {
	Point Px[n];
	Point Py[n];
	int i;
	
	for (i = 0; i < n; i++) {
		Px[i] = P[i];
		Py[i] = P[i];
	}
	
	qsort(Px, n, sizeof(Point), compare_x);
	qsort(Py, n, sizeof(Point), compare_y);
	
	return closest_pair_rec(Px, Py, n);
}

int main(int argc, char* argv[]) {
	Point P[] = {{2,3}, {12,30}, {40,50}, {5,1}, {12,10}, {3,4}, {100, 9}};
	int n = sizeof(P) / sizeof(P[0]);
	printf("The smallest distance is: %f\n", closest_pair(P, n));
	return 0;
}
