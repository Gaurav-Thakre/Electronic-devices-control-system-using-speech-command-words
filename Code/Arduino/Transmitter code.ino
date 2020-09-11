int dataPin=2;
int ledPin=7;
int matlabData;
void setup()
{
	pinMode(dataPin,OUTPUT);
	pinMode(ledPin,OUTPUT);
	Serial.begin(115200);
}
void loop()
{
	if(Serial.available()>0) // if there is data to read
	{
		matlabData=Serial.read(); // read data
		if(matlabData==1)	
		{
			rf_send('2');
		} // turn light on
		else if(matlabData==2)
		{
			rf_send('3');
		}
	}
}

void rf_send(byte input){
	int i;
	for(i=0; i<20; i++){
		digitalWrite(2, HIGH);
		delayMicroseconds(500);
		digitalWrite(2, LOW);
		delayMicroseconds(500);
	}
	
	digitalWrite(2, HIGH);
	delayMicroseconds(3000);
	digitalWrite(2, LOW);
	delayMicroseconds(500);
	
	for(i=0; i<8; i++){
		if(bitRead(input,i)==1)
			digitalWrite(2, HIGH);
		else
			digitalWrite(2, LOW);
		delayMicroseconds(500);
		if(bitRead(input,i)==1)
			digitalWrite(2, LOW);
		else
			digitalWrite(2, HIGH);
		delayMicroseconds(500);
	}
}