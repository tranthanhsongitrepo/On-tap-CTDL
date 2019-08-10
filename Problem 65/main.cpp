#include <iostream>
#include <stack>
using namespace std ;
long long int largestRectLength (long long int a[], long long int n){
    long long int rect_length[n] = {0};
    stack<long long int> s ;
    for (int i = 0 ; i < n ; i ++){
        while (!s.empty() && a[s.top()] >= a[i]){
            rect_length[s.top()] += i - s.top() - 1;
            s.pop() ;
        }
        rect_length[i] += s.empty() ? i + 1 : i - s.top() ;
        s.push(i);
    }
    while (!s.empty()){
        rect_length[s.top()] += n - s.top() - 1 ;
        s.pop() ;
    }
    long long int max_rect_S = 0 ;
    for (int i = 0 ; i < n ; i ++){
        max_rect_S = max(max_rect_S, a[i] * rect_length[i]) ;
    }
    return max_rect_S ;
}
int main() {
    long long int t ;
    cin >> t ;
    while (t --){
        long long int n ;
        cin >> n ;
        long long int a[n] ;
        for (long long int i = 0; i < n ; i ++)
            cin >> a[i] ;
        cout << largestRectLength(a, n) << endl ;
    }
    return 0;
}