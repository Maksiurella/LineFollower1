const int silnikLewy = 5;
const int silnikPrawy = 6;
const int silnikMax = 80;
int wartoscProgowa = 600;


float ostatniaDeltaU =0;
float uchyb = 0; 
float ostatniUchyb = 0;
/*const float Tl = 0;
const float Td = Tl/100;
const float Ts = 100; */
const float kp = 2; 
const float kd = 0.05;
const float MAXwychylenie =2.75;
const float OdlegloscMiedzyCzujnikami = 0.5;


void setup() {
  Serial.begin(9600);
  pinMode(silnikLewy, OUTPUT); //
  pinMode(silnikPrawy, OUTPUT); //
  
}

void loop() {
  int czujnik1 = analogRead(A0);
  int czujnik2 = analogRead(A1);
  int czujnik3 = analogRead(A2);
  int czujnik4 = analogRead(A3);
  int czujnik5 = analogRead(A4);
  int czujnik6 = analogRead(A5);

  bool WykrytoCzarny1 = 0;
  bool WykrytoCzarny2 = 0;
  bool WykrytoCzarny3 = 0;
  bool WykrytoCzarny4 = 0;
  bool WykrytoCzarny5 = 0;
  bool WykrytoCzarny6 = 0;

  if(czujnik1 > wartoscProgowa)
  WykrytoCzarny1 = 1;
  if(czujnik2 > wartoscProgowa)
   WykrytoCzarny2 = 1;
  if(czujnik3  > wartoscProgowa)
   WykrytoCzarny3 = 1;
  if(czujnik4 > wartoscProgowa)
   WykrytoCzarny4 = 1;
  if(czujnik5 > wartoscProgowa)
   WykrytoCzarny5 = 1;
  if(czujnik6 > wartoscProgowa)
  WykrytoCzarny6 = 1;

 Serial.print(WykrytoCzarny1);
 Serial.print(" ");
 Serial.print(WykrytoCzarny2);
 Serial.print(" ");
 Serial.print(WykrytoCzarny3);
 Serial.print(" ");
 Serial.print(WykrytoCzarny4);
 Serial.print(" ");
 Serial.print(WykrytoCzarny5);
 Serial.print(" ");
 Serial.print(WykrytoCzarny6);
 Serial.print(" ");

 Serial.print(czujnik1);
 Serial.print(" ");
 Serial.print(czujnik2);
 Serial.print(" ");
 Serial.print(czujnik3);
 Serial.print(" ");
 Serial.print(czujnik4);
 Serial.print(" ");
 Serial.print(czujnik5);
 Serial.print(" ");
 Serial.print(czujnik6);
 Serial.print(" ");

bool WynikiCzujnikow[6] = {WykrytoCzarny1,WykrytoCzarny2,WykrytoCzarny3,WykrytoCzarny4,WykrytoCzarny5,WykrytoCzarny6};

if(WynikiCzujnikow[0] == 1)
{
  if(WynikiCzujnikow[1] == 1)
  {
    if(WynikiCzujnikow[2] ==1)
    {
      if(WynikiCzujnikow[3]==1)
      {
        if(WynikiCzujnikow[4]==1)
        {
          if(WynikiCzujnikow[5]==1)
          {
             uchyb = 0;
     ostatniUchyb = uchyb;
          }
          else 
          {
            uchyb = -MAXwychylenie;
     ostatniUchyb = uchyb;
          }
        }
        else
        {
          if(WynikiCzujnikow[5] == 1)
          {
            BLADczujnika(uchyb,ostatniUchyb);
          }
          else
          {
             uchyb = -MAXwychylenie;
     ostatniUchyb = uchyb;
          }
        }
      }
      else 
      {
        if(WynikiCzujnikow[4]== 0 & WynikiCzujnikow[5]==0)
        {
          uchyb = -MAXwychylenie;
     ostatniUchyb = uchyb;
        }
     else
     {
      BLADczujnika(uchyb,ostatniUchyb);
     }
        }
      }
    else
    {
      if(WynikiCzujnikow[3] == 0 & WynikiCzujnikow[4]== 0 & WynikiCzujnikow[5]==0)
      {
         uchyb = -MAXwychylenie;
     ostatniUchyb = uchyb;
      }
      else
      {
        BLADczujnika(uchyb,ostatniUchyb);
      }
    }
  }
  else
  {
     if(WynikiCzujnikow[2] == 0 & WynikiCzujnikow[3] == 0 & WynikiCzujnikow[4]== 0 & WynikiCzujnikow[5]==0)
      {
         uchyb = -MAXwychylenie;
     ostatniUchyb = uchyb;
      }
      else
      {
        BLADczujnika(uchyb,ostatniUchyb);
      }
  }
}
else
{
  if(WynikiCzujnikow[1]== 1)
  {
    if(WynikiCzujnikow[2]==1)
    {
      if(WynikiCzujnikow[3]==1)
      {
        if(WynikiCzujnikow[4]==1)
        {
          if(WynikiCzujnikow[5] ==1)
          {
             uchyb = MAXwychylenie;
     ostatniUchyb = uchyb;
          }
          else
          {
            uchyb = 0;
     ostatniUchyb = uchyb;
          }
        }
        else
        {
          if(WynikiCzujnikow[5]==0)
          {
            uchyb = -MAXwychylenie+OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
          }
          else
          {
      BLADczujnika(uchyb,ostatniUchyb);
          }
        }
      }
      else
      {
        if(WynikiCzujnikow[4] == 0 & WynikiCzujnikow[5]==0)
        {
          uchyb = -MAXwychylenie+OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
        }
        else
        {
          BLADczujnika(uchyb,ostatniUchyb); 
        }
      }
    }
    else
    {
      if(WynikiCzujnikow[3] == 0 & WynikiCzujnikow[4] == 0 & WynikiCzujnikow[5]==0)
      {
        uchyb = -MAXwychylenie+OdlegloscMiedzyCzujnikami;
       ostatniUchyb = uchyb;
      }
    }
  }
  else
  {
    if(WynikiCzujnikow[2]==1)
    {
      if(WynikiCzujnikow[3]==1)
      {
        if(WynikiCzujnikow[4]==1)
        {
          if(WynikiCzujnikow[5]==1)
          {
            uchyb = MAXwychylenie;
     ostatniUchyb = uchyb;
          }
          else
          {
             uchyb = MAXwychylenie -OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
          }
        }
        else
        {
          if(WynikiCzujnikow[5]==0 )
          {
            uchyb = 0;
            ostatniUchyb = uchyb;
          }
          else
          {
             BLADczujnika(uchyb,ostatniUchyb); 
          }
        }
      }
      else
      {
        if(WynikiCzujnikow[4]==0 & WynikiCzujnikow[5]==0)
        {
          uchyb = -MAXwychylenie +2*OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
        }
        else
        {
          BLADczujnika(uchyb,ostatniUchyb);
        }
      }
    }
    else 
    {
      if(WynikiCzujnikow[3] ==1 )
      {
        if(WynikiCzujnikow[4] ==1)
        {
          if(WynikiCzujnikow[5]==1)
          {
             uchyb = MAXwychylenie;
     ostatniUchyb = uchyb;
          }
          else
          {
            uchyb =  MAXwychylenie -OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
          }
        }
        else
        {
          if(WynikiCzujnikow[5]==0)
          {
            uchyb = MAXwychylenie -2*OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb;
          }
          else
          {
            BLADczujnika(uchyb,ostatniUchyb);
          }
        }
      }
      else
      {
        if(WynikiCzujnikow[4]==1)
        {
          if(WynikiCzujnikow[5]==1)
          {
            uchyb = MAXwychylenie;
     ostatniUchyb = uchyb;
          }
          else
          {
            uchyb = MAXwychylenie-OdlegloscMiedzyCzujnikami;
     ostatniUchyb = uchyb ;
          }
        }
        else
        {
          if(WynikiCzujnikow[5]==1)
          {
            uchyb = MAXwychylenie;
     ostatniUchyb = uchyb ;
          }
          else
          {
            if(ostatniUchyb >0)
            {
                uchyb = 100/kp;
           }
            if(ostatniUchyb < 0)
           {
                uchyb = -100/kp;
          }
        }
        }
      }
    }
  }
}

 NadaniePWMsilnikom(uchyb,ostatniUchyb);

}
 
