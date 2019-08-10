#include <iostream>
#include <queue>
using namespace std ;
struct BinaryNum{
    long long int bin, dec ;
    BinaryNum(long long int bin, long long int dec){
        this->bin = bin ;
        this->dec = dec ;
    }
};
void BND(long long int n) {
    long long int c = 1 ;
    queue<BinaryNum> q ;
    BinaryNum temp(1, 1);
    if (n >= 1)
        cout << 1 << " " ;
    q.push(temp);
    while (!q.empty()){
        long long int tb = q.front().bin * 10, td = q.front().dec * 2 ;
            if (td <= n) {
                BinaryNum t(tb, td) ;
                q.push(t);
                cout << t.bin << " " ;
            }
            if (td + 1 <= n) {
                BinaryNum t(tb + 1, td + 1) ;
                q.push(t);
                cout << t.bin << " " ;
            }
            q.pop();
    }
    cout << endl ;
}
int main() {
    int n;
    cin >> n ;
    while (n --){
        int t;
        cin >> t ;
        BND(t) ;
    }
    return 0;
}
// test 2 sai