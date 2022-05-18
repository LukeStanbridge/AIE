#include <iostream>
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

    // creates rectangle dimensions/position used for drawing and collisions
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

    // creates instances of the required objects
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

    // initialise winner text to null
    const char* winnerText = nullptr;

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

        // control left paddle
        if (IsKeyDown(KEY_W))
        {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S))
        {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }

        // control right paddle
        if (IsKeyDown(KEY_UP))
        {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_DOWN))
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
            winnerText = nullptr;
        }

        // Drawing to screen
        BeginDrawing();
            ClearBackground(WHITE); // draw background

            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();

            if (winnerText) // if not nullptr
            {
                int textWidth = MeasureText(winnerText, 60); // gets text width for text alignment
                DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, RED); // Draws winner text
            }

            DrawFPS(10, 10); // draw FPS rate to screen
        EndDrawing();
    }

    CloseWindow();

    // add score
    // add bounds for paddles
    // add controls and header maybe
    // make ball curve when it hits paddle maybe
    return 0;
}
