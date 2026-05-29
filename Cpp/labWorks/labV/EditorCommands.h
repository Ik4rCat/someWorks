#pragma once

#include "ICommand.h"
#include <string>

using namespace std;

class TextBuffer {
    string data;

public:
    const string& text() const { return data; }

    void append(const string& s) { data += s; }

    void removeSuffix(size_t n) {
        if (n > data.size())
            n = data.size();
        data.resize(data.size() - n);
    }
};

class AppendCommand : public ICommand {
    TextBuffer& buffer;
    string chunk;

public:
    AppendCommand(TextBuffer& buf, string s) : buffer(buf), chunk(std::move(s)) {}

    void execute() override { buffer.append(chunk); }

    void undo() override { buffer.removeSuffix(chunk.size()); }

    string describe() const override { return "append \"" + chunk + "\""; }
};
