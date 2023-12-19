use std::io::stdin;
use std::collections::VecDeque;

fn calc_sum(n:i32,k:i32) -> i64 {
    n as i64 * k as i64 - (k as i64 - 1)* k as i64 / 2
}

fn lower_bound(n:i32,x:i64) -> (i32,i64) {
    let mut l = 0;
    let mut r = n;
    while l != r {
        let mid = l + r + 1 >> 1;
        if calc_sum(n,mid) >= x {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    (l, x-calc_sum(n,l))
}

fn solve() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).ok();
    let at = buf.to_owned();
    let a = at.trim().as_bytes();
    let n = a.len();
    let mut ena = vec![true;n];
    let mut cnt = 0;
    let mut st:VecDeque<usize> = VecDeque::new();
    buf.clear();
    stdin().read_line(&mut buf).ok();
    let pos:i64 = buf.trim().parse().unwrap();
    let (prev, diff) = lower_bound(n as i32,pos);
    // println!("{prev} {diff}");
    for (i,&c) in a.iter().enumerate() {
        if cnt == prev{
            break;
        }
        while let Some(&j) = st.back() {
            if a[j] <= c {
                break;
            }
            cnt += 1;
            ena[j] = false;
            if cnt == prev {
                break;
            }
            st.pop_back();
        }
        st.push_back(i);
    }
        for i in (0..n).rev() {
            if cnt == prev {
                break;
            }
            if ena[i] {
                ena[i] = false;
                cnt+=1;
            }
        }
    let mut p = 0;
    for (i,&c) in a.iter().enumerate() {
        if ena[i] {
            p += 1;
            if p == diff {
                print!("{}",c as char);
                return;
            }
        }
    }
}

fn main() {
    let mut buf = String::new();
    stdin().read_line(&mut buf).ok();
    let t:i32 = buf.trim().parse().unwrap();
    for _ in 0..t {
        solve();
    }
}