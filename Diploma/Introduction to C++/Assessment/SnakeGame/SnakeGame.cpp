#include <iostream>
#include <raylib.h>
#include <vector>

static const int ROWS = 38;
static const int COLS = 28;

const char* titleText = "SNEK!";

int m_tileWidth = 20;
int m_tileHeight = 20;

float xPos = 0;
float yPos = 0;

int foodX[COLS];
int foodY[ROWS];

float velocity = 100;

// variables for food
struct Food
{
	float x, y;
	float radius;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, RED);
	}
};

// variables for snake
struct Snake 
{
	float x = (float)GetScreenWidth() / 2 + (float)10;
	float y = (float)GetScreenHeight() / 2 + (float)10;
	float width = 20;
	float height = 20;
	
	/*Vector2 velocity = { 0.0, 0.0 };*/
	float speedX;
	float speedY;

	Rectangle GetRect()
	{
		return Rectangle{ x - width / 2, y - height / 2, 20, 20 };
	}

	void Draw()
	{
		DrawRectangleRec(GetRect(), BLACK);
	}
};

int main()
{
	InitWindow(800, 600, "SNAKE!"); // opens window for game
	SetWindowState(FLAG_VSYNC_HINT); // stabilize frame rate

	// spawn food in random location on grid
	Food food;
	food.x = GetRandomValue(2, ROWS - 1) * 20 + 10;
	food.y = GetRandomValue(2, COLS - 1) * 20 + 10;
	food.radius = 5;

	Snake snake;
	snake.speedX = velocity;
	snake.speedY = 0;

	//// initialise player
	//std::vector<Snake> player;
	//Snake head = Snake();
	//head.velocity = { 0.0, 1.0 };
	//player.push_back(head);

	//Snake tail = Snake();
	//tail.y = head.y - ((float)GetScreenWidth() / 2 + (float)10);
	//player.push_back(tail);
	//tail.y = head.y - ((float)GetScreenWidth() / 2 + (float)10 * 2.0);
	//player.push_back(tail);

	//Vector2 previous = { player[0].x, player[0].y };

	while (!WindowShouldClose())
	{
		snake.x += snake.speedX * GetFrameTime();
		snake.y += snake.speedY * GetFrameTime();

		// control snake
		if (IsKeyPressed(KEY_S) && snake.speedY != velocity)
		{
			snake.speedY = velocity;
			snake.speedX = 0;
		}
		if (IsKeyPressed(KEY_W) && snake.speedY != -velocity)
		{
			snake.speedY = -velocity;
			snake.speedX = 0;
		}
		if (IsKeyPressed(KEY_D) && snake.speedX != velocity)
		{
			snake.speedY = 0;
			snake.speedX = velocity;
		}
		if (IsKeyPressed(KEY_A) && snake.speedX != -velocity)
		{
			snake.speedY = 0;
			snake.speedX = -velocity;
		}


		//// control snake
		//if (IsKeyPressed(KEY_S) && player[0].velocity.y != -1) player[0].velocity = {0, 1};
		//if (IsKeyPressed(KEY_W) && player[0].velocity.y != 1) player[0].velocity = { 0, -1 };
		//if (IsKeyPressed(KEY_D) && player[0].velocity.x != -1) player[0].velocity = { 1, 0 };
		//if (IsKeyPressed(KEY_A) && player[0].velocity.x != 1) player[0].velocity = { -1, 0 };

		// handle food respawn
		if (CheckCollisionCircleRec(Vector2{ food.x, food.y }, food.radius, snake.GetRect()))
		{
			food.x = GetRandomValue(2, ROWS - 1) * 20 + 10;
			food.y = GetRandomValue(2, COLS - 1) * 20 + 10;
		}

		//// player movement
		//for (int i = 1; i < player.size(); i++)
		//{
		//	float tmpX = player[i].x;
		//	float tmpY = player[i].y;
		//	player[i].x = previous.x;
		//	player[i].y = previous.y;
		//	previous.x = tmpX;
		//	previous.y = tmpY;
		//}
		//player[0].x += player[0].velocity.x * ((float)GetScreenWidth() / 2 + (float)10);
		//player[0].y += player[0].velocity.y * ((float)GetScreenWidth() / 2 + (float)10);
		//previous = { player[0].x, player[0].y };

		// drawing to screen
		BeginDrawing();
			ClearBackground(WHITE); // draw background

			int titletextWidth = MeasureText(titleText, 20); // gets text width for alignment
			DrawText(titleText, GetScreenWidth() / 2 - titletextWidth / 2, 10, 20, BLUE); // draws title text

			food.Draw();
			snake.Draw();
			
			////draw player
			//for (int i = 0; i < player.size(); i++)
			//{
			//	if (i == 0)
			//	{
			//		/*DrawRectangle(player[i].x, player[i].y, player[i].width, player[i].height, GRAY);*/
			//		head.Draw();
			//	}
			//	else
			//	{
			//		DrawRectangle(player[i].x, player[i].y, player[i].width, player[i].height, BLACK);
			//	}

			//}

			//grid for game
			for (int rowIndex = 2; rowIndex < ROWS; rowIndex++)
			{
				for (int colIndex = 2; colIndex < COLS; colIndex++)
				{
					xPos = rowIndex * m_tileWidth;
					yPos = colIndex * m_tileHeight;
					int index = colIndex + (rowIndex * COLS);
					DrawRectangleLines(xPos, yPos, m_tileWidth, m_tileHeight, PURPLE);
				}
			}

			DrawFPS(10, 10); // draw FPS rate
		EndDrawing();
	}

	CloseWindow();
}


