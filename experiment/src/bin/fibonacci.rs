use std::time::Instant;

const MOD: u64 = 1_000_000_007;
fn main() {
    let n = 1_000_000_000;
    let mut start = Instant::now();
    let ans_dp = fib_dp(n);
    let mut elapsed = start.elapsed();
    println!("DP: {}, elapsed: {:.3?}", ans_dp, elapsed);

    start = Instant::now();
    let ans_fast_doubling = fib_fast_doubling(n);
    elapsed = start.elapsed();
    println!(
        "Fast Doubling: {}, elapsed: {:.3?}",
        ans_fast_doubling, elapsed
    );
}

fn fib_dp(n: usize) -> u64 {
    if n == 0 {
        return 0;
    };
    if n == 1 {
        return 1;
    };

    let mut a: u64 = 0; // F_0
    let mut b: u64 = 1; // F_1

    for _ in 2..=n {
        let next = (a + b) % MOD;
        a = b;
        b = next;
    }

    b
}

// ビット演算
fn fib_fast_doubling(n: usize) -> u64 {
    if n == 0 {
        return 0;
    };
    if n == 1 {
        return 1;
    };
    if n == 2 {
        return 1;
    };

    let msb_position = usize::BITS - 1 - n.leading_zeros();
    let mut f_k: u64 = 0;
    let mut f_k_plus_1: u64 = 1;

    for position in (0..=msb_position).rev() {
        let next_f_2k = f_k * ((2 * f_k_plus_1 + MOD - f_k) % MOD) % MOD;
        let next_f_2k_plus_1 = (f_k_plus_1 * f_k_plus_1 % MOD + f_k * f_k % MOD) % MOD;

        f_k = next_f_2k;
        f_k_plus_1 = next_f_2k_plus_1;

        // position桁シフトした結果が奇数の時
        if (n >> position) & 1 == 1 {
            let next_f_2k_plus_2 = (f_k + f_k_plus_1) % MOD;
            f_k = f_k_plus_1;
            f_k_plus_1 = next_f_2k_plus_2;
        }
    }

    f_k
}
