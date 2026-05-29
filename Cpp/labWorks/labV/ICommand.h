#pragma once

#include <string>

using namespace std;

// Command: инкапсулирует действие и поддерживает отмену
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual string describe() const = 0;
};
