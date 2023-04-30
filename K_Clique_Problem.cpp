//Clique Problem
#include <bits/stdc++.h>
using namespace std;

const int N = 999;
int g[N][N], store[N], d[N];
int n,k;

//checking if all vertices are connected to each other or not
bool is_clique(int size) {
    for (int i=1; i<=size; i++) {
        for (int j=i+1; j<=size; j++) {
            //if edge is not exist then there will be no clique
            if (g[store[i]][store[j]] == 0) return false;
        }
    }
    return true;
}

//finding all k cliques if exist
void find_clique(int root, int size) {
    for (int i=root; i<=n-(k-size); i++) {
        if (d[i] >= k-1) {
            //storing the edges for searching clique
            store[size] = i;
            if (is_clique(size)) {
                //if size is less than k than calling the function again
                if (size < k) find_clique(i, size+1);
                //else we found a clique of k
                else {
                    for (int j=1; j<=k; j++) {
                        cout << store[j] << ' ';
                    }
                    cout << endl;
                }
            }
        }
    }
}

int main() {
    int m; cin>>n>>m>>k;

    //taking inputs of edges and degree
    for (int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        g[x][y] = 1;
        g[y][x] = 1;
        d[x]++;
        d[y]++;
    }

    find_clique(1,1);

    return 0;
}