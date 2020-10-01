#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int y, p, val, ans, begin, end;

  while (cin >> y >> p) {
    vector<int> popes;
    vector<int>::iterator it1, it2;

    for (int i = 0; i < p; i++) {
      cin >> val;
      popes.push_back(val);
    }

    ans = begin = end = 0;
    for (it1 = popes.begin(); it1 != popes.end(); it1++) {
      it2 = upper_bound(popes.begin(), popes.end(), *it1 + y - 1);
      if (it2 - it1 > ans) {
        ans = it2 - it1;
        begin = *it1;
        end = *(it2 - 1);
      }
    }
    cout << ans << " " << begin << " " << end << "\n";
  }
  return 0;
}
