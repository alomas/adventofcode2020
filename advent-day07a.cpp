#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int findGold(map<string, map<string, int>> &outerbagmap, string bagtosearch, int depth)
{
    bool foundgold = false;
    int goldcount = 0;
    int result = 0;
    for (int f=0; f<depth; f++)
        cout << "\t";
    cout  << "Searching " << bagtosearch << endl;
    auto item = outerbagmap.find(bagtosearch);
    if (item != outerbagmap.end())
    {
        for_each(item->second.begin(), item->second.end(), [&outerbagmap, &result, depth](const std::pair<string, int> subitem)
        {
            for (int f=0; f<depth+1; f++)
                cout << "\t";
            cout  << subitem.first << endl;
            if (subitem.first == "shiny gold bag")
                return 1;
           if (subitem.first != "no other bag")
           {
               result = findGold(outerbagmap, subitem.first, depth + 1);
               for (int f=0; f<depth+1; f++)
                   cout << "\t";
               if (result > 0)
               {
                   cout << "Found Gold!" << endl;
                   return 1;
               }
           }
        });
    }
    if (result > 0)
        return 1;
}

int main(int argc, char *argv[]) {
    std::string qline;
    int total=0;

    map<string, int> innerbagmap;

    map<string, map<string, int>> outerbagmap;


    while (std::getline(std::cin, qline) && qline!="")
    {
        //cout << "Processing line: "  << qline << endl;
        int outerPos = qline.find(" contain ");
        string outsidebag = qline.substr(0, outerPos);
        if (outsidebag[outsidebag.length()-1] == 's')
        {
            outsidebag.erase(outsidebag.length()-1);
        }
        //cout << outsidebag << " <- ";
        int innerPos = qline.find(", ", outerPos);
        int middle = strlen(" contain ");
        middle += outerPos;
        bool lastone = false;
        string innerbags = qline.substr(middle);
        {
            innerbagmap.clear();

            char c = ',';
            string buff = "";
            vector<string> v;
            int fieldnum = 0;
            for(auto n:innerbags)
            {
                if(n != c) buff+=n; else
                if(n == c && buff != "") {
                    fieldnum++;
                    // cout << " fieldnum: " << fieldnum << endl;
                    if (buff[buff.length()-1] == 's')
                    {
                        buff.erase(buff.length()-1);
                    }
                    if (buff[0] == ' ')
                    {
                        buff.erase(0, 1);
                    }
                    int num;
                    string bagtype;
                    int nPos = buff.find(" ");
                    string numstr = buff.substr(0, nPos);
                    num = stoi(numstr);
                    bagtype = buff.substr(nPos+1);
                    innerbagmap.insert(make_pair(bagtype, num));
                    // cout << bagtype << ", " << num << endl;
                    v.push_back(buff); buff = ""; }
            }
            if (buff[0] == ' ')
            {
                buff.erase(0, 1);
            }
            if (buff[buff.length()-1] == '.')
            {
                lastone = true;
                buff.erase(buff.length()-1);
                total++;
            }
            if (buff[buff.length()-1] == 's')
            {
                buff.erase(buff.length()-1);
            }
            if(buff != "") v.push_back(buff);
            int num;
            string bagtype;
            int nPos = buff.find(" ");
            string numstr = buff.substr(0, nPos);
            if (buff == "no other bag")
            {
                num = 0;
                bagtype = "no other bag";
            }
            else {
                num = stoi(numstr);
                bagtype = buff.substr(nPos + 1);
            }
            innerbagmap.insert(make_pair(bagtype, num));
            if (lastone) {
                outerbagmap.insert(make_pair(outsidebag, innerbagmap));
                lastone = true;
            }
            //for(auto n:v) cout << n << endl;
        }

    }
    for_each(outerbagmap.begin(), outerbagmap.end(), [](const std::pair<string, map<string, int>> item)
    {
        cout << "Outer: " << item.first << endl;
        for_each(item.second.begin(), item.second.end(), [](const std::pair<string, int> subitem)
        {
            cout << "\t" << subitem.second << " " << subitem.first << endl;
        });
    });
    cout << "Total: " << total << endl;

    string sentinel = "light red bag";
    findGold(outerbagmap, "light red bag", 1);

    if (argc > 1)
    {
        auto item = outerbagmap.find(argv[1]);
        if (item==outerbagmap.end())
        {
            cout << "Could not find outer bag " << argv[1] << endl;
        }
        else
        {
            map<string, int> theitem;
            theitem = item->second;
            cout << "For Outer Bag " << argv[1] << ": " << endl;
            for_each(item->second.begin(), item->second.end(), [](const std::pair<string, int> subitem)
            {
                cout << "\t" << subitem.second << " " << subitem.first << endl;
            });
        }
    }

    return 0;
}
