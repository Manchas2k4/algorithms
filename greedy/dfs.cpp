#include <cstdio>
#include <map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

typedef map<char, list<char> > Graph;

list<char> dfs(const Graph &g, char startVertex) {
	list<char> visited;
	stack<char> xVisit;
	
	xVisit.push(startVertex);
	while (!xVisit.empty()) {
		char vertex = xVisit.top(); xVisit.pop();
		
		list<char>::iterator found = find(visited.begin(), visited.end(), vertex);
		if (found == visited.end()) {
			list<char> conections = g.at(vertex);
			for (list<char>::iterator it = conections.begin(); it != conections.end(); it++) {
				xVisit.push( *it );
			}
		}
	}
	return visited;
}

int main(int argc, char* argv[]) {
	return 0;
}
