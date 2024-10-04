#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Global vector to store tasks
vector<Task> todo_list;

void add_task(const string& task) {
    Task new_task = {task, false}; // Create a new task with 'completed' set 
    //to false
    todo_list.push_back(new_task);
    cout << "Task '" << task << "' added." << endl;
}

void view_tasks() {
    if (todo_list.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    for (size_t i = 0; i < todo_list.size(); ++i) {
        cout << i + 1 << ". " << todo_list[i].description << " [";
        cout << (todo_list[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void mark_task_completed(int task_number) {
    if (task_number > 0 && task_number <= todo_list.size()) {
        todo_list[task_number - 1].completed = true;
        cout << "Task '" << todo_list[task_number - 1].description << "' marked as completed." << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void remove_task(int task_number) {
    if (task_number > 0 && task_number <= todo_list.size()) {
        cout << "Task '" << todo_list[task_number - 1].description << "' removed." << endl;
        todo_list.erase(todo_list.begin() + task_number - 1);
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    int choice, task_number;
    string task_description;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the task description: ";
                cin.ignore();
                getline(cin, task_description);
                add_task(task_description);
                break;

            case 2:
                view_tasks();
                break;

            case 3:
                cout << "Enter the task number to mark as completed: ";
                cin >> task_number;
                mark_task_completed(task_number);
                break;

            case 4:
                cout << "Enter the task number to remove: ";
                cin >> task_number;
                remove_task(task_number);
                break;

            case 5:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid option, please try again." << endl;
        }
    }

    return 0;
}

