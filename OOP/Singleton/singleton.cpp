#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

class Database
{
    public:
        static Database& get()
        {
            static Database db;
            return db;
        }

        void print_capitals() const
        {
            for (const auto& [city, count] : capitals)
            {
                std::cout << "Capital city: " << std::setw(15) << city << ", Count: " << count << "\n";
            }
        }

    private:
        Database(const Database&) = delete;
        Database operator= (const Database&) = delete;
        Database(Database&&) = delete;
        Database& operator= (Database&&) = delete;

        Database()
        {
            std::ifstream file("capitals.txt");

            std::string city, count;
            while (getline(file, city))
            {
                getline(file, count);
                capitals[city] = std::stoi(count);
            }
        }

        std::unordered_map<std::string, int> capitals;
};

int main()
{
    Database& db = Database::get();
    db.print_capitals();

    return 0;
}
