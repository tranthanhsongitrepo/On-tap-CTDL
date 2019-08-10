#include <iostream>
using namespace std ;
int main() {
    string s ;
    while (getline(cin, s)){
        for (int i = 0 ; i < s.length(); i ++){
            if (s[i] == ' ') {
                int j = i - 1;
                while (j >= 0 && !isspace(s[j])){
                    cout << s[j --] ;
                }
                cout << " " ;
            }
            else if (i == s.length() - 1){
                int j = i ;
                while (j >= 0 && !isspace(s[j])){
                    cout << s[j --] ;
                }
                cout << " " ;
            }
        }
    }
    return 0;
}