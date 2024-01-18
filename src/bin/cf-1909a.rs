fn judge(x: Vec<Vec<i32>>) -> bool {
    let a = x.iter().fold(true, |b, p|{
        b && p[0] <= 0
    });
    let b = x.iter().fold(true, |b, p|{
        b && p[1] <= 0
    });
    let c = x.iter().fold(true, |b, p|{
        b && p[0] >= 0
    });
    let d = x.iter().fold(true, |b, p|{
        b && p[1] >= 0
    });
    a || b || c || d
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let n: usize = buf.trim().parse::<usize>().unwrap();
        let mut co = Vec::with_capacity(n);
        for _ in 0..n {
            buf.clear();
            std::io::stdin().read_line(&mut buf).ok();
            let tmp: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
            co.push(tmp);
        }
        if judge(co) {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}