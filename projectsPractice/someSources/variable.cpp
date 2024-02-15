#include <iostream>
#include <cmath>

using namespace std;
/*
string getDayofWeek(int dayNum){
    string dayName{};

    switch(dayNum){
    case 0:
        dayName = "Sunday";
        break;
    case 1:
        dayName = "Monday";
        break;
    case 2:
        dayName = "Tuesday";
        break;
    case 3:
        dayName = "Wednesday";
        break;
    case 4:
        dayName = "thursday";
        break;
    case 5:
        dayName = "Friday";
        break;
    case 6:
        dayName = "Saturday";
        break;
    default:
        dayName = "Invalid day number";
    }


    return dayName;
}

double cube(double num) {

 return num * num * num;
}

void sayHi(string name, int age){

 cout << "Hello " << name << " you are " << age << '\n';
}


int getMax (int num1, int num2, int num3){
    int result;

    if(num1 >= num2 && num1 >= num3){
        result = num1;
    } else if (num2 >= num1 && num2 >= num3){
        result = num2;
    } else {
        result = num3;
    }

    return result;
}


int power(int baseNum, int powNum){
    int result{1};
    for(int i = 0; i < powNum; i++){
        result = result*baseNum;
    }
    return result;
}


// Definition of user-defined function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()\n";
}

int getValueFromUser() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}
*/



int main ()
{
/*
cout << power(2, 3);

    string characterName = "Carlos";
    int characterAge;
    characterAge = 39;
    cout<<"there is a man named "<<characterName<<endl;
    cout<<"he is "<< characterAge <<'\n';


  char grade = 'A';
  string phrase = "What's up people";
  int age = 50;
  double gpa = 2.3;
  bool isMale = true;
  phrase[15]= 'R';
  float guito = 0.5;

  string name{};

  cout << grade << '\n' << phrase << '\n'

  << age << '\n' << gpa << '\n' << isMale << '\n';

  cout << phrase[15] << '\n';

  cout << phrase.find("peo",0) << '\n';

  cout <<  phrase.substr(10 , 6) << '\n';

  cout << pow(guito, gpa) << '\n';

  //sqrt, round, ceil, floor

  cout << fmax(6, 9) << fmin(78, 1) << endl;

  cout << " Enter your name: ";

  getline(cin, name);

  cout << "Hello " << name;

int luckyNums[50] = {4, 8, 15, 16, 23, 42};

cout << luckyNums[25];

sayHi("Carlos", 39);
sayHi("Karely", 35);
sayHi("Fili", 35);

cout << cube(5.3) << '\n';



bool isMale = false;
bool isTall = true;

if(isMale && isTall){
    cout << "you are a tall male";
} else if(isMale && !isTall){
    cout << "you are a short male";
} else if(!isMale && isTall){
    cout << "You are a tall female";
} else {
    cout << "You are a short female";
}

//&& and in an if
//|| or in an if


cout << getMax(2, 2, 1);


int num1, num2;
char op;

cout << "Enter first number: ";
cin >> num1;
cout << "Enter operator: ";
cin >> op;
cout << "Enter second number: ";
cin >> num2;
int result{};

if(op == '+'){
    result = num1 + num2;
} else if(op == '-'){
    result = num1 - num2;
} else if(op == '*'){
    result = num1 * num2;
} else if(op == '/'){
    result = num1 / num2;
} else {
    cout << "invalid operator";
}
    cout << result;


cout << getDayofWeek(10);


int i{1};
do{
    cout << i << '\n';
    i++;

}while(i<=10);


string secretNum{7};
string guess{};
int guessCount{};
int guessLimit{5};
bool outOfGuesses{false};

while(secretNum != guess && !outOfGuesses){
    if(guessCount < guessLimit){
        cout << "Enter guess: ";
        cin >> guess;
        guessCount++;
    } else {
        outOfGuesses = true;
    }

}
if(outOfGuesses == true){
    cout << "You lose";

} else {
    cout << "you win!";
}

int index{1};
while(index <= 5){
    cout << index << '\n';
    index++;
}


for(int i = 1; i <= 5; i++){
    cout << i << '\n';
}

int nums[]={1,2,4,5,6,7,89};
for(int i = 0; i < 7; i++){
    cout << nums[i] << '\n';
}


int age = 45;
//int *pAge = &age;
int numberGrid[3][2]={
{1, 2},
{3, 4},
{5, 6}
};

for(int i{0}; i<3; i++){
    for(int j{0}; j<2; j++){
        cout << numberGrid[i][j];
    }
    cout << " " << '\n';
}

cout << &age << '\n';


    int num1{};
    int num2{};

    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter another integer: ";
    cin >> num2;
    cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";


    std::cout << "Starting main()\n";
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends



	int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

	std::cout << num << " doubled is: " << num * 2 << '\n';


    int num1{getValueFromUser()};
    int num2{getValueFromUser()};


    cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";
*/

    return 0;
}
