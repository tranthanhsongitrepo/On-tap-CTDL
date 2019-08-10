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
        if (s == "PUSHBACK"){
            int x ;
            cin >> x ;
            dq.push_back(x) ;
        }
        else if (s == "PUSHFRONT"){
            int x ;
            cin >> x ;
            dq.push_front(x) ;
        }
        else if (!dq.empty() && s == "POPBACK"){
            dq.pop_back() ;
        }
        else if (!dq.empty() && s == "POPFRONT") {
            dq.pop_front() ;
        }
        else if (s == "PRINTFRONT")
            dq.empty() ? cout << "NONE" << endl : cout << dq.at(0) << endl ;
        else if (s == "PRINTBACK")
            dq.empty() ? cout << "NONE" << endl : cout << dq.at(dq.size() - 1) << endl ;
    }
    return 0;
}