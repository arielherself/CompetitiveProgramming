/// 状压dp
/// 状态c表示c的每一位1对应的饼干包都已经被分发
/// dp[i][j] 表示分给前 i 个人，状态为 j 时每个人获得的最大饼干数量。
/// 新的状态中，考虑是否有新的人出现。如果有新的人出现，那么枚举他分到了哪些饼干
/// dp[i][j] = min(max(dp[i-1][j^t],cookies_sum[t]))，其中t|j==j
struct Solution;

impl Solution {
    pub fn distribute_cookies(cookies: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let n = cookies.len();
        let mut cookies_sum = vec![0;1<<n];
        let mut dp = vec![vec![i32::MAX;1<<n];k+1];
        for j in 1..1<<n {
            for i in 0..n {
                if (j >> i) & 1 == 1 {
                    cookies_sum[j] += cookies[i];
                }
            }
        }
        dp[0][0] = 0;
        for i in 1..=k {
            dp[i][0] = 0;
            for j in 1..1<<n {
                let mut t = j;
                loop {
                    dp[i][j] = dp[i][j].min(dp[i-1][j^t].max(cookies_sum[t]));
                    if t == 0 {
                        break;
                    }
                    t = (t - 1) & j;
                }
            }
        }
        dp[k][(1<<n)-1]
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let cookies: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::distribute_cookies(cookies, k));
}