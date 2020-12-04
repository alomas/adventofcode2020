#include <iostream>

int main(int argc, char *argv[]) {
    std::string treeline;
    int xpos = 0;
    int treecount = 0;
    int ypos = 0;
    int downbeat = 1;
    int rightbeat = 3;
    bool pauseright = false;
    if (argc > 2)
    {
        int right = atoi(argv[1]);
        int down = atoi(argv[2]);
        downbeat = down;
        rightbeat = right;
    }
    while (std::getline(std::cin, treeline))
    {
        if ((ypos > 0) && (ypos % downbeat) == 0)
        {
            if (treeline[xpos] == '#') {
                treeline[xpos] = 'X';
                treecount++;
            }
            else
                treeline[xpos] = 'O';
            pauseright = false;
        }
        ypos++;
        if (!pauseright) {
            for (int f = 0; f < rightbeat; f++) {
                xpos++;
                if (xpos > (treeline.length() - 1))
                    xpos = 0;
                treeline[xpos] = '-';

            }
            pauseright = true;
        }
        std::cout << treeline << std::endl;
    }
    std::cout << "Trees: " << treecount << std::endl;

    return 0;
}
