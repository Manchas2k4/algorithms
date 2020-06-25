#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &inputs) {
	vector<int> dp(inputs.size());
	int acum;
	
	dp[0] = 1;
	for (int i = 1; i < inputs.size(); i++) {
		acum = 0;
		for (int j = 0; j < i; j++) {
			if (inputs[j] > inputs[i]) {
				acum = max(acum, dp[j]);
			}
		}
		dp[i] = acum + 1;
	}
	
	acum = 0;
	for (int i = 0; i < dp.size(); i++) {
		acum = max(acum, dp[i]);
	}
	return acum;
}

int main(int argc, char* argv[]) {
	int num, first = 1, cases = 0;
	
	cin >> num;
	while (num != -1) {
		if (first) {
			first = 0;
		} else {
			cout << "\n";
		}
		cases++;
		vector<int> inputs;
		do {
			inputs.push_back(num);
			cin >> num;
		} while (num != -1);
		cout << "Test #" << cases << ":\n" << "  maximum possible interceptions: " << lis(inputs) << "\n";
		cin >> num;
	}
	return 0;
}