#include "Direction.hpp"
#include <string>
#include <vector>

using namespace std;

namespace ariel {

    class Board {

        std::vector<std::vector<char>> messageBoard;
        uint maxR, maxC, minR, minC;

        public:
        Board(){
            maxR=maxC=0;
            minR=minC=UINT8_MAX;
        }
        void resizeMB(uint row, uint col);
        void post(uint row, uint col, Direction direction, std::string msg);
        std::string read(uint row, uint col, Direction direction, uint len);
        void show();
    };

}