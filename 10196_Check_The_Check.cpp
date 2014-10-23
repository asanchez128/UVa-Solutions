#include <cstdio>
#include <cmath>
using namespace std;

char board[10][10];

bool valid(int x, int y){
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int pawnWhiteX[] = {-1, 1};
int pawnWhiteY[] = {-1, -1};
int pawnBlackX[] = {-1, 1};
int pawnBlackY[] = {1, 1};

int knightX [] ={-2, -2, -1, -1, 1, 1, 2, 2};
int knightY [] = {-1, 1, -2, 2, -2, 2, -1, 1};
int blackKingX, blackKingY;
int whiteKingX, whiteKingY;
void findBlackKing(){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == 'k'){
				blackKingX = i;
				blackKingY = j;
				return;
			}
		}
	}
}

void findWhiteKing(){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == 'K'){
				whiteKingX = i;
				whiteKingY = j;
				return;
			}
		}
	}

}

bool gotWhiteKing(int x, int y){
	return (x == whiteKingX && y == whiteKingY);
}

bool gotBlackKing(int x, int y){
	return (x == blackKingX && y == blackKingY );
}
bool whitekingCheck = false;

bool blackkingCheck =  false;
void solve(){
	int _x, _y;
		for(int i = 0; i < 8; ++i){
			for(int j = 0; j < 8; ++j){
				char &ans = board[i][j];
				if(ans == 'p'){
					for(int k = 0; k < 2; ++k){
						_x = i + pawnBlackY[k];
						_y = j + pawnBlackX[k];
						if(valid(_x, _y) && gotWhiteKing(_x, _y)){
							//printf("white king is in check.\n");
							whitekingCheck = true;
						}
					}
				}
				if( ans == 'P'){
					for(int k = 0; k < 2; ++k){
						_x = i + pawnWhiteY[k];
						_y = j + pawnWhiteX[k];
						if(valid(_x, _y) && gotBlackKing(_x, _y)){
							//printf("black king is in check.\n");
							blackkingCheck = true;
							//return;
						}
					}
				}
				if(ans == 'N'){
					for(int k = 0; k < 8; ++k){
						_x = i+ knightX[k];
						_y = j+ knightY[k];
						if(valid(_x, _y) && gotBlackKing(_x, _y)){
							//printf("black king is in check.\n");
							blackkingCheck = true;
							//return;
						}
					}
				}
				if (ans == 'n'){
					for(int k = 0; k < 8; ++k){
						_x = i+ knightX[k];
						_y = j+ knightY[k];
						if(valid(_x, _y) && gotWhiteKing(_x, _y)){
							//printf("white king is in check.\n");
							//return;
							whitekingCheck = true;
						}
					}
				} 
				if (ans == 'r' || ans == 'q'){
					if(whiteKingY == j){
						if(whiteKingX < i){
							bool found = true;
							for(int k = whiteKingX + 1; k < i; ++k){
								if(board[k][j] != '.'){
									found = false;
									break;
								}
							}
							if(found){
								//printf("white king is in check.\n");
								//return;
								whitekingCheck = true;
							}
							
						}else{
							bool found = true;
							for(int k = i + 1; k < whiteKingX; ++k){
								if(board[k][j] != '.'){
									found = false;
									break;
								}
							} 
							if(found){
								//printf("white king is in check.\n");
								//return;
								whitekingCheck = true;
							}
						}
					} 
					else if (whiteKingX == i){
						if(whiteKingY < j){
							bool found = true;
							for(int k = whiteKingY + 1; k < j; ++k){
								if(board[i][k] != '.'){
									found = false;
									break;
								}
							}
							if(found){
								//printf("white king is in check.\n");
								//return;
								whitekingCheck = true;
							}
							
						}else{
							bool found = true;
							for(int k = j + 1; k < whiteKingY; ++k){
								if(board[i][k] != '.'){
									found = false;
									break;
								}
							} 
							if(found){
								//printf("white king is in check.\n");
								//return;
								whitekingCheck = true;
							}
						}
					}
				}
				if(ans == 'R' || ans == 'Q'){
					if(blackKingY == j){
						if(blackKingX < i){
							bool found = true;
							for(int k = blackKingX + 1; k < i; ++k){
								if(board[k][j] != '.'){
									found = false;
									break;
								}
							}
							if(found){
								//printf("black king is in check.\n");
								//return;
								blackkingCheck = true;
							}
							
						}else{
							bool found = true;
							for(int k = i + 1; k < blackKingX; ++k){
								if(board[k][j] != '.'){
									found = false;
									break;
								}
							} 
							if(found){
								//printf("black king is in check.\n");
								//return;
								blackkingCheck = true;
							}
						}
					} 
					else if (blackKingX == i){
						if(blackKingY < j){
							bool found = true;
							for(int k = blackKingY + 1; k < j; ++k){
								if(board[i][k] != '.'){
									found = false;
									break;
								}
							}
							if(found){
								//printf("black king is in check.\n");
								//return;
								blackkingCheck = true;
							}
							
						}else{
							bool found = true;
							for(int k = j + 1; k < blackKingY; ++k){
								if(board[i][k] != '.'){
									found = false;
									break;
								}
							} 
							if(found){
								//printf("black king is in check.\n");
								//return;
								blackkingCheck = true;
							}
						}
					}
				}
				if(ans == 'B' || ans == 'Q'){
					if(abs(blackKingX - i) == abs(blackKingY - j)){
						bool found = true;
						if(i < blackKingX && j > blackKingY){
							for(int k = i + 1, l = j - 1; k < blackKingX; ++k, --l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						}
						else if(i > blackKingX && j > blackKingY){
							for(int k = i - 1, l = j - 1; k > blackKingX; --k, --l){
								if(board[k][l] != '.'){
									found = false;
								}
							}		
						} else if(i < blackKingX && j < blackKingY){
							for(int k = i + 1, l = j + 1; k < blackKingX; ++k, ++l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						} else if(i > blackKingX && j < blackKingY){
							for(int k = i - 1, l = j + 1; k > blackKingX; --k, ++l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						}
						if(found == true){
							//printf("black king is in check.\n");
							//return;
							blackkingCheck = true;
						}
						
					}
				}
				if(ans == 'b' || ans == 'q'){
					if(abs(whiteKingX - i) == abs(whiteKingY - j)){
						bool found = true;
						if(i < whiteKingX && j > whiteKingY){
							for(int k = i + 1, l = j - 1; k < whiteKingX; ++k, --l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						}
						else if(i > whiteKingX && j > whiteKingY){
							for(int k = i - 1, l = j - 1; k > whiteKingX; --k, --l){
								if(board[k][l] != '.'){
									found = false;
								}
							}		
						} else if(i < whiteKingX && j < whiteKingY){
							for(int k = i + 1, l = j + 1; k < whiteKingX; ++k, ++l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						} else if(i > whiteKingX && j < whiteKingY){
							for(int k = i - 1, l = j + 1; k > whiteKingX; --k, ++l){
								if(board[k][l] != '.'){
									found = false;
								}
							}	
						}
						
						if(found == true){
							//printf("white king is in check.\n");
							//return;
							whitekingCheck = true;
						}
					}
				}
			}
		}
		//printf("no king is in check.\n");
		if(!whitekingCheck && !blackkingCheck){
			printf("no king is in check.\n");
		}else if(whitekingCheck){
			printf("white king is in check.\n");
		}else{
			printf("black king is in check.\n");
		}
}

bool blank(){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] != '.')return false;
		}
	}
	return true;
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tc = 0;
	bool done = false;
	do{
		whitekingCheck = false;
		blackkingCheck = false;
		for(int i = 0; i < 8; ++i){
			fgets(board[i], 10, stdin);
		}
		if(!blank()){
			printf("Game #%d: ", ++tc);
			findBlackKing();
			findWhiteKing();
			solve();
		}else{
			done = true;
		}
		
	// gotcha : Do not assume that the "empty grid" is the last one.	
	}while(!done && fgets(board[0], 10, stdin) != NULL);
	return 0;
}