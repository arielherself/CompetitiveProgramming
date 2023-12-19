struct Solution;

impl Solution {
    pub fn find_minimum_time(tasks: Vec<Vec<i32>>) -> i32 {
        use std::collections::BinaryHeap;
        use std::cmp::{min, max};
        let mut tasks = tasks.to_owned();
        tasks.sort();
        let mut cnt = 0;
        let mut res = 0;
        let mut pq:BinaryHeap<(i32,i32)> = BinaryHeap::new();
        for it in &tasks {
            let s = it[0];
            let e = it[1];
            let req = it[2];
            while let Some(&(pe,pc)) = pq.peek() {
                if -pe >= s {
                    pq.pop();
                    let new_pc = min(pc, - pe - s + 1);
                    pq.push((pe, new_pc));
                    cnt -= pc - new_pc;
                    break;
                }
                pq.pop();
                cnt -= pc;
            }
            let c = max(req - cnt, 0);
            cnt += c;
            res += c;
            pq.push((-e,c));
        }
        res
    }
}

fn main() {
    let tasks = vec![vec![2,3,1],vec![4,5,1],vec![1,5,2]];
    println!("{}",Solution::find_minimum_time(tasks));
}