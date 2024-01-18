struct Solution;

struct Sol;

impl Sol {
    fn solve(mut x: i64, limit: i64, mut s: i64) -> i64 {
        let mut pow = vec![1i64;17];
        for i in 1..17 {
            pow[i] = pow[i-1] * 10;
        }
        let mut cnt = vec![0;17];
        let m = s;
        let mut s_len = 0;
        while s != 0 {
            s_len += 1;
            s /= 10;
        }
        let pass = m <= x % pow[s_len];
        let mut x_len = 0;
        let mut x_digit = vec![];
        x_digit.push(0);
        while x != 0 {
            x_len += 1;
            x_digit.push(x % 10);
            x /= 10;
        }
        if s_len > x_len {
            return 0;
        }
        for i in 1..=x_len {
            if i <= s_len {
                cnt[i] = 1;
            } else {
                cnt[i] = cnt[i-1] * (limit + 1);
            }
        }
        let mut res = 0;
        let mut f = true;
        for i in (s_len+1..=x_len).rev() {
            res += cnt[i-1] * (limit.min(x_digit[i] - 1) + 1);
            if limit < x_digit[i] {
                f = false;
                break;
            }
        }
        if f && pass {
            res += 1;
        }
        res
    }
}

impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        let upper = Sol::solve(finish   , limit as i64, s.parse().unwrap());
        let lower = Sol::solve(start - 1, limit as i64, s.parse().unwrap());
        upper - lower
    }
}

fn main() {
    println!("{}", Solution::number_of_powerful_int(1, 1000000000000000, 4, "1".to_string()));
}