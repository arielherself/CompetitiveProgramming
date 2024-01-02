struct Solution;

impl Solution {
    pub fn intersection_size_two(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by(|x,y|
            if x[1] == y[1] {
                y[0].cmp(&x[0])
            } else {
                x[1].cmp(&y[1])
            }
        );
        let mut t1 = -1;
        let mut t2 = -1;
        let mut res = 0;
        for x in intervals {
            if x[0] > t2 {
                t1 = x[1] - 1;
                t2 = x[1];
                res += 2;
            } else if x[0] > t1 {
                t1 = t2;
                t2 = x[1];
                res += 1
            }
        }
        res
    }
}

fn main() {

}