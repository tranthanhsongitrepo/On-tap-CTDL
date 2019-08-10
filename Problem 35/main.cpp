#include <iostream>
#include <algorithm>
const int MOD = 1e9+7 ;
using namespace std ;
int C(int n, int k){
    if (n > k)
        k = n - k ;
    int t[k + 1] = {0};
    t[0] = t[1] = 1 ;
    for (int i = 2; i <= n; i ++){
        for (int j = min(i, k); j > 0; j --){
            t[j] = (t[j] + t[j - 1]) % MOD ;
        }
    }
    return t[k] ;
}
int main() {
    int t ;
    cin >> t;
    while(t --){
        int n, k ;
        cin >> n >> k ;
        cout << C(n, k) << endl ;
    }
    return 0;
}