use std::collections::{BTreeSet, HashMap};

struct BIT(usize, Vec<i64>);

impl BIT {
    fn new(n: usize) -> Self {
        Self(n, vec![0;n+1])
    }
    fn query(&self, mut i: usize) -> i64 {
        let lowbit = |x: i64|x&-x;
        let mut res = 0;
        while i > 0 {
            res += self.1[i];
            i -= lowbit(i as i64) as usize;
        }
        res
    }
    fn insert(&mut self, mut i: usize) {
        let lowbit = |x: i64| x & -x;
        while i <= self.0 {
            self.1[i] += 1;
            i += lowbit(i as i64) as usize;
        }
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let n : usize = buf.trim().parse::<usize>().unwrap();
        let mut a = vec![];
        let mut numbers = BTreeSet::new();
        for _ in 0..n {
            buf.clear();
            std::io::stdin().read_line(&mut buf).ok();
            let tmp: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
            a.push((tmp[0], tmp[1]));
            numbers.insert(tmp[0]);
            numbers.insert(tmp[1]);
        }
        let mut mp = HashMap::new();
        let mut tot = 0;
        for p in numbers {
            tot += 1;
            mp.insert(p, tot);
        }
        a.sort_unstable();
        let mut st = BIT::new(tot);
        let mut res = 0;
        for x in a.iter().rev() {
            let td = *mp.get(&x.1).unwrap();
            let cnt = st.query(td);
            res += cnt;
            st.insert(td);
        }
        println!("{res}");
    }
}