#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int n, m;

  while (cin >> n) {
    if (n == 0) {
      break;
    }
    vector<int> v;

    for (int i = 0; i < n; i++) {
      cin >> m;
      if (m > 0) {
        v.push_back(m);
      }
    }

    if (v.size() == 0) {
      cout << "0\n";
    } else {
      for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
          cout << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
