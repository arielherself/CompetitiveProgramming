struct Solution;

impl Solution {
    pub fn min_capability(nums: Vec<i32>, k: i32) -> i32 {
        let mut l = 0;
        let mut r = *nums.iter().max().unwrap();
        while l < r {
            let mid = l + r >> 1;
            let mut cnt1 = 0;
            let mut cnt2 = 0;
            for &x in &nums {
                let new = cnt2.max(cnt1 + if x <= mid {1} else {0});
                cnt1 = cnt2;
                cnt2 = new;
            }
            if cnt1.max(cnt2) < k {
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
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::min_capability(nums, k));
}