struct Solution;

impl Solution {
    pub fn min_operations_max_profit(customers: Vec<i32>, boarding_cost: i32, running_cost: i32) -> i32 {
        let delta = 4 * boarding_cost - running_cost;
        let mut max_tm = 0;
        let mut max_amount = 0;
        let mut curr_tm = 0;
        let mut curr_amount = 0;
        let mut cand_amount = 0;
        let mut ac = 0;
        for (i, &x) in customers.iter().enumerate() {
            let i = i as i32;
            if curr_tm < i {
                ac = 0;
                curr_tm = i;
                curr_amount = cand_amount - (i - curr_tm) * running_cost;
            }
            let x = x + ac;
            curr_amount += (x >> 2) * delta;
            curr_tm += x >> 2;
            if curr_amount > max_amount || curr_amount == max_amount && curr_tm < max_tm {
                max_tm = curr_tm;
                max_amount = curr_amount;
            }
            let residual = x - (x >> 2 << 2);
            ac = residual;
            let tmp = curr_amount + residual * boarding_cost - running_cost;
            cand_amount = tmp;
            if tmp > max_amount {
                max_tm = curr_tm + 1;
                max_amount = tmp;
            }
        }
        if max_amount <= 0 {
            -1
        } else {
            max_tm
        }
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let customers: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let boarding_cost: i32 = buf.trim().parse::<i32>().unwrap();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let running_cost: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::min_operations_max_profit(customers, boarding_cost, running_cost));
}