#include <iostream>
#include <queue>
using namespace  std ;
int noOfSteps(int s, int t) {
    bool visited[2000000] = {false};
    queue<int> q;
    q.push(s);
    int prev_size = 1, c = 0;
    while (q.front() != t) {
        int front = q.front();
        q.pop();
        int moveA = front - 1;
        int moveB = front * 2;
        if (moveA >= 0 && !visited[moveA])
            q.push(moveA);
        if (moveB >= 0 && !visited[moveB])
          q.push(moveB);
        prev_size--;
        if (prev_size == 0) {
            c++;
            prev_size = q.size();
        }
    }
    return c;
}
int main() {
    int n ;
    cin >> n ;
    while (n --) {
        int s, t ;
        cin >> s >> t ;
        cout << noOfSteps(s, t) << endl ;
    }
    return 0;
}