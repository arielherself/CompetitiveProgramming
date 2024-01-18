struct DancingLinks<T: Copy + Eq> {
    cnt: usize,
    left: Vec<usize>,
    right: Vec<usize>,
    up: Vec<usize>,
    down: Vec<usize>,
    row_head: Vec<usize>,
    col_head: Vec<usize>,
    val: Vec<T>,
    row_info: Vec<usize>,
    col_info: Vec<usize>,
}

impl<T: Copy + Eq> DancingLinks<T> {
    fn new(max_n: usize) -> Self {
        let mut ins = Self {
            cnt: 0,
            left: vec![],
            right: vec![],
            up: vec![],
            down: vec![],
            row_head: vec![0;max_n],
            col_head: vec![0;max_n],
            val: vec![],
            row_info: vec![],
            col_info: vec![],
        };
        ins.left.push(0);
        ins.right.push(0);
        ins.up.push(0);
        ins.down.push(0);
        ins.row_info.push(0);
        ins.col_info.push(0);
        ins
    }
    fn get_item(&self, idx: usize) -> T {
        self.val[idx-1]
    }
    fn get(&self, i: usize, j: usize) -> Option<T> {
        let mut curr = self.row_head[i];
        while curr != 0 {
            if self.col_info[curr] == j {
                return Some(self.get_item(curr));
            }
            curr = self.right[curr];
        }
        curr = self.row_head[i];
        while curr != 0 {
            if self.col_info[curr] == j {
                return Some(self.get_item(curr));
            }
            curr = self.left[curr];
        }
        None
    }
    fn insert(&mut self, i: usize, j: usize, val: T) {
        self.cnt += 1;
        self.val.push(val);
        self.left.push(0);
        self.right.push(self.row_head[i]);
        self.left[self.row_head[i]] = self.cnt;
        self.row_head[i] = self.cnt;
        self.up.push(0);
        self.down.push(self.col_head[j]);
        self.up[self.col_head[j]] = self.cnt;
        self.col_head[j] = self.cnt;
        self.row_info.push(i);
        self.col_info.push(j);
    }
    fn remove_row(&mut self, i: usize) {
        let mut curr = self.row_head[i];
        while curr != 0 {
            self.down[self.up[curr]] = self.down[curr];
            self.up[self.down[curr]] = self.up[curr];
            curr = self.right[curr];
        }
        self.row_head[i] = 0;
    }
    fn remove_col(&mut self, j: usize) {
        let mut curr = self.col_head[j];
        while curr != 0 {
            self.right[self.left[curr]] = self.right[curr];
            self.left[self.right[curr]] = self.left[curr];
            curr = self.right[curr];
        }
        self.col_head[j] = 0;
    }
    fn dance_remove(&mut self, i: usize, plain: T) {
        let mut curr = self.row_head[i];
        while curr != 0 {
            if self.val[curr] != plain {
                let mut curr = self.col_head[self.col_info[curr]];
                while curr != 0 {
                    if self.row_info[curr] != i && self.val[curr] != plain {
                        self.remove_row(self.row_info[curr]);
                    }
                    curr = self.down[curr];
                }
            }
            self.remove_col(self.col_info[curr]);
            curr = self.right[curr];
        }
        self.remove_row(i);
    }
}

fn main() {
    let mut mat = DancingLinks::new(100);
    mat.insert(0,0,10086);
    mat.insert(0,1,234);
    mat.insert(1,1,10010);
    mat.insert(12,25,12345);
    assert_eq!(mat.get(0,0), Some(10086));
    assert_eq!(mat.get(1,0), None);
    assert_eq!(mat.get(12, 25), Some(12345));
    mat.dance_remove(0,0);
    assert_eq!(mat.get(0,0), None);
    assert_eq!(mat.get(1,0), None);
    assert_eq!(mat.get(1,1), None);
}