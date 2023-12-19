trait Printable<T> {
    fn print(a:T);
}

struct Test;

impl<T> Printable<T> for Test where T: std::fmt::Display {
    fn print(a:T) {
        println!("{a}");
    }
}

fn main() {
    <Test>::print(1.5);
}
