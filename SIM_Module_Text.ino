Once am try to receive sms from my SIM900 GSM module and try to send it on Terminal window with the help of Arduino UNO, I have faced lots of problem related to set SIM900 as Text mode and Accessing the memory location where receive message to be store, after setting all AT commands step by step finally i did it.

During this i have searched lots  on internet to solve my problem, but none of solved my problem.

So i decided to give you all my code for which help you alot





Here is my code which will give you perfect result without any trouble----



 #include <SoftwareSerial.h>

SoftwareSerial gsm(0, 1);

int led=13;

char incoming_char=0;



void setup()

{

  pinMode(led,OUTPUT);

  Serial.begin(9600); // for serial monitor

  gsm.begin(2400); // for GSM shield

  delay(2000);

  gsm.println("ATV1");

  delay(100);

  gsm.println("ATE0");

  delay(100);

  gsm.println("AT+CMGF=1");

  delay(100);

  gsm.println("AT+CMGD=1");

  delay(1000);

  gsm.println("AT+CNMI=2,2,0,0,0\r");

  delay(100);

  gsm.println("AT+CMGR=1");

  delay(200);

  }

 
void loop()

{



  if(gsm.available() >0)

  {

    incoming_char=gsm.read(); //Get the character from the cellular serial port.

  //  Serial.print(incoming_char); //Print the incoming character to the terminal.

    if(incoming_char=='a')

    {

      digitalWrite(led,HIGH);

      Serial.println("Coin Acceptor OFF");

      }

  }

}
