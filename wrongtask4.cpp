#include <iostream>
#include <string>
using namespace std;

// Enums for Priority, Status, and Category
enum Priority { Low = 1, Medium = 2, High = 3 };
enum Status { Pending = 0, InProgress = 1, Completed = 2, Canceled = 3 };
enum Category { Work = 0, Personal = 1, Study = 2, Shopping = 3 };

// Union for category-specific task details
union TaskDetails {
    int workId;             // For Work tasks
    string personalDetails; // For Personal tasks
    int chapters;           // For Study tasks
    int itemCount;          // For Shopping tasks
};

// Struct to represent a Task
struct Task {
    string title;
    string description;
    Priority priority;
    Status status;
    Category category;
    TaskDetails details;
};

// Function to create a task
void createTask(Task& t) {
    // Get task details from the user
    cout << "Enter task title: ";
    getline(cin, t.title);

    cout << "Enter task description: ";
    getline(cin, t.description);

    int priorityChoice, statusChoice, categoryChoice;

    cout << "Choose Priority (1 for Low, 2 for Medium, 3 for High): ";
    cin >> priorityChoice;
    t.priority = static_cast<Priority>(priorityChoice);

    cout << "Choose Status (0 for Pending, 1 for In Progress, 2 for Completed, 3 for Canceled): ";
    cin >> statusChoice;
    t.status = static_cast<Status>(statusChoice);

    cout << "Choose Category (0 for Work, 1 for Personal, 2 for Study, 3 for Shopping): ";
    cin >> categoryChoice;
    t.category = static_cast<Category>(categoryChoice);

    // Clear input buffer before reading category-specific details
    cin.ignore();

    // Collect category-specific details
    switch (t.category) {
    case Work:
        cout << "Enter work ID: ";
        cin >> t.details.workId;
        break;
    case Personal:
        cout << "Enter personal details: ";
        cin.ignore();  // To clear the newline left by the previous cin
        getline(cin, t.details.personalDetails);
        break;
    case Study:
        cout << "Enter number of chapters: ";
        cin >> t.details.chapters;
        break;
    case Shopping:
        cout << "Enter number of items to buy: ";
        cin >> t.details.itemCount;
        break;
    }
}

// Function to display a task
void displayTask(const Task& t) {
    // Display basic task information
    cout << "\nTitle: " << t.title << endl;
    cout << "Description: " << t.description << endl;

    // Display priority as a string
    cout << "Priority: ";
    switch (t.priority) {
    case Low: cout << "Low"; break;
    case Medium: cout << "Medium"; break;
    case High: cout << "High"; break;
    }
    cout << endl;

    // Display status as a string
    cout << "Status: ";
    switch (t.status) {
    case Pending: cout << "Pending"; break;
    case InProgress: cout << "InProgress"; break;
    case Completed: cout << "Completed"; break;
    case Canceled: cout << "Canceled"; break;
    }
    cout << endl;

    // Display category as a string
    cout << "Category: ";
    switch (t.category) {
    case Work: cout << "Work"; break;
    case Personal: cout << "Personal"; break;
    case Study: cout << "Study"; break;
    case Shopping: cout << "Shopping"; break;
    }
    cout << endl;

    // Display category-specific details
    switch (t.category) {
    case Work:
        cout << "Work ID: " << t.details.workId << endl;
        break;
    case Personal:
        cout << "Personal Details: " << t.details.personalDetails << endl;
        break;
    case Study:
        cout << "Chapters to Study: " << t.details.chapters << endl;
        break;
    case Shopping:
        cout << "Items to Buy: " << t.details.itemCount << endl;
        break;
    }
}

// Main function
int main() {
    Task task;  // Declare a task instance

    // Display welcome message and task creation process
    cout << "Welcome to the Task Management System!" << endl;

    // Create a task by prompting the user for details
    createTask(task);

    // Display the task information
    cout << "\nTask Information:" << endl;
    displayTask(task);

    return 0;
}
