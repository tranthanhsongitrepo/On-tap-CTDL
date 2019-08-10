#include <iostream>
#include <queue>
using namespace std ;
struct Cordinate{
    int x, y;
    Cordinate(char c[2]){
        this->x = 8 - c[1] + '0';
        this->y = c[0] - 'a' ;
    }
    Cordinate(int x, int y) {
        this->x = x ;
        this->y = y ;
    }
    bool operator != (Cordinate a){
        return this->x != a.x || this->y != a.y ;
    }
};

const int N = 8 ;
int getShortest(char st[2] , char end[2]){
    queue<Cordinate> q ;
    Cordinate s(st), e(end) ;
    q.push(s) ;
    bool visited[N][N] = {false} ;
    visited[s.x][s.y] = true ;
    int prev_size = 1, c = 0 ;
    while (q.front() != e){
        int x = q.front().x,
            y = q.front().y ;

        q.pop() ;
        if (x + 2 < N && y + 1 < N && !visited[x + 2][y + 1]){
            Cordinate temp(x + 2, y + 1) ;
            q.push(temp) ;
            visited[x + 2][y + 1] = true ;
        }

        if (x + 2 < N && y - 1 >= 0 && !visited[x + 2][y - 1]){
            Cordinate temp(x + 2, y - 1) ;
            q.push(temp) ;
            visited[x + 2][y - 1] = true ;
        }

        if (x + 1 < N && y + 2 < N && !visited[x + 1][y + 2]){
            Cordinate temp(x + 1, y + 2) ;
            q.push(temp) ;
            visited[x + 1][y + 2] = true ;
        }

        if (x + 1 < N && y - 2 >= 0 && !visited[x + 1][y - 2]){
            Cordinate temp(x + 1, y - 2) ;
            q.push(temp) ;
            visited[x + 1][y - 2] = true ;
        }

        if (x - 2 >= 0 && y + 1 < N && !visited[x - 2][y + 1]){
            Cordinate temp(x - 2, y + 1) ;
            q.push(temp) ;
            visited[x - 2][y + 1] = true ;
        }

        if (x - 2 >= 0 && y - 1 >= 0 && !visited[x - 2][y - 1]){
            Cordinate temp(x - 2, y - 1) ;
            q.push(temp) ;
            visited[x - 2][y - 1] = true ;
        }

        if (x - 1 >= 0 && y + 2 < N && !visited[x - 1][y + 2]){
            Cordinate temp(x - 1, y + 2) ;
            q.push(temp) ;
            visited[x - 1][y + 2] = true ;
        }

        if (x - 1 >= 0 && y - 2 >= 0 && !visited[x - 1][y - 2]){
            Cordinate temp(x - 1, y - 2) ;
            q.push(temp) ;
            visited[x - 1][y - 2] = true ;
        }

        prev_size -- ;
        if (prev_size == 0){
            c ++ ;
            prev_size = q.size() ;
        }
    }

    return c ;
}
int main() {
    int t;
    cin >> t ;
    while (t --){
        char c1[2], c2[2] ;
        cin >> c1 >> c2 ;
        cout << getShortest(c1, c2) << endl ;
    }

    return 0;
}