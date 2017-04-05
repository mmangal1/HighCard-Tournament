#include "Heap.h"
#include <string>
#include <iostream>

//initalize empty array????
Heap::Heap(){}

Heap::Heap(std::string filename){
	std::ifstream myFile;
	myFile.open(filename.c_str());
	if(myFile.is_open()){
		int counter = 0;
		std::string name, money;
		while(std::getline(myFile, name) && std::getline(myFile, money)){
			data.push_back(Player(name, std::stoi(money)));
		}
		heapify();
	}else{}
	myFile.close();

}

Heap::Heap(const Heap &copy){}

void Heap::addPlayer(Player newPlayer){
	data.push_back(newPlayer);
	heapify();
}

Player Heap::getPlayer(){
	Player obj = data.at(0);
	data.erase(data.begin());
	heapify();
	return obj;
}

std::vector<Player> Heap::getArray(){
	return data;
}

bool Heap::empty(){
	if(data.size() == 0)
		return true;
	return false;
}

unsigned int Heap::size(){
	return data.size();
}

void Heap::heapify(){
	for(int i = (data.size()-2)/2; i >= 0; i--){
		siftdown(i);
	}
}

void Heap::siftdown(int i){
	if((i < 0) ||( i >= data.size()))
		return;
	while(!isLeaf(i)){
		int child = leftChild(i);
		if(((2*i+2) < data.size()) && (data.at(child).getBudget() < data.at(rightChild(i)).getBudget()))
			child = rightChild(i);				
	
		if(data.at(i).getBudget() < data.at(child).getBudget()){
			std::swap(data.at(i), data.at(child));
		}else{
			return;
		}
		i = child;	
	}
}

bool Heap::isLeaf(int i){
	if(((2*i+1) >= data.size()) && ((2*i+2) >= data.size()))
		return true;
	return false;
}

int Heap::leftChild(int i){
	return 2*i+1;
}

int Heap::rightChild(int i){
	return 2*i+2;
}






