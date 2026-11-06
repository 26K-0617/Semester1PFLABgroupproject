#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int n = 0; // Number of cases for this session
    int internalcase=0;
	 int externalcase=0;
    int low_sev=0 ;
	int med_sev=0 ;
	int crit_sev=0;
    int threat[5]={0}; //array for n per cyber case//
    

    printf("====================================================\n");
    printf("         SECURITY THREAT REPORTING SYSTEM            \n");
    printf("====================================================\n\n");

    printf("Number of cases to report for this session? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input or no cases to report. Exiting.\n");
        return 1;
    }
    clear_input_buffer(); // Clear leftover newline from scanf

    // Loop runs 'n' times for multiple case reporting
    for (int i = 0; i < n; i++) {
        int user_type = 0;     // 1 = Employee, 2 = Client
        int case_origin = 0;   // 1 = Company's internal tragedy, 2 = External case
        int threat_choice = 0; // 1 to 5 for threats
        int impact_scale = 0;  // Scale of impact: 1 = Single user, 2 = Handful, 3 = Company-wide

        char user_id[100];
        char description[500];

        printf("\n--- Reporting Case %d of %d ---\n", i + 1, n);

        // --- STEP 1: Identification ---
    do {
   printf("Are you an employee or a client?\n");
   
        printf("1. Employee\n");
        printf("2. Client\n");
        printf("Select option (1 or 2): ");
        scanf("%d", &user_type);
        clear_input_buffer();
        
        if (user_type < 1 || user_type > 2) {
        printf("\nError! Invalid choice. Please pick  1 or 2.\n");
        }
     } while (user_type < 1 || user_type > 2);

        printf("Enter User Identification (Email or 16-digit Credit Card Number): ");
        fgets(user_id, sizeof(user_id), stdin);
        user_id[strcspn(user_id, "\n")] = 0; // Strip trailing newline

        // --- STEP 2: Scope/Origin ---
     do{    
printf("\nIs this case related to:\n");
        printf("1. Our own Company's tragedy/incident\n");
        printf("2. An external case\n");
        printf("Select option (1 or 2): ");
        scanf("%d", &case_origin);
        clear_input_buffer();
        if(case_origin < 1 || case_origin > 2) {
        printf("\nError! Invalid choice. Please pick 1 or 2\n");
}
}while(case_origin < 1 || case_origin > 2);
       

        // --- STEP 3: Select Threat Type ---
     do {
       printf("\nSelect the type of security threat:\n"); 
       printf("1. Data Breach\n");
       printf("2. Fraud\n");
       printf("3. Credentials Leak\n");
       printf("4. Malware\n");
       printf("5. Ransom Threat\n");
       printf("Enter choice (1-5): ");
       scanf("%d", &threat_choice);
       clear_input_buffer();
       if (threat_choice < 1 || threat_choice > 5) {
        printf("\nError! Invalid choice. Please pick a number between 1 and 5.\n");
        }
     } while (threat_choice < 1 || threat_choice > 5);



        // --- STEP 4: Description ---
        printf("\nPlease provide a brief description of the incident:\n> ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = 0;

        // --- STEP 5: Scale of Impact ---
     do{
   printf("\nWhat is the scale of impact for this threat?\n");
        printf("1. Single user affected\n");
        printf("2. Handful of users affected\n");
        printf("3. Entire company / System-wide affected\n");
        printf("Select scale (1-3): ");
        scanf("%d", &impact_scale);
        clear_input_buffer();
        if (impact_scale < 1 || impact_scale > 3) {
        printf("\nError! Invalid choice. Please pick a number between 1 and 5.\n");
        }
     } while (impact_scale < 1 || impact_scale > 3);

        // --- STEP 6: Threat Processing & Severity Evaluation ---
        printf("\n=============================================================================================\n");
        printf("                 INCIDENT REPORT                    \n");
        printf("===============================================================================================\n");
        printf("Reporter Type : %s\n", (user_type == 1) ? "Employee" : "Client");
        printf("Identifier    : %s\n", user_id);
        printf("Scope         : %s\n", (case_origin == 1) ? "Company Internal Tragedy" : "External Case");
        printf("Description   : %s\n", description);
        printf("------------------------------------------------------------------------------------------------\n");

        switch (threat_choice) {
            case 1: // Data Breach
                printf("Threat Category: Data Breach\n");
                
                if (impact_scale == 1) {
                	
                	low_sev++;
                    printf("Severity Depth : LOW\n");
                    printf("Action Required: Logged as an unidentified login / routine social media alert.\n");
                    
                } else if (impact_scale == 2) {
                	
                	med_sev++;
                    printf("Severity Depth : MEDIUM\n");
                    printf("Action Required: Investigate regional breach vectors and isolate affected accounts.\n");
                    
                } else {
                	
                	crit_sev++;
                    printf("Severity Depth : HIGH / CRITICAL\n");
                    printf("Action Required: Initiate full company data breach containment and security protocols.\n");
                }
                threat[0]++;
                break;

            case 2: // Fraud
                printf("Threat Category: Fraud\n");
                if (impact_scale == 1) {
                	
                	low_sev++;
                    printf("Severity Depth : LOW (Friendly Fraud)\n");
                    printf("Action Required: Handle standard customer chargeback/dispute verification.\n");
                    
                } else if (impact_scale == 2) {
                	
                	med_sev++;
                    printf("Severity Depth : MEDIUM\n");
                    printf("Action Required: Flag merchant IDs and audit transaction logs for patterns.\n");
                } else {
                	
                	crit_sev++;
                    printf("Severity Depth : HIGH\n");
                    printf("Action Required: Freeze payment gateway services and start systematic audit.\n");
                }
                threat[1]++;
                break;

            case 3: { // Credentials Leak
                int cred_type = 0;
                printf("Threat Category: Credentials Leak\n");
                printf("\nSpecify Credentials Situation:\n");
                printf("1. Forgot password\n");
                printf("2. Lost login credentials\n");
                printf("Select (1 or 2): ");
                scanf("%d", &cred_type);
                clear_input_buffer();
                threat[2]++;

                if (cred_type == 1) {
                    printf("Severity Depth : LOW\n");
                    printf("Action Required: Send automated verification email for password reset.\n");
                    
                } else if (cred_type == 2) {
                	
                    if (impact_scale == 1) {
                    	low_sev++;
                        printf("Severity Depth : LOW / MODERATE\n");
                        printf("Action Required: Force-change password and invalidate active user sessions.\n");
                        
                    } else {
                    	crit_sev++;
                        printf("Severity Depth : HIGH\n");
                        printf("Action Required: Mass password reset and deploy 2FA enforcement.\n");
                    }
                } else {
                    printf("Invalid selection recorded.\n");
                }
                threat[2]++;
                break;
            }

            case 4: // Malware
                printf("Threat Category: Malware\n");
                
                if (impact_scale == 1) {
                	
                	low_sev++;
                    printf("Severity Depth : LOW (Adware / Unauthorized Redirection)\n");
                    printf("Action Required: Run endpoint browser scan and clear malicious extensions/cookies.\n");
                    
                } else if (impact_scale == 2) {
                	
                	med_sev++;
                    printf("Severity Depth : MEDIUM\n");
                    printf("Action Required: Quarantining endpoints and updating local antivirus rules.\n");
                    
                } else {
                	
                	crit_sev++;
                    printf("Severity Depth : HIGH\n");
                    printf("Action Required: Network isolation and full system malware removal.\n");
                    
                    
                }
                threat[3]++;
                break;

            case 5: // Ransom Threat
                printf("Threat Category: Ransom Threat\n");
                
                if (impact_scale == 1) {
                	med_sev++;
                    printf("Severity Depth : MODERATE\n");
                    printf("Action Required: Isolate host device, inspect ransom note, and check backups.\n");
                } 
				else {
                	crit_sev++;
                    printf("Severity Depth : CRITICAL\n");
                    printf("Action Required: Immediate network air-gapping, notify IR team, and preserve log files.\n");
                }
                
                threat[4]++;
                break;

            default:
                printf("Invalid threat choice selected.\n");
                break;
        }

        printf("===============================================================================================\n");
    }

    printf("====================================================================================================\n");
    printf("+++++++++++++++++++++++++++++++++++++CASES DASHBOOARD+++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("====================================================================================================\n");
    
    printf("CASES REPORTED PER SEVERITY \t\n");
    
    printf("Low Severity         :                 %d   \n",low_sev);
    printf("Medium Severity      :                 %d   \n",med_sev);
    printf("Critical Severity    :                 %d   \n\n",crit_sev); 
    
    printf("---------------------------------------- \n");  //1 DB 2 F 3CL 4Mal 5Ran
    printf("1. BATA BREACH       :                 %d\n",threat[0]);
    printf("2. FRAUD             :                 %d\n",threat[1]);
    printf("3. CREDENTIALS LEAK  :                 %d\n",threat[2]);
    printf("4. MALWARE           :                 %d\n",threat[3]);
    printf("5. RANSOM            :                 %d\n\n",threat[4]);
    
    printf("--------------------------------------- \n");
    
    
    
}

//Persistent incident Logging (File I/O) for maintaining audit trail
//Automatic Timestamping
//Session Summary & Analytics Dashboard
//Input Validation & Masking , formatting credit hour input, and starring the digits out

