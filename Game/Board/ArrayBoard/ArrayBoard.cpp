#include "ArrayBoard.h"
#include <iostream>
#include <random>
#include "../../Logs/LogOutput/LogFileOut/LogFileOut.h"
#include "../../Logs/LogOutput/LogConsoleOut/LogConsoleOut.h"
#include  "../Cell/Elements/Bomb/Bomb.h"
#include  "../Cell/Elements/Heal/Heal.h"
#include  "../Cell/Elements/Star/Star.h"


ArrayBoard::ArrayBoard(int width, int height){

    this->player.setCurrentX(0);
    this->player.setCurrentY(0);
    this->player.setStars(0);
    this->player.setHealth(10);

    this->width = width;
    this->height = height;
    this->board = new Cell*[width];

    for(int i = 0; i < width; i++){
        this->board[i] = new Cell[height];
    }

    fillCells();

    board[0][0].setObject(START);
    board[0][0].setPassability(true);
    generateBoard(0,0);
    setExitPoint();
    putElement(new Heal());
    putElement(new Bomb());
    putElement(new Star());

}

//copy constructor
ArrayBoard::ArrayBoard(const ArrayBoard &other){
    this->width = other.width;
    this->height = other.height;
    this->player = other.player;
    this->exitX = other.exitX;
    this->exitY = other.exitY;
    if(other.board) {
        this->board = new Cell *[width];
        for (int i = 0; i < width; i++) {
            board[i] = new Cell[height];
        }
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }
}

//move constructor
ArrayBoard::ArrayBoard(ArrayBoard &&other) {
    this->width = other.width;
    this->height = other.height;
    this->board = other.board;
    this->player = other.player;
    this->exitY = other.exitY;
    this->exitX = other.exitX;
    other.board = nullptr;
}

//copy operator
ArrayBoard& ArrayBoard::operator=(const ArrayBoard &other) {
    if(&other == this)
        return *this;

    if(board) {
        for (int i = 0; i < width; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

    this->width = other.width;
    this->height = other.height;
    this->player = other.player;
    this->exitY = other.exitY;
    this->exitX = other.exitX;

    if(other.board) {
        this->board = new Cell *[width];
        for (int i = 0; i < width; i++) {
            board[i] = new Cell[height];
        }
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }

    return *this;
}

//move operator
ArrayBoard& ArrayBoard::operator=(ArrayBoard &&other) {
    if(&other == this)
        return *this;

    std::swap(this->board, other.board);
    std::swap(this->width,other.width);
    this->height = other.height;
    this->player = other.player;
    this->exitX = other.exitX;
    this->exitY = other.exitY;
    return *this;
}

ArrayBoard::~ArrayBoard(){
    if(board) {
        for (int i = 0; i < width; i++) {
            delete[] board[i];
        }
    }
    delete[] board;
}

void ArrayBoard::clearData() {

    if(board) {
        for (int i = 0; i < width; i++) {
            delete[] board[i];
        }
    }
    board = nullptr;
    this->exitX = -1;
    this->exitY = -1;
    this->player.setStars(-1);
    this->player.setHealth(-1);
    this->player.setCurrentX(-1);
    this->player.setCurrentY(-1);

}

void ArrayBoard::rebuildData() {

    this->player.setCurrentX(0);
    this->player.setCurrentY(0);
    this->player.setStars(0);
    this->player.setHealth(10);

    this->board = new Cell*[this->width];

    for(int i = 0; i < this->width; i++){
        this->board[i] = new Cell[this->height];
    }

    fillCells();

    board[0][0].setObject(START);
    board[0][0].setPassability(true);
    generateBoard(0,0);
    setExitPoint();
    putElement(new Heal());
    putElement(new Bomb());
    putElement(new Star());
}


ArrayBoard  &ArrayBoard::getInstance() {
    static ArrayBoard instance(15,15);
    return instance;
}

void ArrayBoard::generateBoard(int x, int y) {
    if(board[x][y].getObject()!=2) {
        board[x][y].setObject(ROAD);
        board[x][y].setPassability(true);
    }

    int dirs[4];
    //NORTH
    dirs[0] = 0;
    //EAST
    dirs[1] = 1;
    //SOUTH
    dirs[2] = 2;
    //WEST
    dirs[3] = 3;
    std::random_device rd;
    std::mt19937 mersenne(rd());
    for(int i = 0; i<4; i++){
        int r = mersenne() & 3;
        int temp = dirs[r];
        dirs[r] = dirs[i];
        dirs[i] = temp;
    }

    for(int i = 0; i<4; i++) {

        int dx = 0, dy = 0;
        switch (dirs[i]) {
            case 0:
                dy = -1;
                break;
            case 2:
                dy = 1;
                break;
            case 1:
                dx = 1;
                break;
            case 3:
                dx = -1;
                break;
        }

        int x2 = x + (dx << 1);
        int y2 = y + (dy << 1);
        bool condition = (x2<0 || x2>=width || y2<0 || y2>=height);
        if (!condition) {
            if (!board[x2][y2].isPassible()) {
                board[x2 - dx][y2 - dy].setObject(ROAD);
                board[x2 - dx][y2 - dy].setPassability(true);
                generateBoard(x2, y2);
            }
        }
    }
}

void ArrayBoard::setExitPoint() {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int randX = mersenne() & width-1;
    int randY = mersenne() & height-1;
    while(board[randX][randY].getObject()!=1){
        randX = mersenne() & width-1;
        randY = mersenne() & height-1;
    }
    board[randX][randY].setObject(END);
    exitX = randX;
    exitY = randY;
}

void ArrayBoard::putElement(ElementInterface *el) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int randX = mersenne() & width-1;
    int randY = mersenne() & height-1;
    while (board[randX][randY].getObject() != 1 || board[randX][randY].getEl()->getType() != NONE){
        randX = mersenne() & width - 1;
        randY = mersenne() & height - 1;
    }
    board[randX][randY].setEl(el);
    subscribe(new LogFileOut(*board[randX][randY].getEl()->getSubLog()));
    subscribe(new LogConsoleOut(*board[randX][randY].getEl()->getSubLog()));
}

int ArrayBoard::getExitX() const {
    return this->exitX;
}

int ArrayBoard::getExitY() const {
    return this->exitY;
}

BoardIterator ArrayBoard::createIterator() const  {
    return BoardIterator(this->board, width, height);
}

int ArrayBoard::getWidth() const {
    return this->width;
}

int ArrayBoard::getHeight() const {
    return this->height;
}

 Cell& ArrayBoard::getItem(int x, int y) const {
    return this->board[x][y];
}

BoardIterator ArrayBoard::end() const {
    BoardIterator it(this->board,width,height);
    it.currentX = 0;
    it.currentY = height;
    return it;
}

bool ArrayBoard::isRightMost(const BoardIterator &it) const {
    return (it.currentX == width-1);
}

BoardIterator ArrayBoard::begin() const{
    BoardIterator it(this->board,width,height);
    it.currentX = 0;
    it.currentY = 0;
    return it;
}

Player& ArrayBoard::getPlayer() {
    return this->player;
}

void ArrayBoard::subscribe(AbstractLogs *subLog) {
    subscribers.push_back(subLog);
}

void ArrayBoard::unsubscribe(AbstractLogs *subLog) {
    subscribers.remove(subLog);
}

void ArrayBoard::notify(Cell &cell, std::ostream &file) {
    std::list<AbstractLogs *>::iterator iterator = subscribers.begin();
    while(iterator!=subscribers.end()){
        (*iterator)->update(cell.getEl()->getType(),file);
        ++iterator;
    }
}

void ArrayBoard::fillCells() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            board[i][j].setX(i);
            board[i][j].setY(j);
        }
    }
}

