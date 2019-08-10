#include <iostream>
using namespace std ;
const long long int MOD = 1e9+7 ;
class Matrix{
    long long int** matrix ;
    int n ;
public:
    Matrix(int n){
        this->n = n ;
        matrix = new long long int* [n] ;
        for (int i = 0; i < n ; i ++)
            matrix[i] = new long long int[n] ;
    }
    void input(){
        for (int i = 0; i < n; i ++)
            for (int j = 0 ; j < n;  j ++)
                cin >> matrix[i][j] ;
    }
    Matrix operator * (const Matrix &b){
        Matrix res(n);
        for (int k = 0; k < n ; k ++){
            for (int i = 0; i < n ; i ++){
                long long int t = 0 ;
                for (int j = 0 ; j < n ; j ++){
                    t = (t + this->matrix[k][j] * b.matrix[j][i]) % MOD ;
                }
                res.matrix[k][i] = t ;
            }
        }
        return res ;
    }
    Matrix powMod(int n){
        if (n == 1){
            return *this ;
        }
        Matrix t = powMod(n / 2) ;
        return n % 2 == 0 ? t * t : t * t * (*this) ;
    }
    void output (){
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl ;
        }
    }
};
int main() {
    int t ;
    cin >> t;
    while (t --) {
        int n, k ;
        cin >> n >> k ;
        Matrix temp(n) ;
        temp.input() ;

        temp.powMod(k).output() ;
    }
    return 0;
}