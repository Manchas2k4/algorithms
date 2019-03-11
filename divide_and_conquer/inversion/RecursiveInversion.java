import java.util.concurrent.ForkJoinPool;
import java.util.Random;

public class RecursiveInversion {
	private static final int MAXTHREADS = Runtime.getRuntime().availableProcessors();
	private static final int SIZE = 100_000_000;
	private static final int MAX = 100;
	
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
		int result;
		long start, end;
		ForkJoinPool pool;
		int A[] = new int[SIZE];
		int B[] = new int[SIZE];
		RecursiveInversion ri = new RecursiveInversion();
		
		ri.fillArray(A);
		ri.display("antes", A);
		
		start = System.currentTimeMillis();
		pool = new ForkJoinPool(MAXTHREADS);
		result = pool.invoke(new Task(A, B, 0, A.length - 1));
		end = System.currentTimeMillis();
		
		ri.display("despues", A);
		System.out.println("result = " + result);
		System.out.println("time = " + (end - start) + " ms");
	}
}