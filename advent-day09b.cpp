#include <iostream>
#include <list>

using namespace std;
const long long magic = 36845998;

int main(int argc, char *argv[]) {
    std::string qline;
    std::list<long long> numchain;
    while (std::getline(std::cin, qline) && qline!="")
    {
        long long num;
        num = std::stoll(qline.c_str());
            numchain.push_back(num);
    }

    for (auto it = numchain.begin(); it != numchain.end(); ++it)
    {
        long long thesum = 0;
        for (auto sumit = it; sumit != numchain.end(); ++sumit)
        {
            thesum += *sumit;
            if (thesum == magic)
            {
                cout << "OMG, I found it!! " << *it << " + " << *sumit << " = " << (*it+*sumit) <<  endl;
                break;
            }
        }
    }
    cout << "size of list: " << numchain.size() << endl;
    return 0;
}
