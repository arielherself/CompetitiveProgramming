struct Solution;

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let n = haystack.len();
        let m = needle.len();
        let haystack = haystack.into_bytes();
        let needle = needle.into_bytes();
        let mut next = vec![-1;m];
        let mut j = -1;
        let mut i = 0;
        while i + 1 < m as i32 {
            if j == -1 || needle[i as usize] == needle[j as usize] {
                i += 1;
                j += 1;
                next[i as usize] = j;
            } else {
                j = next[j as usize];
            }
        }
        eprintln!("{:?}", next);
        i = 0;  // haystack
        j = 0;  // needle
        while i < n as i32 {
            if j == -1 || haystack[i as usize] == needle[j as usize] {
                i += 1;
                j += 1;
            } else {
                j = next[j as usize];
            }
            if j == m as i32 {
                return i - m as i32;
            }
        }
        -1
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let haystack: String = buf.trim().parse::<String>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let needle: String = buf.trim().parse::<String>().unwrap();
    println!("{}", Solution::str_str(haystack, needle));
}