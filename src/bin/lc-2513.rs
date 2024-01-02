struct Solution;

impl Solution {
    pub fn minimize_set(divisor1: i32, divisor2: i32, unique_cnt1: i32, unique_cnt2: i32) -> i32 {
        let divisor1 = divisor1 as i64;
        let divisor2 = divisor2 as i64;
        let unique_cnt1 = unique_cnt1 as i64;
        let unique_cnt2 = unique_cnt2 as i64;
        let gcd = |mut x: i64, mut y: i64|{
            while y != 0 {
                (x, y) = (y, x % y);
            }
            x
        };
        let mut l = 1;
        let mut r = i64::MAX;
        let lcm = divisor1 * divisor2 / gcd(divisor1, divisor2);
        while l != r {
            let mid = l + (r - l >> 1);  // mid == 11
            let a = mid / divisor1;  // a == 5
            let b = mid / divisor2;  // b == 2, c == 2
            let c = mid / lcm;       // c == 3
            let o = mid - a - b + c; // o == 6
            eprintln!("mid = {mid}, a = {a}, b = {b}, c = {c}, o = {o}");
            if b - c + o < unique_cnt1 || a - c + o - 0.max(unique_cnt1 - b + c) < unique_cnt2 {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l as i32
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let divisor1: i32 = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let divisor2: i32 = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let unique_cnt1: i32 = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let unique_cnt2: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::minimize_set(divisor1, divisor2, unique_cnt1, unique_cnt2));

}