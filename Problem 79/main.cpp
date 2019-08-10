#include <iostream>
#include <queue>
using namespace std ;
bool isEqual (int a[], int b[]){
    for(int i = 0; i < 6 ; i ++)
        if (a[i] != b[i])
            return false ;
        return true ;
}
int *rotateLeft(int a[]) {
    int* res = new int[6] ;
    res[0] = a[3] ;
    res[1] = a[0] ;
    res[2] = a[2] ;
    res[3] = a[4] ;
    res[4] = a[1] ;
    res[5] = a[5] ;
    return res ;
}
int *rotateRight(int a[]){
    int* res = new int[6] ;
    res[0] = a[0] ;
    res[1] = a[4] ;
    res[2] = a[1] ;
    res[3] = a[3] ;
    res[4] = a[5] ;
    res[5] = a[2] ;
    return res ;
}
int noOfSteps(int st[], int end[]){
    queue<int*> q ;
    q.push(st) ;
    int prev_size = 1, c = 0 ;
    while (!isEqual(q.front(), end)){
        q.push(rotateLeft(q.front())) ;
        q.push(rotateRight(q.front())) ;
        q.pop() ;
        prev_size -- ;
        if (prev_size == 0){
            c ++ ;
            prev_size = q.size() ;
        }
    }
    return c ;
}
int main() {
    int st[6], end[6] ;
    for(int i = 0; i < 6 ; i ++)
        cin >> st[i];
    for (int j = 0 ; j < 6 ; j ++)
        cin >> end[j] ;
    cout << noOfSteps(st, end) ;
    return 0;
}