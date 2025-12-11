use proconio::input;

fn main() {
    // 1. 入力を文字列として受け取る
    input! {
        s: String,
    }

    // 2. 文字列 "ABCxxx" の後ろ3文字（xxx）を切り出して数字にする
    // 低レイヤー好きのユーザーさんなら &s[3..] がスライスであることは直感的にわかるはずです
    let num_str = &s[3..];
    let num: u16 = num_str.parse().unwrap(); // 文字列を数値にパース

    // 3. 問題の条件判定（ABC350 A問題のルール）
    // "349以下" かつ "316ではない" なら Yes
    if num < 350 && num != 316 {
        println!("Yes");
    } else {
        println!("No");
    }
}
