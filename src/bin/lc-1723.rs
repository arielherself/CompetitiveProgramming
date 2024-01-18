struct Solution;

struct Sol {
    jobs: Vec<i32>,
    k: i32,
    n: usize,
    tm: Vec<i32>,
}

impl Sol {
    fn init(&mut self, i: usize, curr_st: usize, curr_tm: i32) {
        if i == self.n {
            self.tm[curr_st] = curr_tm;
            return;
        }
        self.init(i + 1, curr_st, curr_tm);
        self.init(i + 1, curr_st | 1 << i, curr_tm + self.jobs[i]);
    }
    fn dfs(&mut self, i: usize, cnt: i32, curr_st: usize, curr_tm: i32, tm_res: i32) -> bool {
        // eprintln!("{} {} {:#b} {}", i, cnt, curr_st, curr_tm);
        if cnt == self.k {
            return curr_st + 1 == 1 << self.n;
        }
        if i == self.tm.len() {
            return false;
        }
        self.dfs(i + 1, cnt, curr_st, curr_tm, tm_res) ||
        if curr_st & i == 0 && self.tm[i] <= tm_res {
            self.dfs(i + 1, cnt + 1, curr_st | i, curr_tm.max(self.tm[i]), tm_res)
        } else {false}
    }
    fn solve(&mut self) -> i32 {
        self.init(0, 0, 0);
        let mut l = *self.jobs.iter().min().unwrap();;
        let mut r = self.jobs.iter().sum::<i32>();
        while l < r {
            let mid = l + r >> 1;
            if self.dfs(0, 0, 0, 0, mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}

impl Solution {
    pub fn minimum_time_required(jobs: Vec<i32>, k: i32) -> i32 {
        let n = jobs.len();
        let mut sol = Sol {jobs, k, n, tm: vec![0;1<<n]};
        sol.solve()
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let jobs: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::minimum_time_required(jobs, k));
}