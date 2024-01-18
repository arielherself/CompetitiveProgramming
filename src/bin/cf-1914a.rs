use std::collections::HashMap;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let t: String = buf.trim().parse::<String>().unwrap();
        let a = t.into_bytes();
        let mut mp = HashMap::<u8, usize>::new();
        let mut cnt = 0;
        for x in a {
            *mp.entry(x).or_default() += 1;
            if matches!(mp.get(&x), Some(&t) if t + 64 == x as usize) {
                cnt += 1;
            }
        }
        println!("{cnt}");
    }
}