boolean show = false;
int total[6];
int cur = 0;
int cpu = 0;
int mem = 0;
int Brightness = 255;


void setup() {       
  Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps  
  pinMode(3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) 
  {
    total[cur] = Serial.read();
    cur++;
    show = true;
    delay(5);    
  }
  else if (show)
  {
  
    show = false;
    cur = 0;
    
    cpu = 0;
    mem = 0;
    for(int i = 0; i < 6; i++) {
      //Serial.println((total[i] * pow(10, 2 - i)), DEC);
        if(i<3)
        { 
          cpu += (intToChar(total[i])) * pow(10, 2 - i);
        }
        else if(i < 6)
        {
          mem += (intToChar(total[i])) * pow(10, 5 - i);
        }
    }

    //Serial.print("result: ");
    //Serial.println(res, DEC);
    
  }
  else
  {
//    showLed(11,'C', 255);
//    delay(5);
//    showLed(10,'P', 255);
//    delay(5);
//    showLed(9,'U', 255);
//    delay(5);
  }

  
  
  myShowLeds(mem, 10, Brightness);
  analogWrite(3, map(cpu, 0, 100, 0, 255));
  analogWrite(5, map(mem, 0, 100, 0, 255));
  
  //analogWrite(3, map(correctAnalogDisplay(res), 0, 100, 0, 255));
  //Brightness--;
  if(Brightness == 0) Brightness = 255;
  
}

int correctAnalogDisplay(int input)
{
  if(input > 0 && input <= 10) input = 5; //10
  else if (input > 10 && input <= 20) input = 11; //20 
  else if (input > 20 && input <= 30) input = 17; //30
  else if (input > 30 && input <= 40) input = 24; //40
  else if (input > 40 && input <= 50) input = 35; //50
  else if (input > 50 && input <= 60) input = 47; //60
  
  else if (input > 60 && input <= 70) input = 56; //70
  else if (input > 70 && input <= 80) input = 65; //80
  else if (input > 80 && input <= 90) input = 76; //90
  else if (input > 90 && input <= 100) input = 97; //100
  else if (input > 100) input = 97; //100
  return input;
}

void myShowLeds(int num, int time, int brightness)
{

  int one = num % 10;
  int two = (num/10) % 10;
  int three = (num/100) % 10;
  
 
  
  for(int i=0; i<=time; i++)
  {
    showLed(9, one, brightness);   
    delay(1);              
    
  
    if(num < 10 && two == 0)
    {
      
    }
    else 
    {
      showLed(10, two, brightness);   
      delay(1); 
    }
  
    if(num < 100 && three == 0)
    {
      
    }
    else
    {
      showLed(11, three, brightness);   
      delay(1); 
    }
      
  }  
}



void showLed(int pos, char num, int brightness)
{
 
  int D1 = 9;
  int D10 = 10;
  int D100 = 11;
    
  int A = 6;
  int B = 4;
  int C = 12;
  int D = 8;
  int E = 7;
  int F = 2;
  int G = 13;
  
  pinMode(A, OUTPUT);     
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D100, OUTPUT);
  
  
  analogWrite(D1, 0);
  analogWrite(D10, 0);
  analogWrite(D100, 0);
  
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  
  analogWrite(pos, brightness);   
  
  if(num == 8)
  {
    digitalWrite(G, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(B, LOW);
  }
  else if (num == 0)
  {
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(B, LOW);
  }
  else if (num == 1)
  {
    digitalWrite(C, LOW);
    digitalWrite(B, LOW);
  }
  else if (num == 2)
  {
    digitalWrite(G, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
  }
  else if (num == 3)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(G, LOW);
    digitalWrite(D, LOW);
  }
  else if (num == 4)
  {
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  }
  else if (num == 5)
  {
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }
  else if (num == 6)
  {
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
  }
  else if (num == 7)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  }
  else if (num == 9)
  {
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(B, LOW);
    digitalWrite(G, LOW);
    digitalWrite(D, LOW);
    digitalWrite(C, LOW);

  }
  else if (num == 'A')
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }
  else if (num == 'C')
  {
    digitalWrite(A, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
  }
  else if (num == 'U')
  {
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
  }
  else if (num == 'P')
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }
 
}

////////////////////


int pow (int num, int to) {
    if( to == 0 ) return 1;
    
    int res = num;
    for(int i = 1; i < to; i++) {
        res *= num;
    }
    return res;
}

char intToChar(int digit)
{
  
  if(digit >= 48 && digit <= 57)
  {
    return digit - 48;  
  }
  else if (digit == 65)
  {
    return 'A';
  }
  else if (digit == 66)
  {
    return 'B';
  }
  else if (digit == 67)
  {
    return 'C';
  }
}


