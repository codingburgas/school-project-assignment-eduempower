#include "physicsTest1.h"
#include "physicsMenu.h"
#include "Question.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <random>
#include "raylib.h"

// Function to display a question along with its possible answers vertically
void displayQuestion(const Question& question, int x, int y, int fontSize) {
    DrawText(question.question.c_str(), x, y, fontSize, WHITE);
    y += 50; // Increase vertical position for answers
    for (size_t i = 0; i < question.answers.size(); ++i) {
        DrawText(question.answers[i].c_str(), x + 50, y + i * 50, fontSize, WHITE); // Moved text to the right by 50 pixels
    }
}

// Function to display radio buttons for selecting answers
void displayRadioButtons(int x, int y, int selectedAnswer, int questionNumber, int fontSize, bool clickable, int* selectedAnswers) {
    y += 50; // Increase vertical position for radio buttons
    for (size_t i = 0; i < 3; ++i) {
        // Draw radio button
        Rectangle radioBtnRect = { x, y + i * 50, 20, 20 };
        DrawRectangleLinesEx(radioBtnRect, 2, WHITE);

        // Check if the radio button is clickable and if the mouse is over it
        if (clickable && CheckCollisionPointRec(GetMousePosition(), radioBtnRect)) {
            DrawRectangle(radioBtnRect.x, radioBtnRect.y, radioBtnRect.width, radioBtnRect.height, Fade(LIGHTGRAY, 0.5f)); // Highlight when hovered
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                selectedAnswers[questionNumber] = i; // Set the selected answer for the current question
            }
        }

        // If current option is selected, draw a checkmark
        if (i == selectedAnswers[questionNumber]) {
            DrawText("X", x + 5, y + i * 50 + 5, fontSize, WHITE);
        }

        // Display answer options using snprintf
        char answerOption[32]; // Allocate a buffer for the formatted answer option
        snprintf(answerOption, sizeof(answerOption), "%d. ", static_cast<int>(i) + 1);
        DrawText(answerOption, x + 30, y + i * 50, fontSize, WHITE);
    }
}

