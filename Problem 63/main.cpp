#include <iostream>
#include <stack>

using namespace std ;
bool isOperator(char c){
    return c == '*' || c == '/' || c == '+' || c == '-' || c == ')' || c == '(' ;
}
bool isNum(char c){
    return c >= '0' && c <= '9';
}
int priority(char c){
    switch (c) {
        case '+' : case '-' :
            return 1 ;
        case '*' : case '/' :
            return  2 ;
        case '(' :
            return -2 ;
        case ')' :
            return -1 ;
    }
}
long long int apply (long long int operand1, char op, long long int operand2){
    switch (op){
        case '+' :
            return operand1 + operand2 ;
        case '-' :
            return operand1 - operand2 ;
        case '/' :
            return operand1 / operand2 ;
        case '*' :
            return operand1 * operand2 ;
    }
}
long long int toInt (int &i, string ex){
    long long int res = 0 ;
    while (i < ex.length() && isNum(ex[i])) {
        res = res * 10 + ex[i] - '0';
        i++;
    }
    return res ;
}
long long int caculaceExpression(string ex){
    stack<char> operators ;
    stack<long long int> operands ;
    int i = 0 ;
    while (i < ex.length()){
        if (isOperator(ex[i])){
            if (ex[i] != '(') {
                while (!operators.empty() && priority(operators.top()) >= priority(ex[i])) {
                    long long int operand1 = operands.top();
                    operands.pop();
                    long long int operand2 = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    operands.push(apply(operand2, op, operand1));
                }
            }
            if (ex[i] != ')')
                operators.push(ex[i]) ;
            else
                operators.pop() ;
            i ++ ;
        }
        else{
            operands.push(toInt(i, ex)) ;
        }
    }
    while (!operators.empty() && priority(operators.top()) >= priority(ex[i])) {
        long long int operand1 = operands.top();
        operands.pop();
        long long int operand2 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(apply(operand2, op, operand1));
    }
    return operands.top() ;
}
int main() {
    int t ;
    cin >> t ;
    while (t --) {
        string ex ;
        cin >> ex ;
        cout << caculaceExpression(ex) << endl ;
    }
    return 0;
}