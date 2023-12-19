use std::collections::VecDeque;

struct Solution;

struct St {
    n:i32,
    stack:VecDeque<i32>,
    res:Vec<String>
}

impl St {
    fn solve(&mut self, i: i32, open: i32, close: i32){
        if i == 2 * self.n {
            let mut s = String::with_capacity(self.n as usize);
            for x in &self.stack {
                match x {
                    1 => s.push('('),
                    0 => s.push(')'),
                    _ => ()
                }
            }
            self.res.push(s);
            return;
        }
        if open < self.n {
            self.stack.push_back(1);
            self.solve(i+1,open+1,close);
            self.stack.pop_back();
        }
        if close < open {
            self.stack.push_back(0);
            self.solve(i+1,open,close+1);
            self.stack.pop_back();
        }

    }
}

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut st = St{n, stack: Default::default(), res: vec![] };
        st.solve(0,0,0);
        st.res
    }
}

fn main() {
    let n = 3;
    let res = Solution::generate_parenthesis(n);
    for s in &res {
        println!("{s}");
    }
}