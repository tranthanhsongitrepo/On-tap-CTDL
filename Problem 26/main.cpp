#include <iostream>
using namespace std ;
string getMinLuckyNumber(int n) {
    string res ;
    int cur_sum = 0 ;
    while (cur_sum < n) {
        cur_sum += 7 ;
        res.insert(res.begin(), '7') ;
    }
    int i = 0 ;
    while (cur_sum != n && i != res.length()){
        if (cur_sum < n){
            cur_sum += 4 ;
            res.insert(res.begin(), '4') ;
            i ++ ;
        }
        else{
            res[i ++] = '4' ;
            cur_sum -= 3 ;
        }
        if (cur_sum == n){
            return res;
        }
    }
    return (cur_sum == n) ? res : "-1" ;

}
int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n ;
        cin >> n ;
        cout << getMinLuckyNumber(n) << endl ;
    }
    return 0;
}