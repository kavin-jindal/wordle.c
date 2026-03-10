#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // specifically for the islower() function
void exit(int status);

int main(){

	// beginning
	
    printf("\e[1;37m╔══════════════════════════════════╗\n");
    printf("║                                  ║\n");
    printf("║            Wordle.c              ║\n");
    printf("║                                  ║\n");
    printf("║    Developer: Kavin Jindal       ║\n");
    printf("║  https://github.com/kavin-jindal ║\n");
    printf("║                                  ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("\n\t\e[1;32m[^_^] Type a valid 5-letter word below to start playing.");
    printf("\n\t\e[1;32m[^_^] You get 6 attempts to guess the correct word.");
    printf("\n\t\e[1;32m[^_^] Make sure to have your caps-lock on because only uppercase letters are accepted.");
    printf("\n\t\e[1;32m[^_^] Have a good time playing :).");



	FILE *words;
	words = fopen("words.txt", "r");	
	
	char user[10];
	 // wc -l filename.txt to count lines in the wordlist
	char dashes[7]="_____";

	int MAX_WORDS = 14855;
	int WORD_LENGTH = 6;
	int word_count = 0;
	char lines[MAX_WORDS][WORD_LENGTH];
	char line[WORD_LENGTH];
// =================================== code to fetch all words from words.txt and add them to an array
	while (fgets(line, sizeof(line), words) && word_count < MAX_WORDS){
		line[strcspn(line, "\n")] = '\0';
		if (strlen(line)==5){
			// line is the temporary buffer with a single word which is sent to the lines list.
			strncpy(lines[word_count], line, WORD_LENGTH);
			word_count++;
		}

	}
	fclose(words);
// =====================================	
	
	// code to randomly choose a word
	srand(time(NULL));
	char *word = (lines[rand() % word_count]);	
	int count = 1;

// =============== code to get the user input via fgets and check for validity
	/*
	The following conditions are checked for: 
	1. If no lowercase characters are used.
	2. If the length of the input is 5
	3. If the input is a valid word (checked from the wordlist)

	*/
	while (count != 7){
		printf("\n\n\e[0;37mAttempt %d:>> ", count);
		fgets(user, sizeof(user), stdin);
		printf("\n");
		user[strcspn(user, "\n")] = '\0'; 
		int l = 0;
		while (user[l] != '\0'){
			if (islower(user[l])){
				printf("\n\t\e[0;31m[-_-] Lowercase characters are not allowed!\n");
				l++;
				break;
			}
			else {
				l++;
				continue;
			}
		}
		int x = strlen(user);
		if (x != 5){
			printf("\n\t\e[0;31m[-_-] The word should have five letters!\n");
			
		}
		
		else {			
			bool valid = false; // the following few lines check for validity of the word from the wordlist
			for (int y = 0; y < word_count; y++){
				if (strcmp(user, lines[y])==0){
					valid = true;
					break;

				}
				
			}
			if (!valid){
				printf("\n\t\e[0;31m[-_-] The word does not exist, try again.");

			}
// ===================

			 else { // code for working with valid input begins
				
				printf("\n\t");
				count++;
					for (int i = 0; i<7; i++){
						char *check;
						check = strchr(word, user[i]);	// strchr finds the first occurrence of user[i] in word
						// PS ANSI color codes have been used to colorize the output
						if (user[i] == word[i] )
						{
							printf("\e[;032m%c", user[i]); // exact index match
							dashes[i] = user[i]; 

						}
						else if (check != NULL){
							printf("\e[0;33m%c", user[i]); // letter exists but different index
						}
						else {
						printf("\e[38;5;248m%c", user[i]); // letter does not exist
						}
					
					}
					printf("\n\t\e[;032m%s", dashes); // for loop ends
				
			}
			if (strcmp(user, word)==0){ // strcmp is to compare
					printf("\n\n\t\e[;032m[^_^] You guessed it correct! The word is: %s", word);
					exit(0);
				}	
			if (count==7){ // if user is unable to guess the right word, the correct one prints on its own in the end
					printf("\n\n\e[0;33m[-_-] The word is %s", word);
				}
		

		} // else loop
		

			
}

}
