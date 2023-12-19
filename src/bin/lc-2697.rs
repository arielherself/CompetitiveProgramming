struct Solution {}

impl Solution {
    pub fn make_smallest_palindrome(s: String) -> String {
        let n = s.len();
        let r = n >> 1;
        let mut ss = s.into_bytes();
        for i in 0..r {
            if ss[i] > ss[n - 1 - i] {
                ss[i] = ss[n-1-i];
            } else {
                ss[n-1-i] = ss[i];
            }
        }
        String::from_utf8(ss).unwrap()
    }
}

fn main() {
    let s = "atie".to_string();
    println!("{}",Solution::make_smallest_palindrome(s));
}