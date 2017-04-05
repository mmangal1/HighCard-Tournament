#ifndef HEAP_H
#define HEAP_H

#include <string>
#include "Player.h"
#include <cstdlib>
#include <vector>
#include <fstream>
class Heap{

	private:
		std::vector<Player> data;
		unsigned int heap_size;
		unsigned int data_size;
		void heapify();
		void siftdown(int i);
		bool isLeaf(int i);
		int leftChild(int i);
		int rightChild(int i);
	public:
		Heap();
		Heap(std::string filename);
		Heap(const Heap &copy);
		void addPlayer(Player newPlayer);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		unsigned int size();
};

#endif
