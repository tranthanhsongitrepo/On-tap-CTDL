#include <iostream>
#include <stack>
using namespace std ;
int largestRectS(int sq_h[], int  n){
    stack<int> s ;
    int sq_l[n] = {0};
    for(int i = 0 ; i < n ; i ++) {

            while (!s.empty() && sq_h[s.top()] >= sq_h[i]) {
                if (sq_h[s.top()] != 0)
                    sq_l[s.top()] += i - 1 - s.top();
                s.pop();
            }
            if (sq_h[i] != 0)
               sq_l[i] += s.empty() ? i + 1 : i - s.top();

            s.push(i);
    }
    while (!s.empty()){
        if (sq_h[s.top()] != 0)
          sq_l[s.top()] += n - s.top() - 1 ;
        s.pop() ;
    }
    int max_l = 0 ;
    for (int i = 0 ; i < n ; i  ++){
        if (sq_h[i] == sq_l[i] && max_l < sq_l[i])
            max_l = sq_l[i] ;
    }
    return max_l ;
}

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m, max_l =0 ;
        cin >> n >> m ;
        int a[n][m], rect_height[m] =  {0};
        for (int i = 0 ; i < n; i ++){
            for (int j = 0 ; j < m ; j ++){
                cin >> a[i][j] ;
                if (a[i][j] == 0)
                    rect_height[j] = 0 ;
                else
                    rect_height[j] ++ ;
            }
            max_l = max(max_l, largestRectS(rect_height, m)) ;
        }
        cout << max_l << endl ;
    }
    return 0;
}