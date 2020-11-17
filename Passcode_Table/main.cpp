#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>

class Table {
public:
 
    Table() {

    }
    void drawTable();
    void move(std::vector<char>&, std::vector<char>&);
    std::vector<char> cells{ 'A','*','*','*','*','*' };
    std::vector<char> Arrow{ 'V',' ',' ',' ',' ',' ' };
};

int main()
{
    Table table;
    table.drawTable();
    table.move(table.cells, table.Arrow);
}


void Table::drawTable()
{
    system("cls");
    std::cout << std::setw(50) << " | ";
    for (auto A : Arrow) {
        std::cout << A << " | ";
    }
    std::cout << std::endl;
    std::cout << std::setw(50) << " | ";
    for (auto c : cells) {
        std::cout << c << " | ";
    }

}

void Table::move(std::vector<char>& T, std::vector<char>& arrow)
{
    char star = 'A';
    T.at(0) = star;
    int count = 0;
    char temp;
    char word = 65;
    char word_temp;
    char ch = ' ';
    do {
        if (T[0] == 'A' && T[1] == 'B' && T[2] == 'C' && T[3] == 'D' && T[4] == 'E' && T[5] == 'F') {
            std::cout << std::setw(20) << " Unlocked\n";
            break;
        }
        switch (ch = _getch())
        {
        case 65:case 97: case 75:
            std::cout << "Left";
            if (count == 0) {
                break;
            }
            else {
                arrow[count] = ' ';
                count--;
                arrow[count] = 'V';
                if (T[count] < 65 || T[count]> 90) {
                    T[count] = 65;
                }
                else {
                    T.at(count) = T[count];
                }

            }
            drawTable();
            break;
        case 68:case 100: case 77:
            std::cout << "Right";
            if (count >= T.size() - 1) {
                break;
            }
            else {
                arrow[count] = ' ';
                count++;
                arrow[count] = 'V';
                if (T[count] < 65 || T[count]> 90) {
                    T[count] = 65;
                }

                T.at(count) = T[count];
            }
            drawTable();
            break;
        case 87:case 119: case 72:
            std::cout << "Up";
            if (T[count] >= 65 && T[count] < 90) {
                T[count]++;
            }
            else
            {
                break;
            }
            drawTable();
            break;
        case 83:case 115: case 80:
            std::cout << "Down";
            if (T[count] > 65 && T[count] <= 90) {
                T[count]--;
            }
            else
            {
                break;
            }
            drawTable();
            break;
        default:
            break;
        }

    } while ((ch != 'q'));

    std::cout << "end";
}
