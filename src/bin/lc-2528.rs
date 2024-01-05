struct Solution;

impl Solution {
    pub fn max_power(stations: Vec<i32>, r: i32, k: i32) -> i64 {
        let n = stations.len();
        let r = r as usize;
        let mut left = 0;
        let mut right = stations.iter().fold(0i64, |s, &x|s+x as i64) + k as i64;
        while left <  right{
            let mid = left + right + 1 >> 1;
            let mut cnt = 0i64;
            let mut extra = vec![0;n];
            for i in 0..r {
                cnt += stations[i] as i64;
            }
            for i in 0..n {
                // eprintln!("mid = {mid}, cnt = {cnt}");
                if i + r < n {
                    cnt += stations[i+r] as i64 + extra[i+r];
                }
                if i > r {
                    cnt -= stations[i-r-1] as i64 + extra[i-r-1];
                }
                if cnt < mid {
                    let pos = (i + r).min(n - 1);
                    extra[pos] += mid - cnt;
                    cnt += mid - cnt;
                }
            }
            if extra.iter().sum::<i64>() > k as i64 {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        left
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let stations: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let r: i32 = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::max_power(stations, r, k));
}