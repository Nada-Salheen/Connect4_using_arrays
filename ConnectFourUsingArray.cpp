#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
void StartGame(); //Runs game
void SetColor();
void WelcomingMSG(); //outputs welcoming messages
void display(); //Displays game board
void PlayWithComputer();
void PlayWithFriend();
bool check(int a, int b);
int drop(int b, char player);
char BoardDimensions[6][7];//Board Dimensions
int changePlay; //Changes turns between Player and Computer
int choose; // used to choose 1 vs 1 or 1 vs Computer
int I;// AI input



int main()

{

	srand(time(0)); //Sets random time (to be used in computer AI)
	StartGame();

	return 0;
}


void StartGame()
{
	SetColor();
	WelcomingMSG();
	cin >> choose;
	system("cls");
	if (choose == 1)
		PlayWithComputer();
	else
		PlayWithFriend();
}

void SetColor()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
}

void WelcomingMSG()
{
	cout << "WELCOME TO CONNECT 4 GAME !!!!!!!!!!!!!!" << endl;
	cout << "**********************************************" << endl;
	cout << "Do You want to play against a friend or the computer? \n \n";
	cout << "Choose '1' for a computer or any other button for a friend \n";
}
void PlayWithComputer()
{

	{	for (int a = 0; a <= 5; a++) {		//fill BoardDimensions with whitespace
		for (int b = 0; b <= 6; b++)	//
			BoardDimensions[a][b] = ' ';		//
	}								//
	display();//Displays for first time so players can see the board
	int hold;//Will house user row choice
	int hold2 = 0;//will hold drop value
	int charsBoardDimensionsd = 0;//Number of pieces dropped so that game ends if a draw occurs
	bool gamewon = false;//Will be changed to true when game is won and will exit while loop
	char player = 15;//start as player 2 will change back 2 player 1

	while (!gamewon) {//will stop when game is won, ! means NOT makes the opposite be checked
		I = (rand() % 7) + 1;
		if (hold2 != -1) {//check if there was a error in the last drop
			if (player == 15) {//if player 2 lasted dropped a piece so its player 1's turn
				cout << "Your turn ";
				player = 254;//char of players piece
				changePlay = 1;
			}
			else {
				cout << "Player's 2 turn";
				player = 15;//char of player piece
				changePlay = 2;

			}
		}
		while (true) {//will run until 'break;'
			if (charsBoardDimensionsd == 42) break;//if draw
			if (changePlay == 1)
				cin >> hold;//get user input
			else hold = I;
			hold--;//take off 1 to account for arrays starting at 0 not 1
			if (hold <= 6 && hold >= 0) break;//if within valid range stop loop
			else cout << "\n please enter a value between 1 and 7 :";//ask for input and loop again
			if (cin.fail())	//catch a non number
			{						//
				cin.clear();		//Stops cin trying to put its value in to hold
				char c;			//Try entering a non number without this, 2 see what this does
				cin >> c;			//
			}						//Catch a non number

		}
		if (charsBoardDimensionsd == 42) break;//if draw
		hold2 = drop(hold, player);//drop the player store the row in hold2
		if (hold2 == -1)	cout << "Column is full \n Please enter another number between 1 and 7:";//if error -1 row is full
		else {
			gamewon = check(hold2, hold);//check if game is run
			charsBoardDimensionsd++;//another character has been seccessfuly placed
			system("cls");//This clears the screen
			display();//displayed updated board
		}
	}

	system("cls");//this clears the screen
	if (charsBoardDimensionsd == 42) {//if draw
		cout << "No winner, Game was draw\n";
		system("pause");
		return;
	}
	if (player == 15)//if won by player 2
		cout << "HARD LUCK NEXT TIME, THE COMPUTER WON THE GAME !!!!!!!!!\n \n \n";
	else cout << "Congratulations YOU WON THE GAME !!!!!!!!!\n \n \n";//Else won by player 1
	system("pause");//pauses before exit so players can see who won
	return;//Exit
	}
}
void PlayWithFriend()
{
	for (int a = 0; a <= 5; a++) {		//fill BoardDimensions with whitespace
		for (int b = 0; b <= 6; b++)	//
			BoardDimensions[a][b] = ' ';		//
	}								//
	display();//Displays for first time so players can see the board
	int hold;//Will house user row choice
	int hold2 = 0;//will hold drop value
	int charsBoardDimensionsd = 0;//Number of peices dropped so can end game if a draw
	bool gamewon = false;//Will be changed to true when game is won and will exit while loop
	char player = 15;//start as player 2 will change back 2 player 1
	while (!gamewon) {//will stop when game is won, ! means NOT makes the oppisite be checked
		if (hold2 != -1) {//check if there was a error in the last drop
			if (player == 15) {//if player 2 lasted dropped a piece so its player 1s turn
				cout << "Player's 1 turn ";
				player = 254;//char of players piece
			}
			else {
				cout << "Player's 2 turn";
				player = 15;//char of player piece
			}
		}
		while (true) {//will run until 'break;'
			if (charsBoardDimensionsd == 42) break;//if draw
			cin >> hold;//get user input
			hold--;//take off 1 to account for arrays starting at 0 not 1
			if (hold <= 6 && hold >= 0) break;//if within valid range stop loop
			else cout << "\nplease enter a value between 1 and 7 :";//ask for input and loop again
			if (cin.fail())	//catch a non number
			{						//
				cin.clear();		//Stops cin trying to put its value in to hold
				char c;			//Try entering a non number without this, 2 see what this does
				cin >> c;			//
			}						//Catch a non number

		}
		if (charsBoardDimensionsd == 42) break;//if draw
		hold2 = drop(hold, player);//drop the player store the row in hold2
		if (hold2 == -1)	cout << "Colom is full\nPlease enter anothor number between 1 and 7:";//if error -1 row is full
		else {
			gamewon = check(hold2, hold);//check if game is run
			charsBoardDimensionsd++;//another character has been successfully placed
			system("cls");//This clears the screen works with windows, not necessary to run game
			display();//displayed updated board
		}
	}
	system("cls");//this clears the screen
	if (charsBoardDimensionsd == 42) {//if draw
		cout << "No winner, Game was draw\n";
		system("pause");
		return;
	}
	if (player == 15)//if won by player 2
		cout << "PLAYER 2 WON THE GAME !!!!!!!!!\n \n \n";
	else cout << "PLAYER 1 WON THE GAME !!!!!!!!!\n \n \n";//Else won by player 1
	system("pause");//pauses before exit so players can see who won
	return;//Exit
}




