#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std ;

void printRes(int a[], int n){
    sort(a ,a + n, greater<>()) ;
    int min_m = INT_MAX, c = 0, i = 1 ;
    for (int i = 0; i < n - 1 ; i ++) {
        int t = a[i] - a[i + 1] ;
        if (t < min_m)
            min_m = t ;
    }
    for (int i = 0; i < n - 1 ; i ++) {
        int t = a[i] - a[i + 1] ;
        if (t == min_m)
            c ++ ;
    }
    cout << min_m << " " << c << endl ;

}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n ;
        cin >> n ;
        int a[n] ;
        for (int i = 0; i < n ; i ++)
            cin >> a[i] ;
        printRes(a, n) ;
    }
    return 0;
}