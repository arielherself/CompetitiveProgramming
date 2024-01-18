// 中位数贪心，枚举结果中的中间那个1的位置。
// 预处理一下前缀和和后缀和，这样在枚举的过程中就可以用二分查找，实现O(n\log n)复杂度。
// nums = [1 0 0 1 0 1]
// pa   = [1 1 1 2 2 3]
// pasum= [0 0 0 3 3 8]


struct Solution;

#[inline]
fn sum(start: i32, length: i32) -> i64 {
    (2 * start as i64 + length as i64 - 1) * length as i64 >> 1
}

impl Solution {
    pub fn min_moves(nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return 0;
        }
        let n = nums.len();
        let mut pa = vec![0;n+1];
        let mut pa_sum = vec![0;n+1];
        for i in 1..=n {
            pa[i] = pa[i-1] + nums[i-1];
            if nums[i-1] == 1 {
                pa_sum[i] = pa_sum[i-1] + i as i64 - 1;
            } else {
                pa_sum[i] = pa_sum[i-1];
            }
        }
        let part = k >> 1;
        let mut res = i64::MAX;
        for (i,&x) in nums.iter().enumerate() {
            let i = i as i32;
            if x == 0 { continue; }
            let lsr = if k & 1 == 0 {i} else {i-1};
            let rsl = i + 1;
            if lsr < 0 || rsl >= n as i32 {continue;}
            if let Ok(li) = pa[0..=lsr as usize+1].binary_search_by_key(&-part, |t|t-pa[lsr as usize+1]) {
                if let Ok(ri) =  pa[rsl as usize+1..=n].binary_search_by_key(&part, |t|t-pa[rsl as usize]) {
                    let right_sum = pa_sum[ri+rsl as usize + 1] - pa_sum[rsl as usize] - sum(rsl, part);
                    let left_sum = sum(lsr - part + 1, part) - pa_sum[lsr as usize + 1] + pa_sum[li];
                    res = res.min(left_sum + right_sum);
                }
            }
        }
        res as i32
    }
}

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).ok();
    let nums: Vec<i32> = buf.trim().split(' ').map(|x|x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    buf.clear();
    std::io::stdin().read_line(&mut buf).ok();
    let k: i32 = buf.trim().parse::<i32>().unwrap();
    println!("{}", Solution::min_moves(nums, k));
}