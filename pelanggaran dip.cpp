#include <iostream>
using namespace std;

class MySQLDatabase {
public:
    void connect() {
        cout << "Connecting to MySQL..." << endl;
    }
};

class DataService {
private:
    MySQLDatabase db; // Ketergantungan langsung ke implementasi

public:
    void getData() {
        db.connect();
        cout << "Fetching data..." << endl;
    }
};

int main() {
    DataService service;
    service.getData();
    return 0;
}