void display() {
	for (int a = 0; a <= 5; a++)
	{
		for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(179) << BoardDimensions[a][b] << char(179) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";
		cout << '\n';
	}
	cout << " 1   2   3   4   5   6   7\n \n";
}
bool check(int a, int b) {
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = BoardDimensions[a][b];
	int i;//vertical
	int ii;//horizontal
	//check for vertical(|)
	for (i = a + 1; BoardDimensions[i][b] == player && i <= 5; i++, vertical++);//Check down
	for (i = a - 1; BoardDimensions[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	//check for horizontal(-)
	for (ii = b - 1; BoardDimensions[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left
	for (ii = b + 1; BoardDimensions[a][ii] == player && ii <= 6; ii++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for (i = a - 1, ii = b - 1; BoardDimensions[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left
	for (i = a + 1, ii = b + 1; BoardDimensions[i][ii] == player && i <= 5 && ii <= 6; diagonal1++, i++, ii++);//down and right
	if (diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for (i = a - 1, ii = b + 1; BoardDimensions[i][ii] == player && i >= 0 && ii <= 6; diagonal2++, i--, ii++);//up and right
	for (i = a + 1, ii = b - 1; BoardDimensions[i][ii] == player && i <= 5 && ii >= 0; diagonal2++, i++, ii--);//up and left
	if (diagonal2 >= 4) return true;
	return false;
}
int drop(int b, char player) {
	if (b >= 0 && b <= 6)
	{
		if (BoardDimensions[0][b] == ' ') {
			int i;
			for (i = 0; BoardDimensions[i][b] == ' '; i++)
				if (i == 5) {
					BoardDimensions[i][b] = player;
					return i;
				}
			i--;
			BoardDimensions[i][b] = player;
			return i;

		}
		else {
			return -1;
		}

	}
	else {
		return -1;
	}

}
