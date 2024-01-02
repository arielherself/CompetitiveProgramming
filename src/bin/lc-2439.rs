struct Solution;

impl Solution {
    pub fn minimize_array_value(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = *nums.iter().max().unwrap();
        while l != r {
            let mid = l + r >> 1;
            let mut ac = 0i64;
            for &x in nums.iter().rev() {
                ac = 0.max(x as i64 + ac - mid as i64);
            }
            if ac > 0 {
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
    println!("{}", Solution::minimize_array_value(nums));
}