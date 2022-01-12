#include <iostream>
#include "sstream"

using namespace std;

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
    }

    Matrix(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        rows = num_rows;
        cols = num_cols;
    }

    void Reset(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        rows = num_rows;
        cols = num_cols;
    }

    int At(int num_rows, int num_cols) const {
        if (num_rows > rows || num_cols > cols) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        return 0;
    }

    int *At(int num_rows, int num_cols) {
        if (num_rows > rows || num_cols > cols) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        return nullptr;
    }

    int GetNumRows() const {
        return rows;
    }

    int GetNumCols() const {
        return cols;
    }

private:
    int rows;
    int cols;
};

void RunCommand(stringstream &stream, string command) {
    stream << command << endl;
}

void ExecuteCommands(istream &stream) {
    string command_line;

    while (getline(stream, command_line)) {
        cout << command_line;
    }
}

void RunTest() {
    stringstream stream;
    RunCommand(stream, "TEST");

    ExecuteCommands(stream);
}

void RunProduction() {
    ExecuteCommands(cin);
};

int main() {
    RunTest();

    return 0;
}
