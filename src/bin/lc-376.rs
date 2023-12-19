struct Solution;

impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        use std::collections::VecDeque;
        type pii = (i32,i32);
        let mut up:VecDeque<pii>   = VecDeque::new();
        let mut down:VecDeque<pii> = VecDeque::new();
        let mut up_max = 0;
        let mut down_max = 0;
        for x in nums {
            while let Some(&(y,_)) = up.back() {
                if y < x { break; }
                up.pop_back();
            }
            while let Some(&(y,_)) = down.back() {
                if y > x { break; }
                down.pop_back();
            }
            let mut u = 1;
            let mut d = 1;
            if let Some(&(_,l)) = up.back() {
                u = u.max(l+1);
            }
            if let Some(&(_,l)) = down.back() {
                d = d.max(l+1);
            }
            up_max = up_max.max(u);
            down_max = down_max.max(d);
            down.push_back((x,u));
            up.push_back((x,d));
        }
        up_max.max(down_max)
    }
}

fn main() {
    let nums = vec![1,7,4,9,2,5];
    let b = nums[1..2].iter().collect::<Vec<&i32>>();
    println!("{}",Solution::wiggle_max_length(nums));
}