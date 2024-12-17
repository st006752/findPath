// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdint>
#include <cstdlib>

struct BitMap {
	int rows;
	int cols;
	uint8_t* data;
};

bool loadBitMap(const char* filename, BitMap&);
bool isFree(int x, int y, const BitMap*);

struct Pos {
	int x;
	int y;
};


struct PosInfo {
	Pos prev;
	size_t length;
};

struct Map {
	int rows;
	int cols;
	PosInfo* data;
};

void initPosInfo(Map&);
PosInfo getAt(int x, int y);
void setAt(int x, int y, const PosInfo &);



struct ListNode {
	Pos pos;
	ListNode* next;
};

struct List {
	ListNode* head;
	ListNode* tail;
};
void initList(List&);
bool hasHead(const List&);
Pos getHead(List&);
void addTail(List&, const Pos&);



List where2go;

List findPath(BitMap&, const Pos& start, const Pos& fin);


int main(int argc, char* argv[] )
{

	BitMap bitMap;
	if (!loadBitMap(argv[1], bitMap)) {
		return 1;
	}
	Pos start;
	start.x = atoi(argv[2]);
	start.y = atoi(argv[3]);

	Pos fin;
	fin.x = atoi(argv[4]);
	fin.y = atoi(argv[5]);

	List resultPath = findPath(bitMap, start, fin);

	if (hasHead(resultPath))
		;// Print found path


    return 0;
}

