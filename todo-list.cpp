#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {
private:
    string description;
    bool completed;

public:
    Task(const string& desc) : description(desc), completed(false) {}

    const string& getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void markAsCompleted() {
        completed = true;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDesc) {
        tasks.emplace_back(taskDesc);
        cout << "Task added: " << taskDesc << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].getDescription();
                if (tasks[i].isCompleted()) {
                    cout << " (Completed)";
                } else {
                    cout << " (Pending)";
                }
                cout << endl;
            }
        }
    }

    void markTaskAsCompleted(int index) {
        if (index < 1 || index > static_cast<int>(tasks.size())) {
            cout << "Invalid index." << endl;
        } else {
            tasks[index - 1].markAsCompleted();
            cout << "Marked task as completed: " << tasks[index - 1].getDescription() << endl;
        }
    }

    void removeTask(int index) {
        if (index < 1 || index > static_cast<int>(tasks.size())) {
            cout << "Invalid index." << endl;
        } else {
            cout << "Removed task: " << tasks[index - 1].getDescription() << endl;
            tasks.erase(tasks.begin() + index - 1);
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDesc;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore the newline character from previous input
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskAsCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }
    }

    return 0;
}

