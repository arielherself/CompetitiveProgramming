use std::collections::HashMap;

/**
 * dp[i] 表示进行i次删除首字母操作后得到的结果
 */

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
        let a = buf.trim().parse::<String>().unwrap().into_bytes();
        let mut res = 0;
        let mut mp = HashMap::new();
        let mut dp = vec![0;n+1];
        for i in (0..n).rev() {
            dp[i] = mp.get(&a[i]).unwrap_or(&n) - i;
            res += dp[i];
            mp.insert(a[i], i);
        }
        println!("{}", res);
    }
}