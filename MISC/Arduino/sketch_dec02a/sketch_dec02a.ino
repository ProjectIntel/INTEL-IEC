#include <SD.h>

File myFile;
String dist="";
String ang="";
char character;
int i=0;
int x,y;
void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  
 
  // re-open the file for reading:
  myFile = SD.open("test1.txt");
  if (myFile) 
  {
    //Serial.println("test1.txt:");
   
    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
       character=myFile.read();
       if(character==' ' || i==1)
       {
        if(character==' ')
        {  
            character=myFile.read(); 
            ang=ang + character;
            i=1;
        }else ang=ang+character;
       }
       else dist=dist + character;
     
    }
    float rad=(3.14/180)*ang.toInt();
    int x=dist.toInt() * (cos(rad));
    int y=dist.toInt() * (sin(rad));
    Serial.println(x);
    Serial.print(y);
    // close the file:
    myFile.close();
  } 
}

void loop()
{
    // nothing happens after setup
}

