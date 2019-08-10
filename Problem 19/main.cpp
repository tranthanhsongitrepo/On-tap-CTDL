#include <iostream>
using namespace std ;
const long long int MOD = 1e9+7 ;
class Matrix{
    long long int matrix[2][2] ;
    const int N = 2 ;
public:
    Matrix(){
        matrix[0][0] = 1 ;
        matrix[0][1] = 1 ;
        matrix[1][0] = 1 ;
        matrix[1][1] = 0 ;
    }
    Matrix operator * (const Matrix &b){
        Matrix res;
        for (int k = 0; k < N ; k ++){
            for (int i = 0; i < N ; i ++){
                long long int t = 0 ;
                for (int j = 0 ; j < N ; j ++){
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
    long long int get (int i, int j){
        return matrix[i][j] ;
    }
};
int main() {
    int t ;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        Matrix temp ;
        cout << temp.powMod(n).get(0, 1) << endl ;
    }
    return 0;
}