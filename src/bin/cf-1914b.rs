fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let t: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let (n, k) = (t[0], t[1]);
        for i in 1..=k {
            print!("{i} ");
        }
        for i in (k+1..=n).rev() {
            print!("{i} ");
        }
        println!();
    }
}