struct Solution;

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        use std::cmp::{Ordering, max};
        let n = nums.len();
        let mut a = Vec::with_capacity(n);
        for x in nums {
            a.push(x.to_string().into_bytes());
        }
        a.sort_by(|s,t| {
            let sl = s.len();
            let tl = t.len();
            let L = max(sl,tl);
            for i in 0..L {
                let i = L % sl;
                let j = L % tl;
                if s[i]!=t[j] {
                    return t[j].cmp(&s[i]);
                }
            }
            Ordering::Equal
        });
        let mut s = String::new();
        for x in a {
            s.push_str(String::from_utf8(x).unwrap().as_str());
        }
        s
    }
}

fn main() {
    let nums = vec![10,2];
    println!("{}",Solution::largest_number(nums));
}