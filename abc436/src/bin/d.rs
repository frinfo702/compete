use nalgebra::VectorSlice1;
use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        maze: [[char; h]; w]
    }

    if maze[h][w] == '#' {
        println!("{}", -1);
    }
}

// fn decide_direction(x: usize, y: usize, maze: Vec<Vec<char>>) -> (usize, usize) {
//     up = maze.get((x-1,y));
//     right =
// }
