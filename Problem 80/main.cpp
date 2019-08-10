#include <iostream>
#include <queue>
using namespace std ;
char board[100][100] ;
bool visited[100][100] = {0};
int n ;
struct Cordinate{
    int x, y ;
    Cordinate(int x, int y){
        this->x = x ;
        this->y = y ;
    }
    bool operator != (Cordinate b){
        return this->x != b.x || this->y != b.y ;
    }
};

int noOfSteps(Cordinate st, Cordinate end){
    queue<Cordinate> q;
    q.push(st) ;
    visited[st.x][st.y] = true ;
    int prev_size = 1, c = 0 ;
    while (q.front() != end) {
        for (int i = q.front().x + 1; i < n; i++) {
            if (board[i][q.front().y] != 'X') {
                if (!visited[i][q.front().y]) {
                    Cordinate temp(i, q.front().y);
                    q.push(temp);
                    visited[i][q.front().y] = true;
                }
            }
            else
                break;
        }
        for (int i = q.front().x - 1; i >= 0; i--) {
            if (board[i][q.front().y] != 'X') {
                if (!visited[i][q.front().y]) {
                    Cordinate temp(i, q.front().y);
                    q.push(temp);
                    visited[i][q.front().y] = true;
                }
            }
            else
                break;
        }
        for (int i = q.front().y + 1; i < n; i++) {
            if (board[q.front().x][i] != 'X') {
                if (!visited[q.front().x][i]) {
                    Cordinate temp(q.front().x, i);
                    q.push(temp);
                    visited[q.front().x][i] = true;
                }
            }
            else
                break;
        }
        for (int i = q.front().y - 1; i >= 0; i--) {
            if (board[q.front().x][i] != 'X') {
                if (!visited[q.front().x][i]) {
                    Cordinate temp(q.front().x, i);
                    q.push(temp);
                    visited[q.front().x][i] = true;
                }
            }
            else
                break;
        }
        q.pop();
        prev_size--;
        if (prev_size == 0) {
            prev_size = q.size();
            c++;
        }
    }
    return c ;
}
int main() {
    cin >> n ;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n; j ++){
            cin >> board[i][j] ;
        }
    }
    int x, y ;
    cin >> x >> y ;
    Cordinate st(x, y) ;
    cin >> x >> y ;
    Cordinate end(x, y) ;
    cout << noOfSteps(st, end) ;
    return 0;
}