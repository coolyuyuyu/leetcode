class TodoList {
private:
    struct Task {
        Task(int id_, const string& desp_, int date_, const vector<string>& tags_)
            : id(id_)
            , desp(desp_)
            , date(date_)
            , tags(tags_.begin(), tags_.end()) {
        }

        int id;
        string desp;
        int date;
        unordered_set<string> tags;
    };

public:
    TodoList()
        : m_id(0) {
    }

    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        auto& tasks = m_tasks[userId];

        auto itr = tasks.begin();
        for (; itr != tasks.end(); ++itr) {
            if (dueDate < itr->date) {
                break;
            }
        }
        tasks.emplace(itr, ++m_id, taskDescription, dueDate, tags);

        return m_id;
    }

    vector<string> getAllTasks(int userId) {
        vector<string> ret;

        auto& tasks = m_tasks[userId];
        for (auto itr = tasks.begin(); itr != tasks.end(); ++itr) {
            ret.push_back(itr->desp);
        }
        return ret;
    }

    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> ret;

        auto& tasks = m_tasks[userId];
        for (auto itr = tasks.begin(); itr != tasks.end(); ++itr) {
            if (itr->tags.find(tag) != itr->tags.end()) {
                ret.push_back(itr->desp);
            }
        }
        return ret;
    }

    void completeTask(int userId, int taskId) {
        auto& tasks = m_tasks[userId];
        auto itr = tasks.begin();
        for (; itr != tasks.end(); ++itr) {
            if (itr->id == taskId) {
                break;
            }
        }

        if (itr != tasks.end()) {
            tasks.erase(itr);
        }
    }

private:
    int m_id;
    unordered_map<int, list<Task>> m_tasks;
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
