import java.util.concurrent.ForkJoinPool;
import java.util.Random;
import java.util.Arrays;
import java.util.Scanner;

public class RecursiveClosestPair {
	private static final int MAXTHREADS = Runtime.getRuntime().availableProcessors();
	
	public static void main(String args[]) {
		double dist = 0;
		int n, x, y;
		long start, end;
		ForkJoinPool pool;
		Scanner stdIn = new Scanner(System.in);
		
		n = stdIn.nextInt();
		Point P[] = new Point[n];
		for (int i = 0; i < n; i++) {
			x = stdIn.nextInt();
			y = stdIn.nextInt();
			P[i] = new Point(x, y);
		}
		
		n = P.length;
		Point Px[] = new Point[n];
		Point Py[] = new Point[n];
		Point Aux[] = new Point[n];
		
		for (int i = 0; i < P.length; i++) {
			Px[i] = P[i];
			Py[i] = P[i];
		}
		
		Arrays.sort(Px, new SortByX());
		Arrays.sort(Py, new SortByY());
		
		start = System.currentTimeMillis();
		pool = new ForkJoinPool(MAXTHREADS);
		dist = pool.invoke(new Task(Px, Py, Aux, 0, P.length - 1));
		end = System.currentTimeMillis();
		
		System.out.println("The smallest distance is " + dist);
		System.out.println("time = " + (end - start) + " ms");
	}
}