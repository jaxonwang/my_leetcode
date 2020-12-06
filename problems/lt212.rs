struct Solution;

use std::collections::HashMap;
use std::rc::Rc;
use std::cell::RefCell;

struct TrieNode {
    next: HashMap<u8, Rc<RefCell<TrieNode>>>,
}

impl TrieNode {
    fn match_string(&self, word: &str) -> bool{
        let b = word.as_bytes();
        unsafe{
        let mut rf: *const TrieNode = self;
        for c in b.iter(){
            if !(*rf).next.contains_key(c){
                return false;
            }
            let tmp: *const TrieNode = &(*(*rf).next[c].borrow());
            rf = tmp;
        }
        }
        return true;
    }
}

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        fn dfs(
            board: &Vec<Vec<char>>,
            visit: &mut Vec<Vec<bool>>,
            row: usize,
            col: usize,
            pos: usize,
            node: &mut TrieNode,
        ) {
            // println!("{} {} {}", row, col, pos);
            let rowsize = board.len();
            let colsize = board[0].len();
            if visit[row][col] || pos == 10 {
                return;
            }

            let k = board[row][col] as u8;

            if !node.next.contains_key(&k) {
                let newnode = Rc::new(RefCell::new(TrieNode {
                    next: HashMap::new(),
                }));
                node.next.insert(k, Rc::clone(&newnode));
            }
            let rf = &mut (*node.next[&k]).borrow_mut();
            visit[row][col] = true;

            if row > 0 {
                dfs(board, visit, row - 1, col, pos + 1, rf);
            }
            if col > 0 {
                dfs(board, visit, row, col - 1, pos + 1, rf);
            }
            if row + 1 < rowsize {
                dfs(board, visit, row + 1, col, pos + 1, rf);
            }
            if col + 1 < colsize {
                dfs(board, visit, row, col + 1, pos + 1, rf);
            }
            visit[row][col] = false;
        }
        let rowsize = board.len();
        let colsize = board[0].len();
        let mut visit = vec![vec![false; colsize]; rowsize];
        let mut root = TrieNode {
            next: HashMap::new(),
        };
        for (i, row) in board.iter().enumerate() {
            for (j, _) in row.iter().enumerate() {
                dfs(&board, &mut visit, i, j, 0, &mut root);
            }
        }

        let mut ret:Vec<String> = vec![];
        for word in words.iter(){
            if root.match_string(word){
                ret.push(word.clone());
            }
        }
        return ret;
    }
}

pub fn main() {
    // let board = vec![
    //     vec!['A', 'B', 'C', 'E'],
    //     vec!['S', 'F', 'C', 'S'],
    //     vec!['A', 'D', 'E', 'E'],
    // let ret = Solution::find_words(board, vec![String::from("ADEESE")]);
    // let board = vec![vec!['a']];
    // let ret = Solution::exist(board, String::from("a"));
    let board = vec![vec!['o','a','a','n'],vec!['e','t','a','e'],vec!['i','h','k','r'],vec!['i','f','l','v']];
    let words = vec!["oath","pea","eat","rain"].iter().map(|s|String::from(*s)).collect::<Vec<String>>();
    let ret = Solution::find_words(board, words);
    println!("{:?}", ret);
}
