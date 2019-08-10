#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> s ;
void push(int a){
    s.insert(s.begin(), a) ;
}
void pop(){
    if (s.size() != 0)
        s.erase(s.begin()) ;
}

void print(){
    (s.size() == 0) ? cout << "NONE" << endl : cout << s[0] << endl;
}
int main() {
    int q;
    cin >> q ;
    while (q --) {
        string in;
        cin >> in;
        if (in == "PUSH") {
            int x;
            cin >> x;
            push(x);
        }
        else if (in == "POP")
            pop();
        else
            print();
    }
    return 0;
}