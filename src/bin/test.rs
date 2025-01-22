struct Foo {
    bar: String,
}

fn main() {
    let mut a = Foo { bar: String::new() };
    let c = &mut a;
    c.bar = String::new();
    a.bar = String::new();
}
