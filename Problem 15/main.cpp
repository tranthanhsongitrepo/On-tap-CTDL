#include <iostream>
using namespace std ;
int binarySearch(int a[], int k, int n){
    int h = n - 1, l = 0 ;
    while (h >= l){
        int mid = (l + h) / 2 ;
        if (a[mid] == k)
            return mid ;
        if (a[mid] > k) {
            h = mid - 1;
        }
        else {
            l = mid + 1 ;
        }
    }
    return -1 ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, k ;
        cin >> n >> k ;
        int a[n] ;
        for (int i = 0; i < n; i ++)
            cin >> a[i] ;
        int search = binarySearch(a, k, n) ;
        (search == -1) ? cout << "NO" << endl : cout  << search + 1 << endl ;
    }
    return 0;
}