#pragma once
#include <map>
#include <cmath>
#include <optional>
#include "player.h"
#include "gameplay.h"

const auto EPSILON = 1e-6; 
/*if (abs(lhs.relevance - rhs.relevance) < EPSILON) { } */

double CheckWinPct() {
	return 1.0 / all_players.size();
}

//Ф-я считает сколько кубиков того или иного номинала присутствует у игроков в среднем
double CheckBidVariation(Bid bid, Player& player) {
	//формируем словарь кубиков игрока
	std::vector<int> cup = player.GetCup();
	std::map<double, double> dices_amount{ {1.0 ,0.0}, {2.0,0.0}, {3.0,0.0}, {4.0,0.0}, {5.0,0.0}, {6.0,0.0} };
	for (int i = 0; i < cup.size(); ++i) {
		int n = cup[i];
		dices_amount[n] += 1.0;
	}

	if (bid.quantity != 1) {
		double players_amount = dices_amount.at(bid.quantity) + dices_amount.at(1);
		int oponent_dices_amount = all_dices - cup.size();
		return (oponent_dices_amount / 3) + players_amount;
	}
	else {
		double players_amount = dices_amount.at(1);
		int oponent_dices_amount = all_dices - cup.size();
		return (oponent_dices_amount / 6) + players_amount;
	}
}

//факториал числа n. Нужно обязательно использовать uint_64, чтобы влез 
uint64_t Factorial(int num) {
	uint64_t factorial = 1;
	while (num > 1) {
		factorial *= num;
		--num;
	}
	return factorial;
}

//n - кол-во кубиков; k - кол-во выпавших столько
uint64_t CalcVar(double n, double k) {
	return (Factorial(n) / (Factorial(k) * Factorial(n - k))) * pow(2.0 / 6.0, k) * pow(4.0 / 6.0, n - k);
}

//n - кол-во кубиков; k - кол-во выпавших столько
uint64_t CalcVarForOnes(double n, double k) {
	return (Factorial(n) / (Factorial(k) * Factorial(n - k))) * pow(1.0 / 6.0, k) * pow(5.0 / 6.0, n - k);
}

//dices_amount - словарь с кубиками того игрока, который выбирает стратегию
std::optional<Bid> CheckBetterBid (uint64_t variation, Bid bid, std::map<int, double>& dices_amount) {
	int nominal = bid.quantity;
	
	//переписать на !=1 как наиболее распространенный вариант       !!!!!!!!!!!!!!!!!!!!!!!!
	if (nominal == 1) {
		                                                //нельзя .size т.к. он всегда равен 6, нужно передавать отдельно
		uint64_t new_var = CalcVarForOnes( (all_dices - dices_amount.size()), ( bid.number + 1 ) );

	}

	int better_nominal = 0;
	int bid_better_num = 0;
	uint64_t new_var;
	for (; nominal < 7; ++nominal) {
		if (dices_amount.at(nominal) >= bid_better_num) {
			bid_better_num = dices_amount.at(nominal);
		}
	}

	if (better_nominal != 1) {
		new_var = CalcVar();  
	}
	else {
		
	}
 
	return std::nullopt;
}

Bid BestPossibleBluff(Player& player) {
	
}

Bid BestPossibleBet(Player& player) {

}

void MakeDecision () {
	
}

//вызывется, если перед опонентом не было сделано ни одной ставки
Bid MakeBid(Player& player) {
	//формируем словарь кубиков игрока
	std::vector<int> cup = player.GetCup();
	std::map<int, double> dices_amount { {1 , 0.0}, {2 , 0.0}, {3 , 0.0}, {4 , 0.0}, {5 , 0.0}, {6 , 0.0} };
	for (int i = 0; i < cup.size(); ++i) {
		int n = cup[i];
		dices_amount.at(n) += 1;
	}

	//под вырез 
	for (int i = 1; i < 7; ++i) {
		std::cout << "Колличество кубиков под номиналом " << i << " равно " << dices_amount.at(i) << std::endl;
	}

	int nominal = 0;
	int number = 0;

	if (dices_amount.at(1) != cup.size()) {
		for (int i = 2; i < 7; ++i) {
			if (dices_amount.at(i) >= number) {
				nominal = i;
				number = dices_amount.at(i);
			}
		}
		double no_round_number = dices_amount.at(nominal) + dices_amount.at(1.0) + ((all_dices - cup.size()) / 3.0);
		number = round(no_round_number); //округяляю по математике
	}

	else {
		nominal = 1;
		double no_round_number = dices_amount.at(1.0) + ((all_dices - cup.size()) / 6.0);
		number = round(no_round_number); //округяляю по математике
	}

	//нужно учесть сколько у опонентов в среднем этого номинала + мои еденицы.
	//вероятности нужно пересчитать в double
	return Bid{ nominal, number };
}

Bid GenerateStrategy(std::vector<int> cup) {
	return Bid{ 0,0 };
}