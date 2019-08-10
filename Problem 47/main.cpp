#include <iostream>
#include <algorithm>

using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        int start = 0, end = n - 1;
        while (start < n && a[start] == b[start])
            start ++ ;
        while (end >= 0 && a[end] == b[end])
            end -- ;
        int c = end - start + 1 ;
        c + n == 0 ? cout << "YES" << endl : cout << c << endl ;
    }
    return 0;
}