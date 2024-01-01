struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        use std::collections::HashMap;
        let mut s = s.into_bytes();
        let mut mp = HashMap::<u8,i32>::new();
        for i in s {
            if let Some(&v) = mp.get(&i) {
                mp.insert(i,v+1);
            }else{
                mp.insert(i,1);
            }
        }
        let mut res = 0;
        let mut f = 0;
        for (_,v) in mp {
            if v & 1 != 0 { f = 1; }
            res += v >> 1;
        }
        res + f
    }
}

fn main() {

}