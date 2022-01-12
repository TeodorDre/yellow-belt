#include <iostream>
#include "sstream"
#include "vector"

using namespace std;

/**
 * 3, 3
 *
 * [1, 1, 1]
 * [1, 1, 1]
 * [1, 1, 1]
 */
class Matrix {
public:
    vector<vector<int>> values;

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

        values.erase(values.begin(), values.end());
        values.resize(rows);
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

    void PrintValues() const {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << values[r][c] << " ";
            }

            cout << endl;
        }
    }

private:
    int rows;
    int cols;
};

istream &operator>>(istream &stream, Matrix &matrix) {
    int rows, cols;

    stream >> rows >> cols;
    matrix.Reset(rows, cols);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int value;
            stream >> value;
            matrix.values[r].push_back(value);
        }
    }

    return stream;
}

ostream &operator<<(ostream &stream, Matrix &matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumCols() << endl;

    matrix.PrintValues();

    return stream;
}

bool operator==(const Matrix &left, const Matrix &right) {
    if (left.GetNumRows() != right.GetNumRows() && left.GetNumCols() != right.GetNumCols()) {
        return false;
    }

    return true;
}

Matrix operator+(const Matrix &left, const Matrix &right) {
    if (left.GetNumRows() != right.GetNumRows() && left.GetNumCols() != right.GetNumCols()) {
        throw invalid_argument("Matrix must have equal size");
    }

    Matrix sum_result;

    return sum_result;
}

void RunCommand(stringstream &stream, const string& command) {
    stream << command << endl;
}

void ExecuteCommands(istream &stream) {
    Matrix one;
    Matrix two;
    stream >> one;
    stream >> two;

    cout << one << endl;
    cout << two << endl;
}

void RunTest() {
    stringstream stream;
    RunCommand(stream, "3 5");
    RunCommand(stream, "6 4 -1 9 8");
    RunCommand(stream, "12 1 2 9 -5");
    RunCommand(stream, "-4 0 12 8 6");
    RunCommand(stream, "3 5");
    RunCommand(stream, "5 1 0 -8 23");
    RunCommand(stream, "14 5 -6 6 9");
    RunCommand(stream, "8 0 5 4 1");

    ExecuteCommands(stream);
}

void RunProduction() {
    ExecuteCommands(cin);
};

int main() {
    RunTest();

    return 0;
}
