#include <iostream>
#include <algorithm>

using namespace std ;
struct Pair{
    int a, b ;
    bool operator < (Pair b) {
        return this->a < b.a ;
    }
};
int main() {
    int n ;
    cin >> n ;
    Pair a[n] ;
    for (int i = 0 ; i < n; i ++)
        cin >> a[i].a >> a[i].b ;
    sort(a, a + n) ;
    int t = 0 ;
    for (int i = 0 ; i <n; i ++){
        if (t <= a[i].a){
            t = a[i].a + a[i].b ;
        }
        else
            t += a[i].b ;
    }
    cout << t ;
    return 0;
}