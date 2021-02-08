#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n, m;
ifstream f("cuplaj.in");

vector <vector <int>> adj(1000);
bool vizitate[1000];
int legatura[1000];

bool dfs(int u)
{
        for(auto v : adj[u]) {
            if(!vizitate[v]) {
                vizitate[v] = true;
                if(legatura[v] < 0 || dfs(legatura[v])) {
                    legatura[v] = u;
                    return true;
                }
            }
        }
    return false;
}

int cuplaj_grafBipartit()
{

    memset(legatura, -1, sizeof(legatura));

    int cuplaj_max = 0;
    for (int u = 0; u < m; u++)
    {
        memset(vizitate, 0, sizeof(vizitate));

        if (dfs(u))
            cuplaj_max++;
    }

    cout << cuplaj_max << endl;

    for(int i = 0; i < n; i++) {
        if(legatura[i] != -1) {
            cout << i+1 << " " << legatura[i] + 1 << endl;
        }
    }
}


int main()
{
    int e, a, b;
    f >> n >> m >> e;

    for(int i = 0; i < e; i++) {
        f >> a >> b;
        adj[b-1].push_back(a-1);
    }

    cuplaj_grafBipartit();

    return 0;
}