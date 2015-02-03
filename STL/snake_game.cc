#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<unistd.h>

using namespace std;

const int kMaxFood = 20;

const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';




struct pointT {
	int row;
	int col;
};

struct gameT{
	vector<string>world;
	int numRows,numCols;
	deque<pointT> snake;
	int dx,dy;
	int numEaten;
};

void InitializeGame(gameT& game);
void LoadWorld(gameT& game ,ifstream &input);
void PerformAI(gameT& game );
void RunSimulation(gameT& game);
void DisplayResult(gameT& game);
pointT GetNextPosition(gameT& game,int dx,int dy); 
bool Crashed(pointT headPos,gameT& game );
bool InWorld(pointT& pt,gameT& game );
bool RandomChance(double probability );
bool MoveSnake(gameT& game);
void Pause();
void DisplayResult(gameT& game);
void PlaceFood( gameT& game );
pointT MakePoint(int row,int col) ;
void PrintWorld(gameT& game);

string GetLine() {
	string result;
	getline(cin,result);
	return result;
}

int main() {
	gameT game;
	InitializeGame(game);
	RunSimulation(game);
	return 0;
}


void InitializeGame(gameT& game) {
	ifstream input;
	while(true) {
		cout<<"Enter the File name:";
		string filename = GetLine();
		input.open(filename.c_str());
		if(input.is_open())
			break; 
		cout<<"Sorry ,I can't find the file"<<filename<<endl;
		 input.clear();
	}
	LoadWorld(game,input);
}

void LoadWorld(gameT& game ,ifstream &input) {
	input>>game.numRows>>game.numCols;
	game.world.resize(game.numRows);
	input>>game.dx>>game.dy;

	string dummy;
	getline(input,dummy);
	
	for(int row = 0;row < game.numRows;++row) {
		getline(input,game.world[row]);
		int col = game.world[row].find(kSnakeTile);
		if(col != string::npos){
			game.snake.push_back(MakePoint(row,col));

		}
	}	
	game.numEaten = 0;
}

pointT MakePoint(int row,int col) {
	pointT result ;
	result.row  = row;
	result.col = col ;
}

void RunSimulation(gameT& game) {
	while(game.numEaten < kMaxFood) {
		PrintWorld(game);
		PerformAI(game);
	if(!MoveSnake(game))
		break;
	Pause();
	
	}
	DisplayResult(game);
}

const double kWaitTime = 0.1;

void Pause() {
	clock_t startTime  = clock();
	
	while(static_cast<double>(clock() - startTime /CLOCKS_PER_SEC<kWaitTime));
	sleep(20);

}

const string kClearCommand = "clear";
void PrintWorld(gameT& game)
{
	system(kClearCommand.c_str());
	for(int row = 0; row< game.numRows;++row)
		cout<<game.world[row]<<endl;
	cout<<"Food eaten: "<< game.numEaten<<endl;
}

void DisplayResult(gameT& game) {
	PrintWorld(game);
	if(game.numEaten == kMaxFood )
		cout<<"The snake ate enough food to wins !"<<endl;
	else
		cout<<"Oh no! The snake crashed!"<<endl;
}

const double kTurnRate = 0.2 ;
void PerformAI(gameT& game ) {
	pointT nextHead =  GetNextPosition(game,game.dx,game.dy);
	
	if(Crashed(nextHead,game) || RandomChance(kTurnRate)){
		int leftDx = -game.dy ;
		int leftDy = game.dx;
		
		int rightDx = game.dy;
		int rightDy = -game.dx;
		
		bool canLeft = !Crashed(GetNextPosition(game,leftDx,leftDy),game);
		bool canRight = !Crashed(GetNextPosition(game,rightDx,rightDy),game);
		
		bool willTurnLeft = false;
		if(! canLeft && !canRight)
			return ;
		else if(canLeft && !canRight )
			willTurnLeft = true;
		else if(!canLeft && canRight )
			willTurnLeft = false;
		else
			willTurnLeft = RandomChance(0.5);	
		game.dx = willTurnLeft ? leftDx : rightDx;
		game.dy = willTurnLeft ? leftDy : rightDy;
	
	}

}

pointT GetNextPosition(gameT& game,int dx,int dy) {

	pointT result = game.snake.front();
	
	result.row += game.dy;
	result.col += game.dx;
	
return result ;
}


bool Crashed(pointT headPos,gameT& game ) {
	return !InWorld(headPos,game) || 
	game.world[headPos.row][headPos.col] == kSnakeTile || 
	game.world[headPos.row][headPos.col] == kWallTile ;
}

bool InWorld(pointT& pt,gameT& game ) {
	return pt.col >= 0 && pt.row >= 0 && pt.col < game.numCols && pt.row < game.numRows;

}

bool RandomChance(double probability ) {
	return (rand() /(RAND_MAX + 1.0 )) < probability;

}

bool MoveSnake(gameT& game) {

	pointT nextHead = GetNextPosition(game,game.dx,game.dy);
	if(Crashed(nextHead,game))
		return false;
	bool isFood = ( game.world[nextHead.row][nextHead.col] == kFoodTile);

	game.world[nextHead.row][nextHead.col] = kSnakeTile;
	game.snake.push_front(nextHead);

	if(!isFood) {
		game.world[game.snake.back().row][game.snake.back().col] = kEmptyTile;
		game.snake.pop_back();
	}
	else
	{

		++game.numEaten;
		PlaceFood(game);
	}
	return true;
}


void PlaceFood( gameT& game ) {

while(true) {
	int row = rand() % game.numRows;
	int col = rand() % game.numCols;
	if(game.world[row][col] == kEmptyTile )
		game.world[row][col] = kFoodTile ;
	return ;
}	
}




