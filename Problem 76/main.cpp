#include <iostream>
#include <queue>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    deque<int> dq ;
    while (t --){
        string s ;
        cin >> s ;
        if (s == "PUSH"){
            int x ;
            cin >> x ;
            dq.push_back(x) ;
        }
        else if (!dq.empty() && s == "POP"){
            dq.pop_front() ;
        }
        else
            dq.empty() ? cout << "NONE" << endl : cout << dq.at(0) << endl ;
    }
    return 0;
}