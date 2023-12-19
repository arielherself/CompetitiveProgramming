struct Solution;

impl Solution {
    pub fn min_cost(nums: Vec<i32>, cost: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut idx = (0..n).collect::<Vec<usize>>();
        idx.sort_by(|&i,&j| nums[i].cmp(&nums[j]));
        let mut l = 0;
        let mut r = 0;
        cost.iter().for_each(|&x|r+=x as i64);
        let mut min_diff = (r - l).abs();
        let mut med = 0;
        for (t,&i) in idx.iter().enumerate() {
            r -= cost[i] as i64;
            l += cost[i] as i64;
            if (r - l).abs() < min_diff {
                min_diff = (r-l).abs();
                med = if r > l { nums[idx[t + 1]] } else { nums[i] };
            }
        }
        let mut res = 0;
        for i in 0..n {
            res += (nums[idx[i]] - med).abs() as i64 * cost[idx[i]] as i64;
        }
        res
    }
}

fn main() {
    let nums = vec![1,3,5,2];
    let cost = vec![2,3,1,14];
    println!("{}",Solution::min_cost(nums,cost));
}