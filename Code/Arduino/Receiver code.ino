int i, good, k;
byte data_in;
char input_cmd;

void setup(){
	attachInterrupt(1,data_incoming,RISING);
	pinMode(3, INPUT);
	pinMode(7, OUTPUT);
	Serial.begin(115200);
}//setup

void loop(){
	if(input_cmd=='1')
		digitalWrite(7,HIGH);
	else
		digitalWrite(7,LOW);
}//loop

void data_incoming(){
	for(i=0; i<100; i++){
		delayMicroseconds(20);
		good=1;
		if(digitalRead(3)==LOW){
			good=0;
			i=100;
		}
	}//for
	if(good==1){
		detachInterrupt(1);
		while(1){
			if(digitalRead(3)==LOW){
				delayMicroseconds(750);
				for(i=0; i<8; i++){
					if(digitalRead(3)==HIGH)
						bitWrite(data_in, i, 1);
					else
						bitWrite(data_in, i, 0);
					delayMicroseconds(1000);
				}//for
			Serial.print(char(data_in));
			
			if(char(data_in)=='2')
				input_cmd='1';
			else if(char(data_in)=='3')
				input_cmd='0';
			
			break;//secondtwhile
			}//low kickoff
		}//second while
	}//good check
	
	attachInterrupt(1,data_incoming,RISING);
}//routine