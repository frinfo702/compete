use std::string;

use proconio::input;

fn main() {
    input! {
        n: usize,
        s: String,
    }

    let count = n - s.len();
    let mut result = String::from("");
    for _ in 1..=count {
        result.push_str("o");
    }

    result.push_str(&s);
    println!("{}", result);
}
