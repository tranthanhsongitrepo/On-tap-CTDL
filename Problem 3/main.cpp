#include <iostream>
#include <algorithm>
using namespace std ;
bool isFinal(int n, int k, int a[]){
    for (int i = 0 ; i < k; i ++)
        if (a[i] != n - k + i + 1)
            return false ;
        return true ;
}

bool genNext(int n, int k, int a[]){
    if (isFinal(n, k, a))
        return false ;
    int i = k - 1 ;
    while (a[i] == n - k + i + 1) i -- ;
    a[i++] ++ ;
    for (i; i < k; i ++){
        a[i] = a[i - 1] + 1 ;
    }
    return true ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        int a ;
        cin >> a ;
        string s ;
        cin >> s ;
        cout << a << " " ;
        (next_permutation(s.begin(), s.end())) ? cout << s << endl : cout << "BIGGEST" << endl ;
    }
}