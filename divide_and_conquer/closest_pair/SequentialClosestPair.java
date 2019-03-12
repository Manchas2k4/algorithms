import java.util.Arrays;
import java.util.Scanner;

public class SequentialClosestPair {
	private double dist(Point p1, Point p2) {
		return Math.sqrt( Math.pow(p1.getX() - p2.getX(), 2) + 
						  Math.pow(p1.getY() - p2.getY(), 2) );
	}
	
	private double bruteForce(Point P[], int low, int high) {
		double min = Double.MAX_VALUE;
		for (int i = low; i <= high; i++) {
			for (int j = low; j <= high; j++) {
				if (i != j && dist(P[i], P[j]) < min) {
					min = dist(P[i], P[j]);
				}
			}
		}
		return min;
	}
	
	private void copy(Point A[], Point B[], int low, int high) {
		for (int i = low; i <= high; i++) {
			A[i] = B[i];
		}
	}
	
	private void merge(Point A[], Point B[], int low, int mid, int high) {
		int left ,right, i;
		
		left = i = low;
		right = mid + 1;
		while (left <= mid && right <= high) {
			if (A[left].compareTo(A[right]) < 0) {
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
	
	private double stripClosest(Point P[], int n, double d) {
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
	
	private double closestUtil(Point Px[], Point Py[], Point Aux[], int low, int high) {
		double d, dl, dr;
		int j, mid;
		
		if ( (high - low + 1) <= 3 ) {
			return bruteForce(Px, low, high);
		}
		
		mid = low + ((high - low) / 2);
		Point midPoint = Px[mid];
		
		dl = closestUtil(Px, Py, Aux, low, mid);
		dr = closestUtil(Px, Py, Aux, mid + 1, high);
		d = Math.min(dl, dr);
		
		merge(Py, Aux, low, mid, high);
		copy(Py, Aux, low, high);
		
		j = 0;
		for (int i = low; i <= high; i++) {
			if (Math.abs(Py[i].getX() - midPoint.getX()) < d) {
				Aux[j++] = Py[i];
			}
		}
		
		return Math.min(d, stripClosest(Aux, j, d)); 
	}
	
	public double closestPair(Point P[]) {
		int n = P.length;
		Point Px[] = new Point[n];
		Point Py[] = new Point[n];
		Point Aux[] = new Point[n];
		
		for (int i = 0; i < P.length; i++) {
			Px[i] = P[i];
			Py[i] = P[i];
		}
		
		Arrays.sort(Px, new SortByX());
		Arrays.sort(Py, new SortByY());
		
		return closestUtil(Px, Py, Aux, 0, n - 1);
	}
	
	public static void main(String args[]) {
		double dist = 0;
		int n, x, y;
		long start, end;
		Scanner stdIn = new Scanner(System.in);
		SequentialClosestPair sqp = new SequentialClosestPair();
		
		n = stdIn.nextInt();
		Point P[] = new Point[n];
		for (int i = 0; i < n; i++) {
			x = stdIn.nextInt();
			y = stdIn.nextInt();
			P[i] = new Point(x, y);
		}
		
		start = System.currentTimeMillis();
		dist = sqp.closestPair(P);
		end = System.currentTimeMillis();
		
		System.out.println("The smallest distance is " + dist);
		System.out.println("time = " + (end - start) + " ms");
	}
}