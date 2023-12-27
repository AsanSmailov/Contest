#include <vector>
#include <iomanip>

class OSUpdater : public IRunnable {
public:
    void run() override {
        std::cout << "OSUpdater" << std::endl;
    }
};

class Alarm : public IRunnable {
public:
    void run() override {
        std::cout << "Alarm" << std::endl;
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() override {
        std::cout << "ActivityChecker" << std::endl;
    }
};

class Clock : public IClock, public IRunnable {
private:
    struct ScheduledTask {
        IRunnable* client;
        Time time;
    };

    std::vector<ScheduledTask> tasks;

public:
    void add(IRunnable* client, Time time) override {
        ScheduledTask task{client, time};
        tasks.push_back(task);
    }

    bool next() override {
        if (tasks.empty())
            return false;

        auto it = tasks.begin();
        Time nextTime = it->time;

        for (auto task = tasks.begin(); task != tasks.end(); ++task) {
            if (task->time < nextTime)
                nextTime = task->time;
        }

        for (auto task = tasks.begin(); task != tasks.end(); ++task) {
            if (task->time == nextTime) {
                std::cout << std::setfill('0') << std::setw(2) << task->time.hours << ":"
                  << std::setw(2) << task->time.minutes << ":"
                  << std::setw(2) << task->time.seconds << " ";
                task->client->run();
                tasks.erase(task);
                break;
            }
        }

        return true;
    }

    void run() override {
        while (next()) {}
    }
};