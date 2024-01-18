use std::collections::BTreeSet;
use std::ops::Bound::*;
fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut l: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let r: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut rst = BTreeSet::new();
        r.into_iter().for_each(|x|{ rst.insert(x); });
        let mut c: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        l.sort_unstable();
        let mut ranges = vec![];
        for &x in l.iter().rev() {
            let cr = *rst.range((Excluded(x), Unbounded)).next().unwrap();
            rst.remove(&cr);
            ranges.push(cr - x);
        }
        ranges.sort_unstable_by_key(|x|-x);
        c.sort_unstable();
        let res = ranges.into_iter().zip(c.into_iter()).fold(0i64, |s, p|s + p.0 * p.1);
        println!("{res}");
    }
}