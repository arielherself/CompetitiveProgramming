fn main() {
    use std::io::stdin;
    use std::collections::HashSet;
    let mut buf:String = String::new();
    stdin().read_line(&mut buf).ok();
    let n:usize = buf.trim().parse().unwrap();
    buf.clear();
    let mut a:Vec<i32> = Vec::with_capacity(n);
    stdin().read_line(&mut buf).ok();
    buf.trim().split(' ').for_each(|val| a.push(val.parse().unwrap()));
    let mut mp:HashSet<i32> = HashSet::new();
    let mut res = vec![];
    let mut l = 0usize;
    for i in 0..n {
        if mp.contains(&a[i]) {
            res.push([l,i]);
            l = i + 1;
            mp.clear();
        } else {
            mp.insert(a[i]);
        }
    }
    if res.is_empty() {
        println!("-1");
    } else {
        let m = res.len();
        println!("{}",res.len());
        res[m-1] = [res[m-1][0],n-1];
        res.into_iter().for_each(|[l,r]| println!("{} {}",l+1,r+1));
    }
}