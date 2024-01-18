fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let mut a: Vec<u64> = buf.trim().split(' ').map(|x|x.parse::<u64>().unwrap()).collect::<Vec<u64>>();
        let mut mdl = 2u64;
        loop {
            let mut one = false;
            let mut zero = false;
            for x in &mut a {
                if *x & 1 == 0 {
                    zero = true;
                } else {
                    one = true;
                }
                *x >>= 1;
            }
            if zero && one {
                println!("{mdl}");
                break;
            }
            mdl <<= 1;
        }
    }
}