#include <iostream>
#include <vector>

using namespace std;

const int MAX = 110;
const int WHITE = -1;
const int BLACK = 1;

void calculate(int u, int n, int &max, vector<int> &colors,
    vector<int> &result, vector<vector<int> > &graph) {
  int count;
  bool canBlack;

  if (u == n) {
    count = 0;
    for (int i = 0; i < n; i++) {
      if (colors[i] == BLACK) {
        count++;
      }
    }

    if (count > max) {
      max = count;
      result.clear();
      for (int i = 0; i < n; i++) {
        if (colors[i] == BLACK) {
          result.push_back(i);
        }
      }
    }

    return;
  } else {
    canBlack = true;
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (colors[v] && colors[v] == BLACK) {
        canBlack = false;
        break;
      }
    }

    if (canBlack) {
      colors[u] = BLACK;
      calculate(u + 1, n, max, colors, result, graph);
    }

    colors[u] = WHITE;
    calculate(u + 1, n, max, colors, result, graph);
    colors[u] = 0;
  }
}

int main(int argc, char* argv[]) {
  int cases, n, k, max, u, v;
  vector<int> colors;
  vector<int> result;
  vector<vector<int> > graph;

  cin >> cases;
  while (cases > 0) {
    cin >> n >> k;

    graph.assign(n, vector<int>());
    colors.assign(n, 0);
    max = -1;
    for (int i = 0; i < k; i++) {
      cin >> u >> v;
      u--; v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    calculate(0, n, max, colors, result, graph);

    cout << max << "\n";
    for (int i = 0; i < result.size(); i++) {
      cout << (result[i] + 1);
      if (i != result.size() - 1) {
        cout << " ";
      }
    }
    cout << "\n";

    cases--;
  }
  return 0;
}
