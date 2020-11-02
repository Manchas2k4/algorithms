#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	string letters = "abcdefghijklmnopqrstuvwxyz";
	string passwd = "";
	int n, k;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		passwd += letters[i % k];
	}
	cout << passwd << endl;
	return 0;
}