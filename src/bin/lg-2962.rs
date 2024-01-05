use std::collections::HashMap;

struct Solution {
    n: usize,
    ch:Vec<Vec<usize>>,
    stat: HashMap<u64, u32>
}

impl Solution {
    fn dfs1(&mut self, curr: usize, switch: u64, status: u64) {
        if curr == self.n + 1 >> 1 {
            if let Some(&pr) = self.stat.get(&status) {
                self.stat.insert(status, switch.count_ones().min(pr));
            } else {
                self.stat.insert(status, switch.count_ones());
            }
            return;
        }
        let ch_cnt = self.ch[curr].len();
        let bit = 1 << curr;
        let switch1 = switch ^ bit;
        let mut status1 = status ^ bit;
        for i in 0..ch_cnt {
            let child = self.ch[curr][i];
            status1 ^= 1 << child;
        }
        self.dfs1(curr + 1, switch, status);
        self.dfs1(curr + 1, switch1, status1);
    }
    fn dfs2(&mut self, curr: usize, switch: u64, status: u64) -> u32 {
        if curr == self.n {
            return if let Some(&o) = self.stat.get(&(!status&((1<<self.n)-1))) {
                o + switch.count_ones()
            } else {
                u32::MAX
            };
        }
        let ch_cnt = self.ch[curr].len();
        let bit = 1 << curr;
        let switch1 = switch ^ bit;
        let mut status1 = status ^ bit;
        for i in 0..ch_cnt {
            let child = self.ch[curr][i];
            status1 ^= 1 << child;
        }
        self.dfs2(curr + 1, switch, status).min(self.dfs2(curr + 1, switch1, status1))
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let nm: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
    let (n, m) = (nm[0], nm[1]);
    let mut ch = vec![vec![];n];
    for _ in 0..m {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let uv: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let (u, v) = (uv[0], uv[1]);
        ch[u-1].push(v-1);
        ch[v-1].push(u-1);
    }
    let mut solution = Solution{n, ch, stat: HashMap::<u64, u32>::new()};
    solution.dfs1(0, 0, 0);
    println!("{}", solution.dfs2(n + 1 >> 1, 0, 0));
}