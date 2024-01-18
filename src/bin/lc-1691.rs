struct Solution;

impl Solution {
    pub fn max_height(mut cuboids: Vec<Vec<i32>>) -> i32 {
        for x in cuboids.iter_mut() {
            x.sort_unstable_by_key(|x|-x);
        }
        cuboids.sort_unstable_by(|x, y| {
            if x[0] == y[0] {
                if x[1] == y[1] {
                    return y[2].cmp(&x[2]);
                }
                return y[1].cmp(&x[1]);
            }
            return y[0].cmp(&x[0]);
        });
        let n = cuboids.len();
        let if_fit = |x: &Vec<i32>, y: &Vec<i32>| {
            x[1] <= y[1] && x[2] <= y[2]
        };
        let mut dp = vec![0;n];
        let mut res = 0;
        for i in 0..n {
            for j in 0..i {
                if if_fit(&cuboids[i], &cuboids[j]) {
                    dp[i] = dp[i].max(dp[j]);
                }
            }
            dp[i] += cuboids[i][0];
            res = res.max(dp[i]);
        }
        res
    }
}

fn main() {

}