use std::collections::VecDeque;

fn main() {
    let maze = vec![
        vec!['S', '.', '.', '#'],
        vec!['.', '#', '.', '.'],
        vec!['#', '.', '.', '.'],
        vec!['.', '.', '.', 'G'],
    ];

    let dist_to_goal = bfs(maze);
    println!("distance to goal: {:?}", dist_to_goal);
}

fn bfs(grid: Vec<Vec<char>>) -> Option<i32> {
    let height = grid.len();
    let width = grid[0].len();

    let mut queue = VecDeque::<(usize, usize)>::new(); // 次に探索予定の座標
    let mut dist = vec![vec![-1; width]; height];

    let start_x = 0;
    let start_y = 0;

    dist[start_y][start_x] = 0;
    queue.push_back((start_y, start_x));

    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]; // (y, x)

    while let Some((y, x)) = queue.pop_front() {
        for (dy, dx) in dirs {
            let nx = x as isize + dx;
            let ny = y as isize + dy;

            if nx < 0 || nx >= width as isize || ny < 0 || ny >= height as isize {
                continue;
            }

            let nx = nx as usize;
            let ny = ny as usize;

            if grid[ny][nx] == '#' || dist[ny][nx] != -1 {
                continue;
            }

            dist[ny][nx] = dist[y][x] + 1;
            queue.push_back((ny, nx));
        }
    }

    for line in dist {
        println!("{:?}", line);
    }
    return None;
}
