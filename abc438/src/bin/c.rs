use proconio::input;
fn main() {
    input! {
        n: i32,
        mut a: [i32; n]
    }

    let mut idx = 0;
    while idx + 3 < a.len() {
        if (a[idx] == a[idx + 1]) || (a[idx + 1] == a[idx + 2]) || (a[idx + 2] == a[idx + 3]) {
            for _ in 0..4 {
                a.remove(idx);
            }
            continue;
        }
        idx += 1;
    }

    println!("{}", a.len());
}
