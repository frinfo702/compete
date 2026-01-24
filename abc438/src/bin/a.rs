use proconio::input;

fn main() {
    input! {
        d: i32,
        f: i32,
    }

    let mut day = f;
    while day <= d {
        day += 7;
    }

    println!("{}", day % d);
}
