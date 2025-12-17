use std::{collections::HashSet, vec};

use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
        queries: [(usize, usize); m]
    }

    let mut seen: HashSet<(usize, usize)> = HashSet::with_capacity(m * 4);
    let mut count = 0;

    for (r, c) in queries {
        if seen.contains(&(r, c))
            || seen.contains(&(r, c + 1))
            || seen.contains(&(r + 1, c))
            || seen.contains(&(r + 1, c + 1))
        {
            continue;
        }
        seen.insert((r, c));
        seen.insert((r, c + 1));
        seen.insert((r + 1, c));
        seen.insert((r + 1, c + 1));

        count += 1;
    }

    println!("{}", count);
}
