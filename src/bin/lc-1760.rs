struct Solution;

impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();
        while l != r {
            let mid = l + r >> 1;
            eprint!("{:?} ", mid);
            let mut cnt = 0;
            for &x in nums.iter() {
                cnt += (x - 1) / mid;
            }
            eprintln!("{:?}", cnt);
            if cnt > max_operations {
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
    let max_operations: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::minimum_size(nums, max_operations));
}