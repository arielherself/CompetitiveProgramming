struct Item {
    time: i64,
    value: i64,
    cost: f64
}

impl Item {
    fn new(time: i64, value: i64) -> Self {
        Item { time, value, cost : value as f64 / time as f64 }
    }
}

struct Sol {
    a: Vec<Item>,
    tt: i64,
    m: usize,
    res: i64
}

impl Sol {
    fn estimate(&self, mut curr_t: i64, next_idx: usize) -> f64 {
        let mut res = 0.;
        for i in next_idx..self.m {
            if self.a[i].time + curr_t > self.tt {
                return res + (self.tt - curr_t) as f64 * self.a[i].cost;
            }
            curr_t += self.a[i].time;
            res += self.a[i].value as f64;
        }
        res
    }
    fn dfs(&mut self, curr_t: i64, idx: usize, curr_v: i64) {
        self.res = self.res.max(curr_v);
        if idx == self.m {
            return;
        }
        if curr_t + self.a[idx].time <= self.tt {
            self.dfs(curr_t + self.a[idx].time, idx + 1, curr_v + self.a[idx].value);
        }
        if curr_v + self.estimate(curr_t, idx + 1).ceil() as i64 > self.res {
            self.dfs(curr_t, idx + 1, curr_v);
        }
    }
    fn solve(&mut self) -> i64 {
        self.dfs(0, 0, 0);
        self.res
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let tm: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
    let (tt, m) = (tm[0], tm[1]);
    let mut a = Vec::<Item>::with_capacity(m as usize);
    for _ in 0..m {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut iter = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap());
        a.push(Item::new(iter.next().unwrap(), iter.next().unwrap()));
    }
    a.sort_unstable_by(|x,y|y.cost.total_cmp(&x.cost));
    let mut sol = Sol { a, tt, m: m as usize, res: 0 };
    println!("{}", sol.solve());
}