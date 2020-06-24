public class Point implements Comparable<Point> {
	private final int x, y;
	
	public Point() {
		x = y = 0;
	}
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	public int compareTo(Point other) {
		if (this.getY() < other.getY()) {
			return -1;
		}
		if (this.getY() > other.getY()) {
			return +1;
		}
		if (this.getX() < other.getX()) {
			return -1;
		}
		if (this.getX() > other.getX()) {
			return +1;
		}
		return 0;
	}
}