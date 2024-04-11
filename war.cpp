#include <iostream>
#include <ctime>


using namespace std; 


class Card{

    private:

        char suit;
        char rank;

    public:

        Card()
        {

        }

        Card(char s, char r)
        {
            suit = s;
            rank = r; 

        }

        void display()
        {

            if (rank == 'T'){
                cout << "10" << suit;
            }
            else
            {
                cout << rank << suit;
            }

        }

        int compare(Card other)
        {
            int rank_index = -1;
            int other_index = -1; 
            char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

            for(int i = 0; i < 13; i++){
                if (rank == ranks[i]){
                    rank_index = i;
                }
            }

            for(int j = 0; j < 13; j++){
                if (other.rank == ranks[j]){
                    other_index = j;
                }
            }

            if (rank_index > other_index)
                return 1;
            else if (rank_index < other_index)
                return -1;
            else
                return 0;   
        }
};

class Deck {

    private:

        Card storage[52];
        int card_index;

    public:
    
        Deck()
        {

            card_index = 0;
            char suits[]= {'C', 'S', 'D', 'H'};
            char ranks[]= {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 13; j++){
                    storage[card_index++] = Card(suits[i], ranks[j]);
                }
            }
        }

        Card deal()
        {

            if (isEmpty()){
                try{
                    throw "Error - Deck is empty";
                }
                catch(const char* error_message){
                    cout << error_message << endl;
                }
            }
            return storage[--card_index]; 
        }

        void display()
        {
            for(int i = 0; i < card_index; i++){
                if(i % 13 ==12){
                    storage[i].display();
                    cout << endl;
                }
                else{
                    storage[i].display();
                    cout << ",";   
                }    
            }
	        cout << endl;
        }

        void shuffle()
        {

            srand(time(0));

            for(int i = 0; i < card_index; ++i){
                int j = rand() % card_index;
                swap(storage[i], storage[j]);
            }
            cout << endl;
        }

        bool isEmpty()
        {
            return card_index == -1;
        }
};
    
int main()
{
    string firstname; 
    string secondname; 
    int player1_score = 0;
    int player2_score = 0;
    int game_play = 0;
    int ties = 0;

    cout << "\nEnter the name of the first player:";
    cin >> firstname;
    cout << "Enter the name of the second player:";
    cin >> secondname;
    cout << "How many games will they play?";
    cin >> game_play;


    Deck deck;
    cout << "\n Original Deck\n";
    deck.display();

    deck.shuffle();
    cout << " Shuffled Deck\n";
    deck.display();

    for(int i = 1; i < game_play; i++){
        try{

            Card first_player_c = deck.deal();
            Card second_player_c = deck.deal();

            cout << "\nGame" << " " << i << "\n";
            cout << "-------\n";
        

            cout << "       " << firstname << "=>";
            first_player_c.display();
            cout << "\n";
            cout << "       " << secondname << "=>";
            second_player_c.display();
            cout << "\n";

            if (first_player_c.compare(second_player_c) == 1){
                cout << firstname << "=>" << " Winner" << endl;
                player1_score++;
            }
            else if(first_player_c.compare(second_player_c) == -1){
                cout << secondname << "=>" << " Winner" << endl;
                player2_score++;
            }
            else{
                cout << "Tie game" << endl;
                ties++;
            }
        }
        catch(const char* msg){
            cerr << "Jorge" << msg << endl;

        }


    cout << "\n------Final Stats-------" << endl;
    cout << "       " << firstname << " vs. " << secondname << endl;
    cout << "Wins   " << player1_score << "          " << player2_score << endl;
    cout << "Losses " << player2_score << "          " << player1_score << endl;
    cout << "Ties   " << ties << "           " << ties << endl;
    }
}
