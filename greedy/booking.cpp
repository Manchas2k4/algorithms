#include <cstdio> //display
#include <vector> //vector
#include <utility> //pair
#include <algorithm> //max

using namespace std;

const int MAX = 100;

bool bookingProblem(int arrival[], int departure[], int n, int k) {
	vector<pair<int, int> > times;
	
	for (int i = 0; i < n; i++) {
		times.push_back(make_pair(arrival[i], 1));
		times.push_back(make_pair(departure[i], 0));
	}
	
	sort(times.begin(), times.end());
	
	int current = 0, required = 0;
	
	for (int i = 0; i < times.size(); i++) {
		if (times[i].second == 1) { // arrival
			current++;
			required = max(current, required);
		} else {  //departure
			current--;
		}
	}
	
	return (k >= required);
}

int main(int argc, char* argv[]) {
	int arrival[MAX], departure[MAX], n, k;
	
	scanf("%i %i", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%i %i", &arrival[i], &departure[i]);
	}
	if (bookingProblem(arrival, departure, n, k)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
			
		
