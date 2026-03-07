use proconio::input;

fn main() {
    input! {
        x: usize,
        n: usize,
        w: [usize; n],
        q: usize,
        p: [usize; q],
    }

    let mut robot_weight = x;
    let mut attached = vec![false; n];

    for part in p {
        let idx = part - 1;
        if !attached[idx] {
            attached[idx] = true;
            robot_weight += w[idx];
        } else {
            attached[idx] = false;
            robot_weight -= w[idx];
        }
        println!("{}", robot_weight);
    }
}
