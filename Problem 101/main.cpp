    #include <iostream>
    #include <vector>
    #include <stack>

    using namespace std;
    class Graph {
        int size;
        vector<int>* g;
    public :
        Graph(int size) {
            this->size = size ;
            g = new vector<int>[size] ;
        }

        int getSize(){
            return size ;
        }
        void addEdge(int v1, int v2) {
            g[v1].push_back(v2) ;
            g[v2].push_back(v1) ;
        }

        void DFS(int u){
            stack<int> s ;
            s.push(u) ;
            bool visited[size] = {false};
            visited[u] = true ;
            while (!s.empty()){
                int top = s.top() ;
                s.pop() ;
                cout << top + 1 << " " ;
                for (int i = g[top].size() - 1; i >= 0 ; i --){
                    if (!visited[g[top][i]]) {
                        s.push(g[top][i]);
                        visited[g[top][i]] = true ;
                    }
                }
            }
            cout << endl ;
        }
    };

    int main() {
        int t ;
        cin >> t ;
        while (t --){
            int n, m, u ;
            cin >> n >> m >> u ;
            Graph g(n) ;
            while (m --) {
                int v1, v2 ;
                cin >> v1 >> v2 ;
                g.addEdge(v1 - 1, v2 - 1);
            }
            g.DFS(u - 1) ;
        }
        return 0;
    }