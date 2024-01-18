// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
struct Solution;


impl Solution {
    pub fn insert_greatest_common_divisors(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let gcd = |mut x: i32, mut y: i32| {
            while y != 0 {
                (x, y) = (y, x % y);
            }
            x
        };
        let mut t = head.as_mut().unwrap();
        while t.next != None {
            let next = t.next.take().unwrap();
            let mut mid = Box::new(ListNode::new(gcd(t.val, next.val)));
            mid.next = Some(next);
            t.next = Some(mid);
            t = t.next.as_mut().unwrap().next.as_mut().unwrap();
        }
        head
    }
}

fn main() {

}