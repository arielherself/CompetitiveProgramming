/**
 * 如果有负数，那么就不需要变，因为现在已经是最小的了
 * 如果没负数，至多需要把随便一个数变成0即可。
 */


fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        let mut f = true;
        let mut sgn = 1;
        for x in a {
            sgn *= x.signum();
            if x == 0 {
                println!("0");
                f = false;
                break;
            }
        }
        if f {
            if sgn == 1 {
                println!("1\n1 0");
            } else {
                println!("0");
            }
        }
    }
}