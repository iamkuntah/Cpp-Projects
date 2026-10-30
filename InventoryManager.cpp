#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct item
{
    string name;
    double price;
    int quantity;
};

void addItem();
void menu();

vector<item> inventory;

void addItem();
void viewItems();
void updateItem();
void deleteItem();
void searchItem();
void saveToFile();
void loadFromFile();
void menu();

void addItem()
{
    item newItem;

    cout << "\n Enter the item's name: ";
    cin >> newItem.name;

    cout << "\n Enter the quantity: ";
    cin >> newItem.quantity;

    cout << "\n Enter the price of the:";
    cin >> newItem.price;

    inventory.push_back(newItem);
}

void viewItems()
{
}

void updateItem()
{
    string name;
    cout << "\nEnter item to update!: ";
    cin >> name;

    for (auto &item : inventory)
    {
        if (item.name == name)
        {
            int change;
            cout << "Enter quantity change (+ to add, - to reduce): ";
            cin >> change;

            if (item.quantity + change < 0)
            {
                cout << "Quantity cannot be negative!!\n";
                return;
            }
        }
    }

    cout << "Item not found!!\n";
}

void deleteItem()
{
    string name;

    cout << "Enter the name to remove from inventory: ";
    cin >> name;

    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].name == name)
        {
            inventory.erase(inventory.begin() + i);
            cout << "Item removed!!" << endl;

            return;
        }
    }

    cout << "Item was not found!!" << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n====== INVENTORY MANAGER ======\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Update Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Search Item\n";
        cout << "6. "
    }
}