//
// Created by oupson on 07/12/22.
//

#include <Day7.hpp>
#include <fstream>
#include <regex>

class Dir;

class Entry {
private:
    std::weak_ptr<Dir> parent;
    std::string name;

public:
    explicit Entry(std::weak_ptr<Dir> &parent, std::string &name) : parent(parent), name(name) {

    }

    [[nodiscard]]  virtual int get_size() const {
        return 0;
    };

    [[nodiscard]]  virtual int part1() const {
        return 0;
    };

    [[nodiscard]] virtual int part2(int needed) const {
        return 0;
    }

    [[nodiscard]] virtual bool is_dir() const {
        return false;
    }

    [[nodiscard]] const std::weak_ptr<Dir> &get_parent() const {
        return parent;
    }

    [[nodiscard]] const std::string &get_name() const {
        return name;
    }
};

class Dir : virtual public Entry {
private:
    std::vector<std::shared_ptr<Entry>> entries = std::vector<std::shared_ptr<Entry>>();

public:
    explicit Dir(std::weak_ptr<Dir> parent, std::string name) : Entry(parent, name) {};

    void add_entry(const std::shared_ptr<Entry> &entry) {
        this->entries.push_back(entry);
    }

    [[nodiscard]] int part1() const override {
        int a = 0;
        if (this->get_name() != "/") {
            int total_size = this->get_size();
            if (total_size <= 100000) {
                a = total_size;
            }
        }

        for (auto &e: this->entries) {
            if (e->is_dir()) {
                a += e->part1();
            }
        }

        return a;
    }

    [[nodiscard]] int part2(int needed) const override {
        int a = 0;
        if (this->get_name() != "/") {
            int total_size = this->get_size();
            if (total_size > needed) {
                a = total_size;
            }
        }

        for (auto &e: this->entries) {
            if (e->is_dir()) {
                int size = e->part2(needed);
                if (size != 0 && (a == 0 || size < a)) {
                    a = size;
                }
            }
        }

        return a;
    }

    [[nodiscard]] int get_size() const override {
        int sum = 0;
        for (auto &entry: this->entries) {
            sum += entry->get_size();
        }
        return sum;
    }

    [[nodiscard]] bool is_dir() const override {
        return true;
    }

    void print(int index = 0) const {
        for (auto &e: this->entries) {
            for (int i = 0; i < index; i++) {
                std::cout << "\t";
            }

            if (e->is_dir()) {
                std::cout << e->get_name() << std::endl;
                dynamic_cast<const Dir *> (e.get())->print(index + 1);
            } else {
                std::cout << e->get_name();

                std::cout << std::endl;
            }
        }
    }
};

class File : public Entry {
private:
    int size;

public :
    explicit File(std::weak_ptr<Dir> &parent, std::string name, int size) : Entry(parent, name), size(size) {}

    [[nodiscard]] int get_size() const override {
        return this->size;
    }

    [[nodiscard]] int part1() const override {
        return this->size;
    }
};

void Day7::run_day(std::ifstream &stream) const {
    std::regex reg(R"(^\$ cd (.+)|(\d+) (.+)$)");
    std::cmatch m;

    std::string line;

    std::shared_ptr<Dir> root = std::make_shared<Dir>(std::weak_ptr<Dir>(), "/");
    std::weak_ptr<Dir> cwd = root;

    while (std::getline(stream, line)) {
        if (std::regex_match(line.c_str(), m, reg)) {
            auto m1 = m[1].str();
            auto m2 = m[2].str();

            if (!m1.empty()) {
                if (m1 == "..") {
                    cwd = cwd.lock()->get_parent();
                } else {
                    std::shared_ptr<Dir> nd = std::make_shared<Dir>(cwd.lock(), m1);
                    cwd.lock()->add_entry(nd);
                    cwd = nd;
                }
            } else {
                cwd.lock()->add_entry(std::make_shared<File>(cwd, m[3].str(), std::atoi(m2.c_str())));
            }
        }
    }
    std::cout << "Part 1 : " << root->part1() << std::endl;

    int size_fs = 70000000;
    int needed_for_update = 30000000;
    int used = root->get_size();
    int remaining = size_fs - used;
    int needed = needed_for_update - remaining;

    std::cout << "Used : " << used << std::endl;
    std::cout << "Remaining " << remaining << std::endl;
    std::cout << "Needed " << needed << std::endl;
    std::cout << "Part 2 : " << root->part2(needed) << std::endl;
}