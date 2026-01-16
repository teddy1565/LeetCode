#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>




class FileSystem {

    private:
        struct FileNode {
            std::string path;
            std::vector<std::string, FileNode *> childs;

            FileNode(std::string path) {
                this->path = path;
            }
        };

        FileNode *root_dir;

    public:
        FileSystem() {
            this->root_dir = new FileNode("/");
        }
        
        std::vector<std::string> ls(std::string path) {
            
        }
        
        void mkdir(std::string path) {
            
        }
        
        void addContentToFile(std::string filePath, std::string content) {
            if (filePath.back() == '/') {
                return;
            }

            
        }
        
        std::string readContentFromFile(std::string filePath) {
            
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