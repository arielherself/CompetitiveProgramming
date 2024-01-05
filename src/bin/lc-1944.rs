struct Solution;

impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let mut st = vec![];
        let mut res = vec![];
        for &x in heights.iter().rev() {
            let mut cnt = 0;
            while let Some(&p) = st.last() {
                cnt += 1;
                if p > x { break; }
                st.pop();
            }
            st.push(x);
            res.push(cnt);
        }
        res.into_iter().rev().collect()
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let heights: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    println!("{:?}", Solution::can_see_persons_count(heights));
}