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
    pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        use std::collections::VecDeque;
        let mut st = VecDeque::<Box<ListNode>>::new();
        let mut curr = head;
        while let Some(mut node) = curr {
            while matches!(st.back(), Some(prev) if prev.val < node.val) {
                st.pop_back();
            }
            while let Some(prev) = st.back() {
                if prev.val >= node.val { break; }
                st.pop_back();
            }
            curr = node.next.take();
            st.push_back(node);
        }
        let mut next = st.pop_back().unwrap();
        while let Some(mut node) = st.pop_back() {
            node.next = Some(next);
            next = node;
        }
        Some(next)
    }
}

fn main() {
    
}