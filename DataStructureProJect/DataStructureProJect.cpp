#include <iostream>
#include "clsMyDynamicArray.h" 
#include <iomanip> 
#include "clsMyQueue.h"
#include "clsDblLinkedList.h"
#include <string>
using namespace std;

void MenuList(clsDynamicArray<string>& m) {
     m.SetItem(0,"Pizza");
     m.SetItem(1,"Burger");
     m.SetItem(2,"Fish");
     m.SetItem(3,"Soup");
     m.SetItem(4,"Chicken");
     m.SetItem(5,"Pasta");
     m.SetItem(6,"Steak");
     m.SetItem(7,"Sandwich");
     m.SetItem(8,"Cake");
     m.SetItem(9, "Cookie");
     cout << "----------------------\n";
     cout << "        Menu\n";
     cout << "----------------------\n";

     for (int i = 0; i < m.Size(); i++) {
         cout << setw(2) << i + 1 << ". " << m.GetItem(i) << endl;
     }
     cout << "----------------------\n";
}

void FindRecipeByIndex(clsDynamicArray<string>& g,int i) {

    cout<<"The Recipe With Index["<<i<<"] Is " << g.GetItem(i);
}


void FindRecipeByName(clsDynamicArray<string>& ff, string recipeName) {

    int index = ff.Find(recipeName); 

    if (index != -1) {  
        cout << "Recipe found: " << recipeName <<" at index " << index << endl;
    }
    else {
        cout << "Recipe not found: " << recipeName << endl;
    }
}

void ClearMenu(clsDynamicArray<string>& ff) {
    ff.Clear();
    cout << "Menu cleared.\n";
}



//////////////////////////////////////////


enum MenuOptions {
    ViewMenu = 1,
    FindByIndex = 2,
    FindByName = 3,
    ClearMenuOption = 4,  
    Exit = 5
};

void ManageMenu(clsDynamicArray<string>& m) {
    int choice;
    string recipeName;
    int index;

    do {
        cout << "----------------------\n";
        cout << "        Menu\n";
        cout << "----------------------\n";
        cout << "1. View Menu\n";
        cout << "2. Find Recipe by Index\n";
        cout << "3. Find Recipe by Name\n";
        cout << "4. Clear Menu\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case ViewMenu:
            MenuList(m); 
            break;

        case FindByIndex:
            cout << "Enter index: ";
            cin >> index;
            FindRecipeByIndex(m, index);  
            break;

        case FindByName:
            cout << "Enter recipe name: ";
            cin >> recipeName;
            FindRecipeByName(m, recipeName);  
            break;

        case ClearMenuOption:  
            ClearMenu(m);  
            break;

        case Exit:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }//☺☺☺☺☺

    } while (choice != Exit);
}



void CustomersMenu(clsMyQueue<string>& customerQueue)
{
    customerQueue.push("Khaled Hagag");
    customerQueue.push("Ahmed Osama");
    customerQueue.push("Omar Abd-Elrady");
    customerQueue.push("Abdullah Ebrahim");
    customerQueue.push("Zyad El-Daly");
    customerQueue.push("Mohamed El-Said");

}


void pushCustomer(clsMyQueue<string>& customerQueue, const string& name) {
   
    customerQueue.push(name);
    cout << "Customer added: " <<endl;
    cout << endl;
}


void printt(clsMyQueue<string>& customerQueue)
{
    if (customerQueue.IsEmpty()) {
        cout << "No customers in the queue." << endl;
        return;
    }

    cout << "----------------------" << endl;
    cout << "   Customer Queue     " << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < customerQueue.Size(); i++) {
        cout << setw(2) << i + 1 << ". " << customerQueue.GetItem(i) << endl;
    }

    cout << "----------------------" << endl;
    cout << "Total Customers: " << customerQueue.Size() << endl; 
    cout << "----------------------" << endl;
}


void serveCustomer(clsMyQueue<string>& customerQueue) {
    if (!customerQueue.IsEmpty()) {
        string customer = customerQueue.front();
        customerQueue.pop();
        cout << "Serving " << customer << "..." << endl;
    }
    else {
        cout << "No customers in the queue." << endl;
    }
}

/////////////////////////////////////////////

enum MenuuOptions {
    AddCustomers = 1,
    AddSingleCustomer=2,
    PrintQueue=3,
    ServeCustomer=4,
    Exitt=5
};


void Customers(clsMyQueue<string>& customerQueue) {
    int choice;
    do {
        cout << "\n----------------------\n";
        cout << "      Main Menu       \n";
        cout << "----------------------\n";
        cout << "1. Add Default Customers\n";
        cout << "2. Add a Single Customer\n";
        cout << "3. Print Customer Queue\n";
        cout << "4. Serve a Customer\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case AddCustomers:
            Customers(customerQueue);
            cout << "Default customers added.\n";
            break;
        case AddSingleCustomer: {
            string name;
            cout << "Enter customer name: ";
            cin.ignore(); 
            getline(cin, name);
            pushCustomer(customerQueue, name);
            break;
        }
        case PrintQueue:
            printt(customerQueue);
            break;
        case ServeCustomer:
            serveCustomer(customerQueue);
            break;
        case Exit:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != Exit);
}



//LooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooL

