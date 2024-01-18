struct Solution;

impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut s = s.into_bytes();
        let mut n = s.len();
        let mut f = true;
        while f && n != 0 {
            f = false;
            for i in 0..n-1 {
                if s[i] == 65 && s[i+1] == 66 || s[i] == 67 && s[i+1] == 68 {
                    s.remove(i);
                    s.remove(i);
                    n -= 2;
                    f = true;
                    break;
                }
            }
        }
        n as i32
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let s: String = buf.trim().parse::<String>().unwrap();
    println!("{}", Solution::min_length(s));
}