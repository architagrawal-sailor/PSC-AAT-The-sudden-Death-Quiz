#include <stdio.h>

/* * Function: ask_question
 * ----------------------
 * Displays a question and four options, accepts user input,
 * and checks if the answer is correct.
 * * returns: 1 if the answer is correct, 0 if incorrect.
 */
int ask_question(char *question, char *opt1, char *opt2, char *opt3, char *opt4, int correct_opt) {
    int choice;

    // Print the question and options
    printf("\n%s\n", question);
    printf("1. %s\n", opt1);
    printf("2. %s\n", opt2);
    printf("3. %s\n", opt3);
    printf("4. %s\n", opt4);

    printf("Enter Option (1-4): ");
    scanf("%d", &choice);

    // Check answer
    if (choice == correct_opt) {
        printf(">> You are CORRECT!\n");
        return 1;
    } else {
        printf(">> You are INCORRECT!\n");
        return 0;
    }
}

int main() {
    int topic;
    int level1_score = 0;
    int level2_score = 0;

    // --- GAME START ---
    printf("================================\n");
    printf("      WELCOME TO THE QUIZ       \n");
    printf("================================\n");
    printf("\n--- LEVEL 1 ---\n");
    printf("Please Select A Topic:\n");
    printf("1. C Programming\n2. Mythology\n3. Sports\n4. Indian History\n");
    printf("Enter the Topic (1-4): ");
    scanf("%d", &topic);

    // --- LEVEL 1 LOGIC ---
    switch (topic) {
        case 1:
            printf("\n[ Selected: C Programming ]\n");
            level1_score += ask_question("1) Who is the father of C language?", "Steve Jobs", "James Gosling", "Dennis Ritchie", "Rasmus Lerdorf", 3);
            level1_score += ask_question("2) Which is NOT a valid C variable name?", "int number", "float rate", "int variable_count", "int $main", 4);
            level1_score += ask_question("3) All keywords in C are in?", "LowerCase", "UpperCase", "CamelCase", "None", 1);
            level1_score += ask_question("4) Which is a valid C expression?", "int my_num = 100,000", "int my_num = 100000", "int my num = 1000", "int $my_num = 10000", 2);
            level1_score += ask_question("5) Purpose of #include <stdio.h>?", "Standard input/output", "User functions", "Global variables", "Comments", 1);
            break;

        case 2:
            printf("\n[ Selected: Mythology ]\n");
            level1_score += ask_question("1) Vehicle of Lord Vishnu?", "Peacock", "Garuda", "Swan", "Owl", 2);
            level1_score += ask_question("2) Rama's battle was against?", "Ravana", "Duryodhana", "Hiranyakashipu", "Mahishasura", 1);
            level1_score += ask_question("3) Weapon of Lord Vishnu?", "Trishula", "Sudarshana Chakra", "Vajra", "Parashu", 2);
            level1_score += ask_question("4) Author of Mahabharatha?", "Valmiki", "Bharadwaja", "Vishwamitra", "Ved Vyasa", 4);
            level1_score += ask_question("5) Battle of Mahabharat location?", "Kurukshetra", "Panipat", "Ambala", "Varanasi", 1);
            break;

        case 3:
            printf("\n[ Selected: Sports ]\n");
            level1_score += ask_question("1) Who is the god of cricket?", "Virat Kohli", "Sachin Tendulkar", "Jacques Kallis", "Ricky Ponting", 2);
            level1_score += ask_question("2) Players in a football team?", "7", "9", "11", "13", 3);
            level1_score += ask_question("3) Olympic rings represent?", "Continents", "Sports", "Countries", "Values", 1);
            level1_score += ask_question("4) NOT an Olympic sport?", "Basketball", "Polo", "Gymnastics", "Swimming", 2);
            level1_score += ask_question("5) Most FIFA World Cups?", "Germany", "Brazil", "Argentina", "Italy", 2);
            break;

        case 4:
            printf("\n[ Selected: Indian History ]\n");
            level1_score += ask_question("1) Civilization in Indus Valley?", "Harappan", "Vedic", "Maurya", "Gupta", 1);
            level1_score += ask_question("2) Founder of Nanda dynasty?", "Chandragupta", "Ashoka", "Mahapadmananda", "Kanishka", 3);
            level1_score += ask_question("3) First to start 1857 revolt?", "Mangal Pandey", "Rani Lakshmibai", "Mahatma Gandhi", "Birsa Munda", 1);
            level1_score += ask_question("4) Capital of Maratha Empire?", "Pune", "Raigad", "Satara", "Kolhapur", 2);
            level1_score += ask_question("5) Battle of Haldighati year?", "1578", "1598", "1576", "1520", 3);
            break;

        default:
            printf("Invalid Topic Selected. Exiting game.\n");
            return 1;
    }

    printf("\n--------------------------------\n");
    printf("Your Level 1 Score: %d out of 5\n", level1_score);
    printf("--------------------------------\n");

    // --- CHECK FOR LEVEL 2 ELIGIBILITY ---
    // User needs at least 3 points to proceed
    if (level1_score >= 3) {
        printf("\n\n=== CONGRATULATIONS! LEVEL 2 UNLOCKED ===\n");
        printf("(Sudden Death Mode: One wrong answer and the game ends!)\n");

        // We use 'goto result' here to immediately end the game if a question is missed.
        // This is a "Sudden Death" mechanic.

        if (ask_question("1) Who forgot his powers due to a curse?", "Shiva", "Rama", "Hanuman", "Parshuram", 3)) level2_score++;
        else goto result;

        if (ask_question("2) Goddess who rides a lion?", "Ganesh", "Durga", "Hanuman", "Rama", 2)) level2_score++;
        else goto result;

        if (ask_question("3) Who gave fire to humans?", "Orpheus", "Ares", "Poseidon", "Prometheus", 4)) level2_score++;
        else goto result;

        if (ask_question("4) King of Greek gods?", "Hades", "Zeus", "Apollo", "Poseidon", 2)) level2_score++;
        else goto result;

        if (ask_question("5) Sport with 'birdie' and 'eagle'?", "Tennis", "Golf", "Bowling", "Cricket", 2)) level2_score++;
        else goto result;

        if (ask_question("6) Wimbledon host?", "England", "Australia", "USA", "France", 1)) level2_score++;
        else goto result;

        if (ask_question("7) Most Olympic gold medals?", "Usain Bolt", "Larisa Latynina", "Carl Lewis", "Michael Phelps", 4)) level2_score++;
        else goto result;

        if (ask_question("8) Length of football match?", "60 min", "45 min", "90 min", "120 min", 3)) level2_score++;
        else goto result;

        if (ask_question("9) National sport of Japan?", "Karate", "Sumo", "Judo", "Baseball", 2)) level2_score++;
        else goto result;

        if (ask_question("10) First Maurya Emperor?", "Ashoka", "Chandragupta", "Bindusara", "Chanakya", 2)) level2_score++;
        else goto result;

        if (ask_question("11) First Mughal Emperor?", "Akbar", "Humayun", "Babur", "Aurangzeb", 3)) level2_score++;
        else goto result;

        if (ask_question("12) Who built Ashoka Pillars?", "Ashoka", "Chandragupta", "Samudragupta", "Pratap", 1)) level2_score++;
        else goto result;

        if (ask_question("13) First PM of India?", "Mountbatten", "Patel", "Prasad", "Nehru", 4)) level2_score++;
        else goto result;

        if (ask_question("14) Last Viceroy of India?", "Mountbatten", "Wavell", "Canning", "Rajagopalachari", 1)) level2_score++;
        else goto result;

        if (ask_question("15) C language developed in?", "1977", "1972", "1971", "1973", 2)) level2_score++;
        else goto result;

        if (ask_question("16) Company where C was made?", "Bell Labs", "Microsoft", "Stanford", "IBM", 1)) level2_score++;
        else goto result;

        if (ask_question("17) C file extension?", ".dft", ".c++", ".c", ".o", 3)) level2_score++;
        else goto result;

        if (ask_question("18) What does 'C' stand for?", "Compiler", "Central", "Computer", "Nothing (Successor to B)", 4)) level2_score++;
        else goto result;

        if (ask_question("19) First function in C?", "printf", "main()", "pow", "sqrt", 2)) level2_score++;
        else goto result;

        if (ask_question("20) Symbol to end statements?", "_", ";", "%", ",", 2)) {
            level2_score++;
            printf("\n**************************************************\n");
            printf(" AMAZING! You answered ALL questions correctly! \n");
            printf("**************************************************\n");
        }

    } else {
        printf("You need 3 or more points to unlock Level 2. Better luck next time!\n");
    }

// The 'result' label acts as the exit point for the Sudden Death mode
result:
    if (level1_score >= 3) {
        printf("\n================ RESULT ================\n");
        printf("Level 2 Score: %d\n", level2_score);
        printf("GRAND TOTAL:   %d / 25\n", level1_score + level2_score);
        printf("========================================\n");
    }

    return 0;
}
