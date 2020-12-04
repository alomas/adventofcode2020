#include <iostream>

int main(int argc, char *argv[]) {
    std::string passline;
    int count = 0;
    int passnum = 1;

    while (std::getline(std::cin, passline))
    {
        count++;
        std::cout << passnum << "\t" << count << "\t" << passline;
        std::cout << std::endl;
        if (passline == "")
            passnum++;
    }

    return 0;
}
