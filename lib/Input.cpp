#include <vector>
#include <string>
#include <fstream>
#include "Input.hpp"

std::vector<std::string> input::readLines(const char* fileName) {
    std::string line;
    std::vector<std::string> lines;
    std::ifstream file(fileName);

    if (!file) {
        return lines;
    }

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    return lines;
}

std::vector<std::string> input::split(const std::string& input, const std::string& delimiter) {
    int position = 0;
    int delimiterIndex = 0;
    std::string mutableInput = input;
    std::string result;
    std::vector<std::string> results;

    while (!mutableInput.empty()) {
        result = mutableInput;
        delimiterIndex = mutableInput.find(delimiter);

        if (delimiterIndex != -1) {
            result = mutableInput.substr(0, delimiterIndex);
        }

        results.push_back(result);
        mutableInput.erase(0, result.length() + delimiter.length());
    }

    return results;
}

std::vector<int> input::splitInt(const std::string& input, const std::string& delimiter) {
    std::vector<int> result;
    std::vector<std::string> numberStrings = input::split(input, delimiter);

    for (std::string numberString : numberStrings) {
        if (!numberString.empty()) {
            result.push_back(stoi(numberString));
        }
    }

    return result;
}

std::vector<long> input::splitLong(const std::string& input, const std::string& delimiter) {
    std::vector<long> result;
    std::vector<std::string> numberStrings = input::split(input, delimiter);

    for (std::string numberString : numberStrings) {
        if (!numberString.empty()) {
            result.push_back(stol(numberString));
        }
    }

    return result;
}

std::vector<long long> input::splitLongLong(const std::string& input, const std::string& delimiter) {
    std::vector<long long> result;
    std::vector<std::string> numberStrings = input::split(input, delimiter);

    for (std::string numberString : numberStrings) {
        if (!numberString.empty()) {
            result.push_back(stoll(numberString));
        }
    }

    return result;
}

void input::remove(std::string& input, const char charToRemove) {
    input.erase(remove(input.begin(), input.end(), charToRemove), input.end());
}
