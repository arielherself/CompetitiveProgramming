use std::collections::HashSet;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let n: usize = buf.trim().parse::<usize>().unwrap();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        let mut x = vec![0;n+1];
        let mut y = vec![0;n+1];
        for i in 1..=n {
            x[i] = x[i-1];
            y[i] = y[i-1];
            if i & 1 == 0 {
                x[i] += a[i-1];
            } else {
                y[i] += a[i-1];
            }
        }
        let mut oc = HashSet::new();
        let mut f = true;
        for i in 0..=n {
            if oc.contains(&(x[i] - y[i])) {
                println!("YES");
                f = false;
                break;
            } else {
                oc.insert(x[i] - y[i]);
            }
        }
        if f {
            println!("NO");
        }
    }
}