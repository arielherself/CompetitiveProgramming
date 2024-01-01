use std::cmp::Ordering;

struct Solution;

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        use std::collections::{BinaryHeap,HashSet};
        let mut pq = BinaryHeap::<(i32,usize,usize)>::new();
        pq.push((-nums1[0]-nums2[0],0,0));
        let m=nums1.len();
        let n = nums2.len();
        let mut vis = HashSet::<(usize,usize)>::new();
        let mut res = Vec::new();
        let mut cnt = 0;
        while let Some((_,i,j)) = pq.pop() {
            if vis.contains(&(i,j)) {continue;}
            vis.insert((i,j));
            res.push(vec![nums1[i],nums2[j]]);
            cnt += 1;
            if cnt == k as usize {break;}
            if i+1!=m {
                pq.push((-nums1[i+1]-nums2[j],i+1,j));
            }
            if j+1!=n {
                pq.push((-nums1[i]-nums2[j+1],i,j+1));
            }
        }
        res
    }
}

fn main() {

}