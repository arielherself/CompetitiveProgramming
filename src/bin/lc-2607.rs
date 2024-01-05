// 每个元素都是模k同余类的中位数
// a b c d    a d c

struct Solution;

impl Solution {
    pub fn make_sub_k_sum_equal(arr: Vec<i32>, k: i32) -> i64 {
        let gcd = |mut x: usize, mut y: usize| {
            while y != 0 {
                (x, y) = (y, x % y);
            }
            x
        };
        let n = arr.len();
        let k = gcd(n, k as usize);
        let mut res = 0i64;
        let mut grp = vec![vec![];k];
        for (i,x) in arr.into_iter().enumerate() {
            let id = i.rem_euclid(k);
            grp[id].push(x);
        }
        for mut l in grp {
            l.sort_unstable();
            let len = l.len();
            let curr = l.iter().skip(len>>1).fold(0i64, |s,&x|s+x as i64) - l.iter().take(len+1>>1).fold(0i64, |s,&x|s+x as i64);
            res += curr;
        }
        res
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let arr: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::make_sub_k_sum_equal(arr, k));
}