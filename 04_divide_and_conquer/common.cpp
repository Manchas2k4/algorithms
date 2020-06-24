#include <iostream>
#include <string>

using namespace std;

string common_prefix_util(string str1, string str2) {
	string result;
	int len1, len2, i, j;
	
	len1 = str1.length();
	len2 = str2.length();
	i = j = 0;
	while (i < len1 && j < len2) {
		if (str1[i] != str2[j]) {
			break;
		}
		result.push_back(str1[i]);
		i++; j++;
	}
	return result;
}

string common_prefix(string arr[], int low, int high) {
	int mid;
	
	if (low == high) {
		return arr[low];
	} 
	
	if (low < high) {
		mid = low + (high - low) / 2;
		string str1 = common_prefix(arr, low, mid);
		string str2 = common_prefix(arr, mid + 1, high);
		
		return common_prefix_util(str1, str2);
	}	
	
	return string("aux");	
}

int main(int argc, char* argv[]) {
	string *arr;
	int n;
	
	scanf("%i", &n);
	arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "result = " << common_prefix(arr, 0, n - 1) << "\n";
	return 0;
}
