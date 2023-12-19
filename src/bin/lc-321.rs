use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn max_number(a: Vec<i32>, b: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut i = 0; let n = a.len();
        let mut j = 0; let m = b.len();
        let mut st1 = Vec::new();
        let mut st2 = Vec::new();
        let mut cnt = 0;
        while i<n || j<m {
            if j==m || i<n && (a[i]>b[j] || j+1==m || i+1!=n && a[i+1]>b[j+1]) {
                while let Some(t) = st1.last() {
                    if cnt-1+n+m-i-j<k || &a[i]<=t {break;}
                    cnt -= 1;
                    st1.pop();
                }
                cnt+=1;
                st1.push(a[i]);
                i+=1;
            } else {
                while let Some(t) = st2.last() {
                    if cnt-1+n+m-i-j<k || &b[j]<=t {break;}
                    cnt -= 1;
                    st2.pop();
                }
                cnt+=1;
                st2.push(b[j]);
                j+=1;
            }
        }
        let mut res = Vec::with_capacity(k);
        i = 0;
        j = 0;
        while res.len()<k {
            if j == st2.len() {
                res.push(st1[i]);
                i += 1;
            } else if i == st1.len() {
                res.push(st2[j]);
                j += 1;
            } else {
                if st1[i] > st2[j] {
                    res.push(st1[i]);
                    i += 1;
                } else if st1[i] < st2[j] {
                    res.push(st2[j]);
                    j += 1;
                } else {
                    if i + 1 == st1.len() {
                        res.push(st2[j]);
                        j += 1;
                    } else if j + 1 == st2.len() {
                        res.push(st1[i]);
                        i += 1;
                    } else if st1[i+1]>st2[j+1] {
                        res.push(st1[i]);
                        i += 1;
                    } else {
                        res.push(st2[j]);
                        j += 1;
                    }
                }
            }
        }
        res
    }
}

fn main() {
    let nums1 = vec![3,9];
    let nums2 = vec![8,9];
    let k = 3;
    let res = Solution::max_number(nums1,nums2, k);
    for x in res {
        print!("{x} ");
    }
}