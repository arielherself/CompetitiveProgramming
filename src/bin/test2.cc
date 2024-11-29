#include<bits/stdc++.h>
using namespace std;

#define isdigit(x) ('0' <= x && x <= '9')
template<typename types>
inline void read(types &x){
    x = 0; int f = 1; char c;
    while ((c = getchar()) && !isdigit(c)) if (c == '-') f = -1;
    x = c ^ 48;
    while ((c = getchar()) && isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48);
    x *= f; return; 
}
template<typename types>
void write(types x){
    if (x < 0) putchar('-'), x = - x;
    types k = x / 10;
    if (k) write(k);
    putchar(x - (k << 3) - (k << 1) | 48);
    return;
}

const int MAXN = 500010;
const int MAXM = 4000010;

int n, m;
int head[MAXN], to[MAXM], nxt[MAXM], idx = 1;
int dfn[MAXN], low[MAXN], timecnt;    // timecnt 时间戳记录顺序 
vector<int> vdcc[MAXN];
int vdcc_cnt;
stack<int> s;

inline void addedge(int x, int y){
    nxt[++idx] = head[x];
    to[idx] = y;
    head[x] = idx;
    return;
}

void Tarjan(int x, int from){
    dfn[x] = low[x] = ++timecnt;
    s.push(x);
    int child = 0;
    int p;
    for (int i = head[x]; i; i = nxt[i]){
        if (i == (from ^ 1)) continue;    // 判断来路 
        child++;
        int y = to[i];
        if (!dfn[y]){
            Tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]){    // 找到点双 
                ++vdcc_cnt;
                do{
                    p = s.top(); s.pop();
                    vdcc[vdcc_cnt].push_back(p);
                } while (p != y);    // 弹到子节点 
                vdcc[vdcc_cnt].push_back(x);    // 记得把自己加进去 
            }
        }
        low[x] = min(low[x], dfn[y]);
    }
    if (!child && !from)    // 记得特判孤立点 
        vdcc[++vdcc_cnt].push_back(x);
    return;
}

int main(){
    read(n), read(m);
    int x, y;
    for (int i = 1; i <= m; ++i){
        read(x), read(y);
        if (x != y) addedge(x, y), addedge(y, x);
    }
    
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i, 0); 
    
    write(vdcc_cnt), putchar('\n');
    for (int i = 1; i <= vdcc_cnt; ++i){
        write(vdcc[i].size()), putchar(' ');
        for (auto j = vdcc[i].begin(); j != vdcc[i].end(); ++j){
            write(*j), putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
