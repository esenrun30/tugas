#include <iostream>
using namespace std;

// Abstraksi database
class Database {
public:
    virtual void connect() = 0;
    virtual ~Database() {}
};

// Implementasi MySQL
class MySQLDatabase : public Database {
public:
    void connect() override {
        cout << "Connecting to MySQL..." << endl;
    }
};

// Implementasi PostgreSQL
class PostgreSQLDatabase : public Database {
public:
    void connect() override {
        cout << "Connecting to PostgreSQL..." << endl;
    }
};

// High-level module yang bergantung pada abstraksi
class DataService {
private:
    Database* db;

public:
    DataService(Database* database) : db(database) {}

    void getData() {
        db->connect();
        cout << "Fetching data..." << endl;
    }
};

int main() {
    MySQLDatabase mysql;
    PostgreSQLDatabase postgres;

    DataService service1(&mysql);
    service1.getData();

    DataService service2(&postgres);
    service2.getData();

    return 0;
}
