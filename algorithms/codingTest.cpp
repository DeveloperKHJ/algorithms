#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int board[8][8] = {
		{1, 0, 0, 0},{1, 0, 0, 1},{1, 1, 0, 1},{1, 1, 0, 1}};

class gameBlock {
public:
	gameBlock(int _blockNum, int _length) {
		this->length = _length;
		if (_blockNum == 0) {
			this->pos[this->length - 3][0] = 2;
			this->pos[this->length - 2][0] = 2;
			this->pos[this->length - 1][0] = 2;
			this->originPos[this->length - 3][0] = 2;
			this->originPos[this->length - 2][0] = 2;
			this->originPos[this->length - 1][0] = 2;
		}
		else if (_blockNum == 1) {
			this->pos[this->length - 1][0] = 2;
			this->pos[this->length - 1][1] = 2;
			this->pos[this->length - 1][2] = 2;
			this->originPos[this->length - 1][0] = 2;
			this->originPos[this->length - 1][1] = 2;
			this->originPos[this->length - 1][2] = 2;

		}
		else if (_blockNum == 2) {
			this->pos[this->length - 2][0] = 2;
			this->pos[this->length - 1][0] = 2;
			this->pos[this->length - 1][1] = 2;
			this->originPos[this->length - 2][0] = 2;
			this->originPos[this->length - 1][0] = 2;
			this->originPos[this->length - 1][1] = 2;
		}
		else if (_blockNum == 3) {
			this->pos[this->length - 2][1] = 2;
			this->pos[this->length - 1][0] = 2;
			this->pos[this->length - 1][1] = 2;
			this->originPos[this->length - 2][1] = 2;
			this->originPos[this->length - 1][0] = 2;
			this->originPos[this->length - 1][1] = 2;
		}
		else if (_blockNum == 4) {
			this->pos[this->length - 2][0] = 2;
			this->pos[this->length - 2][1] = 2;
			this->pos[this->length - 1][1] = 2;
			this->originPos[this->length - 2][0] = 2;
			this->originPos[this->length - 2][1] = 2;
			this->originPos[this->length - 1][1] = 2;
		}
		else if (_blockNum == 5) {
			this->pos[this->length - 2][0] = 2;
			this->pos[this->length - 1][0] = 2;
			this->pos[this->length - 2][1] = 2;
			this->originPos[this->length - 2][0] = 2;
			this->originPos[this->length - 1][0] = 2;
			this->originPos[this->length - 2][1] = 2;
		}
	}
	int pos[16][8] = { 0 };
	int originPos[16][8] = { 0 };
	int length;
	bool right(int distance);
	bool down();
	int count();
	void print();
	void insertBoard();
};

bool gameBlock::right(int distance)
{
	pair<int, int> xy[3];
	pair<int, int> origin[3];
	int count = 0;
	int originCount = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) { 
			if (originPos[i][j] == 2) {
				origin[originCount].first = i;
				origin[originCount].second = j;
				originCount++;
			}

			/*if (pos[i][j] == 2) {
				xy[count].first = i;
				xy[count].second = j;
				count++;
			}*/
		}

	}
	// 이동전 이전값을 0으로
	pos[xy[0].first][xy[0].second] = 0;
	pos[xy[1].first][xy[1].second] = 0;
	pos[xy[2].first][xy[2].second] = 0;
	

	// 경계조건 확인후 이동 -> 이동 후 위치값을 1로
	if (origin[0].second + distance < length && origin[1].second + distance < length && origin[2].second + distance < length) {
		pos[origin[0].first][origin[0].second + distance] = 2;
		pos[origin[1].first][origin[1].second + distance] = 2;
		pos[origin[2].first][origin[2].second + distance] = 2;
		return true;
	}
	else {
		return false;
	}

}

void gameBlock::print()
{
	for (int i = 0; i < length*2; i++) {
		for (int j = 0; j < length; j++) { // 2인건 배열 경계 때문에
			printf("%d ", pos[i][j]);
		}
		printf("\n");
	}
	cout << "----------------" << endl;
}

void gameBlock::insertBoard()
{
	for (int i = length; i < length * 2; i++) {
		for (int j = 0; j < length; j++) { // 2인건 배열 경계 때문에
			pos[i][j] = board[i - length][j];
		}
	}
}


bool gameBlock::down()
{
	pair<int, int> xy[3];
	int count = 0;
	for (int i = 0; i < length*2; i++) {
		for (int j = 0; j < length; j++) { 
			if (pos[i][j] == 2) {

				xy[count].first = i;
				xy[count].second = j;
				count++;
			}
		}
	}
	// 이동전 이전값을 0으로
	pos[xy[0].first][xy[0].second] = 0;
	pos[xy[1].first][xy[1].second] = 0;
	pos[xy[2].first][xy[2].second] = 0;

	//if (xy[0].first + 1 < length && xy[1].first + 1 < length && xy[2].first + 1 < length)
	// 경계조건 확인후 이동 -> 이동 후 위치값을 1로
	if (pos[xy[0].first + 1][xy[0].second] != 1 && pos[xy[1].first + 1][xy[1].second] != 1 && pos[xy[2].first + 1][xy[2].second] != 1 &&
		xy[0].first + 1 < length*2 && xy[1].first + 1 < length*2 && xy[2].first + 1 < length*2) {
		pos[xy[0].first + 1][xy[0].second] = 2;
		pos[xy[1].first + 1][xy[1].second] = 2;
		pos[xy[2].first + 1][xy[2].second] = 2;
		return true;
	}
	else {
		return false;
	}
}

int gameBlock::count()
{
	int lineCount = 0;

	for (int i = length; i < length * 2; i++) {
		int lineCounter = 0;
		for (int j = 0; j < length; j++) {
			if (pos[i][j] == 1 || pos[i][j] == 2) {
				lineCounter++;
			}
			if (lineCounter == 8) {
				lineCount++;
			}
		}
	}

	return lineCount;
}





int solution(gameBlock block, int row, int col) {
	
	return 0;
}

int main(void) {
	
	int block = 0;
	gameBlock gBlock(block, 4);
	gBlock.insertBoard();
	gBlock.print();
	int i = 0;
	int max = -1;
	int result = 0;
	while (gBlock.right(i)) {
		while (gBlock.down()) {
			result = gBlock.count();
			cout 
			if (result > max) {
				max = result;
			}
			 gBlock.print();
		}
		i++;
	}
	cout << "final result = " << max << endl;

	return 0;
}


