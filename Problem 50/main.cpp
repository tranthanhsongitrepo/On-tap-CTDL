#include <iostream>
#include <algorithm>

using namespace std ;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        cout << upper_bound(a, a + n, temp) - a << endl;
    }
    //c == 0 ? cout << "YES" << endl : cout << c << endl ;
    return 0;
}