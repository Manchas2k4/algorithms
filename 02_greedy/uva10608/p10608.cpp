#include <iostream>
#include <cstring>

typedef unsigned int uint;

using namespace std;

class WeightQuickUnion {
private:
	uint *ids;
	uint *szs;
	
public:
	WeightQuickUnion(uint);
	uint root(uint p);
	bool find(uint, uint);
	void join(uint, uint);
};

WeightQuickUnion::WeightQuickUnion(uint n) {
	ids = new uint[n + 1];
	szs = new uint[n + 1];
	for (uint i = 1; i <= n; i++) {
		ids[i] = i;
		szs[i] = 1;
	}
}

uint WeightQuickUnion::root(uint p) {
	while (p != ids[p]) {
		ids[p] = ids[ids[p]];
		p = ids[p];
	}
	return p;
}

bool WeightQuickUnion::find(uint p, uint q) {
	return root(p) == root(q);
}

void WeightQuickUnion::join(uint p, uint q) {
	uint pid = root(p);
	uint qid = root(q);
	
	if (szs[pid] < szs[qid]) {
		ids[pid] = qid;
		szs[qid] += szs[pid];
	} else {
		ids[qid] = pid;
		szs[pid] += szs[qid];
	}
}

int main(int argc, char* argv[]) {
	int cases, m, n, a, b, maxi;
	int groups[300001];
	
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n >> m;
		
		memset(groups, 0, sizeof(int) * n);
		WeightQuickUnion citizens(n);
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			citizens.join(a, b);
		}
		for (int j = 1; j <= n; j++) {
			groups[citizens.root(j)]++;
		}
		maxi = 0;
		for (int j = 1; j <= n; j++) {
			maxi = max(maxi, groups[j]);
		}
		cout << maxi << "\n";
	}
	return 0;
}
