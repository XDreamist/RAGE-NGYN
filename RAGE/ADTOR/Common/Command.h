#pragma once

#include <stack>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class CommandManager {
public:
    void executeCommand(Command* command) {
        command->execute();
        undoStack.push(command);
        // Clear the redo stack if a new command is executed
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            Command* command = undoStack.top();
            undoStack.pop();
            command->undo();
            redoStack.push(command);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            Command* command = redoStack.top();
            redoStack.pop();
            command->execute();
            undoStack.push(command);
        }
    }

private:
    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;
};