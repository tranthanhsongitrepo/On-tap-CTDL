#include <iostream>
using namespace std ;
int main() {
    int t[10] = {1,2,3,4,5,6,7,8,9,10};
    int r2, s = 0 ;
    for (int i = 0 ; i < 10; i ++) {
        if (t[i] > 0)
            s += t[i];
    }
    r2 = s ;
    return 0;
}