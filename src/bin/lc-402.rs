use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        use std::collections::VecDeque;;
        let num = num.into_bytes();  // TODO
        let mut st = VecDeque::<u8>::new();
        let mut cnt = 0;
        for x in num {
            while let Some(&y) = st.back() {
                if x >= y || cnt == k { break; }
                st.pop_back();
                cnt += 1;
            }
            st.push_back(x);
        }
        for _ in cnt..k {
            st.pop_back();
        }
        while let Some(48) = st.front() {
            st.pop_front();
        }
        if st.is_empty() { st.push_back(48); }
        String::from_utf8(st.into_iter().collect::<Vec<u8>>()).unwrap()
    }
}

fn main() {
    let num = "1432219".to_string();
    let k = 3;
    println!("{}",Solution::remove_kdigits(num,k));
}