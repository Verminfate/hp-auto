#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <limits.h>
#include <iostream>
#include <string>
#include <filesystem>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;



int main() {
    TCHAR NPath[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, NPath);
    std::wstring test(&NPath[0]);
    string test2(test.begin(), test.end());
    string path = test2;
    for (const auto& file : directory_iterator(path)) {
        string path = "\"" + file.path().u8string();
        if (path.find("sp") != std::string::npos) {
            string cmd = path + "\" /s";
            cout << "Found" << file.path() << "      " << cmd << endl;
            system(cmd.c_str());
        }
    }

    return EXIT_SUCCESS;
}
