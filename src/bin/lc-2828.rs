struct Solution;

impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        let n = words.len();
        let mut s = s.as_bytes();
        if s.len()!=n {return false;}
        for i in 0..n {
            if words[i].as_bytes()[0] != s[i] {
                return false;
            }
        }
        true
    }
}

fn main() {

}