#include <iostream>
#include <vector>

using namespace std;

// Products class
class Product{
    private:
    string name = "";
    double price = 0;
    int quantity = 0;

    public:
    Product() {};
    Product(string name_, double price_, int quantity_) : name(name_),
                                                          price(price_),
                                                          quantity(quantity_)
                                                          {};

    // Setters
    void setName(string name_){
        name = name_;
    }
    void setPrice(double price_){
        price = price_;
   }
    void setQuantity(int quantity_){
        quantity = quantity_;
   };

   // Getters
   string getName(){
        return name;
    }
    double getPrice(){
        return price;
   }
    int getQty(){
        return quantity;
   };

};

// Add new products
void addProducts(vector<Product*> vectorPro, string name, double price, int qty){
    Product* ptr = &Product(name, price, qty);    
    addPtr(vectorPro, ptr);
}

void addPtr (vector<Product*> collection, Product* pointer) {
    collection.push_back(pointer);
}

// Show all products
void showProducts(vector<Product*> collection){
    for (Product* pointer : collection) {cout << "Name: "
                                              << pointer->getName()
                                              << ", "
                                              << "Price: "
                                              << pointer->getPrice()
                                              << ", "
                                              << "Quantity: "
                                              << pointer->getQty()
                                              << endl;
    };
}

int main(){

    // Instance variables
    string ans = "y";
    string name = "";
    double price = 0;
    int qty = 0;

    // Dynamic array
    vector<Product*> vectorPro;

    // Get products
    do{
        cout << "Enter product name: ";
        cin >> name;

        cout << "Enter product price: ";
        cin >> price;

        cout << "Enter product qty: ";
        cin >> qty;

        addProducts(vectorPro, name, price, qty);

        cout << "More products (y/n): ";
        cin >> ans;
    } while (ans == "y");

    // Show products
    cout << "Inventory: "
         << endl;
         
    showProducts(vectorPro);

    cout << "Hello world!"
         << endl;

    return 0;
}