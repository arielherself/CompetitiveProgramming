fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut n: i64 = buf.trim().parse::<i64>().unwrap();
        let mut res = 1;
        while n != 0 {
            let digit = n % 10;
            n /= 10;
            res *= (digit + 2) * (digit + 1) >> 1;
        }
        println!("{res}");
    }
}