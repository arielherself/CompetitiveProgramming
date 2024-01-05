const N: i32 = 17;
const M: i32 = 17;
const SET_P: usize = 0;
const OFF_P: usize = 4;
const SIZE_P: usize = 1;
const OFFSET: i32 = 0;

struct Cache {
    tags: [i32;1<<SET_P],
    cnt: i32,
    tot: i32
}

#[derive(Debug)]
struct Addr {
    ct: i32,
    ci: i32,
    co: i32
}

fn get_addr(i: i32, j: i32, src: bool) -> Addr {
    let bin = OFFSET + (if src {i * M + j} else {(N + i) * M + j} << SIZE_P);
    Addr {
        ct: bin >> (SET_P + OFF_P),
        ci: (bin >> OFF_P) & ((1 << SET_P) - 1),
        co: bin & ((1 << OFF_P) - 1)
    }
}

fn get_src_addr(i: i32, j: i32) -> Addr {
    get_addr(i, j, true)
}

fn get_dst_addr(i: i32, j: i32) -> Addr {
    get_addr(i, j, false)
}

impl Cache {
    fn simulate(&mut self, addr: &Addr) -> bool {
        self.tot += 1;
        let tag = addr.ct;
        let idx = addr.ci;
        if tag != self.tags[idx as usize] {
            self.tags[idx as usize] = tag;
            self.cnt += 1;
            false
        } else {
            true
        }
    }
}

fn main() {
    let mut cache = Cache{ tags: [-1;1<<SET_P], cnt: 0, tot: 0 };
    let deb = 85;
    // for j in 0..M>>1 {
    //     for i in 0..N>>1 {
    //         let i = i << 1;
    //         let j = j << 1;
    //         let mut r = [false;4];
    //         r[0] = cache.simulate(&get_src_addr(i, j));
    //         r[1] = cache.simulate(&get_src_addr(i+1, j));
    //         r[2] = cache.simulate(&get_src_addr(i, j+1));
    //         r[3] = cache.simulate(&get_src_addr(i+1, j+1));
    //         if i == deb {
    //             println!("i = {i}, j = {j}, addr = {:?}, missed = {:?}", get_src_addr(i, j), r[0]);
    //             println!("i = {i}, j = {}, addr = {:?}, missed = {:?}", j+1, get_src_addr(i, j+1), r[2]);
    //         }
    //     }
    // }
    for j in 0..4 {
        for i in 0..4 {
            let addr = get_src_addr(i, j);
            cache.simulate(&addr);
        }
    }
    // for i in 0..N {
    //     for j in 0..M {
    //         let src_addr = get_src_addr(i, j);
    //         let dst_addr = get_dst_addr(i, j);
    //         let r1 = cache.simulate(&src_addr);
    //         let r2 = cache.simulate(&dst_addr);
    //         if i == deb {
    //             println!("i = {i}, j = {j}, addr = {:?}, missed = {:?}", src_addr, r1);
    //         }
    //     }
    // }
    let cnt = cache.cnt;
    let tot = cache.tot;
    println!("cnt = {cnt}, tot = {tot}, miss rate = {}", cnt as f64/tot as f64);
}