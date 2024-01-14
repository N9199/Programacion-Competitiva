use core::ops::ControlFlow;
use std::{
    fs::File,
    io::{prelude::BufRead as _, BufReader},
};

use itertools::iproduct;
use std::collections::BTreeMap;
use std::collections::BTreeSet;

fn main() {
    let input = BufReader::new(File::open("input.txt").unwrap());
    let mut map: BTreeMap<_, Vec<_>> = BTreeMap::new();
    let mut numbers = Vec::new();

    for (i, line) in input.lines().map_while(Result::ok).enumerate() {
        for (j, c) in line.chars().enumerate() {
            if c == '*' {
                map.entry((i as i64, j as i64)).or_default();
            }
        }

        let mut left = 0;
        while left < line.len() {
            let mut right = left;
            while right < line.len() && line.as_bytes()[right].is_ascii_digit() {
                right += 1;
            }
            if line.as_bytes()[left].is_ascii_digit() {
                let number = line[left..right].parse::<u32>().unwrap();
                numbers.push((number, left, right, i));
                left = right + 1;
            } else {
                left += 1;
            }
        }
    }

    numbers.into_iter().for_each(|(n, left, right, i)| {
        (left..right)
            .flat_map(|j| {
                iproduct!(-1..=1, -1..=1).map(move |(dx, dy)| (i as i64 + dx, j as i64 + dy))
            })
            .try_for_each(|(i, j)| {
                if let Some(v) = map.get_mut(&(i, j)) {
                    v.push(n);
                    ControlFlow::Break(())
                } else {
                    ControlFlow::Continue(())
                }
            });
    });
    let out: u64 = map
        .into_values()
        .map(|v| {
            iproduct!(v.iter().enumerate(), v.iter().enumerate())
                .inspect(|(v1, v2)| {
                    dbg!(v1, v2);
                })
                .filter_map(|((i, &v1), (j, &v2))| (i < j).then_some(v1 as u64 * v2 as u64))
                .inspect(|v| {
                    dbg!(v);
                })
                .sum::<u64>()
        })
        .sum();
    println!("{out}");
}
