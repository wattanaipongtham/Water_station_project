/*
		###### SIM800 COMMAND ######
		============================
*/
char AT_CMD[4]		= "AT\r\n";
char AT_CSQ[8]		= "AT+CSQ\r\n";
char AT_CREG[10]		= "AT+CREG?\r\n";
char AT_CIPSHUT[12]	= "AT+CIPSHUT\r\n";
char AT_CFUN[11]	= "AT+CFUN=1\r\n";
char AT_CGATT[12]	= "AT+CGATT=1\r\n";
char AT_CPIN[10]	= "AT+CPIN?\r\n";
char AT_CSTTT[10]	= "AT+CSTT?\r\n";
char AT_CSTT[34]	= "AT+CSTT=\"internet\",\"true\",\"true\"\r\n";
char AT_CIICR[10]	= "AT+CIICR\r\n";
char AT_CIFSR[10]	= "AT+CIFSR\r\n";
char AT_CIPSTART[43]	= "AT+CIPSTART=\"TCP\",\"159.223.49.133\",\"1883\"\r\n";
char AT_CIPSEND[15]	= "AT+CIPSEND=67\r\n";
char DATA[68] = {0x10, 0x11, 0x00, 0x04, 0x4D, 0x51, 0x54, 0x54, 0x04, 0x02, 0x00, 0x3C, 0x00, 0x05, 0x50, 0x51, 0x52, 0x53, 0x54, 0x30, 0x2e, 0x00, 0x09, 0x57, 0x41, 0x54, 0x54, 0x41, 0x4e, 0x41, 0x49, 0x49, 0x7b, 0x22, 0x64, 0x22, 0x3a, 0x39, 0x39, 0x39, 0x39, 0x2c, 0x22, 0x45, 0x43, 0x22, 0x3a, 0x39, 0x39, 0x39, 0x39, 0x39, 0x2e, 0x39, 0x39, 0x2c, 0x22, 0x44, 0x4f, 0x22, 0x3a, 0x39, 0x39, 0x2e, 0x39, 0x39, 0x7d, 0x0A};
/*
		###### RESPONSE BUFFER ######
		=============================
*/
char RES_CMD[50];
char RES_CREG[50];
char RES_CIPSHUT[50];
char RES_CFUN[50];
char RES_CGATT[50];
char RES_CPIN[50];
char RES_CSTT[50];
char RES_CIICR[50];
char RES_CIFSR[50];
char RES_CIPSTART[150];
char RES_CIPSTART2[50];
char RES_CIPSEND[50];
char RES_SERVER[200];
char RES_MX7383[50];
