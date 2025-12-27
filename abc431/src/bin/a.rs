use proconio::input;

fn main() {
    input! {
        h: i32,
        b: i32
    }

    let subtract: i32 = h - b;
    if subtract > 0 {
        println!("{}", h - b);
    } else {
        println!("{}", 0);
    }
}
