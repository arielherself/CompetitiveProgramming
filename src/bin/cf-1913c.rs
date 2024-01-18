fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let m: usize = buf.trim().parse::<usize>().unwrap();
    let mut cnt = vec![0;30];
    for _ in 0..m {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let query: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        let (t, mut v) = (query[0], query[1]);
        if t == 1 {
            cnt[query[1] as usize] += 1;
        } else {
            let mut f = true;
            let mut ccnt = 0;
            let mut i = 0;
            while v != 0 {
                ccnt = (ccnt >> 1) + cnt[i];
                let curr_bit = v & 1;
                v >>= 1;
                if curr_bit == 1 {
                    if ccnt == 0 {
                        f = false;
                        break;
                    }
                    ccnt -= 1;
                }
                i += 1;
            }
            if f {
                println!("YES");
            } else {
                println!("NO");
            }
        }
    }
}