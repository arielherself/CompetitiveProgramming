struct Solution;

impl Solution {
    pub fn product_except_self(a: Vec<i32>) -> Vec<i32> {
        let n = a.len();
        let mut pa = vec![1;n+1];
        for i in 1..=n {
            pa[i] = pa[i-1] * a[i-1];
        }
        let mut sa = vec![1;n+1];
        for i in (0..n).rev() {
            sa[i] = sa[i+1] * a[i];
        }
        let mut res = vec![];
        for i in 0..n {
            res.push(sa[i+1]*pa[i]);
        }
        res
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let a: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    println!("{:?}", Solution::product_except_self(a));
}