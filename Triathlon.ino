//The program asks a user for a time of each part of triathlon.
//If the inserted time is the quickest than it is being stored as the best score.
//The best score is being shown when the user inputs negative value as the first

int read_from_serial(String text)
{
  int input_val;
  Serial.println(text);
  while (!Serial.available()) {
    ;
  }
  input_val = Serial.parseInt();
  return input_val;

}

void setup() {
  Serial.begin(9600);

  long arrayOfSeconds [4]; //creating an array in which time of contestants will be stored [in seconds]
  String names [4] = {"Swim", "Bike", "Run", "Total"}; //creating an array with names of the times that will be stored
  const int seconds_in_hour = 3600;
  const int seconds_in_minute = 60;
  int counter = 0;
  int number_of_the_best_person = 0;
  long best_score = 999999; //assaigning a high value to variable best_score

  while (1) {

    arrayOfSeconds[0] = read_from_serial("Swimming Hours: ");

    if (arrayOfSeconds[0] < 0) { //if user inputs a hour number that is less than zero program will output a current best score
      Serial.println("==========");
      Serial.print("The fastest athlete was no. ");
      Serial.print(number_of_the_best_person);
      Serial.print(" with total time of ");
      Serial.print(best_score / seconds_in_hour);
      Serial.print(" hr ");
      Serial.print(((best_score) % (seconds_in_hour)) / (seconds_in_minute));
      Serial.print(" min ");
      Serial.print(best_score % seconds_in_minute);
      Serial.println(" sec ");
      Serial.print("==========");
      break;
    }



    //storing the rest of the scores in an array
    arrayOfSeconds[0] = (arrayOfSeconds[0] * seconds_in_hour);
    arrayOfSeconds[0] += read_from_serial("Swimming Minutes: ") * seconds_in_minute;
    arrayOfSeconds[0] += read_from_serial("Swimming Seconds: ");

    arrayOfSeconds[1] = read_from_serial("Running Hours: ") * seconds_in_hour;
    arrayOfSeconds[1] += read_from_serial("Running Minutes: ") * seconds_in_minute;
    arrayOfSeconds[1] += read_from_serial("Running Seconds: ");

    arrayOfSeconds[2] = read_from_serial("Cycling Hours: ")  * seconds_in_hour;
    arrayOfSeconds[2] += read_from_serial("Cycling Minutes: ")  * (seconds_in_minute);
    arrayOfSeconds[2] += read_from_serial("Cycling Seconds: ");

    arrayOfSeconds[3] = arrayOfSeconds[1] + arrayOfSeconds[2] + arrayOfSeconds[0];

    counter++;


    //if inserted score is better than the best score than it is now the best score
    if (arrayOfSeconds[3] < best_score) {
      best_score = arrayOfSeconds[3];
      number_of_the_best_person = counter;
    }




    for (int index = 0; index <= 3; index++) {
      Serial.print(names[index] + " Time: ");
      Serial.print(arrayOfSeconds[index] / seconds_in_hour);
      Serial.print(" hr ");
      Serial.print(((arrayOfSeconds[index]) % seconds_in_hour) / seconds_in_minute) ;
      Serial.print(" min ") ;
      Serial.print(arrayOfSeconds[index] % seconds_in_minute) ;
      Serial.println(" sec ")   ;

    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
