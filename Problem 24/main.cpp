#include <iostream>
using namespace std ;
int ex[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int minNoOfBills(int n){
    int c = 0 ;
    for (int i = 9; i >= 0; i --){
        while (n >= ex[i]){
            n -= ex[i] ;
            c ++ ;
        }
    }
    return c ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n ;
        cin >> n ;
        cout << minNoOfBills(n) << endl ;
    }
    return 0;
}