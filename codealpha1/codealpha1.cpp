// codealpha1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string& desc) : description(desc), completed(false) {}

    void markAsCompleted() {
        completed = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task was added ." << std::endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markAsCompleted();
            std::cout << "Task completed." << std::endl;
        }
        else {
            std::cout << "Invalid index. Task not found." << std::endl;
        }
    }

    void viewTasks() const {
        std::cout << "YOUR TASKS:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].isCompleted())
                std::cout << "[X] ";
            else
                std::cout << "[ ] ";
            std::cout << tasks[i].getDescription() << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string description;

    while (true) {
        std::cout << "\n1. Add a task\n2. Mark a task as completed\n3. View tasks\n4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); 
        switch (choice) {
        case 1:
            std::cout << " ENTER TASK DESCRIPTION : ";
            std::getline(std::cin, description);
            todoList.addTask(description);
            break;
        case 2:
            int index;
            std::cout << "ENTER THE INDEX OF A TASK TO MARK AS COMPLETED ";
            std::cin >> index;
            std::cin.ignore(); 
            todoList.markTaskAsCompleted(index - 1);
            break;
        case 3:
            todoList.viewTasks();
            break;
        case 4:
            std::cout << " EXISTING PROGRAM" << std::endl;
            return 0;
        default:
            std::cout << " INVALID CHOICE ENTER A NUMBER BETWEEN 1 AND 4" << std::endl;
        }
    }

    return 0;
}