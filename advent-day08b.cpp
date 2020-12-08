#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    std::string qline;
    int opnum = 0;
    struct opdata {
        string opname;
        int value;
        bool visited;
    };
    map<int, opdata> opmap, opmapog;
    while (std::getline(std::cin, qline) && qline!="")
    {
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
        opmapog.insert(make_pair(opnum, opobject ));
    }
    opmap = opmapog;
    int acc;
    int pos;
    int jmpnop = 1;
    while (jmpnop < opmapog.size())
    {
        opdata object;
        object = opmapog[jmpnop];
        bool nodupevisit = true;
        acc = 0;
        pos = 1;
        if (object.opname == "jmp")
        {
            object.opname = "nop";
            opmap = opmapog;
            opmap.erase(jmpnop);
            opmap.insert(make_pair(jmpnop, object));
            while (nodupevisit && pos < opmap.size()+1)
            {
                opdata object;
                opdata tempobject;
                int jmp = 1;
                object = opmap[pos];
                tempobject.value = object.value;
                tempobject.opname = object.opname;
                tempobject.visited = object.visited;
                opmap.erase(pos);
                if (tempobject.visited == true) {
                    nodupevisit = false;
                } else {
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
            if ((pos == opmap.size()+1) && nodupevisit){
                cout << "Goal acc = " << acc << endl;
            }
        }
        jmpnop++;
    }
    return 0;
}
