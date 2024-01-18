fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect();
        let mut odd = 0;
        let mut even = 0;
        let mut sum = 0;
        for x in a {
            sum += x;
            if x & 1 == 1 {
                odd += 1;
            } else {
                even += 1;
            }
            if odd + even == 1 {
                print!("{x} ");
            } else if odd + even == 2 {
                if odd == 1 && even == 1 {
                    print!("{} ", sum - 1);
                } else {
                    print!("{} ", sum);
                }
            } else {
                let mut res = sum;
                res -= odd / 3;
                if odd % 3 == 1 {
                    print!("{} ", res - 1);
                } else {
                    print!("{} ", res);
                }
            }
        }
        println!();
    }
}