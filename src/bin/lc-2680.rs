struct Solution;

impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let k = k as i64;
        let mut pa = vec![0;n+1];
        for i in 1..=n {
            pa[i] = pa[i-1] | nums[i-1] as i64;
        }
        let mut sa = vec![0;n+1];
        for i in (0..n).rev() {
            sa[i] = sa[i+1] | nums[i] as i64;
        }
        (0..n).fold(0, |res, i|res.max((nums[i] as i64) <<k | pa[i] | sa[i+1]))
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let nums: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::maximum_or(nums, k));
}