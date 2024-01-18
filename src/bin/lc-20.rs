struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let s = s.into_bytes();
        let mut st = vec![];
        for x in s {
            if matches!(st.last(), Some(y) if x - y == 2 || x - y == 1) {
                st.pop();
            } else {
                st.push(x);
            }
        }
        st.is_empty()
    }
}

fn main() {
    
}