struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 || matrix[0].len() == 0{
            return false;
        }

        fn find(
            matrix: &Vec<Vec<i32>>,
            start_x: usize,
            start_y: usize,
            end_x: usize,
            end_y: usize,
            target: i32,
        ) -> bool {
            println!("{} {} {} {}", start_x, start_y, end_x, end_y);
            if start_x > end_x || start_y > end_y {
                false
            } else if start_x == end_x && start_y == end_y {
                if target == matrix[start_y][start_x] {
                    true
                } else {
                    false
                }
            } else {
                use std::cmp::Ordering;
                let (middle_x, middle_y) = ((start_x + end_x) / 2, (start_y + end_y) / 2);
                println!("middle {} {}", middle_x, middle_y);
                match target.cmp(&matrix[middle_y][middle_x]) {
                    Ordering::Equal => true,
                    Ordering::Less => find(matrix, start_x, start_y, middle_x, middle_y, target),
                    Ordering::Greater => {
                        find(matrix, start_x, middle_y + 1, end_x, end_y, target)
                            || find(matrix, middle_x + 1, start_y, end_x, middle_y, target)
                    }
                }
            }
        }
        return find(&matrix, 0, 0, matrix[0].len() - 1, matrix.len() - 1, target);
    }
}

pub fn main() {
    let t1: Vec<Vec<i32>> = vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 50]];
    println!("{}", Solution::search_matrix(t1, 5))
}
