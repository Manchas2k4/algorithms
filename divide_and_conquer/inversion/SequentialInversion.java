import java.util.Random;

public class SequentialInversion {
	private static final int SIZE = 100_000_000;
	private static final int MAX = 100;
	
	private void copy(int A[], int B[], int low, int high) {
		for (int i = low; i <= high; i++) {
			A[i] = B[i];
		}
	}
	
	private int mergeAndCount(int A[], int B[], int low, int mid, int high) {
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
	
	private int sortAndCount(int A[], int B[], int low, int high) {
		int left, right, mid, r;
		
		if ( (high - low + 1) == 1 ) {
			return 0;
		} else {
			mid = low + ((high - low) / 2);
			left = sortAndCount(A, B, low, mid);
			right = sortAndCount(A, B, mid + 1, high);
			r = mergeAndCount(A, B, low, mid, high);
			copy(A, B, low, high);
			return (r + left + right);
		}
	}
	
	public int countInversions(int A[]) {
		int B[] = new int[A.length];
		return sortAndCount(A, B, 0, A.length - 1);
	}
	
	public void fillArray(int A[]) {
		Random r = new Random();
		
		for (int i = 0; i < A.length; i++) {
			A[i] = r.nextInt(100) + 1;
		}
	}
	
	public void display(String text, int A[]) {
		int limit = Math.min(A.length, MAX);
		
		System.out.print(text + ": [" + A[0]);
		for (int i = 1; i < limit; i++) {
			System.out.print(", " + A[i]);
		}
		System.out.println("]");
	}
	
	public static void main(String args[]) {
		long start, end;
		int result, A[] = new int [SIZE];
		SequentialInversion si = new SequentialInversion();
		
		
		si.fillArray(A);
		si.display("antes", A);
		
		start = System.currentTimeMillis();
		result = si.countInversions(A);
		end = System.currentTimeMillis();
		
		si.display("despues", A);
		System.out.println("result = " + result);
		System.out.println("time = " + (end - start) + " ms");
	}
}
