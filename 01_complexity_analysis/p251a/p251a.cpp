#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int lli;

using namespace std;

int main(int argc, char* argv[]) {
	lli n, d, result, range, k;
	
	cin >> n >> d;
	vector<lli> v(n);
	for (lli i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	result = 0;
	for (lli i = 0; i + 2 < n; i++) {
		range = lower_bound(v.begin(), v.end(), v[i] + d) - v.begin();
		if (v[i] + d != v[range]) {
			range--;
		}
		
		k = range - i;
		if (k >= 2) {
			result += ((k * (k - 1)) / 2);
		}
	}
	cout << result << endl;
	return 0;
}
