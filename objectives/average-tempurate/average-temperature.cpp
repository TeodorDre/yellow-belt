#include "iostream"
#include "vector"

using namespace std;

int main() {
    uint32_t days_count;
    cin >> days_count;

    int64_t total_degrees = 0;
    vector<int64_t> day_degrees;

    while (days_count > 0) {
        int degree;
        cin >> degree;

        total_degrees += degree;
        day_degrees.push_back(degree);

        days_count--;
    }

    auto day_degrees_size = static_cast<int64_t>(day_degrees.size());
    int64_t average_degree = total_degrees / day_degrees_size;

    vector<int> days_average_indexes;

    for (int i = 0; i < day_degrees_size; i++) {
        int64_t &entry = day_degrees[i];

        if (entry > average_degree) {
            days_average_indexes.push_back(i);
        }
    }

    cout << static_cast<int64_t>(days_average_indexes.size()) << endl;

    for (auto &i : days_average_indexes) {
        cout << i << " ";
    }

    return 0;
}