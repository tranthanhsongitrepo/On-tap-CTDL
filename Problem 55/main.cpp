#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> s ;
void push(int a){
    s.insert(s.begin(), a) ;
}
void pop(){
    s.erase(s.begin()) ;
}

void print(){
    if (s.size() != 0) {
        for (int i = s.size() - 1; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }
    else
        cout << "empty" << endl ;
}
int main() {
    string in ;
    while (cin >> in){
        if (in == "push"){
            int x ;
            cin >> x ;
            push(x);
        }
        else if (in == "pop")
            pop() ;
        else
            print() ;
    }
    return 0;
}