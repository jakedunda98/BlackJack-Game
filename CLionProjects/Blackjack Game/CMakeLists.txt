cmake_minimum_required(VERSION 4.0)
project(Blackjack_Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Blackjack_Game main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Game.cpp
        Game.h)
