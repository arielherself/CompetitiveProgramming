struct Solution;

impl Solution {
    pub fn maximum_candies(candies: Vec<i32>, k: i64) -> i32 {
        let check = |m: i32| {
            let mut cnt = 0;
            candies.iter().for_each(|&x|cnt += (x / m) as i64);
            cnt >= k
        };
        let mut l = 1;
        let mut r = *candies.iter().min().unwrap() ;
        while l != r {
            let mid = l + r + 1 >> 1;
            if !check(mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if check(l) {
            l
        } else {
            0
        }
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let candies: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i64 = buf.trim().parse::<i64>().unwrap();
    println!("{}",Solution::maximum_candies(candies, k));
}