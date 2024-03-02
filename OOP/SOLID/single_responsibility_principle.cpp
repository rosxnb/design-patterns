#include <fstream>
#include <string>
#include <vector>

struct Journal
{
    std::string title;
    std::vector<std::string> entries;
        
    explicit Journal(const std::string& title)
        : title{title}
    {}

    void add(const std::string& entry);
};

void Journal::add(const std::string& entry)
{
    static int count = 1;

    entries.push_back(
        std::to_string(count++) + ": "
        + entry
    );
}

struct PersistenceManager
{
    static void save_to_file(const Journal& j, const std::string& filename)
    {
        std::ofstream ofs(filename);
        for (const std::string& s : j.entries)
        {
            ofs << s << "\n";
        }
    }
};

int main()
{
    Journal journal("Daily Diary");
    journal.add("I ate a rice");
    journal.add("I flew today");

    // journal.save("diary.txt"); // violates principle: SRP

    PersistenceManager pm;
    pm.save_to_file(journal, "diary.txt");
}
