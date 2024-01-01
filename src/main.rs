mod test_mod;
mod test_mods;
mod a_sibling_file;
fn main() {
    use test_mod::a_mod::hello_world;
    use test_mods::another_mod;
    hello_world();
    another_mod::another_fn();
    a_sibling_file::sibling_mod::sibling_fn();
}