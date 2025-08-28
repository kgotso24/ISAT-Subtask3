#include <iostream>
#include <string>

// Define a constant for the maximum number of orders.
const int MAX_ORDERS = 50;
// Define a constant for the price per Magwinya.
const float PRICE_PER_MAGWINYA = 5.50; // New: Fixed price per Magwinya (R5.50)

using namespace std;

// Main function where the program execution begins.
int main() {
    // 1. Create the four parallel arrays to store order data.
    string orderIDs[MAX_ORDERS];
    string customerNames[MAX_ORDERS];
    int numMagwinyas[MAX_ORDERS];
    float totalCosts[MAX_ORDERS];
    int orderCount = 0; // Tracks the number of valid orders.

    // 2. Initialize the first 10 elements with sample data.
    // Note: Total costs are kept as provided for consistency with the original data.
    orderIDs[0] = "101"; customerNames[0] = "Thabo"; numMagwinyas[0] = 3; totalCosts[0] = 15.75;
    orderIDs[1] = "102"; customerNames[1] = "Lerato"; numMagwinyas[1] = 5; totalCosts[1] = 30.50;
    orderIDs[2] = "103"; customerNames[2] = "Nomvula"; numMagwinyas[2] = 2; totalCosts[2] = 10.00;
    orderIDs[3] = "104"; customerNames[3] = "Sipho"; numMagwinyas[3] = 4; totalCosts[3] = 22.00;
    orderIDs[4] = "105"; customerNames[4] = "Bongani"; numMagwinyas[4] = 6; totalCosts[4] = 40.25;
    orderIDs[5] = "106"; customerNames[5] = "Lindiwe"; numMagwinyas[5] = 1; totalCosts[5] = 5.50;
    orderIDs[6] = "107"; customerNames[6] = "Jabulani"; numMagwinyas[6] = 3; totalCosts[6] = 18.00;
    orderIDs[7] = "108"; customerNames[7] = "Ayanda"; numMagwinyas[7] = 2; totalCosts[7] = 12.75;
    orderIDs[8] = "109"; customerNames[8] = "Kgosi"; numMagwinyas[8] = 6; totalCosts[8] = 28.00;
    orderIDs[9] = "110"; customerNames[9] = "Refilwe"; numMagwinyas[9] = 4; totalCosts[9] = 24.50;
    
    orderCount = 10; // Update the order count.

    // 3. Initialize the remaining Order IDs to "0" as a placeholder for empty slots.
    for (int i = 10; i < MAX_ORDERS; i++) {
        orderIDs[i] = "0";
    }

    int choice;
    do {
        // Display the menu to the user.
        cout << "\n--- Magwinya Magic Order Management System ---" << endl;
        cout << "1. Add a new order" << endl;
        cout << "2. Display all orders" << endl;
        cout << "3. Find an order by Order ID" << endl;
        cout << "4. Calculate and display total revenue" << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Use an if-else if-else structure to handle user choice.
        if (choice == 1) {
            // Option 1: Add a new order.
            if (orderCount >= MAX_ORDERS) {
                cout << "Error: The system has reached the maximum order limit (50)." << endl;
            } else {
                string newCustomerName;
                int newNumMagwinyas;

                cout << "Enter customer name: ";
                cin.ignore(); // Clears the input buffer.
                getline(cin, newCustomerName);

                cout << "Enter number of Magwinyas ordered: ";
                cin >> newNumMagwinyas;

                // New: Calculate total cost based on number of Magwinyas.
                float newTotalCost = newNumMagwinyas * PRICE_PER_MAGWINYA;
                cout << "Calculated total cost: R" << newTotalCost << endl;

                // Generate a new Order ID by incrementing the last valid ID.
                int lastOrderID = stoi(orderIDs[orderCount - 1]);
                string newOrderID = to_string(lastOrderID + 1);

                // Add the new order to the arrays at the next available position.
                orderIDs[orderCount] = newOrderID;
                customerNames[orderCount] = newCustomerName;
                numMagwinyas[orderCount] = newNumMagwinyas;
                totalCosts[orderCount] = newTotalCost;
                
                orderCount++; // Increase the count of orders.
                cout << "Order " << newOrderID << " added successfully!" << endl;
            }
        } else if (choice == 2) {
            // Option 2: Display all orders.
            cout << "\n--- All Orders ---" << endl;
            cout << "Order ID\tCustomer Name\tNumber of Magwinyas\tTotal Cost" << endl;
            cout << "------------------------------------------------------------------" << endl;
            
            // Loop through the valid orders and print their details.
            for (int i = 0; i < orderCount; ++i) {
                if (orderIDs[i] != "0") { // Only display valid orders.
                    cout << orderIDs[i] << "\t\t" << customerNames[i] << "\t\t"
                         << numMagwinyas[i] << "\t\t\t" << totalCosts[i] << endl;
                }
            }
        } else if (choice == 3) {
            // Option 3: Find an order by Order ID.
            string searchID;
            bool found = false;
            cout << "Enter the Order ID to find: ";
            cin >> searchID;
            
            // Loop through the arrays to find a matching ID.
            for (int i = 0; i < orderCount; ++i) {
                if (orderIDs[i] == searchID) {
                    cout << "\nOrder found:" << endl;
                    cout << "Order ID: " << orderIDs[i] << endl;
                    cout << "Customer Name: " << customerNames[i] << endl;
                    cout << "Number of Magwinyas: " << numMagwinyas[i] << endl;
                    cout << "Total Cost: R" << totalCosts[i] << endl;
                    found = true;
                    break; // Exit loop once found.
                }
            }
            if (!found) {
                cout << "Order with ID " << searchID << " not found." << endl;
            }
        } else if (choice == 4) {
            // Option 4: Calculate total revenue.
            float totalRevenue = 0.0;
            // Sum up the total costs of all valid orders.
            for (int i = 0; i < orderCount; ++i) {
                totalRevenue += totalCosts[i];
            }
            cout << "Total revenue generated: R" << totalRevenue << endl;
        } else if (choice == 5) {
            // Option 5: Exit the program.
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            // Handle invalid input.
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
