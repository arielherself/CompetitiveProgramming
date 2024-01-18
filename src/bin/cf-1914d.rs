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
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let b: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let c: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        let mut dp = vec![vec![i64::MIN;8];n+1];
        for i in 1..=n {
            dp[i][0b001] = dp[i-1][0b001].max(c[i-1]);
            dp[i][0b010] = dp[i-1][0b010].max(b[i-1]);
            dp[i][0b100] = dp[i-1][0b100].max(a[i-1]);
            dp[i][0b011] = dp[i-1][0b011].max(dp[i-1][0b001] + b[i-1]).max(dp[i-1][0b010] + c[i-1]);
            dp[i][0b101] = dp[i-1][0b101].max(dp[i-1][0b001] + a[i-1]).max(dp[i-1][0b100] + c[i-1]);
            dp[i][0b110] = dp[i-1][0b110].max(dp[i-1][0b010] + a[i-1]).max(dp[i-1][0b100] + b[i-1]);
            dp[i][0b111] = dp[i-1][0b111].max(dp[i-1][0b110] + c[i-1]).max(dp[i-1][0b101] + b[i-1]).max(dp[i-1][0b011] + a[i-1]);
        }
        println!("{}", dp[n][0b111]);
    }
}