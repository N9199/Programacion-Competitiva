use std::{
    collections::HashSet,
    fs::File,
    io::{prelude::BufRead as _, BufReader},
};

trait Iterstuff: Iterator + Sized {
    fn take_first(mut self) -> (Option<Self::Item>, Self) {
        let first = self.next();
        (first, self)
    }
}

impl<T: Iterator + Sized> Iterstuff for T {}

fn main() {
    let input = BufReader::new(File::open("input.txt").unwrap());

    let mut out = 0;
    let mut mult = 1;
    let mut remain = 0;
    for line in input.lines().map_while(Result::ok) {
        let (_prefix, rest) = line.split(':').take_first();
        // let _id = prefix
        //     .unwrap()
        //     .split(' ')
        //     .nth(1)
        //     .unwrap()
        //     .parse::<u32>()
        //     .unwrap();
        let mut vals = rest
            .inspect(|v| {
                dbg!(v);
            })
            .next()
            .unwrap()
            .split('|')
            .map(|numbers| {
                dbg!(numbers);
                numbers.split(' ').filter_map(|number| {
                    dbg!(number);
                    (!number.is_empty()).then(|| number.parse::<u32>().unwrap())
                })
            });
        let vals1: HashSet<_> = vals.next().unwrap().collect();
        let count = vals
            .next()
            .unwrap()
            .filter(|v| vals1.contains(v))
            .inspect(|winner| {
                dbg!(winner);
            })
            .count();
        out += count * mult;
        if count > 0 {
            mult *= count;
            remain = count;
        }
    }
    println!("{out}");
}
