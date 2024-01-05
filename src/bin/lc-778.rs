struct Solution;

struct QU(Vec<usize>);

impl QU {
    fn query(&mut self, i: usize) -> usize {
        if self.0[i] != i {
            self.0[i] = self.query(self.0[i]);
        }
        self.0[i]
    }
    fn merge(&mut self, i: usize, j: usize) {
        let t = self.query(i);
        self.0[t] = self.query(j);
    }
}

impl Solution {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let n2 = n * n;
        let mut l = 0;
        let mut r = n2 as i32;
        while l < r {
            let mid = l + r >> 1;
            let mut qu = QU((0..n2).collect());
            for i in 0..n {
                for j in 0..n {
                    if grid[i][j] > mid { continue; }
                    if i + 1 != n && grid[i+1][j] <= mid {
                        qu.merge(i*n+j, (i+1)*n+j);
                    }
                    if j + 1 != n && grid[i][j+1] <= mid {
                        qu.merge(i*n+j, i*n+j+1);
                    }
                }
            }
            if qu.query(0) != qu.query(n2-1) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let n: usize = buf.trim().parse::<usize>().unwrap();
    let mut grid = vec![];
    for i in 0..n {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let line: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        grid[i] = line;
    }
    println!("{}", Solution::swim_in_water(grid));
}