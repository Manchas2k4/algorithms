#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
 
using namespace std;
 
int i, j;
vector<long> rad;
long p;
 
void prep() {
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            p = pow(2.0f, i) * pow(3.0f, j);
            if(p > pow(2.0f, 31)) break;
            rad.push_back(p);
        }
    }
}
 
int m;
 
int main(int argc, char* argv[]) {
    prep();
    sort(rad.begin(), rad.end());
    while(scanf("%d", &m)) {
        if(m == 0) break;
        int low = lower_bound(rad.begin(), rad.end(), m) - rad.begin();
        printf("%ld\n", rad[low]);
    }
 
    return 0;
}