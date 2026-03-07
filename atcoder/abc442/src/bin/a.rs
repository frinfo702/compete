use proconio::input;

fn main() {
    input! {
        s: String
    }
    let mut count = 0;

    for char in s.chars() {
        if char == 'i' || char == 'j' {
            count += 1;
        }
    }

    println!("{}", count);
}
