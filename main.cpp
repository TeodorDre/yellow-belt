#include "iostream"
#include "vector"

using namespace std;

int main() {
    uint64_t result = 0;

    int64_t container_count;
    cin >> container_count;

    int64_t material_density;
    cin >> material_density;

    while (container_count > 0) {
        int64_t w, h, d;

        cin >> w >> h >> d;

        int64_t container_result = w * h * d;
        container_result = material_density * container_result;

        result += container_result;

        container_count--;
    }

    cout << result << endl;
}