#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    int count=0;

    int group = 1;
    int total = 0;
    int people = 0;
    bool first = true;

    map<string, int> lettermap;
    while (std::getline(std::cin, qline))
    {
        bool alldone = false;
        if (qline == "") {
            alldone = true;
            group++;
            for_each(lettermap.begin(), lettermap.end(), [&people, &total](const std::pair<string, int> item)
            {
                if (item.second == people)
                {
                    total++;
                }
            });
            people = 0;
            lettermap.clear();
        }
        if (!alldone) {
            if (first)
            {
                people = 0;
                first = false;
            }
            people++;
            for (int f = 0; f < qline.length(); f++) {
                string tempstr;
                tempstr = "";
                tempstr += qline[f];
                count = 1;
                auto result = lettermap.find(tempstr);
                if (result!=lettermap.end())
                {
                    count = (result->second) + 1;
                    lettermap.erase(result);
                }
                lettermap.insert(make_pair(tempstr, count));
            }
        }
        else
        {
            alldone = true;
        }
    }
    cout << "Total: " << total << endl;

    return 0;
}
