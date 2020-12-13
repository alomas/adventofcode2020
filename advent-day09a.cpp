#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    int opnum = 0;
    std::list<int> numchain;
    while (std::getline(std::cin, qline) && qline!="")
    {
        int num;
        num = std::atoi(qline.c_str());
        numchain.push_back(num);
        cout << "num = " << num << endl;

    }

    cout << "size of list: " << numchain.size() << endl;

    return 0;
}