void InventoryElements(clsDblLinkedList<string>& inventory)
{

    inventory.InsertAtEnd("Cheese");
    inventory.InsertAtEnd("Tomato");
    inventory.InsertAtEnd("Lettuce");
    inventory.InsertAtEnd("Pepperoni");
    inventory.InsertAtEnd("Beef ");
    inventory.InsertAtEnd("Fish ");
    inventory.InsertAtEnd("Shrimp");
    inventory.InsertAtEnd("Chicken");
    inventory.InsertAtEnd("Flour");
    inventory.InsertAtEnd("Oil");
    inventory.InsertAtEnd("Parmesan");
    inventory.InsertAtEnd("Butter");
    inventory.InsertAtEnd("Bread");
    inventory.InsertAtEnd("Vanilla");
    inventory.InsertAtEnd("Eggs");
    inventory.InsertAtEnd("Sugar");
    inventory.InsertAtEnd("Chocolate Chips");

}


void AddToInventory(clsDblLinkedList<string>& inventory,string Value) {
    inventory.InsertAtEnd(Value);
    cout << "Updated Inventory: ";

}


void PrintInventoryEle(clsDblLinkedList<string>& inventory) {
    cout << "----------------------" << endl;
    cout << "   Inventory List     " << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < inventory.Size(); i++) {
        cout << setw(2) << i + 1 << ". " << inventory.GetItem(i) << endl;
    }

    cout << "----------------------" << endl;
    cout << "Total Items: " << inventory.Size() << endl;
    cout << "----------------------" << endl;
}

/////////////////////////////////////////
enum InventoryOptions {
    AddCustomItem = 1,
    PrintInventory = 2,
    Exittt = 3
};

void InventoryMenu(clsDblLinkedList<string>& inventory) {
    int choice;
    string item;

    InventoryElements(inventory);
    cout << "Default items added to inventory.\n";

    do {
        cout << "\nInventory Menu:\n";
        cout << "1. Add a custom item to inventory\n";
        cout << "2. Print inventory\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case AddCustomItem:  
            cout << "Enter item to add: ";
            cin.ignore();  
            getline(cin, item);
            AddToInventory(inventory, item);
            break;

        case PrintInventory:  
            PrintInventoryEle(inventory);
            break;

        case Exittt:  
            cout << "Exiting menu.\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != Exittt);
}

////////////////////////////

void addDefaultOrders(clsMyQueue<string>& orderQueue) {
    orderQueue.push("Pizza");
    orderQueue.push("Burger");
    orderQueue.push("Pasta");
    orderQueue.push("Steak");
    orderQueue.push("Sandwich");
    orderQueue.push("Cake");
    orderQueue.push("Ice Cream");
    cout << "Default orders added successfully.\n";
}

void placeOrder(clsMyQueue<string>& OrderQueue,  string& order) {
    OrderQueue.push(order);
    cout << "Order placed: " << order << endl;
}

void processOrder(clsMyQueue<string>& orderQueue) {
    if (!orderQueue.IsEmpty()) {
        string order = orderQueue.front();
        orderQueue.pop();
        cout << "Processing order: " << order << endl;
    }
    else {
        cout << "No orders to process." << endl;
    }
}

void printOrders(clsMyQueue<string>& orderQueue) {
    if (orderQueue.IsEmpty()) {
        cout << "No orders in the queue." << endl;
        return;
    }

    cout << "----------------------" << endl;
    cout << "       Orders         " << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < orderQueue.Size(); i++) {
        cout << setw(2) << i + 1 << ". " << orderQueue.GetItem(i) << endl;
    }

    cout << "----------------------" << endl;
    cout << "Total Orders: " << orderQueue.Size() << endl;
    cout << "----------------------" << endl;
}

enum OrderMenuOptions {
    PlaceNewOrder = 1,
    ProcessOrder,
    PrintOrders,
    ExitMenu
};

void OrderMenu(clsMyQueue<string>& orderQueue) {

    addDefaultOrders(orderQueue);

    int choice;
    string order;

    do {
        cout << "\nOrder Management Menu:\n";
        cout << "1. Place a new order\n";
        cout << "2. Process an order\n";
        cout << "3. Print all orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case PlaceNewOrder:
            cout << "Enter the order: ";
            cin.ignore();
            getline(cin, order);
            placeOrder(orderQueue, order);
            break;

        case ProcessOrder:
            processOrder(orderQueue);
            break;

        case PrintOrders:
            printOrders(orderQueue);
            break;

        case ExitMenu:
            cout << "Exiting menu.\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != ExitMenu);
}

///////////////////////////////////////////

enum Final {
    MenuScreen = 1,
    CustomerScreen = 2,
    InventoryScreen = 3,
    OrderMenus = 4,
    Exitttt = 5


};

void OrderMenu(clsDynamicArray<string>& m, clsMyQueue<string>& customerQueue, clsDblLinkedList<string>& inventory,clsMyQueue<string>& orderQueue) {

    int choice;

    do {
        cout << "1.MenuScreen\n";
        cout << "2. CustomerScreen\n";
        cout << "3. InventoryScreen\n";
        cout << "4. OrderMenu\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case MenuScreen:
            ManageMenu(m);
            break;

        case CustomerScreen:
            Customers(orderQueue);
            break;

        case InventoryScreen:
            InventoryMenu(inventory);
            break;

        case OrderMenus:
            OrderMenu(orderQueue);
            break;

        case Exitttt :
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != Exitttt);
}


int main() {
    cout << "*******************************" << endl;
    cout << "   Welcome to our restaurant!" << endl;
    cout << "*******************************" << endl;
   clsDynamicArray<string> arr(10);
   clsMyQueue<string> customerQueue;
   clsDblLinkedList<string> inventory;
   clsMyQueue<string> hh;
   OrderMenu(arr, customerQueue, inventory, hh);
    return 0;
}

// يا الله سبحاااااااااااااااااانه 
//Fatih Sultan Mohamed 