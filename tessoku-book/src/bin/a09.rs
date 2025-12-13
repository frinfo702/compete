use std::vec;

use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        queries: [(usize, usize, usize, usize); n],
    }

    let mut grid = vec![vec![0; w + 2]; h + 2];
    // pre process for imos-methos
    for (a, b, c, d) in queries {
        grid[a][b] += 1;
        grid[c + 1][d + 1] += 1;
        grid[a][d + 1] -= 1;
        grid[c + 1][b] -= 1;
    }

    // horisontal summarization
    for j in 1..=w {
        for i in 1..=h {
            grid[i][j] += grid[i - 1][j];
        }
    }

    // vertical summarization
    for j in 1..=w {
        for i in 1..=h {
            grid[i][j] += grid[i][j - 1];
        }
    }

    for i in 1..=h {
        for j in 1..=w {
            if j == w {
                println!("{}", grid[i][j]);
            } else {
                print!("{} ", grid[i][j]);
            }
        }
    }
}
