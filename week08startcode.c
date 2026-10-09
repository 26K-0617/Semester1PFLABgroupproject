#include <stdio.h>
int main (){
	int status, card_no, case_type, threat_type;
	printf("===========CYBER SHEILD===========\n");
	printf("Welcome to CYBERSHEILD! We are happy to assist you\n");
	printf("Enter 16-digit card number"); //CAN ADD EMAIL INPUT WITH STRINGS
	scanf("%d",&card_no);    //VALIDATION THAT 16 DIGITS put in loop but as a string with sizeof etc
		
	printf("Please enter status (1= Employee, 2= Client): ");
	scanf("%d", &status);
	
	switch(status){
		case 1: //employee 
		printf("Is the case type:(1=Our Company related , 2=Personal): ");
		scanf("%d",&case_type);
		break; //further specification remaining
		
		case 2: //client
		printf("Is the case type:(1=Our Company related , 2=Personal): ");
		scanf("%d",&case_type);
		printf("Please name the threat (1=Data Breach, 2=Fraud, 3=Credentials leak, 4=Malware): "); //using switch with numbers for now 
        scanf("%d",&threat_type);
              switch(threat_type){
              	case 1: //Data Breach
				    //Unidentified login of social media account. set low_severity=1;
				break;
              	case 2: //fraud
              	// Friendly fraud (when a consumer claims they didn't receive their online purchase or they didn't authorize the transaction)
              	//set low_severity=1;
				  break;
				case 3://credential leak
				//Forgot OR! Lost login credentials (2 different scene), incase of lost credentials, we have to change the passwords for the user but if they forgot it, we can opt for sending verification email.
				break;
				case 4:	//malware	
				//adware
				//set low_severity=1 
				//will understand more with filing to keep record of number of each severity case in history
				break;	  
				}
	    break;
		default: printf("Error! Enter valid status of employee or client.\n");	
		break;	 
	}
return 0;
}
