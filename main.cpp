#include <iostream>
#include <clocale>
#include "mesages.h"
#include "player.h"
#include "gameplay.h"
#include "strategy.h"

//Отображает кости игрока в виде цифр, а кости опонентов в виде символа "x"
void ShowDices() {
    for (const auto player : players_players) {
        std::cout << "У игрока " << player.GetName() << " находятся следующие кости:";
        if (player.GetName() != PLAYER) {
            for (int i = 0; i < player.GetDices(); ++i) {
                std::cout << " x";
            }
            std::cout << std::endl;
        }
        else {
            std::vector<int> cup = player.GetCup();
            for (int i = 0; i < cup.size(); ++i) {
                std::cout << " " << cup.at(i);
            }
            std::cout << std::endl;
        }
    }
}

int wmain()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); // настраиваем кодировку консоли
  
    GreetingMesage();
    DisplayRules();

    StartGame(); //все игроки добавлены в правильном порядке

    /*
    Player player = MakePlayer(player_name);
    Player player2 = MakePlayer("Противник1");
    Player player3 = MakePlayer("Противник2");
    Player player4 = MakePlayer("Противник3");
    */

   //std::cout << std::endl << players_players.size();
   // std::cout << std::endl << players_players.at(0) -> GetName();

    GeneratePlayers();

    ShowDices();

    std::cout << "Дилером является " << DEALER << std::endl;

  

    Bid bid = MakeBid(players_players[0]);

    std::cout << DEALER << " сделал ставку: " << bid.number << " " << bid.quantity << std::endl;
  
  /*
    while (CheckGameWinner() != true) {
        while (CheckRoundWinner() != true) {
            ChooseDealer();
            GenerateDicesForPlayers()
            ShowDices();

        }
    }
    */
}