#include <iostream>
#include <sstream>
#include <raylib.h>

struct Ball
{
    // variables for the ball
    float x, y;
    float speedX, speedY;
    float radius;

    void Draw()
    {
        DrawCircle((int) x, (int) y, radius, BLACK);
    }
};

struct Paddle
{
    float x, y;
    float speed;
    float width, height;

    // creates rectangle struct with dimensions/position used for drawing and collisions
    Rectangle GetRect()
    {
        return Rectangle{ x - width / 2, y - height / 2, 10, 100 };
    }

    void Draw()
    {
        DrawRectangleRec(GetRect(), BLACK);
    }
};

int main()
{
    InitWindow(800, 600, "PONG!"); // Opens window for game
    SetWindowState(FLAG_VSYNC_HINT); // stabilize frame rate

    // creates instances of the required objects and sets values
    Ball ball;
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.speedX = 300;
    ball.speedY = 300;
    ball.radius = 5;

    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2.0f;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;

    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2.0f;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;

    // initialise text to display on screen
    const char* winnerText = nullptr;
    const char* leftScore = "0";
    const char* rightScore = "0";
    int num1 = 0;
    int num2 = 0;
    
    while (!WindowShouldClose()) // Keeps initilised window open
    {
        // give the ball speed
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        // bounces ball off window edges
        if (ball.y < 0)
        {
            ball.y = 0; // stops ball getting stuck at the edge of the screen
            ball.speedY *= -1; // reverse direction
        }
        if (ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        }

        // control left paddle and bound its movement
        if (IsKeyDown(KEY_W) && leftPaddle.y >= 50)
        {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && leftPaddle.y <= 550)
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }

        // control right paddle and boud its movement
        if (IsKeyDown(KEY_UP) && rightPaddle.y >= 50)
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN) && rightPaddle.y <= 550)
        {
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }

        // check collisions with paddles
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))
        {
            // second if check eliminates ball drag when it hits the side of the paddle 
            if (ball.speedX < 0)
            {
                ball.speedX *= -1.1f; //increase speed
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX; // change angle the ball bounces off paddle depending on how close/far from the centre it collides
            }          
        }

        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
        {
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
            }       
        }

        // logic for which player wins
        if (ball.x < 0)
        {
            winnerText = "RIGHT PLAYER WINS!";
        }
        if (ball.x > GetScreenWidth())
        {
            winnerText = "LEFT PLAYER WINS!";       
        }  
        

        // reset game when space is pressed
        if (winnerText && IsKeyPressed(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;

            // adds score depending on who won the point
            if (winnerText == "LEFT PLAYER WINS!")
            {
                num1++;
            }
            if (winnerText == "RIGHT PLAYER WINS!")
            {
                num2++;
            }
            winnerText = nullptr;
        }

        // converts score back to const char
        std::string tmp = std::to_string(num1);
        leftScore = tmp.c_str();
        std::string tmp2 = std::to_string(num2);
        rightScore = tmp2.c_str();

        // Drawing to screen
        BeginDrawing();
            ClearBackground(WHITE); // draw background

            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();

            // Draw scoreboard
            int rightScoreWidth = MeasureText(rightScore, 30);
            int leftScoreWidth = MeasureText(leftScore, 30);           
            DrawText(leftScore, (GetScreenWidth() / 2 - leftScoreWidth / 2) - 32.5f, 50, 40, RED);
            DrawLine(GetScreenWidth() / 2, 30, GetScreenWidth() / 2, 110, BLACK);
            DrawText(rightScore, (GetScreenWidth() / 2 - rightScoreWidth / 2) + 25, 50, 40, RED);

            if (winnerText) // if not nullptr
            {               
                int textWidth = MeasureText(winnerText, 60); // gets text width for text alignment
                DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, RED); // Draws winner text
            }

            DrawFPS(10, 10); // draw FPS rate to screen
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
