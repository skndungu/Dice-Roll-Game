int incomingDice = 0; // declare and initilize the dice number to be input from the Serial monitor

char player; // variable to hold the name of the player
String playerName;
int computerDice = 0;
int playerDice = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("Welcome to the dice game.");
    Serial.println(" "); // prints a blank line
}

void loop()
{
    inputName();                    // calls the input name function to print the input name statement
    playerDice = rollTheDice(1, 7); // calls the function to perform the random function
    Serial.print(player);
    Serial.print(" rolled");
    Serial.println(playerDice);

    computerDice = rollTheDice(1, 7);
    Serial.print("Computer");
    Serial.print(" rolled");
    Serial.println(computerDice);

    if (computerDice > playerDice)
    {
        computerWins();
        inputName();
    }
    else if (playerDice > computerDice)
    {
        youWin();
        inputName();
    }

    else if (playerDice == computerDice)
    {
        tie();
        inputName();
    }
}

long rollTheDice(int min, int max)
{
    /**************************************************
  * Function rollTheDice()
  * Description:
  *   This function simulates rolling a dice
  *   using a random number generator.
  *   A dice has 6 sides, with values 1 through 6.
  * Return:
  *   A long variable that contains the value 
  *   generated for the dice roll.
  * Parameters:
  *   min - lower bound of the random value, inclusive
  *   max - upper bound of the random value, exclusive
  *
  */
    return random(min, max); // returns a number between the passed integer values
}

void inputName()
{
    Serial.println("Please enter you name to play the game."); // Function to be printing the set, to shorten the code.
  while (Serial.available() > 0)
    {
        player = Serial.read();
        playerName +=  player;
        if(player == '/n'){
          Serial.print(playerName);
        }
        
    }
}

void computerWins()
{
    Serial.println("computer Wins!"); //Funtion to print computer wins statement
}

void youWin()
{
    Serial.println("You Win!"); // Function to print the you win statement
}

void tie()
{
    Serial.println("Tie!"); // Function to print the Tie statement
}

void thanksForPlaying()
{
    Serial.println("Thanks for playing"); // Function to print the you win statement
}

long humanRollDice()
{
    int randNumber = random(7);
    Serial.println(randNumber);
}

void clearPlayerName(){
  playerName = ""; // clears the received bytes 
}
