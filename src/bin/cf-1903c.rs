fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        let mut s: i64 = a.iter().sum();
        let mut curr_seg = 0;
        let mut curr_sum = 0;
        let mut res = 0;
        for x in a {
            curr_sum += x;
            s -= x;
            if s >= 0 {
                curr_seg += 1;
                res += curr_seg * curr_sum;
                curr_sum = 0;
            }
        }
        println!("{res}");
    }
}