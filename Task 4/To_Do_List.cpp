#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for formatting

// Structure to represent each task
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Class to manage the to-do list
class ToDoList {
private:
    std::vector<Task> tasks;

public:
    // Function to add a new task
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << " Task added: \"" << description << "\"\n";
    }

    // Function to view all tasks with their status
    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << " Your to-do list is currently empty! Use option 1 to add tasks.\n";
            return;
        }
        std::cout << "\n----  Your To-Do List  ----\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << " [" << (tasks[i].completed ? " Completed" : " Pending") << "]\n";
        }
        std::cout << "-------------------------------\n\n";
    }

    // Function to mark a task as completed
    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << " Task marked as completed: \"" << tasks[taskNumber - 1].description << "\"\n";
        } else {
            std::cout << " Invalid task number. Please try again.\n";
        }
    }

    // Function to remove a task
    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            std::cout << " Task removed: \"" << tasks[taskNumber - 1].description << "\"\n";
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            std::cout << " Invalid task number. Please try again.\n";
        }
    }
};

// Function to display the menu
void displayMenu() {
    std::cout << "\n----  To-Do List Manager  ----\n";
    std::cout << "1.  Add Task\n";
    std::cout << "2.  View Tasks\n";
    std::cout << "3.  Mark Task as Completed\n";
    std::cout << "4.  Remove Task\n";
    std::cout << "5.  Exit\n";
    std::cout << "----------------------------------\n";
    std::cout << "Choose an option (1-5): ";
}

int main() {
    ToDoList toDoList;
    int choice;
    std::string taskDescription;
    size_t taskNumber;

    std::cout << " Welcome to the To-Do List Manager! Let's stay organized and productive!\n";

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the task description: ";
                std::cin.ignore();  // Ignore leftover newline from previous input
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                toDoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskNumber;
                toDoList.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Thank you for using the To-Do List Manager! Goodbye! \n";
                return 0;
            default:
                std::cout << " Invalid choice. Please enter a number from 1 to 5.\n";
        }
    }
}
