#include <iostream>
using namespace std ;
const long long int MOD = 1e9+7 ;
long long int powMod(long long int n, long long int k){
    if (k == 0) return 1;
    else if (k == 1) return n ;
    long long int t = powMod(n, k / 2) ;
    return (k % 2 == 0) ? (t * t) % MOD : ((t * t) % MOD * n) % MOD;
}
int main() {
    long long int t ;
    cin >> t ;
    while (t --){
        long long int n, k ;
        cin >> n >> k ;
        cout << powMod(n, k) << endl ;
    }
    return 0;
}