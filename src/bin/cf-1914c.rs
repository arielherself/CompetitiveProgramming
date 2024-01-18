fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let nk: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let (n, k) = (nk[0], nk[1]);
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let b: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        let mut res = 0;
        let mut a_sum = 0;
        let mut b_max = 0;
        for i in 0..n.min(k) {
            a_sum += a[i];
            b_max = b_max.max(b[i]);
            res = res.max(a_sum + b_max * (k - i - 1) as i64);
        }
        println!("{res}");
    }
}