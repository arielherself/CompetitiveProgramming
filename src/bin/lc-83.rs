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
    pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut c = head.as_mut();
        while let Some(curr) = c {
            while let Some(next) = curr.next.as_mut() {
                if next.val == curr.val {
                    curr.next = next.next.take();
                } else {
                    break;
                }
            }
            c = curr.next.as_mut();
        }
        head
    }
}