#include <iostream>
#include <string>

#define lson fhq[u].l
#define rson fhq[u].r

constexpr int N = 1e6 + 10;
constexpr int INT_MAX = ~0;

struct tuple {
    int val, x, y;
    tuple() : val(0), x(0), y(0) {}
    tuple(int val, int x, int y) : val(val), x(x), y(y) {}
};

bool operator<=(const tuple& l, const tuple& r) {
    if (l.val == r.val) {
        if (l.x == r.x) {
            return l.y <= r.y;
        }
        return l.x < r.x;
    }
    return l.val < r.val;
};

struct Node {
    int l, r;
    int key, size;
    tuple val;
} fhq[N];
int cnt, root;

void pushup(int u) {
    fhq[u].size = fhq[lson].size + fhq[rson].size + 1;
}

int node(tuple val) {
    fhq[++cnt].val = val;
    fhq[cnt].key = rand();
    fhq[cnt].size = 1;
    return cnt;
}

void split(int u, tuple val, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (fhq[u].val <= val) x = u, split(rson, val, rson, y);
        else y = u, split(lson, val, x, lson);
        pushup(u);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (fhq[x].key <= fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        pushup(x);
        return x;
    } else {
        fhq[y].l = merge(x, fhq[y].l);
        pushup(y);
        return y;
    }
}

int x, y, z;

void insert(tuple val) {
    split(root, val, x, y);
    root = merge(merge(x, node(val)), y);
}

void del(tuple val) {
    split(root, val, x, z);
    split(x, {val.val, val.x, val.y - 1}, x, y);
    y = merge(fhq[y].l, fhq[y].r);
    root = merge(merge(x, y), z);
}

int askRank(tuple val) {
    split(root, {val.val, val.x, val.y - 1}, x, y);
    int res = fhq[x].size + 1;
    root = merge(x, y);
    return res;
}

tuple askNum(int u, int rank) {
    if (fhq[lson].size + 1 == rank) return fhq[u].val;
    if (fhq[lson].size >= rank) return askNum(lson, rank);
    else return askNum(rson, rank - fhq[lson].size - 1);
}

constexpr int MAXN = 520;
constexpr int MAXT = 1e5 + 10;

int query[MAXT];
int result[MAXT];
int a[MAXN][MAXN];
bool open[MAXN * MAXN];
int n, m;

class quick_union {
private:
    int c[MAXN * MAXN];
public:
    quick_union(size_t n, size_t m) {
        for (int i = 0; i < n * m; ++i) {
            c[i] = i;
        }
    }
    
    size_t query(size_t i) {
        if (c[i] != i) c[i] = query(c[i]);
        return c[i];
    }
    
    void merge(size_t i, size_t j) {
        c[query(i)] = query(j);
    }

    bool connected(size_t i, size_t j) {
        return query(i) == query(j);
    }
};

long long serialize(int x, int y) {
    return (long long)x * m + y;
}

int main() {
    std::cin >> n >> m;
    int tree_size = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            insert({a[i][j], i, j});
            tree_size += 1;
        }
    }
    int t; std::cin >> t;
    int res = 0;
    for (int i = 0; i < t; ++i) {
        std::cin >> query[i];
    }
    quick_union qu(n, m);
    for (int j = t - 1; ~j; --j) {
        int x = query[j];
        while (tree_size && askNum(root, tree_size).val > x) {
            tuple current = askNum(root, tree_size);
            int cnt = 0;
            int pts[5];
            if (current.x - 1 >= 0 && open[qu.query(serialize(current.x - 1, current.y))]) {
                pts[cnt++] = serialize(current.x - 1, current.y);
            }
            if (current.x + 1 < m && open[qu.query(serialize(current.x + 1, current.y))]) {
                pts[cnt++] = serialize(current.x + 1, current.y);
            }
            if (current.y - 1 >= 0 && open[qu.query(serialize(current.x, current.y - 1))]) {
                pts[cnt++] = serialize(current.x, current.y - 1);
            }
            if (current.y + 1 < m && open[qu.query(serialize(current.x, current.y + 1))]) {
                pts[cnt++] = serialize(current.x, current.y + 1);
            }
            if (!cnt) {
                res += 1;
            } else {
                int distinct = 0;
                for (int i = 0; i < cnt; ++i) {
                    int f = 1;
                    for (int j = i + 1; j < cnt; ++j) {
                        if (qu.connected(pts[i], pts[j])) {
                            f = 0;
                            break;
                        }
                    }
                    if (f) {
                        distinct += 1;
                    }
                }
                res = res - distinct + 1;
                for (int i = 0; i < cnt; ++i) {
                    qu.merge(serialize(current.x, current.y), pts[i]);
                }
            }
            open[serialize(current.x, current.y)] = 1;
            tree_size -= 1;
            del(current);
        }
        result[j] = res;
    }
    for (int i = 0; i < t; ++i) {
        std::cout << result[i] << " \n"[i + 1 == t];
    }
}
