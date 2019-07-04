int crveno = D2;
int plavo = D3;
int zeleno = D4;
//int svetlo = D5;  //jjjjjjj
int alarm = D7;
int a,b,c,d,e;
int napajanje = D0;
int PIR = D5;

char *message = "detektovano je";
char *mes = "nije detektovano";
char *kret[30];


int digitalvalue = 0;


void setup()
{
 
   // Setup the pin as OUTPUT
   pinMode(crveno, OUTPUT);
   pinMode(plavo, OUTPUT);
   pinMode(zeleno, OUTPUT);
//   pinMode(svetlo, OUTPUT);
   pinMode(alarm, OUTPUT);
   pinMode(napajanje, OUTPUT);
   digitalWrite(napajanje, HIGH);
  
  
   //pinMode(senzor, INPUT);
//   pinMode(crveno, OUTPUT);
 
   /*
    Declare a Particle.function so that we can turn the LED on and off from the cloud.
    the function is now available and maps to the ledToggle function below
   */
   Particle.function("led", ledToggle);
 
    if (Particle.variable("rez", &digitalvalue)== LOW)
  {
      Particle.variable("kret", mes) ;
  }
  Particle.variable("kret", message);


 
}
 
void loop()
{
 digitalvalue = digitalRead(D5);
 
}
int ledToggle(String command) {
    /*
     Particle.functions always take a string as an argument and return an integer.
     In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    */
 
    if (command == "csvetlo") {
        if(a==1){
        digitalWrite(crveno, LOW);
        a=0;
        return 0;
        }if(a==0){
        digitalWrite(crveno, HIGH);
        a=1;
        return 1;
        }
       
    }
    if (command == "psvetlo") {
        if(b==1){
        digitalWrite(plavo, LOW);
        b=0;
        return 0;
        }if(b==0){
        digitalWrite(plavo, HIGH);
        b=1;
        return 1;
        }
    }if (command == "zsvetlo") {
        if(c==1){
        digitalWrite(zeleno, LOW);
        c=0;
        return 0;
        }if(c==0){
        digitalWrite(zeleno, HIGH);
        c=1;
        return 1;
        }
    /*}if (command == "svetlo") {
        if(d==1){
        digitalWrite(svetlo, LOW);
        d=0;
        return 0;
        }if(d==0){
        digitalWrite(svetlo, HIGH);
        d=1;
        return 1;
        }*/
    }if (command == "alarm") {
        if(e==1){
        digitalWrite(alarm, LOW);
        e=0;
        return 0;
        }if(e==0){
        digitalWrite(alarm, HIGH);
        e=1;
        return 1;
        }
    }
   
 
}
