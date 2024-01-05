struct Solution;

impl Solution {
    pub fn max_number_of_alloys(n: i32, k: i32, budget: i32, composition: Vec<Vec<i32>>, stock: Vec<i32>, cost: Vec<i32>) -> i32 {
        let budget = budget as i64;
        let mut l = 0;
        let mut r = i32::MAX as i64;
        let types = stock.len();
        while l < r {
            let mid = l + (r - l + 1 >> 1);
            let mut viable = false;
            for line in &composition {
                let mut tot_cost = 0;
                for i in 0..types {
                    tot_cost += 0.max(mid * line[i] as i64 - stock[i] as i64) * cost[i] as i64;
                }
                if tot_cost <= budget {
                    viable = true;
                    break;
                }
            }
            if !viable {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        l as i32
    }
}

fn main() {
    
}