//
// implement breed and starve
//  main.cpp
//  mg6392_hw13
//
//  Created by Max Grove on 9/30/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class World;

const int GRID_SIZE = 20;
const char BUG_SYMBOL = 'X';
const char ANT_SYMBOL = 'o';

const int BUG_BREED_TIME = 8;
const int BUG_STARVE_TIME = 3;
const int ANT_BREED_TIME = 3;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

const int ANT = 1;
const int BUG = 2;

bool isOnGrid(int row, int col);

class Organism {
public:
    virtual void move(World &world) = 0;
    virtual void breed(World &world) = 0;
    virtual void starving(World &world) {};
    
    virtual int getType() = 0;
    void setRow(int newRow) {row = newRow;};
    void setCol(int newCol) {col = newCol;};
    virtual void starve(World &world) {return;}
    int getRow() {return row;};
    int getCol() {return col;};
    Organism(int newRow, int newCol) : row(newRow), col(newCol) {};
    Organism() {};
    virtual ~Organism() {};
private:
    int row, col;
};

class Ant : public Organism {
public:
    virtual void move(World &world);
    virtual void breed(World &world);
    virtual void starve(World &world) {return;}
    
    int getType() { return ANT; };
    
    Ant(int row, int col) : Organism(row, col), timeSinceBreed(0) {};
    Ant() : Organism(), timeSinceBreed(0) {};
    virtual ~Ant() {};
private:
    int timeSinceBreed;
};

class Doodlebug : public Organism {
public:
    virtual void move(World &world);
    virtual void breed(World &world);
    virtual void starve(World &world);
    
    int getType() { return BUG; }
    
    Doodlebug(int row, int col) : timeSinceEat(0), timeSinceBreed(0), Organism(row, col) {};
    Doodlebug() : timeSinceEat(0), timeSinceBreed(0), Organism() {};
    virtual ~Doodlebug() {};
private:
    int timeSinceEat, timeSinceBreed;
};

class World {
public:
    void addOrganism(Organism *organism, int row, int col);
    void removeOrganism(int row, int col);
    void printWorld();
    Organism* getOrganism(int row, int col);
    void timeStep();
    
    World(int numAnts, int numBugs);
    World();
    virtual ~World();
private:
    Organism* world[GRID_SIZE][GRID_SIZE];
};
int main()
{
    srand((int)time(NULL));
    char goAgain;
    World world(100,5);
    int iterate = 1;
    cout << "Press enter to step through time. Press any other key then enter to quit." << endl;
    do {
        cout << "Iteration: " << iterate++ << endl;
        world.printWorld();
        world.timeStep();
        cout << "Press enter to continue, any other key then enter to quit." << endl;
        cin.get(goAgain);
    } while (goAgain == '\n');
    cout << "Thanks for playing!" << endl;
    return 0;
}

bool isOnGrid(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        return false;
    else
        return true;
}

