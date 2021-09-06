#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    string name;
    int price, temperature;
    bool hasCashback;

    cout << "Product's name: ";
    cin >> name;

    cout << "Product's price: ";
    cin >> price;

    cout << "Is cash-back available for this product? (true/false) ";
    cin >> boolalpha >> hasCashback;

    cout << "Maximum storing temperature: ";
    cin >> temperature;
    
    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    cout << name << '\n';

    cout.fill('.');
    cout << setw(17) << left << "Price:" << setfill('0')  << setw(8) << right << uppercase << hex << price << '\n';
    cout << "Has cash-back:" << setfill('.') << boolalpha << setw(11)<< hasCashback << '\n';
    cout << "Max temperature:" << dec << setw(9) << showpos << temperature << '\n';

    return 0;
}