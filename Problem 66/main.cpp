#include <iostream>
#include <stack>
using namespace std ;
int largestRectS(int rect_height[], int  n){
    stack<int> s ;
     int rect_length[n] = {0};
    for(int i = 0 ; i < n ; i ++) {
        while (!s.empty() && rect_height[s.top()] >= rect_height[i]) {
            rect_length[s.top()] += i - 1 - s.top();
            s.pop();
        }
        rect_length[i] += s.empty() ? i + 1 : i - s.top();
        s.push(i) ;
    }
    while (!s.empty()){
        rect_length[s.top()] += n - s.top() - 1 ;
        s.pop() ;
    }
    int max_rect_S = 0 ;
    for (int i = 0 ; i < n ; i  ++){
        max_rect_S = max(max_rect_S, rect_height[i] * rect_length[i]) ;
    }
    return max_rect_S ;
}

int main() {
    int t ;
    cin >> t ;
    while (t --){
        int n, m, max_1_rect_S =0 ;
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
            max_1_rect_S = max(max_1_rect_S, largestRectS(rect_height, m)) ;
        }
        cout << max_1_rect_S << endl ;
    }
    return 0;
}