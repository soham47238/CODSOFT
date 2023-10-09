#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added successfully!\n";
    }

    void viewTasks() {
        cout << "Tasks:\n";
        int taskNumber = 1;
        for (const auto& task : tasks) {
            cout << taskNumber << ". ";
            cout << "[" << (task.completed ? "X" : " ") << "] ";
            cout << task.description << endl;
            taskNumber++;
        }
    }

    void markTaskAsCompleted(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }

    void removeTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;

    cout<<endl<<endl;
	cout<<" ====================================================="<<endl;
    cout<<"|                        TO DO LIST                   |"<<endl;
    cout<<" ====================================================="<<endl;

    do {
        cout<<endl;
        cout << "1. ADD TASK\n\n";
        cout << "2. VIEW ALL TASKS\n\n";
        cout << "3. MARK TASK AS COMPLETE \n\n";
        cout << "4. REMOVE TASK\n\n";
        cout << "5. EXIT\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                int taskNumber;
                cout << "Enter task number to be mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "THANK YOU SO MUCH..\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
