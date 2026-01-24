use std::cmp::min;

use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
        s: String,
        t: String,
    }

    let digits: Vec<i32> = s.chars().map(|c| (c as u8 - b'0') as i32).collect();
    let ref_list: Vec<i32> = t.chars().map(|c| (c as u8 - b'0') as i32).collect();

    let mut min_count = 1000;
    for head in 0..=(n - m) {
        let mut sub_count = 0;
        for j in 0..m {
            let sub = (digits[head + j] - ref_list[j] + 10) % 10;
            sub_count += sub;
        }
        min_count = min(min_count, sub_count as usize);
    }

    println!("{}", min_count);
}
