use core::str::FromStr;
use std::{
    fs::File,
    io::{prelude::BufRead, BufReader},
};

trait Iterstuff: Iterator + Sized {
    fn take_first(mut self) -> (Option<Self::Item>, Self) {
        let first = self.next();
        (first, self)
    }
}

impl<T: Iterator + Sized> Iterstuff for T {}

#[repr(u8)]
#[derive(Debug, Clone, Copy)]
enum Colour {
    Blue = 0,
    Red = 1,
    Green = 2,
    Other = 3,
}

impl Colour {
    fn limit(&self) -> Option<u8> {
        match *self {
            Colour::Blue => Some(14),
            Colour::Red => Some(12),
            Colour::Green => Some(13),
            Colour::Other => None,
        }
    }
}

impl From<u8> for Colour {
    fn from(value: u8) -> Self {
        if value > Self::Other as _ {
            panic!("WTF")
        }
        unsafe { core::mem::transmute(value) }
    }
}

impl FromStr for Colour {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        Ok(match s {
            "blue" => Self::Blue,
            "green" => Self::Green,
            "red" => Self::Red,
            _ => Self::Other,
        })
    }
}

fn main() {
    let input = BufReader::new(File::open("input.txt").unwrap());

    let mut out = 0;
    for line in input.lines().map_while(Result::ok) {
        let (prefix, mut rest) = line.split(':').take_first();
        let id = prefix
            .unwrap()
            .split(' ')
            .nth(1)
            .unwrap()
            .parse::<u32>()
            .unwrap();

        let mut min_cube_amount = rest
            .inspect(|v| {
                dbg!(v);
            })
            .next()
            .unwrap()
            .split(';')
            .flat_map(|game| {
                dbg!(game);
                game.split(',').map(|state| {
                    dbg!(state);
                    let mut state = state[1..].split(' ');
                    // dbg!(&state);
                    let number = state.next().unwrap().parse().unwrap();
                    let colour = state.next().unwrap().parse::<Colour>().unwrap();
                    dbg!(colour, number);
                    (colour as u8, number)
                })
            })
            .fold([0u32; 4], |mut acc, (colour, number)| {
                acc[colour as usize] = acc[colour as usize].max(number);
                acc
            });
        min_cube_amount[Colour::Other as usize] = 1;
        out += min_cube_amount.into_iter().fold(1, |acc, v| v * acc);
    }
    println!("{out}");
}
