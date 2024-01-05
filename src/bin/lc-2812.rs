struct Solution;

struct QU {
    pa: Vec<usize>
}

impl QU {
    fn query(&mut self, i: usize) -> usize {
        if self.pa[i] != i {
            self.pa[i] = self.query(self.pa[i]);
        }
        self.pa[i]
    }
    fn merge(&mut self, i: usize, j: usize) {
        let qi = self.query(i);
        let qj = self.query(j);
        self.pa[qi] = qj;
    }
}

impl Solution {
    pub fn maximum_safeness_factor(grid: Vec<Vec<i32>>) -> i32 {
        use std::collections::VecDeque;
        let n = grid.len();
        let mut dis = vec![vec![0;n];n];
        let mut dq = VecDeque::new();
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    dq.push_back([0,i,j]);
                }
            }
        }
        // 0-1 bfs
        let mut vis = vec![vec![false;n];n];
        while let Some([d,i,j]) = dq.pop_front() {
            if vis[i][j] { continue; }
            vis[i][j] = true;
            dis[i][j] = d;
            if j + 1 != n {
                dq.push_back([d+1,i,j+1]);
            }
            if j != 0 {
                dq.push_back([d+1,i,j-1]);
            }
            if i + 1 != n {
                dq.push_back([d+1,i+1,j]);
            }
            if i != 0 {
                dq.push_back([d+1,i-1,j]);
            }
        }
        // binary search
        let mut l = 0;
        let mut r = n << 1;
        let n2 = n * n;
        while l != r {
            let mid = l + r + 1 >> 1;
            let mut qu = QU{pa: (0..n2).collect()};
            for i in 0..n {
                for j in 0..n {
                    if dis[i][j] < mid { continue; }
                    if i + 1 != n && dis[i+1][j] >= mid {
                        qu.merge(i*n+j, (i+1)*n+j);
                    }
                    if j + 1 != n && dis[i][j+1] >= mid {
                        qu.merge(i*n+j, i*n+j+1);
                    }
                }
            }
            if qu.query(0) != qu.query(n*n-1) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        if l == n << 1 {
            0
        } else {
            l as i32
        }
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let n: usize = buf.trim().parse::<usize>().unwrap();
    let mut grid = vec![vec![];n];
    for i in 0..n {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let line: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        grid[i] = line;
    }
    println!("{}", Solution::maximum_safeness_factor(grid));
}