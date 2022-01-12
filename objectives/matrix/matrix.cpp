//
// Created by Andrew Slesarenko on 12.01.2022.
//

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
    // Конструктор по умолчанию. По умолчанию матрица пуста.
    Matrix() {
        rows = 0;
        cols = 0;
    }

    // Конструктор с значениями, матрица не может содержать внутри себя отрицательный набор строк и колонок.
    // Если что идет не так - выбрасываем исключение.
    Matrix(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        rows = num_rows;
        cols = num_cols;

        // Выставляем размер нашего вектора.
        values.resize(num_rows);
    }

    // Метод для сброса строк и колонок. Здесь все примерно также - валидируем, если что бросаем ошибку.
    void Reset(int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        rows = num_rows;
        cols = num_cols;

        // Если мы изменяем уже существующую матрицу (с значениями)
        // То сбрасываем все что было до этого (обнуляем значения в строках)
        values.erase(values.begin(), values.end());
        // И выставляем новый размер.
        values.resize(rows);
    }

    // Получение значение матрица без ссылки.
    int At(int num_rows, int num_cols) const {
        if (num_rows > rows || num_cols > cols) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        return values[num_rows][num_cols];
    }

    // Получение значение матрица с ссылкой.
    int &At(int num_rows, int num_cols) {
        if (num_rows > rows || num_cols > cols) {
            throw out_of_range("Incorrect range of nums and cols");
        }

        // Возвращаем ссылку на значение, чтобы иметь возможность модифицировать нужное значение на лету.
        int &value = values.at(num_rows).at(cols);

        return value;
    }

    // Константа которое возвращает текущее кол-во строк.
    int GetNumRows() const {
        return rows;
    }

    // Константа которое возвращает текущее кол-во колонок.
    int GetNumColumns() const {
        return cols;
    }

    void SetValues(vector<vector<int>> &items) {
        values = items;
    }

    vector<vector<int>> GetValues() const {
        return values;
    }

    // Выводим в консоль текущие значения.
    void PrintValues() const {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << values[r][c] << " ";
            }

            cout << endl;
        }
    }

private:
    // Здесь храним наши значения в формате строка[]: колонки[]
    vector<vector<int>> values;

    // Приватные свойства для хранения значений
    int rows;
    int cols;
};

// Оператор ввода
/**
 * Данные нам приходят в таком формате, считываем их аккуратно через поток.
 * 3 5
 * 6 4 -1 9 8
 * 12 1 2 9 -5
 * -4 0 12 8 6
 */
istream &operator>>(istream &stream, Matrix &matrix) {
    int rows, cols;

    stream >> rows >> cols;
    // Перестраиваем матрицу (выставлем новые значения для строк / колонок)
    matrix.Reset(rows, cols);

    vector<vector<int>> values(rows);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int value;
            stream >> value;
            values[r].push_back(value);
        }
    }

    matrix.SetValues(values);

    return stream;
}

ostream &operator<<(ostream &stream, Matrix &matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

    matrix.PrintValues();

    return stream;
}

bool operator==(const Matrix &left, const Matrix &right) {
    if (left.GetNumRows() != right.GetNumRows() && left.GetNumColumns() != right.GetNumColumns()) {
        return false;
    }

    int rows = left.GetNumRows();
    int cols = left.GetNumColumns();

    vector<vector<int>> left_values = left.GetValues();
    vector<vector<int>> right_values = right.GetValues();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int left_value = left_values[r][c];
            int right_value = right_values[r][c];

            if (left_value != right_value) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const Matrix &left, const Matrix &right) {
    return !(left == right);
}

Matrix operator+(const Matrix &left, const Matrix &right) {
    int left_rows = left.GetNumRows();
    int left_cols = left.GetNumColumns();
    int right_rows = right.GetNumRows();
    int right_cols = right.GetNumColumns();

    if (left_rows != right_rows && left_cols != right_cols) {
        throw invalid_argument("Matrix must have equal size");
    }

    vector<vector<int>> left_values = left.GetValues();
    vector<vector<int>> right_values = right.GetValues();

    int rows = left_rows == 0 ? right_rows : left_rows;
    int cols = left_cols == 0 ? right_cols : left_cols;

    Matrix sum_result(rows, cols);

    vector<vector<int>> final_values(rows);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int left_value = left_values[r][c];
            int right_value = right_values[r][c];

            final_values[r].push_back(left_value + right_value);
        }
    }

    sum_result.SetValues(final_values);

    return sum_result;
}

void RunCommand(stringstream &stream, const string &command) {
    stream << command << endl;
}

void ExecuteCommands(istream &stream) {
    Matrix one;
    Matrix two;
    stream >> one;
    stream >> two;

    Matrix sum = one + two;

    cout << sum;
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
    return 0;
}
