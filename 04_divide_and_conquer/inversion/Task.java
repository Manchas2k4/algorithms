import java.util.concurrent.RecursiveTask;

public class Task extends RecursiveTask<Integer> {
	private int A[], B[], start, end;
	
	public Task(int A[], int B[], int start, int end) {
		this.A = A;
		this.B = B;
		this.start = start;
		this.end = end;
	}
	
	private void copy() {
		for (int i = start; i <= end; i++) {
			A[i] = B[i];
		}
	}
	
	private int mergeAndCount(int low, int mid, int high) {
		int left ,right, i, count;
		
		left = i = low;
		right = mid + 1;
		count = 0;
		while (left <= mid && right <= high) {
			if (A[left] < A[right]) {
				B[i] = A[left++];
			} else {
				B[i] = A[right++];
				count = count + (mid - left + 1);
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
	
	@Override
	protected Integer compute() {
		int mid, result = 0;
		
		if ( (end - start + 1) == 1 ) {
			return 0;
		} else {
			mid = start + ((end - start) / 2);
			
			Task left = new Task(A, B, start, mid);
			left.fork();
			
			Task right = new Task(A, B, mid + 1, end);
			result = right.compute() + left.join();
			
			result += mergeAndCount(start, mid, end);
			copy();
			
			return result;
		}
	}
}
