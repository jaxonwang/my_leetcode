struct Solution;

impl Solution {
    pub fn advantage_count(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {

        let rank = |v:&Vec<i32>|{
            let mut r:Vec<(usize, i32)> = v.iter().copied().enumerate().collect();
            r.sort_by_key(|e|e.1);
            r 
        };
        let ra1 = rank(&a);
        let rb1 = rank(&b);

        let mut pa:usize = 0;
        let mut pb:usize = 0;

        let mut advantage = vec![];
        let mut remain = vec![];
        let mut advantagenum = 0;

        while pa < ra1.len() && pb<rb1.len(){
            if ra1[pa].1 > rb1[pb].1{
                advantagenum +=1;
                pb+=1;
            }else if advantagenum == 0{
                remain.push(ra1[pa]);
                pa+=1;
            }else{
                advantage.push(ra1[pa]);
                pa+=1;
                advantagenum -=1;
            }
        }

        for i in pa..ra1.len(){
            advantage.push(ra1[i]);
        }

        advantage.append(& mut remain);

        let mut ret = vec![0i32; b.len()];
        for (i, (_, v)) in advantage.iter().enumerate(){
            ret[rb1[i].0] = *v;
        }
        return ret;
    }
}

pub fn main() {
    println!("{:?}", Solution::advantage_count(vec![1,2,3,4,5,8,9,10], vec![0,1,4,5,6,7,8,9]));
}
