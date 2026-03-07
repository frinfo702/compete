use num_integer::binomial;
use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
        pears: [[usize; 2]; m]
    }

    let mut adj = vec![vec![]; n + 1];
    for pear in pears {
        let u = pear[0];
        let v = pear[1];
        adj[u].push(v);
        adj[v].push(u);
    }

    for idx in 1..=n {
        let mut neighbors = std::mem::take(&mut adj[idx]);
        neighbors.sort_unstable();
        neighbors.dedup();

        let contains_self = neighbors.binary_search(&idx).is_ok();
        let distinct_neighbors = neighbors.len();
        let excluded_count = if contains_self {
            distinct_neighbors
        } else {
            distinct_neighbors + 1
        };

        let no_dependent_count = if n > excluded_count {
            n - excluded_count
        } else {
            0
        };
        let count = binomial(no_dependent_count, 3);

        if idx == n {
            println!("{}", count);
        } else {
            print!("{} ", count);
        }
    }
}
