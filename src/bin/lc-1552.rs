use std::io::stdin;

struct Solution;

impl Solution {
    pub fn max_distance(mut position: Vec<i32>, m: i32) -> i32 {
        position.sort_unstable();
        let mut l = 0;
        let mut r = position.last().unwrap().to_owned() - position.first().unwrap().to_owned();
        while l != r {
            let mid = l + r + 1 >> 1;
            let mut prev = -mid;
            let mut cnt = 0;
            for &x in position.iter() {
                if x - prev < mid { continue; }
                cnt += 1;
                prev = x;
            }
            if cnt < m {
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
    stdin().read_line(&mut buf).ok();
    let position = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    stdin().read_line(&mut buf).ok();
    let m = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::max_distance(position, m));
}