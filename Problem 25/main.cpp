#include <iostream>>
#include <algorithm>
using namespace std ;
struct Work{
    int a, b ;
    void input(){
        cin >> a >> b ;
    }
    bool operator < (Work b){
        return this->b < b.b ;
    }
};
int maxWorkload(Work works[], int n) {
    int c = 0, last_end_time = 0 ;
    for (int i = 0; i < n ; i ++){
        if (works[i].a >= last_end_time) {
            last_end_time = works[i].b ;
            c++;
        }
    }
    return c ;
}
int main() {
    int t ;
    cin >> t ;
    while (t--){
        int n ;
        cin >> n ;
        Work works[n] ;
        for (int i = 0; i < n; i ++)
            works[i].input() ;
        sort(works, works + n) ;
        cout << maxWorkload(works, n) << endl ;
    }
    return 0;
}
/* 1 2
 * 3 4
 * 0 6
 * 5 7
 * 5 9
 * 8 9
 */