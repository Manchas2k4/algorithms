import java.util.Arrays;

public class SequentialClosestPair {
	private double dist(Point p1, Point p2) {
		return Math.sqrt( Math.pow(p1.getX() - p2.getX(), 2) + 
						  Math.pow(p1.getY() - p2.getY(), 2) );
	}
	
	private double bruteForce(Point P[]) {
		double min = Double.MAX_VALUE;
		for (int i = 0; i < P.length; i++) {
			for (int j = 0; j < P.length; j++) {
				if (dist(P[i], P[j]) < min) {
					min = dist(P[i], P[j]);
				}
			}
		}
		return min;
	}
	
	private void merge(int A[], int B[], int low, int mid, int high) {
		int left ,right, i, count;
		
		left = i = low;
		right = mid + 1;
		count = 0;
		while (left <= mid && right <= high) {
			if (A[left] < A[right]) {
				B[i] = A[left++];
			} else {
				B[i] = A[right++];
				count++;
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
		return count;		
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
		int j, mid, li, ri;
		
		if ( (high - low + 1) <= 3 ) {
			return bruteForce(Px);
		}
		
		mid = low + ((high - low) / 2);
		Point midPoint = Px[mid];
		
		dl = closestUtil(Px, Py, Aux, low, mid);
		dr = closestUtil(Px, Py, Aux, mid + 1, high);
		d = Math.min(dl, dr);
		
		merge(Py, Aux, low, mid, high);
		
		j = 0;
		for (int i = low; i <= high; i++) {
			if (Math.abs(Py.getX() - midPoint.getX()) < d) {
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
		Point P[] = {new Point(2, 3), new Point(12, 30), new Point(40, 50), new Point(5, 1), new Point(12, 10), new Point(3, 4)};
		SequentialClosestPair sqp = new SequentialClosestPair();
		
		System.out.println("The smallest distance is " + sqp.closestPair(P));
	}
}