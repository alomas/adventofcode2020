#include <iostream>
#include <list>
#include <map>
#include <set>


using namespace std;
const long long magic = 36845998;

int main(int argc, char *argv[]) {
    std::string qline;
    std::set<int> numchain;
    int jolt3 = 0;
    int jolt1 = 0;
    numchain.insert(0);
    while (std::getline(std::cin, qline) && qline!="")
    {
        int num;
        num = std::stoll(qline.c_str());
        numchain.insert(num);
    }
    for (auto it=numchain.begin(); it!=numchain.end(); ++it)
    {
        int up3 = *it + 3;
        int up1 = *it + 1;
        cout << *it << endl;

        auto found1 = numchain.find(up1);
        if (found1 != numchain.end())
        {
            cout << "found +1 " << up1 << endl;
            it = --found1;
            jolt1++;
        }
        else
        {
            auto found3 = numchain.find(up3);

            if (found3!=numchain.end())
            {
                cout << "found +3 " << up3 << endl;
                it = --found3 ;
                jolt3++;
            }
        }


    }
    jolt3++;

    cout << "size of list: " << numchain.size() << endl;
    cout << "1-jolts: " << jolt1 << " x 3-jolts: " << jolt3 << " = " << (jolt1 * jolt3) << endl;
    return 0;
}
