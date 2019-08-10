#include <iostream>
#include <algorithm>
using namespace std ;

bool isFinal(int n, int k, int a[]){
    for (int i = 0 ; i < k; i ++)
        if (a[i] != n - k + i )
            return false ;
    return true ;
}

bool genNext(int n, int k, int a[]){

    int i = k - 1 ;
    while (a[i] == n - k + i) i -- ;
    a[i++] ++ ;
    for (i; i < k; i ++){
        a[i] = a[i - 1] + 1 ;
    }
    return true ;
}
bool check(int k, int S, int x[], int a[]){
    int s = 0 ;
    for (int i = 0 ;i < k ; i ++)
        s += a[x[i]] ;
    return s == S ;
}
bool gen(int n, int k, int S, int a[]){
    int x[k] ;
    for (int i = 0 ; i < k; i ++)
        x[i] = i ;
    if (check(k, S, x, a))
        return true ;
    while (!isFinal(n, k, x)){
        genNext(n, k, x) ;
        if (check(k, S, x, a)){
            return true ;
        }
    }
    return false ;
}
int main() {
    int n, S;
    cin >> n >> S ;
    int a[n] ;
    for (int i = 0; i < n ; i ++)
        cin >> a[i];
    for (int i = 0; i < n ; i ++) {
        if (gen(n, i + 1, S, a)){
            cout << i + 1 ;
            return 0 ;
        }
    }

    return 0;
}