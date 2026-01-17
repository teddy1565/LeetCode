#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

bool compare(std::string a, std::string b) {

    int small_size = a.size() < b.size() ? a.size() : b.size();

    for (int i = 0; i < small_size; i++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    
    if (a.size() < b.size()) {
        return true;
    } else if (a.size() > b.size()) {
        return false;
    }
    
    return false;
}



class FileSystem {

    private:
        struct FileNode {
            std::string file_name;
            std::string content;

            FileNode(std::string file_name) {
                this->file_name = file_name;
            }
        };

        std::map<std::string, std::vector<FileNode *>> file_map;
        std::map<std::string, std::vector<std::string>> dir_map;



    public:
        FileSystem() {
            std::vector<FileNode *> root_dir;
            std::vector<std::string> dir_map_root;

            this->file_map.insert({"/", root_dir});
            this->dir_map.insert({"/", dir_map_root});
        }
        
        std::vector<std::string> ls(std::string path) {
            std::vector<std::string> result;

            if (path.back() != '/') {

                std::size_t last_slash_index = path.find_last_of('/');
                std::string file_name = path.substr(last_slash_index + 1);
                std::string dir_path = path.substr(0, last_slash_index + 1);
                if (this->file_map.find(dir_path) != this->file_map.end()) {
                    std::vector<FileNode *> file_nodes = this->file_map[dir_path];
                    bool is_file = false;
                    for (int i = 0; i < file_nodes.size(); i++) {
                        if (file_nodes[i]->file_name == file_name) {
                            is_file = true;
                            break;
                        }
                    }
                    if (is_file == true) {
                        result.push_back(file_name);
                        return result;
                    }
                }
                
                path = path + '/';
            }
            if (this->file_map.find(path) != this->file_map.end()) {
                std::vector<FileNode *> file_list = this->file_map[path];
                for (int i = 0; i < file_list.size(); i++) {
                    result.push_back(file_list[i]->file_name);
                }

                std::vector<std::string> dir_list = this->dir_map[path];
                for (int i = 0; i < dir_list.size(); i++) {
                    result.push_back(dir_list[i]);
                }
            }
            std::sort(result.begin(), result.end(), compare);
            return result;
        }
        
        void mkdir(std::string path) {

            if (this->file_map.find(path + "/") != this->file_map.end()) {
                return;
            }

            std::size_t last_slash_index = path.find_last_of('/');
            std::string file_name = path.substr(last_slash_index + 1);
            std::string dir_path = path.substr(0, last_slash_index + 1);

            if (this->file_map.find(dir_path) == this->file_map.end()) {
                this->mkdir(path.substr(0, last_slash_index));
            }
            
            std::vector<FileNode *> file_nodes = this->file_map[dir_path];
            bool is_file = false;
            for (int i = 0; i < file_nodes.size(); i++) {
                if (file_nodes[i]->file_name == file_name) {
                    is_file = true;
                    break;
                }
            }

            if (is_file == false) {
                std::vector<FileNode *> file_lists;
                this->file_map.insert({path + '/', file_lists});

                std::vector<std::string> dir_list = this->dir_map[dir_path];
                dir_list.push_back(file_name);
                this->dir_map[dir_path] = dir_list;
            }
        }
        
        void addContentToFile(std::string filePath, std::string content) {
            if (filePath.back() == '/') {
                return;
            }
            
            std::size_t last_slash_index = filePath.find_last_of('/');
            std::string file_name = filePath.substr(last_slash_index + 1);
            std::string dir_path = filePath.substr(0, last_slash_index + 1);

            if (this->file_map.find(dir_path) != this->file_map.end()) {
                std::vector<FileNode *> file_nodes = this->file_map[dir_path];
                FileNode *target = nullptr;
                for (int i = 0; i < file_nodes.size(); i++) {
                    if (file_nodes[i]->file_name == file_name) {
                        target = file_nodes[i];
                        break;
                    }
                }

                if (target == nullptr) {
                    target = new FileNode(file_name);
                    file_nodes.push_back(target);
                    this->file_map[dir_path] = file_nodes;
                }

                target->content += content;
                
            }
            
        }
        
        std::string readContentFromFile(std::string filePath) {
            std::string result = "";
            if (filePath.back() == '/') {
                return result;
            }
            
            std::size_t last_slash_index = filePath.find_last_of('/');
            std::string file_name = filePath.substr(last_slash_index + 1);
            std::string dir_path = filePath.substr(0, last_slash_index + 1);

            if (this->file_map.find(dir_path) != this->file_map.end()) {
                std::vector<FileNode *> file_nodes = this->file_map[dir_path];
                FileNode *target = nullptr;
                for (int i = 0; i < file_nodes.size(); i++) {
                    if (file_nodes[i]->file_name == file_name) {
                        target = file_nodes[i];
                        break;
                    }
                }

                if (target == nullptr) {
                    return result;
                }
                result = target->content;
                return result;
            }

            return result;
        }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */