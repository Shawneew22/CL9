#include <iostream>
#include <string>
using namespace std;

struct Room
{
	float width;
	float length;
	string name;

	float GetArea()
	{
		return width * length;
	}

	float GetPerimeter()
	{
		return 2 * width + 2 * length;
	}
};

struct Building
{
	string address;
	Room rooms[10];
	int totalRooms;

	Building()
	{
		address = "not set";
		totalRooms = 0;
	}

	void AddRoom(string newName, float newWidth, float newLength)
	{
		Room newRoom;
		newRoom.width = newWidth;
		newRoom.length = newLength;
		newRoom.name = newName;
		rooms[totalRooms] = newRoom;
		totalRooms++;
	}
};

int main()
{
	Building bldg;

	bool done = false;

	while (!done)
	{
		cout << "1. Set building address " << endl;
		cout << "2. Add room " << endl;
		cout << "3. View all building information " << endl;
		cout << "4. Quit" << endl;

		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			cout << "What is the address of the building? ";
			getline(cin, bldg.address);
		}
		else if (choice == 2)
		{
			string roomName;
			float width, length;
			cout << " What is the name of the room? " ;
			getline(cin, roomName);
			cout << " What is the width and lenght of the room? " ;
			cin >> width >> length;
			bldg.AddRoom(roomName, width, length);
		}
		else if (choice == 3)
		{
			cout << "Address: " << bldg.address << endl;
			cout <<"Total Rooms: " << bldg.totalRooms << endl;
			for (int i = 0; i < bldg.totalRooms; i++)
			{
				cout << "Room " << i << ": " << bldg.rooms[i].name << endl;
				cout << "Width: " << bldg.rooms[i].width << endl;
				cout << "Length: " << bldg.rooms[i].length << endl;
				cout << "Area: " << bldg.rooms[i].GetArea() << endl;
				cout << "Perimeter: " << bldg.rooms[i].GetPerimeter() << endl;
			}

		}
		else if (choice == 4)
		{
			done = true;
		}
	}

	return 0;
}