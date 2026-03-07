use proconio::input;

fn main() {
    input! {
        q: i32,
        aa: [i8; q]
    }

    let mut volume = 0;
    let mut is_playing = false;

    for a in aa {
        if a == 1 {
            volume += 1;
        } else if a == 2 {
            if volume >= 1 {
                volume -= 1;
            }
        } else {
            is_playing = !is_playing;
        }

        if volume >= 3 && is_playing {
            println!("{}", "Yes")
        } else {
            println!("{}", "No")
        }
    }
}
