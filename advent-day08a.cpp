#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    int total=0;
    int opnum = 0;
    struct opdata {
        string opname;
        int value;
        bool visited;
    };
    map<int, opdata> opmap;

    while (std::getline(std::cin, qline) && qline!="")
    {
        cout << "Processing line: "  << qline << endl;
        qline += " ";
        string op = "";
        string numstr = "";
        string buff = "";
        int num;
        vector<string> v;
        for (auto n:qline)
        {
            if (n != ' ')
            {
                buff += n;
            }
            else
            {
                v.push_back(buff);
                buff = "";
            }
        }
        numstr = v[1];
        num = atoi(numstr.c_str());
        op = v[0];
        opnum++;
        opdata opobject;
        opobject.opname = op;
        opobject.value = num;
        opobject.visited = false;
        opmap.insert(make_pair(opnum, opobject ));

    }

    bool nodupevisit = true;
    int acc = 0;
    int pos = 1;
    while (nodupevisit)
    {
        opdata object;
        opdata tempobject;
        int jmp = 1;
        object = opmap[pos];
        tempobject.value = object.value;
        tempobject.opname = object.opname;
        tempobject.visited = object.visited;
        opmap.erase(pos);
        if (tempobject.visited == true)
        {
            nodupevisit = false;
        }
        else {
            if (tempobject.opname == "acc") {
                acc += object.value;
                tempobject.visited = true;
            }
            if (tempobject.opname == "jmp") {
                jmp = object.value;
                tempobject.visited = true;
            }
        }
        opmap.insert(make_pair(pos, tempobject));
        pos += jmp;

    }
    cout << "acc value before dupe = " << acc << endl;
    return 0;
}
