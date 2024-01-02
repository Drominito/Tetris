// Tetris.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include "Tetris.h"



int main()
{
	const int Width  = 16;
	const int Height = 16;
	int PlayerX = Width / 2;
	int PlayerY = Height / 2;

	bool AutoRun = true;
	int PlayerXPad = 0;
	char InputController;

	int TimeOrientator = 0;
	bool MapArea[Width][Height];
	const int Instances = 10;
	bool BodyArea[Instances][Width][Height];



	//Clear MapArea to false


	for (int y1 = 0; y1 < Height; y1++)
	{
		for (int x = 0; x < Width; x++)
		{
			MapArea[x][y1] = false;
		}
	}
	for (int z1 = 0; z1 < 10; z1++)
	{
		for (int y = 0; y < Height; y++)
		{
			for (int x = 0; x < Width; x++)
			{
				BodyArea[z1][x][y] = false;
			}
		}
	}
	/*
	*/



	// Not player, more body, an array of lists.


	//Fill MapArea
	// build on PlayerAre the body manually.

	
	// Draw
	const int Limit = -8;
	while (true)
	{

		for (int t = 5; t > Limit; t--)
		{
			if (_kbhit())
			{
				int key = _getch();
				Display(Width, Height, PlayerX, PlayerY, BodyArea, PlayerXPad, t);

				switch (key)
				{
					case 97:  PlayerXPad--; break; // a
					case 100: PlayerXPad++; break; // d
					case 114: PlayerXPad = 0; t = 5; break; // r
					case 10:
					{
						if (AutoRun == false) { AutoRun = true; }
						else				  { AutoRun = false; }
					}
					break; // enter
				}

				//SomeRandomFunnyGeneration(Instances, BodyArea, Width, Height);
				PrintOut(Instances, Height, Width, BodyArea, MapArea);


				std::this_thread::sleep_for(std::chrono::milliseconds(125));

				if (t > Limit + 1)
				{
					std::system("cls");
				}
			}
			else
			{
				if (AutoRun)
				{
					Display(Width, Height, PlayerX, PlayerY, BodyArea, PlayerXPad, t);
					PrintOut(Instances, Height, Width, BodyArea, MapArea);

					std::this_thread::sleep_for(std::chrono::milliseconds(125));

					if (t > Limit + 2)
					{
						std::system("cls");
					}

				}
			}
			


		}
	}

	char a;
	std::cin >> a;
		
	



	// Create Objets as an Array(Objects Data) in an Array(Combined in the WorldArray)



	


	//	default:
	//		break;
	//	}
	//	if (PlayerY < Height - 1)
	//	{
	//		PlayerY++;
	//	}
	//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//	std::system("cls");
	//}
}

void Display(const int& Width, const int& Height, int PlayerX, int PlayerY, bool  BodyArea[10][16][16], int PlayerXPad, int t)
{
	for (int y = 0; y < Width; y++)
	{
		for (int x = 0; x < Height; x++)
		{

			bool ThreeCubes01 = (x >= PlayerX - 1 && x <= PlayerX + 1
				&& y >= PlayerY - 1 && y <= PlayerY

				&& (y != PlayerY - 1 || x != PlayerX - 1)
				&& (x != PlayerX + 1 || y != PlayerY - 1));

			bool ThreeCubes02 = (x >= PlayerX - 1 && x <= PlayerX + 1
				&& y >= PlayerY - 1 && y <= PlayerY

				&& (y != PlayerY - 0 || x != PlayerX - 0)
				&& (x != PlayerX + 0 || y != PlayerY - 0));

			bool ThreeCubes03 = (x >= PlayerX - 1 && x <= PlayerX + 0
				&& y >= PlayerY - 2 && y <= PlayerY

				&& (y != PlayerY - 0 || x != PlayerX - 1)
				&& (x != PlayerX - 1 || y != PlayerY - 2));


			bool ThreeCubes04 = (x >= PlayerX - 1 && x <= PlayerX + 0
				&& y >= PlayerY - 3 && y <= PlayerY

				&& (x != PlayerX - 1 || y != PlayerY - 1)
				&& (x != PlayerX - 1 || y != PlayerY - 2)
				&& (x != PlayerX - 1 || y != PlayerY - 3));

			if (ThreeCubes03)
			{
				BodyArea[0][x + PlayerXPad][y - t] = true;
			}
			else
			{
				BodyArea[0][x + PlayerXPad][y - t] = false;
			}

		}

	}
}
													    

void SomeRandomFunnyGeneration(const int& Instances, bool BodyArea[10][16][16], const int& Width, const int& Height)
{
	for (int j = 1; j < Instances / 2; j++)
	{
		for (int i = 0; i < Instances; i += j)
		{
			BodyArea[0][3 + i][4 * 2 + i] = true;
			BodyArea[1][2 + i + i - 2][4 * 3 - i] = true;
			BodyArea[2][5    ][4 * i * 2 - 1] = true;
			BodyArea[3][5 + i][5 * i * i] = true;
			BodyArea[4][5][6] = true;
			BodyArea[4][6][6] = true;
			BodyArea[5][6][6] = true;
			BodyArea[6][6][6] = true;


			//Combine Maparea with MapArea + PlayerArea
			std::this_thread::sleep_for(std::chrono::milliseconds(0));

		}
	}
}

void PrintOut(const int& Instances, const int& Height, const int& Width, bool BodyArea[10][16][16], bool MapArea[16][16])
{
	const int Limit = 1;
	for (int z = 0; z < Limit; z++)
	{
		for (int y = 0; y < Height; y++)
		{
			for (int x = 0; x < Width; x++)
			{
				bool a = BodyArea[z][x][y];
				bool b = MapArea[x][y];
				if (a != b)
				{
					MapArea[x][y] = BodyArea[z][x][y];
					std::cout << "[X]";

				}
				else
				{
					std::cout << "[ ]";
				}
			}
			std::cout << std::endl;

		}

		if (z == Limit - 2)
		{
			std::system("cls");
		}

	}
}