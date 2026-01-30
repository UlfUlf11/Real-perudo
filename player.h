#pragma once
#include "generator.h"
#include "gameplay.h"
#include <map>
#include <string>


class Player {
public:
	Player(const std::string& name) : name_(name), dices_(5) {
		//нужно сгенерировать кости и заполнить ими cup
		cup_ = Generate(dices_);
		all_dices += 5;

		//сгенерированные кости добавл€ютс€ в общую кучу
		for (int i = 0; i < cup_.size(); ++i) {
			int n = cup_[i];
			quantity_all_dices[n] += 1;
		}
	}


	std::string GetName() const{
		return name_;
	}

	std::vector<int> GetCup() const {
		return cup_;
	}

	void MakeBid(int quantity, int number) {
		bid_.quantity = quantity;
		bid_.number = number;

		ACTUAL_BID.quantity = quantity;
		ACTUAL_BID.number = number;
	}

	Bid GetBid() const {
		return bid_;
	}

	int GetDices() const {
		return dices_;
	}

	void DecreaseDices() {
		--dices_;
		--all_dices;
	}

	void GenerateNewDices() {
		
	}

private:
	std::string name_;
	int dices_; // сколько костей у игрока
	Bid bid_; //предположение о кол-ве костей за столом
	std::vector<int> cup_; //карманные кости
};

void GeneratePlayers() {
	for (const auto name : all_players) {
		Player player(name);
		players_players.push_back(player);
	}
}