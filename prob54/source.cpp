#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

/*
only value based results {
    high card           1
    1 pair              2
    2 pairs             3
    three of a kind     4
    straight            5
    full house          7
    poker               8
}
only suit based results {
    flush               6
}
both value and suit {
    straight flush      9
    royal flush         10
}

strategy:
if flush {
    if straight flush {
        if royal flush {
            RES royal flush
        }
        else RES straight flush
    }
    else flush
}
else check only values
*/

using namespace std;

class Card
{
public:
    int value;
    char suit;
    Card(string);
    Card()
    {
        value = -1;
        suit = 'I';
    };
};

Card::Card(string name)
{
    if (isdigit(name[0]))
    {
        value = name[0] - '0';
    }
    else
    {
        switch (name[0])
        {
        case 'J':
            value = 11;
            break;
        case 'Q':
            value = 12;
            break;
        case 'K':
            value = 13;
            break;
        case 'A':
            value = 1;
            break;
        }
    }

    suit = name[1];
}

class Hand
{
private:
    int n = 0;
    int get_value()
    {

        bool flush = true, straight = false, royal = false;
        int hand_value = -1;
        int values[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        // check for flushes
        char suit = cards[0].suit;
        for (int i = 0; i < 5; i++)
        {
            values[cards[i].value - 1] += 1;
            if (cards[i].suit != suit)
            {
                flush = false;
            }
        }

        //check for straight
        for (int i = 0; i < 13 && !straight; i++)
        {
            if (values[i] == 1)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (values[(i + j) % 13] != 1)
                    {
                        break;
                    }
                    if (j == 4)
                    {
                        straight = true;
                        royal = (i == 9);
                    }
                }
            }
        }

        if (flush)
        {
            if (straight)
            {
                if (royal)
                {
                    hand_value = 10;
                }
                else
                {
                    hand_value = 9;
                }
            }
            else
            {
                hand_value = 6;
            }
        }
        else if (straight)
        {
            hand_value = 5;
        }
        else
        {
        }
    };

public:
    Card cards[5];
    void add_card(Card);
    Hand(){};
    bool is_winning(Hand);
};

void Hand::add_card(Card c)
{
    cards[n] = c;
    n++;
}

bool Hand::is_winning(Hand other)
{
}

void parseLine(string &str, Hand &player1, Hand &player2)
{
    char delim = ' ';
    size_t start;
    size_t end = 0;

    for (int i = 0; i < 5; i++)
    {
        start = str.find_first_not_of(delim, end);
        end = str.find(delim, start);
        player1.add_card(Card(str.substr(start, end - start)));
    }

    for (int i = 0; i < 5; i++)
    {
        start = str.find_first_not_of(delim, end);
        end = str.find(delim, start);
        player2.add_card(Card(str.substr(start, end - start)));
    }
}

int main()
{

    ifstream input;
    string line;
    Hand player1, player2;
    input.open("prob54//data.txt");

    while (getline(input, line))
    {
        parseLine(line, player1, player2);
    }
}