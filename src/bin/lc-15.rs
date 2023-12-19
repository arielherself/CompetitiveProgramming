struct Solution;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut a = nums.to_owned();
        a.sort();
        let n = a.len();
        let mut res:Vec<Vec<i32>> = vec![];
        for i in 0..n-2 {
            if i>0 && a[i]==a[i-1] { continue; }
            let mut l = i + 1;
            let mut r = n - 1;
            while l < r {
                if a[l] + a[r] == -a[i] {
                    res.push(vec![a[i],a[l],a[r]]);
                }
                if a[l] + a[r] < -a[i] {
                    while l < r {
                        l += 1;
                        if a[l] != a[l-1] { break; }
                    }
                } else {
                    while l < r {
                        r -= 1;
                        if a[r] != a[r+1] { break; }
                    }
                }
            }
        }
        res
    }
}

fn main() {
    let nums = vec![-1,0,1,2,-1,-4];
    let res = Solution::three_sum(nums);
    for x in res {
        for y in x {
            println!("{y} ");
        }
        println!();
    }
}