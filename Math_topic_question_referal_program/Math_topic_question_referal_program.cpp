#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

enum Topic {
    Statistics, Constructions, Algebra, Sets, Mensuration, Numbers, Similarity, Graphs,
    Trigonometry, Probability, Variation, Circles, Surds, Sequences, Calculus, Bounds,
    Coordinate_Geometry, Vectors, Functions, Geometry, Indices, Transformation_of_Functions
};

struct Question {
    string year;
    string session;
    string variant;
    string question;
    string marks;
    Topic topic;
};

vector<Question> database;

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

        // Convert string topic to the Topic enum
        Topic topic = Statistics; // Default to Statistics if conversion fails
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
        else if (topic_str == "calculas") topic = Calculus;
        else if (topic_str == "bounds") topic = Bounds;
        else if (topic_str == "coordinate geometry") topic = Coordinate_Geometry;
        else if (topic_str == "vectors") topic = Vectors;
        else if (topic_str == "functions") topic = Functions;
        else if (topic_str == "geometry") topic = Geometry;
        else if (topic_str == "indices") topic = Indices;
        else if (topic_str == "transformation of functions") topic = Transformation_of_Functions;

        Question q = { year, session, variant, question, marks, topic };
        database.push_back(q);
    }
}

void PrintTopics() {
    cout << "Available Topics:" << endl;
    cout << "1. Statistics" << endl;
    cout << "2. Constructions" << endl;
    cout << "3. Algebra" << endl;
    cout << "4. Sets" << endl;
    cout << "5. Mensuration" << endl;
    cout << "6. Numbers" << endl;
    cout << "7. Similarity" << endl;
    cout << "8. Graphs" << endl;
    cout << "9. Trigonometry" << endl;
    cout << "10. Probability" << endl;
    cout << "11. Variation" << endl;
    cout << "12. Circles" << endl;
    cout << "13. Surds" << endl;
    cout << "14. Sequences" << endl;
    cout << "15. Calculus" << endl;
    cout << "16. Bounds" << endl;
    cout << "17. Coordinate Geometry" << endl;
    cout << "18. Vectors" << endl;
    cout << "19. Functions" << endl;
    cout << "20. Geometry" << endl;
    cout << "21. Indices" << endl;
    cout << "22. Transformation of Functions" << endl;
}

Topic GetTopicFromUser() {
    int choice;
    cin >> choice;
    return static_cast<Topic>(choice - 1);
}

void DisplayQuestionsByTopic(Topic topic) {
    cout << "Questions on this topic: " << endl;
    for (const auto& q : database) {
        if (q.topic == topic) {
            cout << "Year: " << q.year << ", Session: " << q.session
                << ", Variant: " << q.variant << ", Question: " << q.question
                << ", Marks: " << q.marks << endl;
        }
    }
}

void SearchQuestions() {
    cout << "Enter a topic number: ";
    PrintTopics();

    Topic userTopic = GetTopicFromUser();
    DisplayQuestionsByTopic(userTopic);
}

int main() {
    LoadDatabase();

    while (true) {
        cout << "Welcome to the Math Topic Question Referral Program!" << endl;
        cout << "1. Search questions by topic" << endl;
        cout << "2. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            SearchQuestions();
        }
        else {
            break;
        }
    }

    return 0;
}
