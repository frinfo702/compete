use std::cmp::max;

use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        queries: [[usize; w]; h],
        b: [usize; n]
    }

    let mut max_count = 0;

    for line in queries {
        let mut count = 0;
        for i in 0..b.len() {
            if line.contains(&b[i]) {
                count += 1;
            }
        }
        max_count = max(max_count, count);
    }

    println!("{}", max_count);
}
