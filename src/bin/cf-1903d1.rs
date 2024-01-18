fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let nq: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
    let (n, q) = (nq[0], nq[1]);
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
    for _ in 0..q {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut k: i64 = buf.trim().parse::<i64>().unwrap();
        let mut a = a.to_owned();
        let mut pow = 59;
        let mut res = 0;
        while pow >= 0 {
            let target = 1 << pow;
            let mut need = 0;
            let mut f = true;
            for i in 0..n {
                let curr = 0.max(target - a[i]);
                if curr > k - need {
                    f = false;
                    break;
                }
                need += 0.max(target - a[i]);
            }
            if f {
                for i in 0..n {
                    a[i] = a[i].max(target) - target;
                }
                k -= need;
                res += target;
            } else {
                for i in 0..n {
                    if a[i] >= target {
                        a[i] -= target;
                    }
                }
            }
            pow -= 1;
        }
        println!("{res}");
    }
}