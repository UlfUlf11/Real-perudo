#pragma once
#include <vector>
#include <map>
#include "player.h"

//кол-во костей в игре
static int all_dices = 0;
//кол-во костей разного номинала в игре
static std::map<int, int> quantity_all_dices = { {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0} };

//ставка
struct Bid {
	int quantity = 0; //номинал, инициализирую нулем для проверки наличия ставки
	int number = 0; //кол-во
};

static Bid ACTUAL_BID {0,0};
static std::string ACTUAL_BIDDER("unnamed");
static std::string DEALER("unnamed");
static std::string PLAYER("unnamed");

static std::vector<std::string> all_players; //можно сделать это хранилище временным, хранить поле все время не нужно
class Player;
static std::vector<Player> players_players;

/*
static void AddPlayer(const std::string& name) {
	if (std::find(all_players.begin(), all_players.end(), name) == all_players.end()) {
		all_players.push_back(name);
		std::cout << "Player " << name << " joined the game!" << std::endl;
	}
	else {
		std::cout << "Player " << name << " already exist! Choose another name!" << std::endl;
	}	
}
*/

static void ChooseDealer() {
	int dealer = rand() % all_players.size();
	DEALER = all_players[dealer];

	if (*all_players.begin() != DEALER) {
		std::vector<std::string> new_order;
		auto it = std::find(all_players.begin(), all_players.end(), DEALER);
		new_order.insert(new_order.begin(), it, all_players.end());
		new_order.insert(new_order.end(), all_players.begin(), it);
		std::swap(all_players, new_order);
	}
}

bool Call(const Bid& bid) {
	if (bid.quantity != 1) {
		int count = quantity_all_dices.at(1) + quantity_all_dices.at(bid.quantity);
		return bid.number <= count;
	}
	else {
		return bid.number <= quantity_all_dices.at(1);
	}
}

bool CheckGameWinner() {
	if (all_players.size() > 1) {
		return false;
	}
	return true;
}

void AddToPlayerCollection(std::string player) {
	all_players.push_back(player);
}

void MakePlayer(const std::string& name) {

}

void StartGame() {
	std::string player_name;
	std::cout << "Введите имя пользователя: ";
	std::cin >> player_name;

	PLAYER = player_name;

	AddToPlayerCollection(player_name);
	AddToPlayerCollection("Противник1");
	AddToPlayerCollection("Противник2");
	AddToPlayerCollection("Противник3");

	ChooseDealer(); //имена игроков становятся в правильном порядке
}

void Round() {
	while (CheckGameWinner() != true) {
		
	}
}
