struct Solution;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut st = vec![];
        let s = s.into_bytes();
        let mut res = 0;
        for (i, &x) in s.iter().enumerate() {
            if x == 41 && matches!(st.last(), Some(j) if s[j - 1] == 40) {
                st.pop();
                res = res.max(i + 1 - st.last().unwrap_or(&0));
            } else {
                st.push(i + 1);
            }
        }
        res as i32
    }
}

fn main() {}