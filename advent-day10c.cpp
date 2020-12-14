#include <iostream>
#include <list>
#include <map>
#include <set>


using namespace std;
const long long magic = 36845998;

int validatechain(set<int> &numchain, int jolts)
{
    int numvalid = 0;
    if (numchain.size() == 1)
    {
        return 1;
    }
    else
    {
        set<int>    newchain;
        int up ;
        for (int f=1; f<4; f++)
        {
            newchain = numchain;
            up = *(newchain.begin()) + f;

            auto found = newchain.find(up);

            if (found!=newchain.end())
            {
                while (*(newchain.begin()) != up)
                {
                    newchain.erase(newchain.begin());
                }
                numvalid += validatechain(newchain, f);
            }
        }
    }
    return numvalid;
}

int main(int argc, char *argv[]) {
    std::string qline;
    std::set<int> numchain;
    int jolt3 = 0;
    int jolt1 = 0;
    int root;
    if (argc > 1)
        root = atoi(argv[1]);
    else
        root = 0;
    numchain.insert(root);
    while (std::getline(std::cin, qline) && qline!="")
    {
        int num;
        num = std::stoll(qline.c_str());
        numchain.insert(num);
    }
    int numvalid = 0;
    numvalid += validatechain(numchain, 1);
    cout << "Final numvalid " << numvalid << endl;
    cout << "size of list: " << numchain.size() << endl;
    return 0;
}
