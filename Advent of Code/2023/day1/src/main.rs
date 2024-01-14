use std::{
    fs::File,
    io::{prelude::BufRead, BufReader},
};

fn main() {
    let word_digit_list = [
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];

    let input = BufReader::new(File::open("input.txt").unwrap());
    let mut out = 0;
    for line in input.lines().map_while(Result::ok) {
        let (mut first, mut last) = (None, None);
        for (i, c) in line.chars().enumerate() {
            if c.is_ascii_digit() {
                let c = c.to_digit(10);
                last = c;
                first.get_or_insert(c.unwrap());
            }
            for (j, word) in word_digit_list.iter().enumerate() {
                if line.len() >= i + word.len() && &line[i..(i + word.len())] == *word {
                    let j = (j + 1) as _;

                    last = Some(j);
                    first.get_or_insert(j);
                }
            }
        }
        // println!("{first:?} {last:?}");
        let (Some(first), Some(last)) = (first, last) else {
            continue;
        };
        out += first * 10 + last;
    }
    println!("{out}");
}
