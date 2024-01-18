fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let t: usize = buf.trim().parse::<usize>().unwrap();
    let mut curr = vec![0;1000];
    let mut tmp = vec![0;1000];
    for _ in 0..t {
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let nxz: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        let (n, x, z) = (nxz[0], nxz[1], nxz[2]);
        buf.clear();
        std::io::stdin().read_line(&mut buf).ok();
        let a: Vec<usize> = buf.trim().split(' ').map(|x|x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
        curr.fill(usize::MAX);
        curr[z%x] = z;
        let mut res = usize::MAX;
        for &i in &a {
            for j in 0..x {
                tmp[j] = curr[j];
            }
            for j in 0..x {
                if tmp[j] != usize::MAX {
                    curr[(j + i) % x] = curr[(j + i) % x].min(tmp[j] + i);
                    if (tmp[j] + i) % x == 0 {
                        res = res.min(curr[0] / x);
                    }
                }
            }
        }
        if res != usize::MAX {
            println!("{res}");
        } else {
            println!("-1");
        }
    }
}