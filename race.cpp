#include <iostream>
#include <random>

const int TRACK_LENGTH = 15;
const int HORSES_NUMBER = 5;

void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

std::random_device rd;
std::uniform_int_distribution<int> dist(0, 1);

int main() {
    int horses[] = {0, 0, 0, 0, 0};
    bool keepGoing = true;

    while (keepGoing) {
        for (int hn = 0; hn < HORSES_NUMBER; hn++) {
            advance(hn, horses);
            printLane(hn, horses);
            if (isWinner(hn, horses)) {
                keepGoing = false;
            }
        }

        std::cout << "Press enter for another turn";
        std::cin.ignore();
    }

    return 0;
}

void advance(int hn, int* horses) {
    int turn = dist(rd);
    horses[hn] += turn;
}

void printLane(int hn, int* horses) {
    for (int position = 0; position < TRACK_LENGTH; position++) {
        if (horses[hn] == position) {
            std::cout << hn;
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

bool isWinner(int hn, int* horses) {
    if (horses[hn] >= TRACK_LENGTH) {
        std::cout << "Horse " << hn << " WINS!!! " << std::endl;
        return true;
    }
    return false;
}
