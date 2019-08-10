#include <iostream>
using namespace std ;
int noOfWays(int n, int k){
    int t[n + 1] = {0};

  /*  for (int i = 1; i < n; i ++) {
        t[i] = i < k ? 1 : 0;
    }*/
    t[0] = 1 ;
    for (int i = 1; i <= n; i ++){
        for (int j = 1 ; j <= min(i, k); j ++) {
            t[i] += t[i - j];
        }
    }
    return t[n] ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        int n, k;
        cin >> n >> k;
        cout << noOfWays(n, k) << endl ;
    }
    return 0;
}
