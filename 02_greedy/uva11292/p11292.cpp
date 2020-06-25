#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 200001;

int heads[MAX], nheads, knights[MAX], nknights;

void resuelve_caso() {
	for (int i = 0; i < nheads; i++) {
		cin >> heads[i];
	}
	for (int i = 0; i < nknights; i++) {
		cin >> knights[i];
	}
	sort(heads, heads + nheads);
	sort(knights, knights + nknights);
	
	bool doomed = false;
	int i = 0, j = 0, acum = 0;
	while (i < nheads) {
		if (j == nknights) {
			doomed = true;
			break;
		}
		if (knights[j] >= heads[i]) {
			acum += knights[j];
			i++;
			j++;
		} else {
			j++;
		}
	}
	if (!doomed) {
		cout << acum << endl;
	} else {
		cout << "Loowater is doomed!" << endl;
	}
}

int main(int argc, char* argv[]) {
	while (true) {
		cin >> nheads >> nknights;
		if (nheads == 0 && nknights == 0) {
			break;
		}
		resuelve_caso();
	}
	return 0;
}		
	
