fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let n: usize = buf.trim().parse::<usize>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
    let mut pa = vec![0;n+1];
    let mut sa = vec![0;n+1];
    pa[0] = 0 - n as i64 - 1;
    for i in 1..=n {
        pa[i] = pa[i-1].max(a[i-1] - i as i64 - 1);
    }
    for i in (0..n).rev() {
        sa[i] = sa[i+1].max(a[i] + i as i64);
    }
    let mut res = i64::MAX;
    for i in 0..n {
        res = res.min(a[i].max((pa[i] + n as i64 + 1).max(sa[i+1])));
    }
    println!("{res}");
}