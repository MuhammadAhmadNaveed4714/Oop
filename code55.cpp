#include <iostream>
#include <string>
using namespace std;

// Enum for task priority
enum class Priority
{
    Low = 1,
    Medium = 2,
    High = 3
};

// Enum for task status
enum class Status
{
    Pending = 0,
    InProgress = 1,
    Completed = 2,
    Canceled = 3
};

// Enum for task category
enum class Category
{
    Work = 0,
    Personal = 1,
    Study = 2,
    Shopping = 3
};

// Union for task-specific details (using pointers for string data)
union TaskDetails
{
    int workId;
    // Use a pointer to string instead of a string object in the union
    string* personalDetails;
    int chapters;
    int itemCount;
};

// Struct for task
struct Task
{
    string title;
    string description;
    Priority priority;
    Status status;
    Category category;
    TaskDetails details;
};

// Function to create a task
Task createTask()
{
    Task task;
    cout << "\nEnter task title: ";
    getline(cin, task.title);
    cout << "Enter task description: ";
    getline(cin, task.description);

    int priority = 0;
    cout << "Choose Priority (1 for Low, 2 for Medium, 3 for High): ";
    cin >> priority;
    task.priority = static_cast<Priority>(priority);

    int status = 0;
    cout << "Choose status (0 for Pending, 1 for In Progress, 2 for Completed, 3 for Canceled): ";
    cin >> status;
    task.status = static_cast<Status>(status);

    int category = 0;
    cout << "Choose category (0 for Work, 1 for Personal, 2 for Study, 3 for Shopping): ";
    cin >> category;
    task.category = static_cast<Category>(category);

    cin.ignore();  // To clear the newline left by previous input
    switch (task.category)
    {
    case Category::Work:
        cout << "Enter work ID: ";
        cin >> task.details.workId;
        break;
    case Category::Personal:
        task.details.personalDetails = new string;
        cout << "Enter personal details: ";
        cin.ignore();  // To clear the newline left by previous input
        getline(cin, *task.details.personalDetails);
        break;
    case Category::Study:
        cout << "Enter number of chapters: ";
        cin >> task.details.chapters;
        break;
    case Category::Shopping:
        cout << "Enter number of items: ";
        cin >> task.details.itemCount;
        break;
    }

    return task;
}

// Function to display a task
void displayTask(const Task& task)
{
    cout << "\nTitle: " << task.title;
    cout << "\nDescription: " << task.description;
    cout << "\nPriority: ";
    switch (task.priority)
    {
    case Priority::Low:
        cout << "Low";
        break;
    case Priority::Medium:
        cout << "Medium";
        break;
    case Priority::High:
        cout << "High";
        break;
    }

    cout << "\nStatus: ";
    switch (task.status)
    {
    case Status::Pending:
        cout << "Pending";
        break;
    case Status::InProgress:
        cout << "In Progress";
        break;
    case Status::Completed:
        cout << "Completed";
        break;
    case Status::Canceled:
        cout << "Canceled";
        break;
    }

    cout << "\nCategory: ";
    switch (task.category)
    {
    case Category::Work:
        cout << "Work\n";
        cout << "Work ID: " << task.details.workId;
        break;
    case Category::Personal:
        cout << "Personal\n";
        cout << "Personal Details: " << *task.details.personalDetails;
        break;
    case Category::Study:
        cout << "Study\n";
        cout << "Chapters to study: " << task.details.chapters;
        break;
    case Category::Shopping:
        cout << "Shopping\n";
        cout << "Items to buy: " << task.details.itemCount;
        break;
    }
}

// Function to delete allocated memory (important to avoid memory leaks)
void cleanupTask(Task& task)
{
    if (task.category == Category::Personal)
    {
        delete task.details.personalDetails;
        task.details.personalDetails = nullptr;
    }
}

int main()
{
    Task task = createTask();
    displayTask(task);
    cleanupTask(task);  // Clean up dynamically allocated memory
    return 0;
}
