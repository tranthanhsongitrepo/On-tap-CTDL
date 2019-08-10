#include <iostream>
#include <queue>
#include <vector>
using namespace std ;
class Graph {
private :
    vector<int>* graph ;
    int n ;
    void BFS(int i, int citites[]){
        queue<int> q ;
        q.push(i) ;
        bool visited[n] = {0};
        while (!q.empty()){
            int front = q.front() ;
            q.pop() ;
            citites[front]++;
            visited[front] = true ;
            for (int j = 0 ; j < graph[front].size(); j ++){
                if (!visited[graph[front][j]]) {
                    q.push(graph[front][j]);
                }
            }
        }
    }
public :
    Graph(int n){
        this->n = n ;
        graph = new vector<int> [n] ;
    }

    void addEdge(int v1, int v2 ){
        graph[v1 - 1].push_back(v2 - 1) ;
    }

    int noOfMettingPlaces(int a[], int k){
        int cities[n] = {0};
        for (int i = 0 ; i < k ; i ++) {
            BFS(a[i] - 1, cities) ;
        }
        int c = 0 ;
        for (int i = 0 ; i < n ; i  ++){
            if (cities[i] == k)
                c ++ ;
        }
        return c ;
    }

};
int main() {
    int n,m, k ;
    cin >> k >> n >> m;
    Graph graph(n) ;
    int st[k] ;
    for (int i = 0 ; i < k ;i ++)
        cin >> st[i] ;
    while (m --){
        int v1, v2 ;
        cin >> v1 >> v2;
        graph.addEdge(v1, v2) ;
    }
    cout << graph.noOfMettingPlaces(st, k) ;
    return 0;
}