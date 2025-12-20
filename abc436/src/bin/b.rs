use std::vec;

use num::pow;
use proconio::input;

fn main() {
    input! {
        n: usize
    }

    let mut grid = vec![vec![0; n]; n];
    grid[0][(n - 1) / 2] = 1;

    let count = pow(n, 2) - 1;
    let mut last = [0, (n - 1) / 2, 1];

    for _ in 1..=count {
        let r = last[0];
        let c = last[1];
        let k = last[2];

        let mut x = (r + n - 1) % n;
        let mut y = (c + 1) % n;
        if grid[x][y] == 0 {
            grid[x][y] = k + 1;
            last = [x, y, k + 1];
        } else {
            x = (r + 1) % n;
            y = c;
            grid[x][y] = k + 1;
            last = [x, y, k + 1];
        }
    }

    for i in 0..n {
        for j in 0..n {
            if j == n - 1 {
                println!("{}", grid[i][j])
            } else {
                print!("{} ", grid[i][j])
            }
        }
    }
}