void Ant::move(World &world) {
    int direction = rand() % 4;
    
    int origRow = getRow();
    int origCol = getCol();
    
    int newRow = origRow;
    int newCol = origCol;
    
    if (direction == UP) {
        newRow--;
    }
    else if (direction == DOWN) {
        newRow++;
    }
    else if (direction == LEFT) {
        newCol++;
    }
    else {
        newCol--;
    }
    
    if (!isOnGrid(newRow, newCol)) {
        timeSinceBreed++;
        return;
    }
    if (world.getOrganism(newRow, newCol) == nullptr) {
        world.addOrganism(this, newRow, newCol);
        world.removeOrganism(origRow, origCol);
        timeSinceBreed++;
    }
}
void Ant::breed(World &world) {
    if (this->timeSinceBreed < ANT_BREED_TIME) return;
    
    vector<int> adjacentCells;
    int newRow = getRow();
    int newCol = getCol();

    if ((newRow + 1 < GRID_SIZE) && (world.getOrganism(newRow + 1, newCol) == nullptr))
        adjacentCells.push_back(DOWN);
    if ((newRow - 1 >= 0) && (world.getOrganism(newRow - 1, newCol) == nullptr))
        adjacentCells.push_back(UP);
    if ((newCol + 1 < GRID_SIZE) && (world.getOrganism(newRow, newCol + 1) == nullptr))
        adjacentCells.push_back(RIGHT);
    if ((newCol - 1 >= 0) && (world.getOrganism(newRow, newCol - 1) == nullptr))
        adjacentCells.push_back(LEFT);
    
    if (adjacentCells.empty())
        return;
    
    int directionNewAnt = adjacentCells[rand() % adjacentCells.size()];

    if (directionNewAnt == RIGHT)
        newCol++;
    else if (directionNewAnt == LEFT)
        newCol--;
    else if (directionNewAnt == UP)
        newRow--;
    else
        newRow++;

// Check to make sure that the adjacent cell is empty before adding the new ant.
    if (world.getOrganism(newRow, newCol) != nullptr) return;
    timeSinceBreed = 0;
    Ant* newAnt = new Ant(newRow, newCol);
    world.addOrganism(newAnt, newRow, newCol);
}
void Doodlebug::move(World &world) {
    vector<int> antCells;
    vector<int> adjacentCells;
    int origRow = getRow();
    int origCol = getCol();
    int newRow = origRow;
    int newCol = origCol;
    
    if (origRow+1 < GRID_SIZE && world.getOrganism(origRow+1, origCol) != nullptr) {
        if (world.getOrganism(origRow+1, origCol)->getType() == ANT)
            antCells.push_back(DOWN);
    }
    if (origRow-1 >= 0 && world.getOrganism(origRow-1, origCol) != nullptr) {
        if (world.getOrganism(origRow-1, origCol)->getType() == ANT)
            antCells.push_back(UP);
    }
    if (origCol+1 < GRID_SIZE && world.getOrganism(origRow, origCol+1) != nullptr) {
        if (world.getOrganism(origRow, origCol+1)->getType() == ANT)
            antCells.push_back(RIGHT);
    }
    if (origCol-1 >= 0 && world.getOrganism(origRow, origCol-1) != nullptr) {
        if (world.getOrganism(origRow, origCol-1)->getType() == ANT)
            antCells.push_back(LEFT);
    }
    
    if (antCells.size() > 0) {
        int directionNewBug = antCells[rand() % antCells.size()];
        if (directionNewBug == RIGHT)
            newCol++;
        else if (directionNewBug == LEFT)
            newCol--;
        else if (directionNewBug == UP)
            newRow--;
        else
            newRow++;
        world.removeOrganism(newRow, newCol);
        world.addOrganism(this, newRow, newCol);
        world.removeOrganism(origRow, origCol);
        timeSinceBreed++;
        timeSinceEat = 0;
    }
    else {
        int direction = rand() % 4;
        if (direction == UP)
            newCol++;
        else if (direction == DOWN)
            newCol--;
        else if (direction == LEFT)
            newRow--;
        else
            newRow++;
        if (isOnGrid(newRow, newCol)) {
            if (world.getOrganism(newRow, newCol) == nullptr) {
                world.addOrganism(this, newRow, newCol);
                world.removeOrganism(origRow, origCol);
                timeSinceBreed++;
                timeSinceEat++;
            }
        }
    }
}
void Doodlebug::breed(World &world) {
    if (timeSinceBreed < BUG_BREED_TIME) return;
    vector<int> adjacentCells;
    int row = getRow();
    int col = getCol();
    if ((row+1 < GRID_SIZE) && (world.getOrganism(row+1, col) == nullptr)) {
        adjacentCells.push_back(DOWN);
    }
    if ((row-1 >= 0) && (world.getOrganism(row-1, col) == nullptr)) {
        adjacentCells.push_back(UP);
    }
    if ((col+1 < GRID_SIZE) && (world.getOrganism(row, col+1) == nullptr)) {
        adjacentCells.push_back(RIGHT);
    }
    if (col-1 >= 0 && (world.getOrganism(row, col-1) == nullptr)) {
        adjacentCells.push_back(LEFT);
    }
    
    if (adjacentCells.empty()) {
        return;
    }
    
    int directionNewBug = adjacentCells[rand() % adjacentCells.size()];
    int newRow = row;
    int newCol = col;
    if (directionNewBug == UP)
        newCol++;
    else if (directionNewBug == DOWN)
        newCol--;
    else if (directionNewBug == LEFT)
        newRow--;
    else
        newRow++;
    
    timeSinceBreed = 0;
    
    Doodlebug* newBug = new Doodlebug;
    world.addOrganism(newBug, newRow, newCol);
}
void Doodlebug::starve(World &world) {
    if (timeSinceEat >= BUG_STARVE_TIME)
        world.removeOrganism(getRow(), getCol());
}

