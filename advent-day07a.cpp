#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    int total=0;

    map<string, int> innerbagmap;

    map<string, map<string, int>> outerbagmap;


    while (std::getline(std::cin, qline) && qline!="")
    {
        cout << "Processing line: "  << qline << endl;
        int outerPos = qline.find(" contain ");
        string outsidebag = qline.substr(0, outerPos);
        if (outsidebag[outsidebag.length()-1] == 's')
        {
            outsidebag.erase(outsidebag.length()-1);
        }
        cout << outsidebag << " <- ";
        int innerPos = qline.find(", ", outerPos);
        int middle = strlen(" contain ");
        middle += outerPos;
        outerbagmap.clear();
        string innerbags = qline.substr(middle, innerPos);
        {
            char c = ',';
            string buff = "";
            vector<string> v;
            int fieldnum = 0;
            for(auto n:innerbags)
            {
                if(n != c) buff+=n; else
                if(n == c && buff != "") {
                    fieldnum++;
                    cout << " fieldnum: " << fieldnum << endl;
                    if (buff[buff.length()-1] == 's')
                    {
                        buff.erase(buff.length()-1);
                    }
                    int num;
                    string bagtype;
                    int nPos = buff.find(" ");
                    string numstr = buff.substr(0, nPos);
                    num = stoi(numstr);
                    bagtype = buff.substr(nPos+1);
                    innerbagmap.insert(make_pair(bagtype, num));
                    v.push_back(buff); buff = ""; }
            }
            if (buff[0] == ' ')
            {
                buff.erase(0);
            }
            if (buff[buff.length()-1] == '.')
            {
                buff.erase(buff.length()-1);
            }
            if (buff[buff.length()-1] == 's')
            {
                buff.erase(buff.length()-1);
            }
            if(buff != "") v.push_back(buff);
            outerbagmap.insert(make_pair(outsidebag, innerbagmap));
            for(auto n:v) cout << n << endl;
            innerbagmap.clear();
        }

    }
    cout << "Total: " << total << endl;

    return 0;
}
