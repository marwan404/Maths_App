#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Enum for Topics
enum Topic {
    Statistics, Constructions, Algebra, Sets, Mensuration, Numbers, Similarity, Graphs,
    Trigonometry, Probability, Variation, Circles, Surds, Sequences, Calculus, Bounds,
    Coordinate_Geometry, Vectors, Functions, Geometry, Indices, Transformation_of_Functions
};

// Question structure
struct Question {
    string year;
    string session;
    string variant;
    string question;
    string marks;
    Topic topic;
};

// Vector to hold the questions database
vector<Question> database;

// Function to load data from the CSV file into the database
void LoadDatabase() {
    ifstream file("database.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string year, session, variant, question, marks, topic_str;

        getline(ss, year, ',');
        getline(ss, session, ',');
        getline(ss, variant, ',');
        getline(ss, question, ',');
        getline(ss, marks, ',');
        getline(ss, topic_str, ',');

        Topic topic = Statistics; // Default topic
        // Convert string topic to the Topic enum
        if (topic_str == "statistics") topic = Statistics;
        else if (topic_str == "constructions") topic = Constructions;
        else if (topic_str == "algebra") topic = Algebra;
        else if (topic_str == "sets") topic = Sets;
        else if (topic_str == "mensuration") topic = Mensuration;
        else if (topic_str == "numbers") topic = Numbers;
        else if (topic_str == "similarity") topic = Similarity;
        else if (topic_str == "graphs") topic = Graphs;
        else if (topic_str == "trigonometry") topic = Trigonometry;
        else if (topic_str == "probability") topic = Probability;
        else if (topic_str == "variation") topic = Variation;
        else if (topic_str == "circles") topic = Circles;
        else if (topic_str == "surds") topic = Surds;
        else if (topic_str == "sequences") topic = Sequences;
        else if (topic_str == "calculus") topic = Calculus;
        else if (topic_str == "bounds") topic = Bounds;
        else if (topic_str == "coordinate geometry") topic = Coordinate_Geometry;
        else if (topic_str == "vectors") topic = Vectors;
        else if (topic_str == "functions") topic = Functions;
        else if (topic_str == "geometry") topic = Geometry;
        else if (topic_str == "indices") topic = Indices;
        else if (topic_str == "transformation of functions") topic = Transformation_of_Functions;

        // Store question in the database
        database.push_back({ year, session, variant, question, marks, topic });
    }
}

// Function to print the available topics
void PrintTopics() {
    cout << "Available Topics:" << endl;
    cout << "1. Statistics\n2. Constructions\n3. Algebra\n4. Sets\n5. Mensuration\n6. Numbers\n"
        << "7. Similarity\n8. Graphs\n9. Trigonometry\n10. Probability\n11. Variation\n12. Circles\n"
        << "13. Surds\n14. Sequences\n15. Calculus\n16. Bounds\n17. Coordinate Geometry\n18. Vectors\n"
        << "19. Functions\n20. Geometry\n21. Indices\n22. Transformation of Functions" << endl;
}

// Function to get the topic choice from the user
Topic GetTopicFromUser() {
    int choice;
    cout << "Enter a topic number: ";
    cin >> choice;
    return static_cast<Topic>(choice - 1);
}

// Function to display questions related to a specific topic
void DisplayQuestionsByTopic(Topic topic) {
    bool found = false;
    cout << "Questions for the selected topic:" << endl;
    for (const auto& q : database) {
        if (q.topic == topic) {
            cout << "Year: " << q.year << ", Session: " << q.session
                << ", Variant: " << q.variant << ", Marks: " << q.marks
                << ", Question: " << q.question << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No questions found for this topic." << endl;
    }
}

// Function to search questions based on user input
void SearchQuestions() {
    PrintTopics(); // Display the available topics
    Topic userTopic = GetTopicFromUser(); // Get topic choice from the user
    DisplayQuestionsByTopic(userTopic); // Display questions for the selected topic
}

// Main function
int main() {
    // Load questions from the CSV file
    LoadDatabase();

    while (true) {
        // Display main menu
        cout << "\nWelcome to the math topic finder!" << endl;
        cout << "1. Search questions by topic" << endl;
        cout << "2. Exit" << endl;
        int choice;
        cin >> choice;

        // Handle user input
        if (choice == 1) {
            SearchQuestions(); // If option 1 is selected, search for questions
        }
        else if (choice == 2) {
            cout << "Exiting program..." << endl;
            break; // Exit the program
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
