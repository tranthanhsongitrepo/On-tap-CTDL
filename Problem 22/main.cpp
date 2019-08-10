#include <iostream>
#include <cmath>

using namespace std ;
int noOfDivisorIsEven(int n){
    int lim = sqrt(n), c = 0 ;
    for (int i = 1; i <= lim; i ++){
        if (n % i == 0){
            if (i % 2 == 0) c ++ ;
            if (n / i != lim && (n / i) % 2 == 0) c ++ ;
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
        cout << noOfDivisorIsEven(n) << endl ;
    }
    return 0;
}