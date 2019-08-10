#include <iostream>
using namespace std;
int longestIncreasingSubSequence(int a[], int n) {
    int t[n], max_l = 0 ;
    for (int i = 0 ; i < n ; i ++)
        t[i] = 1 ;
    for (int i = 0 ; i < n - 1; i ++){
        for (int j = i + 1; j < n; j ++) {
            if (a[i] < a[j]){
                t[j] = t[i] + 1;
            }
            if (max_l < t[j])
                max_l = t[j] ;
        }
    }
    return max_l ;
}
int main() {
    int n ;
    cin >> n ;
    int a[n] ;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i] ;
    cout << longestIncreasingSubSequence(a, n) ;
    return 0;
}