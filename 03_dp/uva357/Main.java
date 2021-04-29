import java.util.*;

public class Main {
	private static long matriz[][] = new long[6][30001];
	private static int monedas[] = {0, 50, 10, 5, 25, 1};

	public static void llenaTabla() {
		for (int j = 0; j < matriz[0].length; j++) {
			matriz[0][j] = 0;
		}
		for (int i = 0; i < matriz.length; i++) {
			matriz[i][0] = 1;
		}
		for (int i = 1; i < matriz.length; i++) {
			for (int j = 1; j < matriz[i].length; j++) {
				if (monedas[i] > j) {
					matriz[i][j] = matriz[i - 1][j];
				} else if (monedas[i] <= j) {
					matriz[i][j] = matriz[i - 1][j] +
												 matriz[i][j - monedas[i]];
				}
			}
		}
	}

	public static void main(String args[]) {
		Scanner stdIn = new Scanner(System.in);
		int j;

		llenaTabla();
		while(stdIn.hasNextInt()) {
			j = stdIn.nextInt();
			if (matriz[5][j] == 1) {
				System.out.println("There is only 1 way to produce " + j + " cents change.");
			} else {
				System.out.println("There are " + matriz[5][j] + " ways to produce " + j + " cents change.");
			}
		}
	}
}
