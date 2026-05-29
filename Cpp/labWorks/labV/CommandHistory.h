#pragma once

#include "ICommand.h"
#include <memory>
#include <vector>

using namespace std;

// Invoker: история команд для execute / undo
class CommandHistory {
    vector<unique_ptr<ICommand>> done;

public:
    void executeCommand(unique_ptr<ICommand> cmd) {
        cmd->execute();
        done.push_back(std::move(cmd));
    }

    bool undoLast() {
        if (done.empty())
            return false;
        done.back()->undo();
        done.pop_back();
        return true;
    }

    size_t depth() const { return done.size(); }
};
