struct Solution;

impl Solution {

    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        use std::convert::TryInto;
        let mut slow: usize = 0;
        let mut fast: usize = 0;

        let advance = |slow:usize, fast:usize|{
            let slow1 = nums[slow].try_into().unwrap();
            let index: usize = nums[fast].try_into().unwrap();
            let fast1 = nums[index].try_into().unwrap();
            (slow1, fast1)
        };
        loop{
            let (s, f) = advance(slow, fast);
            slow = s;
            fast = f;
            if slow == fast{
                break;
            }
        }
        let mut looplengh = 0;
        loop{
            let (s, f) = advance(slow, fast);
            slow = s;
            fast = f;
            looplengh+=1;
            if slow == fast{
                break;
            }
        }
        slow = 0;
        fast = 0;
        for _ in 0..looplengh{
            fast = nums[fast].try_into().unwrap();
        }
        loop {
            slow = nums[slow].try_into().unwrap();
            fast = nums[fast].try_into().unwrap();
            if slow == fast{
                break;
            }
        }
        return slow.try_into().unwrap();
    }
}

pub fn main() {
    let nums = vec![1,2,3,4,5,6,7,8,9,10,4,4,4];
    println!("{:?}", Solution::find_duplicate(nums));
}
