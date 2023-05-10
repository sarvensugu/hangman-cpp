#include <iostream>
#include <vector>


using namespace std;

void greet(){
    
    cout<<"+-------------------------------+"<<endl;
    cout<<"Hangman : The Game"<<endl;
    cout<<"+-------------------------------+"<<endl;
    cout<<"Instructions : Save the guy by guessing the correct letters !!!"<<endl;
    
}

void display_status(vector<char> incorrect, string answer){
    
    cout<< "Previous incorrect guesses:"<<endl;
    
    for (int i = 0; i < incorrect.size(); i++){
        cout<<incorrect[i]<<" ";
    }
    
    cout<<"\nCodeword : \n";
    
    for (int i = 0; i < answer.length(); i++){
        cout<< answer[i]<<" ";
    }

}

void endgame(string answer, string codeWord){
    if (answer == codeWord){
        cout<< "You have win the game!"<<endl;
        cout<<"Congratulations"<<endl;
    }
    else{
        cout<<"You have lose the game!"<<endl;
    }
}

void display_misses(int stage){
    
    if(stage == 0){
        cout<< "HANG IS NOT YET SET. YOU ARE SAFE."<<endl;
        cout<< "+==============+"<<endl;
    }
    else if (stage == 1){
        
        cout<< "+-----+" <<endl;
        cout<< "   |  |" <<endl;
        
    }
    else if(stage == 2){
        
        cout<< "+-----+" <<endl;
        cout<< "   |  |" <<endl;
        cout<< "   O  |" <<endl;
        
    }
    else if(stage == 3){
        
        cout<< "+-----+" <<endl;
        cout<< "   |  |" <<endl;
        cout<< "   O  |" <<endl;
        cout<< "  /|\\ |" <<endl;
        
    }
    else if(stage == 4){
        
        cout<< "+-----+" <<endl;
        cout<< "   |  |" <<endl;
        cout<< "   O  |" <<endl;
        cout<< "  /|\\ |" <<endl;
        cout<< "  / \\ |" <<endl;
        
    }
    else if(stage == 5){
        
        cout<< "+-----+" <<endl;
        cout<< "   |  |" <<endl;
        cout<< "   O  |" <<endl;
        cout<< "  /|\\ |" <<endl;
        cout<< "  / \\ |" <<endl;
        cout<< "      |" <<endl;
        cout<< "=========" <<endl;
        cout<< "HANGED"<<endl;
        
    }
}


int main(int argc, const char * argv[]) {
    
    greet();
    
    string codeWord = "sarvendren";
    string answer = "__________";
    int stage = 0;
    vector<char> incorrect;
    bool guess = false;
    char letter;
    
    while ( answer != codeWord && stage < 5){
        
        system("clear");
        
        display_misses(stage);
        
        display_status(incorrect, answer);
        
        cout<<"Enter your guess : "<<endl;
        cin>>letter;
        
        for (int i = 0; i < codeWord.length(); i++){
            
            if (letter == codeWord[i]){
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess){
            cout<<"Correct"<<endl;
        }
        else{
            cout<<"Incorrect"<<endl;
            incorrect.push_back(letter);
            stage++;
        }
        guess = false;
        
    }
    
    endgame(answer, codeWord);
    
    return 0;
}
