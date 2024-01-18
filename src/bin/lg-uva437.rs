use std::collections::VecDeque;

fn solve(mut boxes: Vec<Vec<i64>>) -> i64 {
    let m = boxes.len();
    let n = m * 3;
    for i in 0..m {
        let curr = boxes[i].to_owned();
        boxes.push(vec![curr[0], curr[2], curr[1]]);
        boxes.push(vec![curr[1], curr[2], curr[0]]);
    }
    let mut ch = vec![vec![];n];
    let mut ind = vec![0;n];
    let is_fit = |x: &Vec<i64>, y: &Vec<i64>| {
        x[0] < y[0] && x[1] < y[1] || x[0] < y[1] && x[1] < y[0]
    };
    for i in 0..n {
        for j in 0..n {
            if is_fit(&boxes[j], &boxes[i]) {
                ch[i].push(j);
                ind[j] += 1;
            }
        }
    }
    let mut res = 0;
    let mut dq = VecDeque::new();
    let mut dp = vec![0;n];
    for i in 0..n {
        if ind[i] == 0 {
            dq.push_back(i);
        }
    }
    while let Some(i) = dq.pop_front() {
        dp[i] += boxes[i][2];
        res = res.max(dp[i]);
        for &j in &ch[i] {
            dp[j] = dp[j].max(dp[i]);
            ind[j] -= 1;
            if ind[j] == 0 {
                dq.push_back(j);
            }
        }
    }
    res
}

fn main() {
    let mut i = 0;
    loop {
        i += 1;
        let mut buf = String::new();
        std::io::stdin().read_line(&mut buf).ok();
        let n: usize = buf.trim().parse::<usize>().unwrap();
        if n == 0 {
            break;
        }
        let mut boxes = Vec::with_capacity(n);
        for _ in 0..n {
            buf.clear();
            std::io::stdin().read_line(&mut buf).ok();
            let v: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
            boxes.push(v);
        }
        println!("Case {i}: maximum height = {}", solve(boxes));
    }
}