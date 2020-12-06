#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
use std::cell::RefCell;
use std::convert::{TryFrom, TryInto};
use std::rc::Rc;
use base64;

struct Codec {}

#[repr(C)]
union NodeStr {
    s: [u8; 12],
    node: (i32, i32),
}
type OptNode = Option<Rc<RefCell<TreeNode>>>;

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Codec {}
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        fn _serialize(root: &OptNode) -> Vec<u8>{
            match root {
                None => vec![],
                Some(root) => {
                    let root = root.borrow();
                    let mut ls = _serialize(&root.left);
                    let mut rs = _serialize(&root.right);
                    let s0 = NodeStr {
                        node: (root.val, 12i32 + i32::try_from(ls.len()).unwrap()),
                    };
                    let s1 = unsafe { s0.s };
                    let mut ret = s1.to_vec();
                    ret.append(&mut ls);
                    ret.append(&mut rs);
                    ret
                }
            }
        }
        base64::encode(_serialize(&root).as_slice());
    }

    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        fn _deserialize(data: &[u8]) -> OptNode {
            if data.len() == 0 {
                None
            } else if data.len() % 12 != 0 {
                panic!(format!("badlen {}", data.len()));
            } else {
                let mut roots: [u8; 12] = [0; 12];
                roots.copy_from_slice(&data[0..12]);
                let roots = NodeStr { s: roots };
                let (rootvalue, rightpos) = unsafe { roots.node };
                let optnode = Rc::new(RefCell::new(TreeNode::new(rootvalue)));
                let rightpos: usize = rightpos.try_into().unwrap();
                optnode.borrow_mut().left = _deserialize(&data[12..rightpos]);
                optnode.borrow_mut().right = _deserialize(&data[rightpos..]);
                Some(optnode)
            }
        }
        return _deserialize(base64::decode(&data));
    }
}

pub fn main() {}
