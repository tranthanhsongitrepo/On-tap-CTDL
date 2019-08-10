#include <iostream>

using namespace std ;
int longestSubSumDivisibleS(int a[], int n, int k, int max_s){
    int t[n][max_s + 1], max_l = 0 ;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < max_s; j++) {
            t[i][j] = 0;
        }
    }
    t[0][a[0]] = 1 ;
    for (int i = 1; i < n; i ++){
        t[i][a[i]] = max(1, t[i - 1][a[i]]) ;
        for (int j = 1 ; j <= max_s; j ++) {
            if (j != a[i]) {
                if (j < a[i])
                    t[i][j] = t[i - 1][j];
                else {
                    if (t[i - 1][j - a[i]]) {
                        t[i][j] = max(t[i - 1][j - a[i]] + 1, t[i - 1][j]);
                    }
                    else
                        t[i][j] = t[i - 1][j] ;
                }
                if (i == n - 1 && j % k == 0 && t[i][j] > max_l){
                    max_l = t[i][j] ;
                }
            }
        }
    }
    return max_l ;
}
int main() {
    int n, k;
    cin >> n >> k ;
    int a[n], max_s = 0 ;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        max_s += a[i] ;
    }
    cout << longestSubSumDivisibleS(a, n, k, max_s) ;
    return 0;
}