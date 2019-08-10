#include <iostream>
#include <queue>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while (t --){
        deque<int> dq ;
        int n ;
        cin >> n ;
        while (n --){
            int q ;
            cin >> q ;
            switch (q) {
                case 1 :

                    cout << dq.size() << endl ;
                    break ;
                case 2 :
                    dq.empty() ? cout << "YES" << endl : cout << "NO" << endl ;
                    break ;
                case 3 :
                    int x ;
                    cin  >> x ;
                    dq.push_back(x) ;
                    break ;
                case 4 :
                    if (!dq.empty())
                        dq.pop_front() ;
                    break ;
                case 5 :
                    dq.empty() ? cout << -1 << endl : cout << dq.at(0) << endl ;
                    break ;
                case 6 :
                    dq.empty() ? cout << -1 << endl : cout << dq.at(dq.size() - 1) << endl ;
                    break ;
            }
        }
    }
    return 0;
}