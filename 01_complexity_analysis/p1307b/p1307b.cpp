#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
	int cases, n, x, greatest, number;
	set<int> numbers;
	
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n >> x;
		greatest = 0;
		for (int j = 0; j < n; j++) {
			cin >> number;
			numbers.insert(number);
			greatest = max(greatest, number);
		}
		
		if (numbers.count(x) != 0) {
			cout << "1" << endl;
		} else {
			cout << max(2, ((x + greatest - 1) / greatest)) << endl;
		}
		numbers.clear();
	}
	return 0;
}