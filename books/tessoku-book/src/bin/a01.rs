use proconio::input;
fn main() {
    input! {
        d: i32,
        f: i32,
    }

    let diff = d - f;
    println!("{}", diff);
    let count = (diff / 7) % d;
    println!("{}", count);
}
