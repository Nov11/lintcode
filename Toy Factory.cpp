/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
    public:
    void talk()const{
        cout << "Wow";
    }
};

class Cat: public Toy {
    // Write your code here
    public:
    void talk()const{
        cout <<"Meow";
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if(type == "Cat"){
            return new Cat;
        }else if(type == "Dog"){
            return new Dog;
        }
        return nullptr;
    }
};