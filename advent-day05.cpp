#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    std::string seatline;

    short int row = 0;
    short int seat = 0;
    short int bit = 0;
    int biggest = 0;
    while (std::getline(std::cin, seatline))
    {
        if (seatline.length() > 7)
        {
            row = 0;
            seat = 0;
            for (int f = 0; f < 7; f++)
            {
                if (seatline[f] == 'F')
                {
                    bit = 0 << (6-f);
                }
                else
                {
                    bit = 1 << (6-f);
                }
                row |= bit;
            }
            for (int f = 7; f < 10; f++)
            {
                if (seatline[f] == 'L')
                {
                    bit = 0 << (3-f + 6);
                }
                else
                {
                    bit = 1 << (3-f + 6);
                }
                seat |= bit;
            }
            int seatid = (8 * row ) + seat;
            if (biggest < seatid)
                biggest = seatid;

        }

    }
    cout << "Biggest ID: " << biggest << endl;

    return 0;
}
