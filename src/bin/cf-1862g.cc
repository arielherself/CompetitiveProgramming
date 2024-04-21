$include(template.hh);

// #define SINGLE_TEST_CASE
// #define DUMP_TEST_CASE 7219

void dump() {}

void dump_ignore() {}

void prep() {}

void solve() {
    $read(int, n);
    $readvec(int, a, n);
    multiset<int> st(a.begin(), a.end());
    multiset<int> diff;
    int prev = *st.begin();
    for (auto&& x : st) {
        diff.emplace(x - prev);
        prev = x;
    }
    $read(int, q);
    while (q--) {
        $read(int, i, x);
        --i;
        auto it = st.lower_bound(a[i]);
        bool it_ne_st_begin = it != st.begin();
        bool it_ne_st_end = it != st.end();
        auto prev = it; int prev_val; if (it_ne_st_begin) prev_val = *--prev;
        auto next = it; int next_val; if (it_ne_st_end) it_ne_st_end = (++next) != st.end(); if (it_ne_st_end) next_val = *next;
        if (it_ne_st_begin) {
            diff.erase(diff.lower_bound(a[i] - prev_val));
        }
        if (it_ne_st_end) {
            diff.erase(diff.lower_bound(next_val - a[i]));
        }
        if (it_ne_st_begin && it_ne_st_end) {
            diff.emplace(next_val - prev_val);
        }
        st.erase(st.lower_bound(a[i]));
        prev = st.lower_bound(x);
        next = st.lower_bound(x);
        bool nx_ne_st_begin = next != st.begin();
        bool nx_ne_st_end = next != st.end();
        if (nx_ne_st_end) next_val = *next;
        if (nx_ne_st_begin) prev_val = *--prev;
        if (nx_ne_st_begin && nx_ne_st_end) {
            diff.erase(diff.lower_bound(next_val - prev_val));
        }
        if (nx_ne_st_begin) {
            diff.emplace(x - prev_val);
        }
        if (nx_ne_st_end) {
            diff.emplace(next_val - x);
        }
        a[i] = x;
        st.emplace(x);
        cout << (diff.size() ? *diff.rbegin() : 0) + *st.rbegin() << " \\n"[q == 0];
    }
}

$include(mian.hh)
