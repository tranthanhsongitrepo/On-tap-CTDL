#include <iostream>
#include <climits>

using namespace std;
int board[8][8] ;
int mark(int  n,  int x[]){
    int s = 0 ;
    for (int i = 0 ; i < n ; i ++)
        s += board[i][x[i]] ;
    return s ;
}
bool isSafe(int x, int y, int n, int cur[]) {
    for (int i = y - 1; i >= 0; i --) {
        if (cur[i] == x)
            return false;
    }
    for (int i = y - 1; i >= 0;  i --){
        if (abs(i - y) == abs (cur[i] - x))
            return false ;
    }
    return true ;
}
void nQueensBackTrack(int i, int& max_grade, int n, int x[]){
    if (i == n) {
        int grade = mark(n, x) ;
        if (max_grade < grade)
            max_grade = grade ;
        return;
    }
    for (int j = 0; j < n ;  j ++){
        if (isSafe(j, i, n, x)) {
            x[i] = j;
            nQueensBackTrack(i + 1, max_grade, n, x);
        }
    }
}
int nQueens(){
    int max_grade = INT_MIN ;
    int x[8] ;
    nQueensBackTrack(0, max_grade, 8, x) ;
    return max_grade;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        for (int i = 0 ; i < 8; i ++){
            for (int j = 0 ; j < 8; j ++)
                cin >> board[i][j] ;
        }
        cout << nQueens() << endl ;
    }
    return 0;
}