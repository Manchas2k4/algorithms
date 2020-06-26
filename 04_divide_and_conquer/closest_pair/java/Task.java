import java.util.concurrent.RecursiveTask;

public class Task extends RecursiveTask<Double> {
	private Point Px[], Py[], Aux[];
	private int start, end;
	
	public Task(Point Px[], Point Py[], Point Aux[], int start, int end) {
		this.Px = Px;
		this.Py = Py;
		this.Aux = Aux;
		this.start = start;
		this.end = end;
	}
	
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
	
	@Override
	protected Double compute () {
		double d;
		int j, mid, li, ri;
		
		if ( (end - start + 1) <= 3 ) {
			return bruteForce(Px, start, end);
		} else {		
			mid = start + ((end - start) / 2);
			Point midPoint = Px[mid];
			
			Task left = new Task(Px, Py, Aux, start, mid);
			left.fork();
			
			Task right = new Task(Px, Py, Aux, mid + 1, end);
			d = Math.min(right.compute(), left.join());
			
			merge(Py, Aux, start, mid, end);
			copy(Py, Aux, start, end);
			
			j = 0;
			for (int i = start; i <= end; i++) {
				if (Math.abs(Py[i].getX() - midPoint.getX()) < d) {
					Aux[j++] = Py[i];
				}
			}
			
			return Math.min(d, stripClosest(Aux, j, d)); 
		}
	}
	
}