#include <iostream>
#include <list>
#include <map>
#include <set>


using namespace std;
const long long magic = 36845998;

int validatechain(set<int> &numchain, int jolts)
{
    int numvalid = 0;
    cout << "Checking " << jolts << "-jolts" << endl;
    if (numchain.size() == 1)
    {
        cout << "End of the line - " << *(numchain.begin()) << endl;
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
                    cout << "From " << *(newchain.begin()) << " found +" << f << " (" << up << ")" << endl;
                    while (*(newchain.begin()) != up)
                    {
                        newchain.erase(newchain.begin());
                    }
                    cout << "Dropping into chain starting with " << *(newchain.begin()) << " for " << jolts << "-jolts" << endl;
                    numvalid += validatechain(newchain, f);
                    cout << "numvalid = " << numvalid << endl;

                }
                else
                {
                    cout << "No +" << jolts << " past " << *(newchain.begin()) << endl;
                }
                }
            }

            cout << "Returned from validatechain() " << *(numchain.begin()) << endl;

    cout << "numvalid = " << numvalid << endl;
    return numvalid;

}

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
    int numvalid = 0;
    numvalid += validatechain(numchain, 1);
   // numvalid += validatechain(numchain, 2);
   // numvalid += validatechain(numchain, 3);
    cout << "Final numvalid " << numvalid << endl;
    cout << "size of list: " << numchain.size() << endl;
    cout << "1-jolts: " << jolt1 << " x 3-jolts: " << jolt3 << " = " << (jolt1 * jolt3) << endl;
    return 0;
}
