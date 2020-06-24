import java.util.Comparator;

public class SortByX implements Comparator<Point> {
	public int compare(Point a, Point b) {
		return a.getX() - b.getX();
	}
}