import java.util.Comparator;

public class SortByY implements Comparator<Point> {
	public int compare(Point a, Point b) {
		return a.getY() - b.getY();
	}
}