void World::addOrganism(Organism *organism, int row, int col) {
    if(!isOnGrid(row, col) || world[row][col] != nullptr) {
        delete organism;
        organism = nullptr;
        return;
    }
    world[row][col] = organism;
    world[row][col]->setRow(row);
    world[row][col]->setCol(col);
}
void World::removeOrganism(int row, int col) {
    if (world[row][col] == nullptr) return;
    world[row][col] = nullptr;
    delete world[row][col];
}

void World::printWorld() {

    for (int col = 0; col < GRID_SIZE + 2; col++) {
        cout << "_";
    }
    cout << endl;
    for (int row = 0; row < GRID_SIZE; row++) {
        cout << "|";
        for (int col = 0; col < GRID_SIZE; col++) {
            if (world[row][col] == nullptr)
                cout << "-";
            else if (world[row][col]->getType() == ANT)
                cout << ANT_SYMBOL;
            else if (world[row][col]->getType() == BUG)
                cout << BUG_SYMBOL;
            else
                cout << "-";
        }
        cout << "|" << endl;
    }
    for (int col = 0; col < GRID_SIZE + 2; col++) {
        cout << "-";
    }
    cout << endl;
}
Organism* World::getOrganism(int row, int col) {
    if (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE) {
        return world[row][col];
    }
    else
        return nullptr;
}

World::World(int numAnts, int numBugs) {
    //add a case if there are too many ants and bugs
    if ((numAnts + numBugs) > (GRID_SIZE * GRID_SIZE)) {
        cout << "World constructed with too many organisms. Exiting program." << endl;
        exit(1);
    }

    //point everything to a null pointer.
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            world[row][col] = nullptr;
        }
    }
    
    for (int i = 0; i < numAnts; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        
        while (world[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }
        world[row][col] = new Ant(row, col);
    }
    
    for (int i = 0; i < numBugs; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        
        while (world[row][col] != nullptr) {
            row = rand() % GRID_SIZE;
            col = rand() % GRID_SIZE;
        }
        world[row][col] = new Doodlebug(row,col);
    }
}
World::World() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            world[row][col] = nullptr;
        }
    }
}
World::~World() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if(world[row][col] != nullptr) {
                delete world[row][col];
                world[row][col] = nullptr;
            }
        }
    }
}
void World::timeStep() {
    vector<Organism*> doodlebugs;
    vector<Organism*> ants;
    for(int row = 0; row < GRID_SIZE; row++) {
        for(int col = 0; col < GRID_SIZE; col++) {
            if (world[row][col] == nullptr) continue;
            if (world[row][col]->getType() == BUG)
                doodlebugs.push_back(world[row][col]);
        }
    }
    
    for (int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i]->move(*this);
    }

    for(int row = 0; row < GRID_SIZE; row++) {
        for(int col = 0; col < GRID_SIZE; col++) {
            if (world[row][col] == nullptr) continue;
            if (world[row][col]->getType() == ANT)
                ants.push_back(world[row][col]);
        }
    }
    
    for (int i = 0; i < ants.size(); i++) {
        ants[i]->move(*this);
    }
    for (int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i]->breed(*this);
    }
    for (int i = 0; i < doodlebugs.size(); i++) {
        doodlebugs[i]->starve(*this);
    }
    for (int i = 0; i < ants.size(); i++) {
        ants[i]->breed(*this);
    }
}