Cell & ArrayBoard::emptyCell() const {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int randX = mersenne() & width-1;
    int randY = mersenne() & height-1;
    while (board[randX][randY].getObject() != 1){
        randX = mersenne() & width - 1;
        randY = mersenne() & height - 1;
    }
    return board[randX][randY];
}

bool ArrayBoard::isRoad(int x, int y) {
    return x < width && x >= 0 && y<height && y>=0 && board[x][y].getObject() != WALL;
}

std::vector<Cell *> ArrayBoard::getNeighborRoads(int x, int y) {
    std::vector<Cell *> neighbors;
    if(isRoad(x+1,y)){
        neighbors.push_back(&board[x+1][y]);
    }
    if(isRoad(x-1,y)){
        neighbors.push_back(&board[x-1][y]);
    }
    if(isRoad(x,y+1)){
        neighbors.push_back(&board[x][y+1]);
    }
    if(isRoad(x,y-1)){
        neighbors.push_back(&board[x][y-1]);
    }
    return neighbors;
}

void ArrayBoard::resetBoard(json jBoard, int width, int height) {
    if(this->board) {
        for (int i = 0; i < width; i++) {
            delete[] this->board[i];
        }
        delete[] this->board;
    }

    this->width = width;
    this->height = height;
    if(board) {
        this->board = new Cell *[width];
        for (int i = 0; i < width; i++) {
            this->board[i] = new Cell[height];
        }
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                this->board[i][j].setX(i);
                this->board[i][j].setY(j);
                this->board[i][j].setObject(jBoard[i][j][0]);
                this->board[i][j].setEltype(jBoard[i][j][1]);
            }
        }
    }
}

void ArrayBoard::setExitX(int x) {
    this->exitX = x;
}

void ArrayBoard::setExitY(int y) {
    this->exitY = y;
}

void ArrayBoard::setState(json data) {
    this->state = data;
}

json ArrayBoard::getState() {
    return this->state;
}

void ArrayBoard::moveElement(int x, int y) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int randX = mersenne() & width-1;
    int randY = mersenne() & height-1;
    while (board[randX][randY].getObject() != 1 || board[randX][randY].getEl()->getType() != NONE){
        randX = mersenne() & width - 1;
        randY = mersenne() & height - 1;
    }
    ElementInterface *el = board[x][y].getEl();
    board[x][y].setEl(new None());
    board[randX][randY].setEl(el);
}


