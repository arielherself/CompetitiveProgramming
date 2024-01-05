struct Solution;

impl Solution {
    pub fn maximum_tastiness(mut price: Vec<i32>, k: i32) -> i32 {
        price.sort_unstable();
        let mut l = 0;
        let mut r = price.last().unwrap() - price.first().unwrap();
        while l < r {
            let mid = l + r + 1 >> 1;
            let mut fm = -mid;
            let mut cnt = 0;
            for &x in price.iter() {
                if x - fm >= mid {
                    cnt += 1;
                    fm = x;
                }
            }
            if cnt < k {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        l
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let price: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::maximum_tastiness(price, k));
}