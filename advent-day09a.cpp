#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    std::list<long long> numchain;
    bool notfound = true;
    while (std::getline(std::cin, qline) && qline!="")
    {
        long long num;
        num = std::stoll(qline.c_str());
        if (numchain.size() < 25)
        {
            numchain.push_back(num);
        }
        else {
            notfound = false;
            for (auto it = numchain.begin(); it != numchain.end(); ++it)
            {
                    long long diff;
                    diff = num - *it;
                    auto result = std::find(numchain.begin(), numchain.end(), diff);
                    if (result != numchain.end()) {
                        notfound = false;
                        break;
                    } else {
                        notfound = true;
                    }
                }
            if (notfound)
            {
                cout << "Not found " << num;
                return 1;
            }
            if (numchain.size() == 25) {
                numchain.pop_front();
            }
            numchain.push_back(num);
        }
    }
    cout << "size of list: " << numchain.size() << endl;
    return 0;
}
