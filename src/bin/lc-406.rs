struct Solution;

impl Solution {
    pub fn reconstruct_queue(mut people: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        people.sort_unstable_by(|x,y|{
            if x[0] == y[0] {
                x[1].cmp(&y[1])
            } else {
                y[0].cmp(&x[0])
            }
        });
        let n = people.len();
        let mut res = Vec::<Vec<i32>>::with_capacity(n);
        for curr in people {
            res.insert(curr[1] as usize, curr);
        }
        res
    }
}

fn main() {

}