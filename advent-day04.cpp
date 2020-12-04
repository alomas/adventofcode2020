#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    std::string passline;
    int count = 0;
    int passnum = 0;
    std::string tempkey, tempvalue;
    std::map<std::string, std::string> passmap;
    bool onkey;
    while (std::getline(std::cin, passline))
    {
        count++;
        onkey = true;
        tempkey = "";
        tempvalue = "";
        for (int f=0; f<passline.length(); f++)
        {
            if (onkey)
            {
                if (passline[f] == ' ')
                    f++;
                if (passline[f] != ':')
                    tempkey += passline[f];
                else
                    onkey=false;
            }
            else
            {
                if (passline[f] != ' ')
                {
                    tempvalue += passline[f];
                    if (f == passline.length()-1)
                    {
                        passmap.insert(std::make_pair(tempkey, tempvalue));
                    }
                }
                else
                {
                    onkey = true;
                    passmap.insert(std::make_pair(tempkey, tempvalue));

                    tempkey = "";
                    tempvalue = "";
                }
            }
        }
        if (passline == "") {
            bool valid = true;
            if (passmap.find("byr") == passmap.end())
                valid = false;
            else {
                std::string date = passmap["byr"];
                if ((atoi(date.c_str()) >= 1920) && (atoi(date.c_str()) <= 2002))
                    valid = valid;
                else {
                    valid = false;
                }
            }
            if (passmap.find("iyr") == passmap.end())
                valid = false;
            else {
                std::string date = passmap["iyr"];
                if ((atoi(date.c_str()) >= 2010) && (atoi(date.c_str()) <= 2020))
                    valid = valid;
                else {
                    valid = false;
                }
            }
            if (passmap.find("eyr") == passmap.end())
                valid = false;
            else {
                std::string date = passmap["eyr"];
                if ((atoi(date.c_str()) >= 2020) && (atoi(date.c_str()) <= 2030))
                    valid = valid;
                else {
                    valid = false;
                }
            }
            if (passmap.find("hgt") == passmap.end())
                valid = false;
            else {
                std::string height = passmap["hgt"];
                if (height.ends_with("in")) {
                    std::string substr = height.substr(0, height.length() - 2);
                    if ((atoi(substr.c_str()) >= 59) && (atoi(substr.c_str()) <= 76))
                        valid = valid;
                    else {
                        valid = false;
                    }
                }
                else
                    if (height.ends_with("cm"))
                    {
                        std::string substr = height.substr(0, height.length() - 2);
                        if ((atoi(substr.c_str()) >= 150) && (atoi(substr.c_str()) <= 193))
                            valid = valid;
                        else {
                            valid = false;
                        }
                    }
                    else
                    {
                        valid = false;
                    }
            }
            if (passmap.find("hcl") == passmap.end())
                valid = false;
            else {
                std::string hcl = passmap["hcl"];
                if ((hcl.length() == 7) && (hcl.starts_with("#"))) {
                    if (hcl.find_first_not_of("0123456789abcdefABCDEF", 1) == std::string::npos) {
                        valid = valid;
                    } else {
                        valid = false;
                    }
                } else
                    valid = false;
            }
            if (passmap.find("ecl") == passmap.end())
                valid = false;
            else {
                std::map<std::string, std::string> colors = {
                        {"oth", "oth"},
                        {"blu", "blu"},
                        {"brn", "brn"},
                        {"gry", "gry"},
                        {"grn", "grn"},
                        {"hzl", "hzl"},
                        {"amb", "amb"}

                };
                std::string ecl = passmap["ecl"];
                if (colors.find(ecl) != colors.end()) {
                    valid = valid;
                } else {
                    valid = false;
                }
            }
            if (passmap.find("pid") == passmap.end())
                valid = false;
            else {
                std::string passnumber = passmap["pid"];
                if (passnumber.length() == 9)
                {
                    if (passnumber.find_first_not_of("0123456789", 0) == std::string::npos)
                        valid = valid;
                    else
                        valid = false;
                }
                else
                    valid = false;
            }
            if (valid) {
                std::cout << "Valid: ";
                std::for_each(passmap.begin(), passmap.end(), [](std::pair<std::string, std::string> item) {
                    std::cout << item.first << ":" << item.second << " ";
                });
                std::cout << std::endl;
                passnum++;
            } else
            {
                std::cout << "Invalid: ";
                std::for_each(passmap.begin(), passmap.end(), [](std::pair<std::string, std::string> item) {
                    std::cout << item.first << ":" << item.second << " ";
                });
                std::cout << std::endl;
            }
            passmap.clear();
        }
    }

    std::cout << "Valid passport: " << passnum << std::endl;
    return 0;
}
