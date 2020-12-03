struct Solution;
use std::convert::TryFrom;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 || matrix[0].len() == 0 {
            return false;
        }

        fn find(
            matrix: &Vec<Vec<i32>>,
            start_x: isize,
            start_y: isize,
            end_x: isize,
            end_y: isize,
            target: i32,
        ) -> bool {
            if start_x > end_x || start_y > end_y {
                false
            } else {
                use std::cmp::Ordering;
                let (mut sx, mut sy, mut ex, mut ey) = (start_x, start_y, end_x, end_y);

                while sx <= ex && sy <= ey {
                    let (middle_x, middle_y) = ((sx+ ex) / 2, (sy+ ey) / 2);
                    let middle_x_ = usize::try_from(middle_x).unwrap();
                    let middle_y_ = usize::try_from(middle_y).unwrap();
                    match target.cmp(&matrix[middle_y_][middle_x_]) {
                        Ordering::Equal => return true,
                        Ordering::Less => {
                            ex = middle_x - 1;
                            ey = middle_y - 1;
                        }
                        Ordering::Greater => {
                            sx = middle_x + 1;
                            sy = middle_y + 1;
                        }
                    };
                }
                find(matrix, sx, start_y, end_x, ey, target)
                    || find(matrix, start_x, sy, ex, end_y, target)
            }
        }
        return find(&matrix, 0, 0, isize::try_from(matrix[0].len() - 1).unwrap(), isize::try_from(matrix.len() - 1).unwrap(), target);
    }
}

pub fn main() {
    // let t1: Vec<Vec<i32>> = vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 50]];
    // println!("{}", Solution::search_matrix(t1, 5))
    let t1: Vec<Vec<i32>> = vec![vec![1, 3, 5]];
    println!("{}", Solution::search_matrix(t1, 1))
}
