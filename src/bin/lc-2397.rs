struct Solution;

#[inline]
fn bit(x: i32, b: usize) -> i32 {
    (x >> b) & 1
}

impl Solution {
    pub fn maximum_rows(matrix: Vec<Vec<i32>>, num_select: i32) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        // 枚举选择的列
        let mut res = 0;
        for choice in 0..1<<n {
            if choice.count_ones() != num_select {
                continue;
            }
            let mut cnt = 0;
            for i in 0..m {
                let mut f = true;
                for j in 0..n {
                    if matrix[i][j] == 1 && bit(choice, j) == 0 {
                        f = false;
                        break;
                    }
                }
                if f {
                    cnt += 1;
                }
            }
            res = res.max(cnt);
        }
        res
    }
}

fn main() {
    let mut buf = String::new();

}