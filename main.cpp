#include <iostream>
#include "sstream"
#include "vector"

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

    void PrintValues() {}

private:
    vector<vector<int>> values;

    int rows;
    int cols;
};

istream &operator>>(istream &stream, Matrix &matrix) {
    int rows, cols;

    stream >> rows >> cols;
    matrix.Reset(rows, cols);

    return stream;
}

ostream &operator<<(ostream &stream, Matrix &matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumCols() << endl;

    return stream;
}

bool operator==(const Matrix &left, const Matrix &right) {
    return false;
}

Matrix operator+(const Matrix &left, const Matrix &right) {
    if (left.GetNumCols() != right.GetNumCols() && left.GetNumRows() != right.GetNumRows()) {
        throw invalid_argument("Matrix must have equal size");
    }
}

void RunCommand(stringstream &stream, string command) {
    stream << command << endl;
}

void ExecuteCommands(istream &stream) {
    Matrix one;
    stream >> one;
    cout << one;
}

void RunTest() {
    stringstream stream;
    RunCommand(stream, "3 5");

    ExecuteCommands(stream);
}

void RunProduction() {
    ExecuteCommands(cin);
};

int main() {
    RunTest();

    return 0;
}