void physicsTest1() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "EduEmpower");
    SetTargetFPS(30);

    Texture2D background = LoadTexture("../resources/test1_physics.png");
    Texture2D physicsButtonImg = LoadTexture("../resources/Physics_yellow.png");
    Texture2D hover_physicsButtonImg = LoadTexture("../resources/Physics_white.png");

    std::vector<Question> allQuestions;

    // Adding more questions
    Question q1;
    q1.question = "The work done by a friction force is:";
    q1.answers = { "always positive", "either positive or negative depending upon the situation", "always negative" };
    q1.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q1);

    Question q2;
    q2.question = "As defined in physics, work is:";
    q2.answers = { "a scalar quantity", "a vector quantity", "always a positive quantity" };
    q2.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q2);

    Question q3;
    q3.question = "Two forces have magnitudes of 11 newtons and 5 newtons. The magnitude of their sum could NOT be equal to which of the following values?";
    q3.answers = { "9 newtons", "5 newtons", "16 newtons" };
    q3.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q3);

    Question q4;
    q4.question = "If the resultant force acting on a body of constant mass is zero, the body's momentum is:";
    q4.answers = { "decreasing", "increasing", "constant" };
    q4.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q4);

    Question q5;
    q5.question = "Which of the following scientists is responsible for the exclusion principle which states that two objects may NOT occupy the same space at the same time?";
    q5.answers = { "Pauli", "Heisenberg", "Teller" };
    q5.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q5);

    Question q6;
    q6.question = "The force acting between two point charges can be computed using which of the following laws?";
    q6.answers = { "Coulomb's Law", "Newton's Second Law", "Ampere's Law" };
    q6.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q6);

    Question q7;
    q7.question = "The constant potential difference across a 2 ohm resistor is 20 volts. How many watts of power are dissipated by this resistor?";
    q7.answers = { "25 Watts", "200 Watts", "100 Watts" };
    q7.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q7);

    Question q8;
    q8.question = "If 10 joules of energy are required to move 5 coulombs of charge between two points, the potential difference between the two points is equal to how many volts?";
    q8.answers = { "3 Volts", "10 Volts", "2 Volts" };
    q8.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q8);

    Question q9;
    q9.question = "A constant potential difference is applied across the plates of a parallel-plate capacitor. Neglecting any edge effects, the electric field inside the capacitor is:";
    q9.answers = { "varying as one over r squared", "constant", "decreasing as one moves from the positive to the negative plate" };
    q9.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q9);

    Question q10;
    q10.question = "Iron is what type of magnetic material?";
    q10.answers = { "ferromagnetic", "paramagnetic", "non-magnetic" };
    q10.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q10);

    Question q11;
    q11.question = "A virtual image can be formed by one or more of the following single mirrors. Identify them.";
    q11.answers = { "plane mirror", "convex spherical mirror", "all of the above" };
    q11.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q11);

    Question q12;
    q12.question = "In Einstein's universe, what is the fourth dimension?";
    q12.answers = { "Electricity", "Time", "Strength" };
    q12.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q12);

    Question q13;
    q13.question = "The Tesla and the Gauss are units of measure of:";
    q13.answers = { "electrical current", "magnetic flux", "magnetic field strength" };
    q13.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q13);

    Question q14;
    q14.question = "What mechanical and electronic device has a name derived from a Czechoslovakian word meaning 'work; compulsory service'?";
    q14.answers = { "Robot", "Machine", "none of the above" };
    q14.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q14);

    Question q15;
    q15.question = "Which of the following colors of visible light has the longest wavelength?";
    q15.answers = { "green", "yellow", "red" };
    q15.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q15);

    Question q16;
    q16.question = "A 10 kilogram mass rests on a horizontal frictionless surface. A horizontal force of 5 Newtons is applied to the mass. After the force has been applied for 1 second, the velocity of the mass is:";
    q16.answers = { "50 meters per second", "0.5 meters per second", "5 meters per second" };
    q16.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q16);

    Question q17;
    q17.question = "A worker lifts a 10 kilogram block a vertical height of 2 meters. The work he does on the block is:";
    q17.answers = { "200 Joules", "20 Joules", "5 Joules" };
    q17.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q17);

    Question q18;
    q18.question = "The value of G, the universal gravitational constant, was measured experimentally by:";
    q18.answers = { "Newton", "Cavendish", "Copernicus" };
    q18.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q18);

    Question q19;
    q19.question = "If the distance between the earth and moon were halved, the force of the attraction between them would be:";
    q19.answers = { "twice as great", "four times as great", "one fourth as great" };
    q19.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q19);

    Question q20;
    q20.question = "As a pendulum is raised to higher altitudes, its period:";
    q20.answers = { "increases", "decreases", "remains the same" };
    q20.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q20);

    Question q21;
    q21.question = "The SI unit of pressure is the:";
    q21.answers = { "pascal", "atmosphere", "dyne per centimeter squared" };
    q21.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q21);

    Question q22;
    q22.question = "An electroscope charged WITHOUT contacting a charged body is charged by:";
    q22.answers = { "insulation", "convection", "induction" };
    q22.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q22);

    Question q23;
    q23.question = "When a metal becomes a superconductor, there is a tremendous decrease in its:";
    q23.answers = { "length", "electrical resistance", "total volume" };
    q23.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q23);

    Question q24;
    q24.question = "An x-ray photon collides with a free electron, and the photon is scattered. During this collision there is conservation of:";
    q24.answers = { "neither momentum nor energy", "energy but not momentum", "both momentum and energy" };
    q24.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q24);

    Question q25;
    q25.question = "In the sun, helium is produced from hydrogen by:";
    q25.answers = { "fusion", "disintegration", "radioactive decay" };
    q25.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q25);

    Question q26;
    q26.question = "The idea that electrons revolved in orbits around the nucleus of an atom without radiating energy away from the atom was postulated by:";
    q26.answers = { "Bohr", "Einstein", "Thompson" };
    q26.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q26);

    Question q27;
    q27.question = "Alpha particles are nuclei of:";
    q27.answers = { "oxygen", "hydrogen", "helium" };
    q27.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q27);

    Question q28;
    q28.question = "The first instrument used for measuring temperature was the gas thermoscope invented by:";
    q28.answers = { "Galileo", "Celsius", "Fahrenheit" };
    q28.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q28);

    Question q29;
    q29.question = "The first law of thermodynamics is concerned with the conservation of:";
    q29.answers = { "momentum", "energy", "matter" };
    q29.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q29);

    Question q30;
    q30.question = "Which of the following best completes the statement: The calorie is the amount of heat needed to raise:";
    q30.answers = { "1 kilogram of water 1 degree Kelvin", "1 kilogram of water 1 degree Celsius", "1 gram of water 1 degree Celsius" };
    q30.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q30);

    Question q31;
    q31.question = "According to the second law of thermodynamics, energy tends to become more and more unavailable for conversion from:";
    q31.answers = { "thermal to mechanical energy", "kinetic to thermal energy", "mechanical to thermal energy" };
    q31.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q31);

    Question q32;
    q32.question = "When a charge moves through an electric circuit in the direction of an electric force it does one of the following four things. Does it:";
    q32.answers = { "gain potential energy and lose kinetic energy", "lose potential energy and gain kinetic energy", "lose both potential and kinetic energy" };
    q32.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q32);

    Question q33;
    q33.question = "Which one of the following is the name of a device used to measure voltage without drawing ANY current from the circuit being measured? Is it:";
    q33.answers = { "a wattmeter", "an ammeter", "a potentiometer" };
    q33.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q33);

    Question q34;
    q34.question = "Lenz's law is an example of the law of conservation of one of the following. Is it conservation of:";
    q34.answers = { "charge", "energy", "mass" };
    q34.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q34);

    Question q35;
    q35.question = "A satellite is observed to move in a circle about the earth at a constant speed. This means that the force acting upon it is:";
    q35.answers = { "zero", "parallel to the direction of the satellite's instantaneous velocity", "perpendicular to the direction of the satellite's instantaneous velocity" };
    q35.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q35);

    Question q36;
    q36.question = "A machine's output is 4000 joules and its frictional losses are 1000 joules. Which of the following is its efficiency? Is it:";
    q36.answers = { "80%", "30%", "25%" };
    q36.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q36);

    Question q37;
    q37.question = "A rise in temperature of 20 Kelvin degrees is equal to a rise of:";
    q37.answers = { "68 degrees Celsius", "20 degrees Celsius", "36 degrees Celsius" };
    q37.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q37);

    Question q38;
    q38.question = "According to the kinetic theory, the Kelvin temperature of an ideal gas is proportional to which one of the following. Is the temperature proportional to the gas's average molecular:";
    q38.answers = { "kinetic energy", "velocity", "potential energy" };
    q38.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q38);

    Question q39;
    q39.question = "The ENERGY associated with a photon depends upon the photon's:";
    q39.answers = { "the brightness of the source from which it comes", "amplitude", "frequency" };
    q39.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q39);

    Question q40;
    q40.question = "When an atomic nucleus emits a beta particle, one of its neutrons disintegrates into one of the following set of particles. Does it disintegrate into:";
    q40.answers = { "a positron and an electron", "a proton, an electron, and an antineutrino", "a proton, an electron, and a positron" };
    q40.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q40);

    Question q41;
    q41.question = "What does statics study in physics?";
    q41.answers = { "The motion of objects under the influence of forces.", "Objects at rest or in a state of constant velocity.", "The motion of objects with changing velocity." };
    q41.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q41);

    Question q42;
    q42.question = "What is equilibrium in statics?";
    q42.answers = { "The state of an object experiencing an unbalanced force.", "The state of an object in motion.", "The state of an object at rest or in uniform motion." };
    q42.rightAnswerIndex = 2; // Index of the correct answer
    allQuestions.push_back(q42);

    Question q43;
    q43.question = "What are the conditions for static equilibrium?";
    q43.answers = { "The net force and net torque acting on the object are both zero.", "The net force acting on the object is zero, but the net torque may be non-zero.", "The net force acting on the object is non-zero, but the net torque is zero." };
    q43.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q43);

    Question q44;
    q44.question = "Which of the following is an example of static equilibrium?";
    q44.answers = { "A book sliding across a table at a constant speed.", "A crate sitting on the floor.", "A car accelerating down a highway." };
    q44.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q44);

    Question q45;
    q45.question = "What is the significance of the center of mass in statics?";
    q45.answers = { "It indicates the point where an object's weight is concentrated.", "It determines the object's total mass.", "It affects the object's acceleration." };
    q45.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q45);

    Question q46;
    q46.question = "How does the concept of torque relate to static equilibrium?";
    q46.answers = { "Torque is the force applied to an object in static equilibrium.", "Torque is the rotational equivalent of force and can cause angular acceleration.", "Torque has no relevance to static equilibrium." };
    q46.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q46);

    Question q47;
    q47.question = "How does the distribution of mass affect an object's stability in statics?";
    q47.answers = { "Objects with a lower center of mass are more stable.", "Objects with a higher center of mass are more stable.", "The distribution of mass has no effect on stability." };
    q47.rightAnswerIndex = 0; // Index of the correct answer
    allQuestions.push_back(q47);

    Question q48;
    q48.question = "What role does friction play in static equilibrium?";
    q48.answers = { "Friction prevents objects from achieving static equilibrium.", "Friction stabilizes objects in static equilibrium by providing a counteracting force.", "Friction has no effect on static equilibrium." };
    q48.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q48);

    Question q49;
    q49.question = "How does the concept of stability relate to static equilibrium?";
    q49.answers = { "Stable objects have a higher center of mass.", "Stable objects have a lower center of mass.", "Stability depends solely on the mass of the object." };
    q49.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q49);

    Question q50;
    q50.question = "How does the shape of an object affect its stability in statics?";
    q50.answers = { "Objects with irregular shapes are more stable.", "Objects with symmetrical shapes are more stable.", "The shape of an object has no effect on stability." };
    q50.rightAnswerIndex = 1; // Index of the correct answer
    allQuestions.push_back(q50);

    // Add other questions similarly...

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(allQuestions.begin(), allQuestions.end(), g);

    // Declare an array to store selected answers for each question
    int selectedAnswers[10] = { -1 }; // Initialize selected answers to -1

    int buttonWidth = physicsButtonImg.width;
    int buttonHeight = physicsButtonImg.height;
    int buttonPadding = 20; // Padding from the top and right edges
    int buttonX = screenWidth - buttonWidth - buttonPadding - 30; // X-coordinate
    int buttonY = buttonPadding + 5; // Y-coordinate

    const int numQuestionsToDisplay = 4; // Display all questions
    const int x = 50;
    const int columnSpacing = 400; // Space between columns

    Rectangle physicsButtonRect = { buttonX, buttonY, buttonWidth, buttonHeight };

    int totalPoints = 0;

    int currentQuestionIndex = 0; // Initialize index to the first question
    bool isButtonPressed = false; // Flag to track button press

    while (!WindowShouldClose()) {
        // Check for mouse hover and button press
        bool isHover = CheckCollisionPointRec(GetMousePosition(), physicsButtonRect);
        isButtonPressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        // Draw physics button
        if (isHover) {
            // Change cursor to pointer
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

            // Change image on hover
            DrawTexture(hover_physicsButtonImg, buttonX, buttonY, WHITE);
        }
        else {
            // Reset cursor to default
            SetMouseCursor(MOUSE_CURSOR_ARROW);

            // Draw default button image
            DrawTexture(physicsButtonImg, buttonX, buttonY, WHITE);
        }

        // Draw next question button or check button based on the current question
        if (currentQuestionIndex < allQuestions.size() - 1) {
            DrawRectangle(buttonX + buttonWidth - 100, buttonY + 800, 100, 50, GREEN);
            DrawText("Next", buttonX + buttonWidth - 90, buttonY + 815, 20, BLACK);
        }
        else {
            DrawRectangle(buttonX + buttonWidth - 100, buttonY + 800, 100, 50, GREEN);
            DrawText("Check", buttonX + buttonWidth - 110, buttonY + 815, 20, BLACK);
        }

        // Check if the next button is pressed
        if (CheckCollisionPointRec(GetMousePosition(), { static_cast<float>(buttonX + buttonWidth - 100), static_cast<float>(buttonY + 800), 100.0f, 50.0f }) && isButtonPressed && currentQuestionIndex == allQuestions.size() - 1) {
            // Calculate points

            currentQuestionIndex++;

            int numCorrectAnswers = 0;
            for (size_t i = 0; i < allQuestions.size(); ++i) {
                if (selectedAnswers[i] == allQuestions[i].rightAnswerIndex) {
                    numCorrectAnswers++;
                }
            }

            // Print total points
            totalPoints = numCorrectAnswers * 10; // Assuming each correct answer is worth 10 points
            std::cout << "Total Points: " << totalPoints << std::endl;

            isButtonPressed = false; // Reset button press flag
        }

        int xPos = x;
        int yPos = 200; // Start position for the first question, adjusted to be lower
        for (int i = currentQuestionIndex; i < currentQuestionIndex + numQuestionsToDisplay && i < allQuestions.size(); i++) {
            displayQuestion(allQuestions[i], xPos, yPos, 30); // Increased font size to 30
            displayRadioButtons(xPos, yPos, selectedAnswers[i], i + 1, 20, true, selectedAnswers); // Changed font size to 20 and pass true for clickable

            yPos += 500; // Increase vertical position for the next question, adjusted to move both questions lower
        }

        // Display index of the current questions
        DrawText(TextFormat("Questions %d to %d / %d", currentQuestionIndex + 1, std::min(currentQuestionIndex + numQuestionsToDisplay, static_cast<int>(allQuestions.size())), allQuestions.size()), screenWidth - 250, screenHeight - 50, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    UnloadTexture(background);
    UnloadTexture(physicsButtonImg);
    UnloadTexture(hover_physicsButtonImg);
}