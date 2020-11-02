#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <algorithm>  

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

class Point {
private:
	int x, y;

public:
	Point() : x(0), y(0) {}
	
	Point(int xx, int yy) : x(xx), y(yy) {}
	
	int getX() const {
		return x;
	}
	
	int getY() const {
		return y;
	}
};

bool operator< (const Point &a, const Point &b) {
	if (a.getY() == b.getY()) {
		return (a.getX() < b.getX());
	} else {
		return (a.getY() < b.getY());
	}
}

double dist(const Point &p1, const Point &p2) {
	double xs = (p1.getX() - p2.getX());
	double ys = (p1.getY() - p2.getY());
	
	return sqrt( (xs * xs) + (ys * ys) );
}

double bruteForce(const vector<Point> &P, int low, int high) {
	double min = numeric_limits<double>::max();
	for (int i = low; i <= high; i++) {
		for (int j = low; j <= high; j++) {
			if (i != j && dist(P[i], P[j]) < min) {
				min = dist(P[i], P[j]);
			}
		}
	}
	return min;
}

void copy(vector<Point> &A, vector<Point> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

void merge(vector<Point> &A, vector<Point> &B, int low, int mid, int high) {
	int left ,right, i;
		
	left = i = low;
	right = mid + 1;
	while (left <= mid && right <= high) {
		if (A[left] < A[right]) {
			B[i] = A[left++];
		} else {
			B[i] = A[right++];
		}
		i++;
	}
	while (left <= mid) {
		B[i] = A[left++];
		i++;
	}
	while (right <= high) {
		B[i] = A[right++];
		i++;
	}
}

double stripClosest(const vector<Point> &P, int n, double d) {
	double min = d;
	for (int i = 0; i < n; i++) {
		for (int j = (i + 1); j < n && (P[j].getY() - P[i].getY()) < min; j++) {
			if (dist(P[i], P[j]) < min) {
				min = dist(P[i], P[j]); 
			}
		}
	}
	return min; 
}

double closestUtil(vector<Point> &Px, vector<Point> &Py, vector<Point> &Aux, int low, int high) {
	double d, dl, dr;
	int j, mid;
	
	if ( (high - low + 1) <= 3 ) {
		return bruteForce(Px, low, high);
	}
	
	mid = low + ((high - low) / 2);
	Point midPoint = Px[mid];
	
	dl = closestUtil(Px, Py, Aux, low, mid);
	dr = closestUtil(Px, Py, Aux, mid + 1, high);
	d = MIN(dl, dr);
	
	merge(Py, Aux, low, mid, high);
	copy(Py, Aux, low, high);
	
	j = 0;
	for (int i = low; i <= high; i++) {
		if (fabs(Py[i].getX() - midPoint.getX()) < d) {
			Aux[j++] = Py[i];
		}
	}
	
	return MIN(d, stripClosest(Aux, j, d)); 
}

bool sortByX(const Point &a, const Point &b) {
	return a.getX() < b.getX();
}

bool sortByY(const Point &a, const Point &b) {
	return a.getY() < b.getY();
}

double closestPair(const vector<Point> &P) {
	int n = P.size();
	vector<Point> Px(n);
	vector<Point> Py(n);
	vector<Point> Aux(n);
	
	for (int i = 0; i < P.size(); i++) {
		Px[i] = P[i];
		Py[i] = P[i];
	}
	
	sort(Px.begin(), Px.end(), sortByX);
	sort(Py.begin(), Py.end(), sortByY);
	
	return closestUtil(Px, Py, Aux, 0, n - 1);
}

int main(int argc, char* argv[]) {
	int n, x, y;
	double dist = 0;
	
	scanf("%i", &n);
	
	vector<Point> P(n);
	for (int i = 0; i < n; i++) {
		scanf("%i %i", &x, &y);
		P[i] = Point(x, y);
	}
	
	dist = closestPair(P);
	printf("The smallest distance is %lf\n", dist);
	return 0;
}

