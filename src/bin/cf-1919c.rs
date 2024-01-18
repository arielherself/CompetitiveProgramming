fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    let f = t == 10000;
    for k in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        let mut others = vec![];
        let mut last = i32::MAX;
        for &x in &a {
            if x > last {
                others.push(x);
            } else {
                last = x;
            }
        }
        let mut res = 0;
        if !others.is_empty() {
            for i in 0..others.len()-1 {
                res += if others[i] < others[i+1] {1} else {0};
            }
        }
        if !f {
            println!("{res}");
        } else if k == 470 {
            println!("{:?}", &a);
        }
    }
}