fn main() {

    // Here in rust you don't have to explicitely dereference, which is nice.
    // & is the reference operator, it creates a borrow.
    // &mut creates the mutable borrow.
    // It's all quite nice indeed.


    struct Honk {
        msg: i32,
    }

    let pete = Honk { msg: 22 };
    let refpete = &pete;
    println!("{}", refpete.msg);

    let elle = 24;
    let rofi = &elle;

    println!("{}", elle);
    println!("{}", rofi);
    println!("{}", &rofi);

    println!("honk");
}
