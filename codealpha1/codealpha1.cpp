// codealpha1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
private:
    string description;
    bool completed;

public:
    Task(const string& desc) : description(desc), completed(false) {}

    void markAsCompleted() {
        completed = true;
    }

   string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task was added ." << endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markAsCompleted();
           cout << "Task completed." << endl;
        }
        else {
          cout << "Invalid index. Task not found." << endl;
        }
    }

    void viewTasks() const {
       cout << "YOUR TASKS:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].isCompleted())
               cout << "[X] ";
            else
               cout << "[ ] ";
           cout << tasks[i].getDescription() << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string description;

    while (true) {
       cout << "\n1. Add a task\n2. Mark a task as completed\n3. View tasks\n4. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;
        cin.ignore(); 
        switch (choice) {
        case 1:
           cout << " ENTER TASK DESCRIPTION : ";
            getline(std::cin, description);
            todoList.addTask(description);
            break;
        case 2:
            int index;
            cout << "ENTER THE INDEX OF A TASK TO MARK AS COMPLETED ";
            cin >> index;
            cin.ignore(); 
            todoList.markTaskAsCompleted(index - 1);
            break;
        case 3:
            todoList.viewTasks();
            break;
        case 4:
           cout << " EXISTING PROGRAM" << endl;
            return 0;
        default:
            cout << " INVALID CHOICE ENTER A NUMBER BETWEEN 1 AND 4" <<endl;
        }
    }

    return 0;
}
