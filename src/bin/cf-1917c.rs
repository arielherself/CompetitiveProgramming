fn solve(a: Vec<i64>, v: Vec<usize>, start_date: usize, limit: i64) -> (usize, i64) {
    let n = a.len();
    let k = v.len();
    let mut delta_delta = vec![0i64;n+1];
    for i in 0..k {
        delta_delta[0] += 1;
        delta_delta[v[i]] -= 1;
    }
    let mut delta = vec![0;n];
    let mut t = 0;
    for i in 0..n {
        t += delta_delta[i];
        delta[i] = t;
    }
    let mut idx = n + 1;
    let mut raw = 0;
    for i in 0..n {
        if a[i] <= i as i64 + 1 && idx == n + 1 {
            idx = i;
        }
        if a[i] == i as i64 + 1 {
            raw += 1;
        }
    }
    if idx == n + 1  || delta[idx] == 0 {
        return (1, raw);
    }
    let full = (idx as i64 + 1 - a[idx]) / delta[idx];
    let mut res = full * k as i64;
    let mut rs = idx as i64 + 1 - (a[idx] + full * delta[idx]);
    eprintln!("idx={idx}, full={full}, res={res}, rs={rs}");
    let mut cf = vec![0;n+1];
    for t in 0..k {
        if rs == 0 {
            if res + 1 > limit {
                return if raw != 0 {
                    (1, raw)
                } else {
                    (usize::MAX, 0)
                };
            }
            let mut cnt = 0;
            let mut acc = 0;
            for i in 0..n {
                acc += cf[i];
                if a[i] + delta[i] * full + acc == i as i64 + 1 {
                    cnt += 1;
                }
            }
            return (res as usize + 1, cnt);
        }
        res += 1;
        cf[0] += 1;
        cf[v[(start_date+t)%k]] -= 1;
        if v[(start_date+t)%k] > idx {
            rs -= 1;
        }
    }
    panic!()
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let tmp: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let d = tmp[2];
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i64> = buf.trim().split(' ').map(|x|x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let v: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let (next_date, init_score) = solve(a, v, 0, d as i64);
        eprintln!("{next_date} {init_score}");
        if init_score == 0 || next_date > d {
            println!("{}", (d - 1) / 2);
        } else {
            println!("{}", init_score + (d - next_date) as i64 / 2);
        }
    }
}