#include <iostream>
using namespace std ;
int pow10[8] ;
void printMinMaxWrongSum(int a, int b) {
    int res_min_a = 0, res_max_a = 0, res_min_b = 0, res_max_b = 0, i = 0;
    while (a) {
        int num = a % 10;
        a /= 10 ;
        res_min_a += (num == 6) ? 5 * pow10[i] : num * pow10[i];
        res_max_a += (num == 5) ? 6 * pow10[i] : num * pow10[i];
        i ++ ;
    }
    i = 0 ;
    while (b) {
        int num = b % 10;
        b /= 10 ;
        res_min_b += (num == 6) ? 5 * pow10[i] : num * pow10[i];
        res_max_b += (num == 5) ? 6 * pow10[i] : num * pow10[i];
        i ++ ;
    }
    cout << res_min_a + res_min_b << " " << res_max_a + res_max_b ;
}

void fillPow10(){
    pow10[0] = 1 ;
    for (int i = 1; i <= 8; i ++)
        pow10[i] = pow10[i - 1] *  10 ;
}
int main() {
    fillPow10();
    int a, b;
    cin >> a >> b;
    printMinMaxWrongSum(a, b);
    return 0;
}