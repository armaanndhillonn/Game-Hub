#include <iostream>
#include <string>

using namespace std;

void displayIntroduction() {
    cout << "Welcome to the Text Adventure Game for Disabled Individuals!\n";
    cout << "You find yourself navigating through different scenarios. Make decisions wisely!\n\n";
}

void handleScenario(const string& scenarioDescription, const string& choice1, const string& choice2, const string& consequence1, const string& consequence2) {
    cout << scenarioDescription << endl;
    cout << "1. " << choice1 << endl;
    cout << "2. " << choice2 << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << consequence1 << endl;
    } else if (choice == 2) {
        cout << consequence2 << endl;
    } else {
        cout << "Invalid choice! Please choose 1 or 2.\n";
        handleScenario(scenarioDescription, choice1, choice2, consequence1, consequence2);
    }
}

int main() {
    displayIntroduction();

    // Scenario 1
    handleScenario(
        "Scenario 1: You encounter a steep staircase with no ramp. What would you like to do?",
        "Look for an elevator.",
        "Try to climb the stairs quickly to avoid drawing attention.",
        "Good choice! You find an elevator nearby and easily reach the next area.",
        "Unfortunately, attempting to climb the stairs quickly attracts attention, and you trip, leading to a fall. Consequence: You lose energy, time, and face potential injury. The correct solution is to look for an elevator."
    );

    // Scenario 2
    handleScenario(
        "Scenario 2: You come across a narrow pathway with uneven surfaces. What would you like to do?",
        "Take the narrow path carefully.",
        "Take a shortcut over the rough terrain to save time.",
        "Great decision! You navigate the narrow path safely and reach the next area.",
        "Taking a shortcut over the rough terrain results in a fall, causing injuries. Consequence: You face pain, potential injuries, and delays. The correct solution is to take the narrow path carefully."
    );

    // Scenario 3
    handleScenario(
        "Scenario 3: You reach a busy intersection with no accessible pedestrian crossing. What would you like to do?",
        "Wait for assistance from a passerby to help you cross.",
        "Try to cross the busy intersection independently.",
        "A kind passerby notices your situation and assists you in safely crossing the intersection.",
        "Attempting to cross the busy intersection independently puts you at risk of accidents. Consequence: You face potential harm and delays. The correct solution is to wait for assistance or find a nearby crosswalk with accessible features."
    );

    // Scenario 4
    handleScenario(
        "Scenario 4: You enter a building and encounter a narrow doorway. What would you like to do?",
        "Attempt to go through the narrow doorway carefully.",
        "Try to squeeze through the doorway quickly to avoid inconvenience.",
        "You successfully navigate through the narrow doorway and proceed inside the building.",
        "Trying to squeeze through the narrow doorway quickly results in getting stuck and feeling embarrassed. Consequence: You face discomfort, potential injury, and delays. The correct solution is to attempt to go through the narrow doorway carefully."
    );

    // Scenario 5
    handleScenario(
        "Scenario 5: You encounter a broken elevator, and the stairs are the only option. What would you like to do?",
        "Attempt to climb the stairs with caution.",
        "Look for assistance or an alternative route.",
        "Despite the broken elevator, you manage to climb the stairs carefully and reach your destination.",
        "Refusing to ask for assistance or find an alternative route leads to exhaustion and potential accidents while attempting to climb the stairs. Consequence: You face fatigue, potential injuries, and delays. The correct solution is to attempt to climb the stairs with caution or seek assistance and explore an alternative route."
    );

    cout << "\nCongratulations! You successfully navigated through the scenarios. Try purposely choosing wrong answers to learn what you shouldn't do in these situations :D\n";

    return 0;
}
