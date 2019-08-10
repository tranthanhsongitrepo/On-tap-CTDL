#include <iostream>
#include <queue>
using namespace std ;
int a[500][500] ;
int n, m ;
struct Cordinate{
    int x, y ;
    Cordinate(int x, int y){
        this->x = x ;
        this->y = y ;
    }
};
int noOfStep(queue<Cordinate> &q, int oneC) {
    int prev_size = q.size(), c = 0 ;
    while (!q.empty()){
        int x = q.front().x ;
        int y = q.front().y ;
        q.pop() ;
        if (x + 1 < n && a[x + 1][y] == 1){ // dưới
            a[x + 1][y] = 2 ;
            Cordinate t(x + 1, y) ;
            q.push(t) ;
            oneC -- ;
        }

        if (x - 1 >= 0 && a[x - 1][y] == 1){ // trên
            a[x - 1][y] = 2 ;
            Cordinate t(x - 1, y) ;
            q.push(t) ;
            oneC -- ;
        }
            if (y + 1 < m && a[x][y + 1] == 1){ // phải
            a[x][y + 1] = 2 ;
            Cordinate t(x, y + 1) ;
            q.push(t) ;
            oneC -- ;
        }
        if (y - 1 >= 0 && a[x][y - 1] == 1){ // trái
            a[x][y - 1] = 2 ;
            Cordinate t(x, y - 1) ;
            q.push(t) ;
            oneC -- ;
        }
        prev_size -- ;
        if (prev_size == 0){
            prev_size = q.size() ;
            c ++ ;
        }
    }
    return oneC == 0 ? c - 1 : -1 ;
}
int main() {
    int oneC = 0 ;
    queue<Cordinate> q ;
    cin >> n >> m ;
    for (int i = 0 ; i  < n ; i ++){
        for (int j = 0 ; j  < m ; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                oneC ++;
            else if (a[i][j] == 2){
                Cordinate t(i, j) ;
                q.push(t);
            }
        }
    }
    cout << noOfStep(q, oneC) ;
    return 0;
}