#include <iostream>

typedef unsigned int uint;

class QuickFind {
private:
	uint *ids;
	uint size;
	
public:
	QuickFind(uint);
	bool find(uint, uint);
	void join(uint, uint);
};

QuickFind::QuickFind(uint n) {
	ids = new uint[n];
	size = n;
	for (uint i = 0; i < n; i++) {
		ids[i] = i;
	}
}

bool QuickFind::find(uint p, uint q) {
	return ids[p] == ids[q];
}

void QuickFind::join(uint p, uint q) {
	uint pid;
	
	pid = ids[p];
	for (uint i = 0; i < size; i++) {
		if (ids[i] == pid) {
			ids[i] = ids[q];
		}
	}
}

class QuickUnion {
private:
	uint *ids;
	
	uint root(uint p);
	
public:
	QuickUnion(uint);
	bool find(uint, uint);
	void join(uint, uint);
};

QuickUnion::QuickUnion(uint n) {
	ids = new uint[n];
	for (uint i = 0; i < n; i++) {
		ids[i] = i;
	}
}

uint QuickUnion::root(uint p) {
	while (p != ids[p]) {
		p = ids[p];
	}
	return p;
}

bool QuickUnion::find(uint p, uint q) {
	return root(p) == root(q);
}

void QuickUnion::join(uint p, uint q) {
	uint pid = root(p);
	uint qid = root(q);
	
	ids[pid] = qid;
}

class WeightQuickUnion {
private:
	uint *ids;
	uint *szs;
	
	uint root(uint p);
	
public:
	WeightQuickUnion(uint);
	bool find(uint, uint);
	void join(uint, uint);
};

WeightQuickUnion::WeightQuickUnion(uint n) {
	ids = new uint[n];
	szs = new uint[n];
	for (uint i = 0; i < n; i++) {
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
	QuickFind qf(10);
	return 0;
}
