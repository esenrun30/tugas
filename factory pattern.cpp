#include <iostream>
#include <string>
using namespace std;

Database* databaseFactory(string dbType) {
    if (dbType == "mysql") {
        return new MySQLDatabase();
    } else if (dbType == "postgres") {
        return new PostgreSQLDatabase();
    } else {
        throw runtime_error("Unknown database type");
    }
}

int main() {
    string input = "postgres"; // bisa diubah sesuai kebutuhan runtime
    Database* db = databaseFactory(input);

    DataService service(db);
    service.getData();

    delete db;
    return 0;
}
