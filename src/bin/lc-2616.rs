struct Solution;

impl Solution {
    pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        let n = nums.len();
        nums.sort_unstable();
        let mut diff = vec![0;n-1];
        for i in 1..n {
            diff[i-1] = nums[i] - nums[i-1];
        }
        // eprintln!("{:?}", diff);
        let mut l = 0;
        let mut r = *nums.iter().max().unwrap() - *nums.iter().min().unwrap();
        while l < r {
            let mid = l + r >> 1;
            let mut dp1 = 0;
            let mut dp2 = 0;
            for &x in &diff {
                let new = dp2.max(dp1 + if x <= mid {1} else {0});
                dp1 = dp2;
                dp2 = new;
            }
            if dp2 < p {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let nums: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let p: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::minimize_max(nums, p));
}