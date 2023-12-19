struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        use std::cmp::max;
        let n = s.len();
        let mut res = (0,0);
        let mut mx = 0;
        let mut dp=vec![vec![false;n];n];
        let ss = s.into_bytes();
        for i in (0..n).rev() {
            for j in i..n {
                let &c = &ss[i];
                let &d = &ss[j];
                if j == i {
                    dp[i][j] = true;
                } else if j == i + 1 {
                    dp[i][j] = c==d;
                } else {
                    dp[i][j] = dp[i+1][j-1] && c==d;
                }
                if dp[i][j] && (j-i+1 > mx) {
                    mx = max(mx,j-i+1);
                    res = (i,j);
                }
            }
        }
        let (i,j) = res;
        String::from_utf8(ss[i..=j].to_owned()).unwrap()
    }
}

fn main() {
    let s = String::from("babad");
    println!("{}",Solution::longest_palindrome(s));
}