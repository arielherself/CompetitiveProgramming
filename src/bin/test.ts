interface T<type> {
    name: string,
    age: number;
    gender: boolean
}

const a : T<object> = {name: 'Ariel', age: 19, gender: false};
const arr: Readonly<Array<number>> = [1, 2, 3];
console.log(typeof(a));

type optional = {a, b?};
function test(t: optional) {
    const {a, b} = t;
    console.log(b);
}

test({a: 'c'});