float BLADczujnika(float uchyb, float ostatniUchyb)
{
  uchyb = ostatniUchyb;
  return uchyb;
}


void NadaniePWMsilnikom(float uchyb, float ostatniUchyb) {
  
 float deltaU =  kp*uchyb +kd/10*(uchyb - ostatniUchyb);//1/(Tl+Ts)*(Tl*ostatniaDeltaU +(kp*Tl+kd)*(uchyb-ostatniUchyb)+kp*Ts*uchyb);
  //ostatniaDeltaU = deltaU;
 
  int Vprawy = 0;
  int Vlewy = 0;
   

  if(deltaU > 0)
  {
   Vprawy = silnikMax;
   Vlewy = (100 - deltaU) * silnikMax / 100;
 

  }
  else if(deltaU < 0)
  {
    Vlewy = silnikMax;
    Vprawy = (100 + deltaU) * silnikMax / 100;
   
  }
  else if(deltaU == 0)
  {
    //ogien pizda
    Vlewy = silnikMax;
    Vprawy = silnikMax;
  
  }
 

 analogWrite(silnikLewy, Vlewy);
 analogWrite(silnikPrawy, Vprawy);
   
 delay(10);
 
 Serial.print("   ");
Serial.print(deltaU);
Serial.print("            ");

 Serial.print(Vlewy);
 Serial.print(" ");
 Serial.println(Vprawy);
 

}