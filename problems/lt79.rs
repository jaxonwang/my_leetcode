struct Solution;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        if board.len() == 0 || board[0].len() == 0 {
            return false;
        }
        let mut word = word.as_bytes();

        let rowsize = board.len();
        let colsize = board[0].len();

        fn dfs(
            board: &Vec<Vec<char>>,
            visit: &mut Vec<Vec<bool>>,
            row: usize,
            col: usize,
            word: &[u8],
            pos: usize,
        ) -> bool {
            // println!("{} {} {}", row, col, pos);
            let rowsize = board.len();
            let colsize = board[0].len();
            if visit[row][col] || board[row][col] != (word[pos] as char) {
                return false;
            }
            if word.len() == pos + 1{
                return true;
            }
            visit[row][col] = true;
            let valid = (row > 0 && dfs(board, visit, row - 1, col, word, pos + 1))
                || (col > 0 && dfs(board, visit, row, col - 1, word, pos + 1))
                || (row + 1< rowsize  && dfs(board, visit, row + 1, col, word, pos + 1))
                || (col + 1< colsize && dfs(board, visit, row, col + 1, word, pos + 1));
            visit[row][col] = false;
            return valid;
        }
        let mut visit = vec![vec![false; colsize]; rowsize];

        for (i, row) in board.iter().enumerate() {
            for (j, c) in row.iter().enumerate() {
                if *c == (word[0] as char) {
                    if dfs(&board, &mut visit, i, j, &mut word, 0) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}

pub fn main() {
    let board = vec![
        vec!['A', 'B', 'C', 'E'],
        vec!['S', 'F', 'C', 'S'],
        vec!['A', 'D', 'E', 'E'],
    ];
    let ret = Solution::exist(board, String::from("ADEESE"));
    // let board = vec![vec!['a']];
    // let ret = Solution::exist(board, String::from("a"));
    println!("{}", ret);
}
